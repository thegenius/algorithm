#include <stdio.h>
#include <stdint.h>

uint32_t count1(uint32_t x) {
	int num = 0;
	while (x) {
		x = x&(x-1);
		++num;
	}
	return num;
}

uint32_t count2(uint32_t x) {
	uint32_t t[5] = {
		0x55555555,
		0x33333333,
		0x0f0f0f0f,
		0x00ff00ff,
		0x0000ffff };
	for (int i=0; i<5; ++i) {
		int n = 1<<i;
		int low = x & t[i];
		int high = (x>>n) & t[i];
		x = low + high;
	}
	return x;
}

// oct 010101010101 equals to 0x55555555
uint32_t count3(uint32_t x) {
	uint32_t tmp;
	tmp = (x      & 010101010101) +
		  ((x>>1) & 010101010101) +
		  ((x>>2) & 010101010101) +
		  ((x>>3) & 010101010101) +
		  ((x>>4) & 010101010101) +
		  ((x>>5) & 010101010101);
	return tmp%63;
}

uint32_t count4(uint32_t x) {
	uint32_t tmp;
	tmp = x                       -
		  ((x>>1) & 033333333333) -
		  ((x>>2) & 011111111111);
	tmp = (tmp+(tmp>>3)) & 030707070707;
	return tmp%63;
}

inline uint32_t count(uint32_t x) {
	return count4(x);
}


int main() {
	bool isWrong = 0;
	for (int i=0; i<10000; ++i) {
		if (count1(i) == count2(i) &&
			count2(i) == count3(i) &&
			count3(i) == count4(i)) {
		} else {
			isWrong = 1;
		}
	}
	if (isWrong) {
		printf("wrong****\n");
	} else {
		printf("right!\n");
	}
	return 0;
}







