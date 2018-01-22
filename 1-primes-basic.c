#include <stdio.h>
#include <stdlib.h>

int main()
{
	int start, end, i, j, flag=0;
	printf("Enter starting and end: ");
	scanf("%d%d",&start, &end);

	printf("Prime Numbers between %d and %d is :\n", start, end);
	for(i=start; i<=end; i++) {
		flag=0;
		for(j=2; j<i; j++) {
			if(i%j==0) {
				flag = 1;
				break;
			}
		}
		if(flag==0)
			printf("%d  ",i);
	}
	return 0;
}
