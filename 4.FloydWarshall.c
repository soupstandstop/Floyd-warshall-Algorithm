#include<stdio.h>
#include<stdlib.h>

#define node_range 51  
#define edge_range 201 

int node_num=0,edge_num=0;  
int distance[node_range][node_range]; 
void FloydWarshall();  

int main()
{
	scanf("%d%d",&node_num,&edge_num);

	for(int i=1;i<=node_num;i++)
	{
		for(int j=1;j<=node_num;j++)  
		{
			if(i==j)
				distance[i][j]=0;
			else
			    distance[i][j]=10000;
		}
	}

	for(int i=1;i<=edge_num;i++) 
	{
		int s=0,k=0,w=0;
		scanf("%d%d%d",&s,&k,&w);
		distance[s][k]=w;
	}

	FloydWarshall(); 

	printf("\n");
	for(int i=1;i<=node_num;i++)  
	{
		for(int j=1;j<=node_num;j++)
		{
			if(distance[i][j]==10000)  
				printf("N ");
			else
			    printf("%d ",distance[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

void FloydWarshall()
{
	for(int k=1;k<=node_num;k++) 
	{
		for(int i=1;i<=node_num;i++)  
		{
			for(int j=1;j<=node_num;j++)
			{
				if(distance[i][j]>distance[i][k]+distance[k][j])  
					distance[i][j]=distance[i][k]+distance[k][j];
			}
		}
	}
}
