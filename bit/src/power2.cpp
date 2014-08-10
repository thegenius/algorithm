#include <stdio.h>
#include <stdint.h>

bool isPowerOf2( uint64_t x) {
	return x==0 ? false : !(x&(x-1));
}


uint8_t next_power2( uint8_t x) {
	--x;
	x = x | (x>>1);
	x = x | (x>>2);
	x = x | (x>>4);
	++x;
	return x;
}

uint16_t next_power2( uint16_t x) {
	--x;
	x = x | (x>>1);
	x = x | (x>>2);
	x = x | (x>>4);
	x = x | (x>>8);
	++x;
	return x;
}

uint32_t next_power2( uint32_t x) {
	--x;
	x = x | (x>>1);
	x = x | (x>>2);
	x = x | (x>>4);
	x = x | (x>>8);
	x = x | (x>>16);
	++x;
	return x;
}

uint64_t next_power2( uint64_t x) {
	--x;
	x = x | (x>>1);
	x = x | (x>>2);
	x = x | (x>>4);
	x = x | (x>>8);
	x = x | (x>>16);
	x = x | (x>>32);
	++x;
	return x;
}

int main() {
	for (uint32_t i=0; i<100; ++i) {
		printf("%d's next power of 2 is %d\n",i,next_power2(i));
	}
	return 0;
}

