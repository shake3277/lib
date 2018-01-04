#include<bits/stdc++.h>
using namespace std;
#define MAX_V 10000
int d[MAX_V][MAX_V]; //d[u][v]はe=(u,v)のコスト(存在しなければINF、d[i][i]は0)
int V; //頂点数

void warshall_floyd(){
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
