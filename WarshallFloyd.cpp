#include<bits/stdc++.h>
using namespace std;
#define MAX_V 10000
#define INF 2000000001
int d[MAX_V][MAX_V]; //d[u][v]はe=(u,v)のコスト(存在しなければINF、u=vは0)
int V; //頂点数

void init(){
  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
      if(i==j)d[i][j]=0;
      else d[i][j]=INF;
}

void warshall_floyd(){
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++)
	if(d[i][k]!=INF&&d[k][j]!=INF)
	  d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
