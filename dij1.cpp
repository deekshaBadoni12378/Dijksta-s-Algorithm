#include<iostream>
#include <conio.h>
#include<limits.h>
using namespace std;
int minDist(int dist[], bool sptset[])
{
	int min= INT_MAX,idx;

	for(int i=0;i<6;i++)
	{
		if(sptset[i]==false && dist[i]<=min)
		{
			min=dist[i];
			idx=i;
		}
	}
	return idx;
}

void Dij(int graph[6][6],int src)
{
	int dist[6];
	bool sptset[6];

	for(int i = 0; i<6; i++)
	{
	    dist[i] = INT_MAX, sptset[i] = false;
	}

	dist[src] = 0;

	for(int i = 0; i<6; i++)
	{
		int m=minDist(dist,sptset);
		sptset[m]=true;
		for(int i = 0; i<6; i++)
		{

			if(!sptset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
				dist[i]=dist[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance"<<endl;
	for(int i = 0; i<6; i++)
	{
		char str=65+i;
		cout<<str<<"\t\t\t"<<dist[i]<<endl;
	}
}

int main()
{
	int graph[6][6]={
		{0, 1, 2, 1, 0, 0},
        {1, 0, 0, 4, 1, 0},
        {2, 0, 0, 5, 3, 0},
        {0, 5, 2, 3, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 1, 2, 1, 0}};
	Dij(graph,0);
	return 0;
}
