#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdio.h>
#include <stdint.h>


uint64_t next_power2(uint64_t x) {
	--x;
	x = x | x>>1;
	x = x | x>>2;
	x = x | x>>4;
	x = x | x>>8;
	x = x | x>>16;
	x = x | x>>32;
	++x;
	return x;
}

struct queue {
public:
	queue(uint64_t capacity) {
		front = 0;
		back  = 0;
		this->capacity = next_power2(capacity+1);
		q = new uint64_t[this->capacity];
	}
	bool isEmpty() {
		return front==back;	
	}
	bool isFull() {
		return front-back==1 || back-front==capacity-1;
	}
	uint64_t size() {
		int size = back-front;
		if (size < 0) {
			size += capacity;
		}
		return size;
	}
	void enqueue(uint64_t x) {
		if (isFull()) {
			uint64_t *newq = new uint64_t[capacity<<1];
			uint64_t newback = 0;
			for (int i=front; i!=back; i=++i&(capacity-1)) {
				newq[newback++] = q[i];
			}
			delete []q;
			q = newq;
			front = 0;
			back = newback;
			capacity = capacity<<1;
		} 

		q[back] = x;
		back = ++back & (capacity-1);
	}
	bool dequeue(uint64_t& x) {
		if (isEmpty()) {
			return false;
		}
		x = q[front];
		front = ++front & (capacity-1);
		return true;
	}
	void print() {
		for (int i=front; i!=back; i=++i&(capacity-1)) {
			printf("%c\t", q[i]+'A');
		}
		printf("\n");
	}
public:
	uint64_t front;
	uint64_t back;
	uint64_t capacity;
	uint64_t *q;
};

#endif
