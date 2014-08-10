#include <stdio.h>
#include <stdint.h>

template <typename T>
inline void swap(T& value1, T& value2) {
	T tmp = value1;
	value1 = value2;
	value2 = tmp;
}

template <typename T>
T* partition_1 (T* first, T* last, T pivot) {
	while (true) {
		while (*first < pivot) {
			++first;
		}
		while (pivot < *last) {
			--last;
		}
		if (!(first<last)) {
			return first;
		} else {
			swap (*first, *last);
			++first;
		}
	}
}

template <typename T>
void quick_sort_1 (T* first, T* last) {
	if (first < last) {
		T* cut = partition (first, last, *first);
		quick_sort_1 (first, cut-1);
		quick_sort_1 (cut+1, last);
	}
}


/*******************************************************
*                    *
*******************************************************/
template <typename T>
inline T* advance (T* ptr, uint64_t step) {
	return ptr + step;
}

template <typename T>
inline void increase (T*& ptr) {
	++ptr;
}

template <typename T>
inline void decrease (T*& ptr) {
	--ptr;
}

template <typename T>
T* partition (T* first, T* last, T pivot) {
	while (true) {
		while (*first < pivot) {
			increase (first);
		}
		while (pivot < *last) {
			decrease (last);
		}
		if (!(first<last)) {
			return first;
		} else {
			swap (*first, *last);
			increase (first);
		}
	}
}

template <typename T>
void quick_sort (T* first, T* last) {
	if (first < last) {
		T* cut = partition (first, last, *first);
		T* tmp1 = cut;
		T* tmp2 = cut;
		decrease (tmp1);
		increase (tmp2);
		quick_sort (first, tmp1);
		quick_sort (tmp2, last);
	}
}


int main() {
	double arr[10] = { 10.0, 1.0, 8.0, 9.0, 6.0, 7.0, 2.0, 3.0, 4.0, 5.0 };
	quick_sort(arr, arr+9);
	for (int i=0; i<10; ++i) {
		printf("%lf\n", arr[i]);
	}
	return 0;
}
