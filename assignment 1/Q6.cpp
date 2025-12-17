#include<stdio.h>
void swap(int *a,int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;

}
int main()
{
	int a,b;
	printf("Enter 1st number:");
	scanf("%d",&a);
	printf("Enter 2nd number:");
	scanf("%d",&b);
	printf("Numbers before swapping: a=%d,b=%d\n",a,b);
	swap(&a, &b);
	printf("Numbers after swapping: a=%d,b=%d\n",a,b);
	return 0;
}
