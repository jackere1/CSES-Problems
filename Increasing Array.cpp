#include <stdio.h>
#include <stdlib.h>
/* TIME COMPLEXITY:
	LINEAR: O(log(n))*/
	
int main() {
	long long *a, steps;
	int n, i;
	scanf("%d", &n);
	a = (long long *)malloc(sizeof(long long) * n);
	for(i = 0; i < n; i++) 
		scanf("%lld", &a[i]);
	
	for(i = 0, steps = 0; i < n; i++) {
		if(i == 0)
			continue;
		if(a[i - 1] > a[i]) {
			steps += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	free(a);
	printf("%lld", steps);
	return 0;
}