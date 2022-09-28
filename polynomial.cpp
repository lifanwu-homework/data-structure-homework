#include<cstdio>
using namespace std;

struct term{
	int power;
	float coefficient;
};

struct node{
	term T;
	node *next=NULL;
};

class polynomial{
	public:
		node *root;
		polynomial()
		{
			root=NULL;
		}
		
		void init_polynomial()
		{
			int m=0,n=0;
			
			node *p;
			printf("请输入多项式的系数与幂\n");
			if(scanf("%d%d",&m,&n)==2)
			root=new node();
			else {
				root=NULL;
				return;
			}
			for(p=root;;p=p->next)
			{
				p->T.coefficient=m;
				p->T.power=n;
				if(scanf("%d%d",&m,&n)==2)
				p->next=new node();
				else{
					p->next=NULL;
					return;
				}
			}
		}
		
		void print()
		{
			node *p;
			for(p=this->root;p;p=p->next)
			{
				printf("%f*x^%d",p->T.coefficient,p->T.power);
				if(p->next==NULL){
					printf("\n");
					break;
				}
				else printf("+");
			}
		}
		
		node* findpower(int power)
		{
			node *p;
			for(p=root;p;p=p->next)
			{
				if(p->T.power==power)
				return p;
			}
			return NULL;
		}
		
		void add(polynomial &poly2)
		{
			int pos;
			node *p,*q;
			for(p=poly2.root;p;p=p->next)
			{
				q=findpower(p->T.power);
				if(q==NULL)
				{
					q=root;
					root=new node();
					root->next=q;
					root->T.coefficient=p->T.coefficient;
					root->T.power=p->T.power;
				}
				else
				{
					q->T.coefficient+=p->T.coefficient;
				}
			}
		}
};


int main()
{
	polynomial p,q;
	p.init_polynomial();
	printf("第一个多项式:\n");
	p.print();
	q.init_polynomial();
	printf("第二个多项式:\n");
	q.print();
	p.add(q);
	printf("相加后的多项式:\n");
	p.print();
}

