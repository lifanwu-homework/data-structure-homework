#include<cstdio>

#define LENGTH 100

char equal[LENGTH][LENGTH];
int length_1,length_2;
void init_equal(char *s1,char *s2)
{
	int i,j;
	for(i=0;s1[i];i++)
	for(j=0;s2[j];j++)
	if(s1[i]==s2[j])equal[i][j]=1;
	else equal[i][j]=0;
	length_1=i;
	length_2=j;
}

int max_substring()
{
	int max_length=0,max_x,max_y,length;
	for(int i=0;i<length_1+1;i++)
	{
		length=0;
		for(int j=0;j<length_2+1;j++)
		if(equal[i+j][j])length++;
		else{
			if(length>max_length){
				max_x=i+j;
				max_y=j;
				max_length=length;
			}
			length=0;
		}
	}
	for(int i=0;i<length_2+1;i++)
	{
		length=0;
		for(int j=0;j<length_1+1;j++)
		if(equal[j][i+j])length++;
		else{
			if(length>max_length){
				max_x=j;
				max_y=i+j;
				max_length=length;
			}
			length=0;
		}
	}
	return max_length;
}

int main()
{
	char s1[LENGTH],s2[LENGTH];
	scanf("%s",s1);
	scanf("%s",s2);
	init_equal(s1,s2); 
	/*for(int i=0;i<length_1;i++)
	{
		for(int j=0;j<length_2;j++)
		printf("%d",equal[i][j]);
		printf("\n");
	}*/
	printf("%d",max_substring());
}

