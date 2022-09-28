#include<cstdio>
class node{
	public:
	int num;
	node *next;
}*root;

void create_circle(int n)
{
	int i;
	root=new node();
	node *p=root;
	for(i=0;i<n-1;i++)
	{
		p->num=i;
		p->next=new node();
		p=p->next;
	}
	p->num=i;
	p->next=root;
}
void print_circle()
{
	node *p;
	printf("%d ",root->num);
	for(p=root->next;p!=root;p=p->next)
	{
		printf("%d ",p->num);
	}
	printf("\n");
}
void delete_node(int a)
{
	node *p,*q;
	for(p=root;p->next!=p;)
	{
		print_circle();
		for(int j=0;j<a;j++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		if(q==root)root=p;
		delete q;
	}
}

void Josephson(int m,int n)
{
	create_circle(m);
	delete_node(n);
	print_circle();
}
int main()
{
	int m,n;
	printf("请输入约瑟夫环的长度和删除间隔:\n");
	scanf("%d%d",&m,&n);
	Josephson(m,n);
}
