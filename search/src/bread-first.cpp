#include <stdio.h>
#include <stdint.h>

#include "graph.h"
#include "queue.h"

bool bf_traverse(graph_t& g) {
	if (g.size <= 0) {
		return true;
	}
	uint64_t *visit = new uint64_t[g.size];
	for (int i=0; i<g.size; ++i) {
		visit[i] = 0;
	}
	queue vq(g.size);
	//printf("%c enqueue\n", 0+'A');
	vq.enqueue(0);
	++visit[0];
		
	while (!vq.isEmpty()) {
		uint64_t vindex; 
		vq.dequeue(vindex);
		//printf("%c dequeue\n", vindex+'A');	
		printf("visit %c\n", vindex+'A');
		
		for (arc_t *arc=g.node[vindex].first_arc; arc!=NULL; arc=arc->next) {
			if (visit[arc->dest] == 0) {
				vq.enqueue(arc->dest);
				++visit[arc->dest];
				//printf("%c enqueue\n", arc->dest+'A');
			}
		}
	}
	return true;
}


int main() {
	printf("----this is bread first traverse test.\n");
	graph_t g(8);
	g.insertArc( 0, 1);
	g.insertArc( 0, 2);
	g.insertArc( 0, 3);
	g.insertArc( 1, 4);
	g.insertArc( 2, 5);
	g.insertArc( 3, 6);
	g.insertArc( 5, 7);
	g.insertArc( 6, 7);
	bf_traverse(g);


	return 0;
}









