/***************************************************
*  ���ߣ���ε                                      *
*  ���£�2014-07-15                                *
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

	int *path;         // ��¼·�������飬ÿ����Ԫ������ָ��·����ǰһ���ڵ���±�
	int *cost;         // ��¼·���Ĵ���
	int *g_score;      // �ӿ�ʼ�ڵ㣬��Ŀǰ�ڵ�����·����cost
	int *f_score;      // �ӿ�ʼ�ڵ㣬��Ŀ��ڵ��cost�Ĺ���
};

int heuristic_cost_estimate(Graph &g, int src, int dst) {
	return 0;
}

bool AStarTraverse(Graph& g, int src, int dst) {

	AStarHelper helper(g.size);

	// ��ʼ��open��close��Ϊ�ղ���Ҫ������ʽ��ʼ��
	helper._openSet->insert(src, 0);
	helper.g_score[src] = 0;
	helper.f_score[src] = helper.g_score[src] + heuristic_cost_estimate(g, src, dst);

	while (!helper._openSet->isEmpty()) {

		// ��open������ȡf(x)��С�Ľڵ�
		int curr = -1;
		int cost = 0;
		helper._openSet->extractMin(curr, cost);
		helper._closeSet->insert(curr, cost);

		// ����Ѿ��ҵ�
		if (curr == dst) {
			break;
		}

		// �����û���ҵ�Ŀ��ڵ㣬�����������ڽڵ�
		for (GraphArc *arc=g.node[curr].first_arc; arc!=NULL; arc=arc->next) {
			int neighbour = arc->dest;
			// ���������ڽڵ��Ѿ���close��
			if (helper._closeSet->isContain(neighbour)) {
				continue;
			}
			// ���������ǰ�ڵ㣬�������ڽڵ���ӽ�ʡ����
			int tentative_g_score = helper.g_score[curr] + arc->cost;
			if (tentative_g_score < helper.g_score[neighbour]) {
				helper.g_score[neighbour] = tentative_g_score;
				helper.insertPath(curr, neighbour, arc->cost);
			}
			// ���¼���������ڽڵ��f(x)ֵ
			int tentative_f_score = helper.g_score[neighbour] + heuristic_cost_estimate(g, neighbour, dst);
			if (tentative_f_score < helper.f_score[neighbour]) {
				helper.f_score[neighbour] = tentative_f_score;
			}
			// �����ӵ�open����
			helper._openSet->insert(neighbour, helper.f_score[neighbour]);
		}
	}

	helper.printPath(dst);
	return true;
}
