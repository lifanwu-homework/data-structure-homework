#include<stdio.h>
#define MAXP 10000000
struct point{
	int x;
	int y;
	float info;
};

class sparse_matrix{
	public:
		sparse_matrix()
		{
			this->p_num=0;
			point p0;
			p0.x=-1;
			p0.y=-1;
			for(int i=0;i<MAXP;i++)
			{
				this->p[i]=p0;
			}
		}
		
		void double_diagonal(int length)
		{
			for(int i=0;i<length;i++)
			{
				set_info(i,i,1);
				set_info(i+1,i,1);
			}	
		}
		
		void set_info(int x,int y,float info)
		{
			this->p[p_num].x=x;
			this->p[p_num].y=y;
			this->p[p_num].info=info;
			this->p_num++;
		}
		
		void set_info(point x)
		{
			this->p[p_num]=x;
			p_num++;
		}
		
		float get_info(int x,int y)
		{
			for(int i=0;i<p_num;i++)
			{
				if(p[i].x==x&&p[i].y==y)return p[i].info;
			}
			return 0;
		}
		
		void print_matrix(int maxi,int maxj)
		{
			for(int i=0;i<maxi;i++)
			{
				for(int j=0;j<maxj;j++)
				{
					if(get_info(i,j)==0)
					printf(" ");
					else printf("%1.0f",get_info(i,j));
				}
				printf("\n");
			}
		}
		
		int p_num;
		point p[MAXP];
}m;


int main()
{
	
	m.double_diagonal(10);
	m.print_matrix(10,10);
} 
