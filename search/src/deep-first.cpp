#include <stdio.h>
#include <stdint.h>

#include "graph.h"


void df_visit(graph_t& g, uint64_t vindex, uint64_t* visit) {
	++visit[vindex];

	//do something
	printf("visit %c\n", vindex+'A');

	for (arc_t *arc=g.node[vindex].first_arc; arc!=NULL; arc=arc->next) {
		if (visit[arc->dest] == 0) {
			df_visit(g, arc->dest, visit);
		}
	}
}


void df_traverse(graph_t& g) {
	uint64_t size = g.size;
	uint64_t* visit = new uint64_t[size];
	for (int i=0; i<size; ++i) {
		visit[i] = 0;
	}
	for (int i=0; i<size; ++i) {
		if (visit[i] == 0) {
			df_visit(g, i, visit);
		}
	}	
}

int main() {
	printf("----this is deep first traverse test.\n");
	graph_t g(8);
	g.insertArc( 0, 1);
	g.insertArc( 0, 2);
	g.insertArc( 0, 3);
	g.insertArc( 1, 4);
	g.insertArc( 2, 5);
	g.insertArc( 3, 6);
	g.insertArc( 5, 7);
	g.insertArc( 6, 7);
	df_traverse(g);

	return 0;
}









