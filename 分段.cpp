#include<stdio.h>
#define MAXN 10000
int A[MAXN];
int left[MAXN];
int right[MAXN];

int main()
{
	int l,r,i;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	for(l=r=0,i=1;i<n;i++)
	{
		if(A[i]<A[0]){
			left[l]=A[i];
			l++;
		}
		else{
			right[r]=A[i];
			r++;
		}
	}
	A[l]=A[0];
	for(i=0;i<l;i++)
	A[i]=left[i];
	for(i=l+1;i<n+1;i++)
	A[i]=right[i-l-1];
	for(i=0;i<n;i++)printf("%d ",A[i]);
}
