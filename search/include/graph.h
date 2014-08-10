#ifndef __GRAPH_H
#define __GRAPH_H

#include <stdint.h>

struct arc_t {
public:
	arc_t(uint64_t dest, uint64_t cost=0, void*data=NULL, arc_t*next=NULL) :
		dest(dest), cost(cost), data(data), next(next) {
	}
public:
	uint64_t dest;
	int64_t  cost;
	void*    data;
	arc_t*   next;
};

struct node_t {
public:
	node_t() : info((char*)NULL), first_arc(NULL) {
	} 
	
public:
	union info_union {
		info_union(uint8_t ch) : ch(ch) {}
		info_union(char* str)  : str(str) {}
		info_union(void* data) : data(data) {}
		uint8_t ch;
		char* str;
		void* data;
	}info;
	arc_t* first_arc;
};

struct graph_t {
public:
	graph_t(uint64_t size) {
		if (size <= 0) {
			this->size = 0;
			node = NULL;
		} else {
			this->size = size;
			node = new node_t[size];
		}
	}
	bool insertArc(uint64_t from, uint64_t to) {
		arc_t* arc = new arc_t(to);
		arc->next = this->node[from].first_arc;	
		this->node[from].first_arc = arc;
		return true;
	}
public:
	uint64_t size;
	node_t*  node;
};


#endif
