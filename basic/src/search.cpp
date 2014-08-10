

#include <stdio.h>
#include <stdint.h>
//[)
template <typename T>
T* lower_bound_1 (T* first, T* last, const T& value) {
	uint64_t len = last - first;
	if (len <= 0) {
		return first;
	}

	uint64_t half = len>>1;
	T* cut = first + half;
	if (*cut < value) {
		return lower_bound_1 (cut+1, last, value);
	} else {
		return lower_bound_1 (first, cut,  value);
	}
}

template <typename T>
T* lower_bound_2 (T* first, T* last, const T& value) {
	uint64_t len = last - first;
	while (len > 0) {
		uint64_t half = len >> 1;
		T* cut = first + half;
		if (*cut < value) {
			first = cut + 1;
			len = len - half - 1;
		} else {
			len = half;
		}
	}
	return first;
}

template <typename T>
T* lower_bound_3 (T* first, T* last, const T& value) {
	while (first < last) {
		uint64_t half = (last-first)>>1;
		T* cut = first + half;
		if (*cut < value) {
			first = cut + 1;
		} else {
			last = cut;
		} 
	}
	return first;
}

/*******************************************************
*                    *
*******************************************************/
template <typename T>
inline uint64_t distance(T* ptr1, T* ptr2) {
	return ptr2 - ptr1;
}

template <typename T>
inline T* advance (T* ptr, uint64_t step) {
	return ptr + step;
}

template <typename T>
T* lower_bound (T* first, T* last, const T& value) {
	while (first < last) {
		uint64_t half = distance(first,last)>>1;
		T* cut = advance(first, half);
		if (*cut < value) {
			first = advance(cut, 1);
		} else {
			last = cut;
		} 
	}
	return first;
}



int main() {
	int arr[2] = { 1, 25 };
	printf("%d\n", *lower_bound(arr, arr+2, 2));
	return 0;
}













