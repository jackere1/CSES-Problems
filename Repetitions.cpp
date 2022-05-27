#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
//ACGT
int main() {
	int i = -1, n = 1000000, max = 0, count = 0;
	char *a = (char *)malloc(sizeof(char) * n);
	
	while(i < n && a[i] != '\n') {
		i++;
		scanf("%c", &a[i]);
		if(a[i] == a[i - 1]) 
			count++;
		else
			count = 1;
		if(max < count)
			max = count;
		
	}
	printf("%d", max);
	free(a);
	return 0;
}