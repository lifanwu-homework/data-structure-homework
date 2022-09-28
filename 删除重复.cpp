#include<stdio.h>
#define N 8
int a[N]={1,3,4,1,2,5,4,4};
int b[N]={0};
int c[N]={0};
int main()
{
	int i,j,k;
	for(i=0;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])b[i]++;
		}
	}
	j=0;
	for(i=0;i<N;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		
		if(b[i]>1);
		else{
			c[k]=a[i];
			k++;
		}
		
	}
	//for(;j<N;j++)b[j]=0;
	for(i=0;i<N;i++)
	{
		printf("%d ",c[i]);
	}
}

