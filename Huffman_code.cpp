#include<cstdio>
#include<vector>
#define MAXN 128
#define MAXLENGTH 20
using namespace std;

int frequence[MAXN];

char Huffman_code[MAXN][MAXLENGTH];

char code[MAXLENGTH];

struct node
{
	node* left, *right;
	bool in_tree;
	int weight;
	char ch;
}vector_node[MAXN*2];
int stack_top = 0;

node* root = NULL;
/*void first_order_print(node* root)
{
	if (root == NULL)return;
	printf("\n %c %d\n", root->ch, root->weight);
	first_order_print(root->right);
	first_order_print(root->left);
}*/

void fileload()
{
	char ch;
	FILE* fp;
	fp = fopen("input.txt", "rb");
	while (fscanf(fp, "%c", &ch) != EOF)frequence[ch]++;
}

void build_Huffman_tree()
{
	int min_frequence, sec_min_frequence,min_node, sec_min_node;
	node temp;
	temp.left = NULL;
	temp.right = NULL;
	temp.in_tree= false;
	for (int i = 0; i < MAXN; i++)
	{
		if (frequence[i] != 0)
		{
			temp.ch = i;
			temp.weight = frequence[i];
			vector_node[stack_top]=temp;
			stack_top++;
		}
	}
	while (1)
	{
		min_node = -1;
		sec_min_node = -1;
		min_frequence = 0xfffffff;
		sec_min_frequence= 0xfffffff;
		for (int i=0; i<stack_top; i++)
		{
			if (vector_node[i].in_tree)continue;
			if (vector_node[i].weight < min_frequence)
			{
				min_frequence = vector_node[i].weight;
				min_node = i;
			}
			else if (vector_node[i].weight < sec_min_frequence)
			{
				sec_min_frequence = vector_node[i].weight;
				sec_min_node = i;
			}
		}
		
		if (min_node == -1 || sec_min_node == -1)break;
		temp.left = (node*)&(vector_node[min_node]);
		temp.right = (node*)&(vector_node[sec_min_node]);
		
		temp.weight = vector_node[min_node].weight + vector_node[sec_min_node].weight;
		temp.ch = 0;
		temp.in_tree = false;
		vector_node[min_node].in_tree = true;
		vector_node[sec_min_node].in_tree = true;
		vector_node[stack_top] = temp;
		stack_top++;
	}
	for (int i = 0; i < stack_top; i++)
	{
		if (vector_node[i].in_tree == false) {
			root = &vector_node[i];
			break;
		}
	}
	//first_order_print(root);
}

void first_order(node* root,int height)
{
	if (root->left == NULL && root->right == NULL)
	{
		char ch = root->ch;
		for(int i=0;i<MAXLENGTH;i++)
		Huffman_code[ch][i] = code[i];
		return;
	}
	code[height] = '0';
	first_order(root->left, height + 1);
	code[height] = '1';
	first_order(root->right, height + 1);
	code[height] = 0;
	return;
}

void print_Haffman_code()
{
	for (int i = 0; i < MAXN; i++)
	{
		if (Huffman_code[i][0])
		{
			printf("%c : ", i);
			for (int j = 0; j < MAXLENGTH && Huffman_code[i][j]; j++)
			{
				printf("%c ", Huffman_code[i][j]);
			}
			printf("\n");
		}
	}
}

int main()
{
	fileload();
	build_Huffman_tree();
	first_order(root, 0);
	print_Haffman_code();
	
}