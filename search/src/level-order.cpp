#include <stdio.h>
#include <stdint.h>

#include "graph.h"
#include "queue.h"

bool lv_traverse(graph_t& g) {
	if (g.size <= 0) {
		return true;
	}
	uint64_t *visit = new uint64_t[g.size];
	for (int i=0; i<g.size; ++i) {
		visit[i] = 0;
	}
	queue *vq = new queue[2]{g.size, g.size};
		

	//printf("%c enqueue\n", 0+'A');
	vq[0].enqueue(0);
	++visit[0];
	uint64_t level = 0;
	uint64_t qindex = 0;	
	while (!vq[0].isEmpty() || !vq[1].isEmpty()) {
		uint64_t vindex; 
		if (vq[qindex].isEmpty()) {
			++level;
			printf("entering level:%d\n",level);
			qindex ^= 1;
		}
		vq[qindex].dequeue(vindex);
		//printf("%c dequeue\n", vindex+'A');	
		printf("visit %c\n", vindex+'A');
		
		
		for (arc_t *arc=g.node[vindex].first_arc; arc!=NULL; arc=arc->next) {
			if (visit[arc->dest] == 0) {
				vq[qindex^1].enqueue(arc->dest);
				++visit[arc->dest];
				//printf("%c enqueue\n", arc->dest+'A');
			}
		}
	}
	return true;
}


int main() {
	printf("----this is level order traverse test.\n");
	graph_t g(8);
	g.insertArc( 0, 1);
	g.insertArc( 0, 2);
	g.insertArc( 0, 3);
	g.insertArc( 1, 4);
	g.insertArc( 2, 5);
	g.insertArc( 3, 6);
	g.insertArc( 5, 7);
	g.insertArc( 6, 7);
	lv_traverse(g);


	return 0;
}









