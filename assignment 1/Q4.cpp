#include<stdio.h>
int count(int num)
{
	int count =0;
	while(num>0)
   	{
   		count+=(num&1);
   		num>>=1;
	}
	return count;
}
int parity(int num)
  {
	int m;
	if(count(num)%2!=0)
	{
		printf("\nGive byte has odd parity.");
		num |=0x80;
	}
	else
	{
	printf("\nGive byte has even parity");
 }
   return num;

    }
int main()
  {
	int num,m;

 	printf("Enter decimal num:");
	scanf("%d",&num);
   
    printf("Total no of 1's:%d",count(num));
    printf("\nFinal decimal num:%d",parity(num));

	return 0;
  }
