#include <stdio.h>
#include <stdint.h>
#include <vector>
using namespace std;

class Prime {
public:
	Prime() :
		bound(0),bound_prime(NULL),count(0),count_prime(NULL) {
	}

	vector<uint64_t>* getPrimeArrayByCount(uint64_t count) {
		
		return NULL;		
	}
	vector<uint64_t>* getPrimeArrayByBound(uint64_t bound) {
		if (this->bound < bound) {
			uint64_t *new_bound_prime = new uint64_t[bound];			
			for (uint64_t i=0; i<this->bound; ++i) {
				new_bound_prime[i] = bound_prime[i];
			}
			delete[] bound_prime;
			bound_prime = new_bound_prime;
		}
		printf("bound:%d this->bound:%d\n",bound,this->bound);	
		for (uint64_t i=this->bound; i<bound; ++i) {
			bound_prime[i] = 1;
		}
		bound_prime[0] = 0;
		bound_prime[1] = 0;
		for (int i=0; i<100; ++i) {
			if (bound_prime[i] == 1) {
				printf("%d\n", i);
			}
		}


		uint64_t up1 = bound>>1;	
		for (uint64_t i=2; i<up1; ++i) {
			if (bound_prime[i] == 1) {
				uint64_t up2 = 0;
				for (uint64_t j=up2; j<bound; j+=i) {
					bound_prime[j] = 0;
				}
			}
		}
		this->bound = bound;
		for (int i=0; i<100; ++i) {
			if (bound_prime[i] == 1) {
				printf("%d\n", i);
			}
		}

		vector<uint64_t> *vec_ptr = new vector<uint64_t>;
		for (uint64_t i=0; i<bound; ++i) {
			if (bound_prime[i] == 1) {
				vec_ptr->push_back(i);
			}
		}
		return vec_ptr;

	}
	uint64_t getNextPrime() {
		return 0;	
	}
	uint64_t getNextPrime(uint64_t x) {
		return 0;
	}
	bool isPrime(uint64_t x) {
		return false;
	}
private:
	uint64_t bound;
	uint64_t *bound_prime;
	uint64_t count;
	uint64_t *count_prime;
};


void genePrime(uint64_t *&prime, uint64_t n) {
	for (uint64_t i=0; i<n; ++i) {
		prime[i] = 1;
	}
	prime[0] = 0;
	prime[1] = 0;

	int up = n>>1;	
	for (uint64_t i=2; i<up; ++i) {
		if (prime[i] == 1) {
			for (uint64_t j=i+i; j<n; j+=i) {
				prime[j] = 0;
			}
		}
	}
}

int main() {
	uint64_t *p = new uint64_t[100];
	genePrime(p, 100);
	
	getchar();
	Prime prime;
	vector<uint64_t> *vec = prime.getPrimeArrayByBound(100);
	for (int i=0; i<vec->size(); ++i) {
		printf("%d\n", (*vec)[i]);
	}

	return 0;
}

