#include<stdio.h>

int A[]={1,32,32,24,66,23,3};

void reverse(int A[],int n)
{
	int *p=A,*q=A+n-1,temp;
	while(p<q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
}

int main()
{
	reverse(A,7);
	for(int i=0;i<8;i++)
	{
		printf("%d ",A[i]);
	}
}
