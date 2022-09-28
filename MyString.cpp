#include<stdio.h>
#define MAXLENGTH 100000
class MyString{
	public:
	char data[MAXLENGTH];
	int length;
	MyString(){}
	void init_MyString(char d[],int length)
	{
		this->length=length;
		for(int i=0;i<length;i++)
		{
			data[i]=d[i];
		}
	}
	
	void print()
	{
		for(int i=0;i<length;i++)
		printf("%c",data[i]);
		printf("\n");
	}
	
};

int getpos(MyString *S,MyString *Sub)
{
	int i,j,flag;
	for(i=0;i<S->length;i++)
	{
		flag=1;
		for(j=0;j<Sub->length;j++)
		{
			if(S->data[j+i]!=Sub->data[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)return i;
	}
	return -1;
}

void DeleteS(MyString *S,int pos,int len,MyString *Sub)
{
	Sub->length=len;
	if(pos+len>S->length)
	{
		printf("error!");
		return;
	}
	for(int i=0;i<len;i++)
	{
		Sub->data[i]=S->data[pos+i];
	}
	for(int i=pos+len;i<S->length;i++)
	{
		S->data[i-len]=S->data[i];
	}
	S->length=S->length-len;
}

void ReplaceS(MyString *S,MyString *Sub1,MyString *Sub2)
{
	int pos;
	pos=getpos(S,Sub1);
	if(pos==-1){
		printf("not found!");
		return;
	}
	if(Sub1->length>Sub2->length)
	{
		int dl=Sub1->length-Sub2->length;
		for(int i=Sub1->length+pos;i<S->length;i++)
		{
			S->data[i-dl]=S->data[i];
		}
		
	}
	else if(Sub1->length==Sub2->length)
	{
		
	}
	else if(Sub1->length<Sub2->length)
	{
		int dl=Sub2->length-Sub1->length;
		for(int i=S->length-1;i>=pos+Sub1->length;i--)
		{
			S->data[i+dl]=S->data[i];
		}
	}
	for(int i=0;i<Sub2->length;i++)
	{
		S->data[i+pos]=Sub2->data[i];
	}
	S->length+=Sub2->length-Sub1->length;
	
}

int main()
{
	MyString a,b,c;
	a.init_MyString("hello_world",11);
	b.init_MyString("_wr",3);
	c.init_MyString("hi",2);
	a.print();
	b.print();
	c.print();
	ReplaceS(&a,&b,&c);
	a.print();
	b.print();
	c.print();
	return 0;
}

