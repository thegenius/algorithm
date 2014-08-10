/***************************************************
*  作者：汪蔚                                      *
*  更新：2014-07-15                                *
****************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "Queue.h"
#include "Graph.h"
#include "OpenList.h"
#include "CloseList.h"
#include "Geometry.h"
#include "Graph.h"

class AStarHelper {
public:
	AStarHelper(int node_size) {
		_openSet  = new OpenList(node_size);
		_closeSet = new CloseList(node_size);
		g_score   = new int[node_size];
		f_score   = new int[node_size];
		path      = new int[node_size];
		cost      = new int[node_size];
		memset(g_score,      0x7f, sizeof(int)*node_size);  
		memset(f_score,      0x7f, sizeof(int)*node_size);  
		memset(path,         0xff, sizeof(int)*node_size);  //0xffffffff == -1
		memset(cost,         0x7f, sizeof(int)*node_size);  
	}
	void insertPath(int src, int dst, int cst=1) {
		path[dst] = src;
		cost[dst] = cst;
	}
	void printPath(int dst) {
		if (path[dst] != -1) {
			printPath(path[dst]);
			printf(" --[%d]--> %d", cost[dst], dst);
		} else {
			printf("%d", dst);
		}
	}
public:
	OpenList  *_openSet;
	CloseList *_closeSet;

	int *path;         // 记录路径的数组，每个单元的内容指向路径中前一个节点的下标
	int *cost;         // 记录路径的代价
	int *g_score;      // 从开始节点，到目前节点的最佳路径的cost
	int *f_score;      // 从开始节点，到目标节点的cost的估计
};

int heuristic_cost_estimate(Graph &g, int src, int dst) {
	return 0;
}

bool AStarTraverse(Graph& g, int src, int dst) {

	AStarHelper helper(g.size);

	// 初始化open表，close表为空不需要再做显式初始化
	helper._openSet->insert(src, 0);
	helper.g_score[src] = 0;
	helper.f_score[src] = helper.g_score[src] + heuristic_cost_estimate(g, src, dst);

	while (!helper._openSet->isEmpty()) {

		// 从open表中提取f(x)最小的节点
		int curr = -1;
		int cost = 0;
		helper._openSet->extractMin(curr, cost);
		helper._closeSet->insert(curr, cost);

		// 如果已经找到
		if (curr == dst) {
			break;
		}

		// 如果还没有找到目标节点，遍历所以相邻节点
		for (GraphArc *arc=g.node[curr].first_arc; arc!=NULL; arc=arc->next) {
			int neighbour = arc->dest;
			// 如果这个相邻节点已经在close中
			if (helper._closeSet->isContain(neighbour)) {
				continue;
			}
			// 如果经过当前节点，到达相邻节点更加节省代码
			int tentative_g_score = helper.g_score[curr] + arc->cost;
			if (tentative_g_score < helper.g_score[neighbour]) {
				helper.g_score[neighbour] = tentative_g_score;
				helper.insertPath(curr, neighbour, arc->cost);
			}
			// 重新计算这个相邻节点的f(x)值
			int tentative_f_score = helper.g_score[neighbour] + heuristic_cost_estimate(g, neighbour, dst);
			if (tentative_f_score < helper.f_score[neighbour]) {
				helper.f_score[neighbour] = tentative_f_score;
			}
			// 最后添加到open表中
			helper._openSet->insert(neighbour, helper.f_score[neighbour]);
		}
	}

	helper.printPath(dst);
	return true;
}
