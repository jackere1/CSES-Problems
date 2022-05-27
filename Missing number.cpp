#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, *a, *full;
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * n - 1);
	full = (int *)malloc(sizeof(int) * n + 1);
	for(int i = 1; i <= n; i++)
		full[i] = i;

	for(int i = 0; i < n - 1; i++) {
		scanf("%d", &a[i]);
		full[a[i]] = 0;
	}
	
	for(int i = 1; i <= n; i++) 
		if(full[i] != 0)
			printf("%d", full[i]);
	
	return 0;
}