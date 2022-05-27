#include <stdio.h>
#include <stdlib.h>
#define CUTOFF 10

/*TIME ANALYSIS:
	CAN BE BRUTE FORCED: O(n^2)
	SORT: MERGESORT(Optimized) -> O(log(n))
	FILTER: LINEAR -> O(n)
	TOTAL: O(log(n))*/

void insertion_sort(long long *, int, int);
void merge(long long *, long long *, int, int, int);
void sort(long long *, long long *, int, int);

int main() {
	int n, count, i, j, booler;
	scanf("%d", &n);
	long long *a, *aux;
	a = (long long *)malloc(sizeof(long long) * n);
	aux = (long long *)malloc(sizeof(long long) * n);
	
	for(i = 0; i < n; i++)
		scanf("%lld", &a[i]);
		
	sort(a, aux, 0, n - 1);
	
	for(i = 0, count = 0; i < n; i++) {
		if(i == 0) {
			count++;
			continue;
		}
		if(a[i] != a[i - 1]) {
			count++;
		}
	}
	printf("%d", count);
	free(a);
	free(aux);
	return 0;
}

void insertion_sort(long long a[], int lo, int hi) {
	int tmp;
	int i, j;
	for(i = lo; i <= hi; i++) {
		for(j = i; j > lo && a[j - 1] > a[j]; j--) {
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
		}
	}
}

void merge(long long a[], long long aux[], int lo, int mid, int hi) {
	for(int k = lo; k <= hi; k++)
		aux[k] = a[k];
		
	int i = lo, j = mid + 1;
	for(int k = lo; k <= hi; k++) {
		if(i > mid)
			a[k] = aux[j++];
		else if(j > hi)
			a[k] = aux[i++];
		else if(aux[j] < aux[i])
			a[k] = aux[j++];
		else
			a[k] = aux[i++];
	}
}

void sort(long long a[], long long aux[], int lo, int hi) {
	int mid = lo + (hi - lo) / 2;
	if(hi - lo <= CUTOFF) {
		insertion_sort(a, lo, hi);
		return;
	}
	sort(a, aux, lo, mid);
	sort(a, aux, mid + 1, hi);
	merge(a, aux, lo, mid, hi);
}


