#include<cstdio>
#include<algorithm>

using namespace std;
#define MAXN 50
char first_order[MAXN]="DBACEGF";
char middle_order[MAXN]="ABCDEFG";
char last_order[MAXN];

class node{
	public:
		node *left,*right;
		char ch;
		node()
		{
			this->left=NULL;
			this->right=NULL;
		}
}*root;

void build(node* &root,int fl,int fr,int ml,int mr)
{
	int div_pos,left_length,right_length;
	char div_ch=first_order[fl];
	if(div_ch==0)return;
	root=new node();
	root->ch=div_ch;
	for(div_pos=ml;div_pos<=mr;div_pos++)
	{
		if(middle_order[div_pos]==div_ch)break;
	}
	if((left_length=div_pos-ml)>0)
	{
	build(root->left,fl+1,fl+left_length,ml,div_pos-1);
	}
	if((right_length=mr-div_pos)>0)
	{
	build(root->right,fr-right_length+1,fr,div_pos+1,mr);
	}
}
void last_order_print(node *root)
{
	if(root==NULL)return;
	last_order_print(root->right);
	last_order_print(root->left);
	printf("%c",root->ch);
}
int get_height(node *root)
{
	if(root==NULL)return 0;
	return max(get_height(root->left)+1,get_height(root->right));
}

int sum(node *root)
{
	int s=0;
	if(root->left!=NULL)s++;
	node *p;
	for(p=root;p!=NULL;p=p->right)
	{
		s++;
	}
	return s;
}

int main()
{
	root=new node();
	build(root,0,MAXN-1,0,MAXN-1);
	last_order_print(root);
	printf("\n%d\n",get_height(root));
	printf("%d",sum(root));
}
