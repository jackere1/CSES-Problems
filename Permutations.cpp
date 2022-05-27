#include <stdio.h>
#include <stdlib.h>

/*TIME COMPLEXITY:
	EVEN: LINEAR -> O(n)
	ODD: LINEAR -> O(n)
	TOTAL: O(n)*/
	
int main() {
	int n;
	scanf("%d", &n);
	if(1 < n && n < 4)
		printf("NO SOLUTION");
	else {
		for(int i = 2; i <= n; i += 2) {
			printf("%d ", i);
		}
		for(int i = 1; i <= n; i += 2) {
			printf("%d ", i);
		}
	}
	return 0;
}