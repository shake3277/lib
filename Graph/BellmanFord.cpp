#include<bits/stdc++.h>
using namespace std;
#define MAX_V 10000000
#define MAX_E 10000000
#define INF 1111111111
struct edge{int from,to,cost;};

edge es[MAX_E]; //辺
int d[MAX_V]; //最短距離
int V,E; //頂点数、辺数

//最短距離を求める+sから負の閉路に到達するか?
int shortest_path(int s){
  fill(d,d+V,INF);
  d[s]=0;
  int cnt=0;
  while(1){
    bool update=false;
    for(int i=0;i<E;i++){
      edge e=es[i];
      if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
	d[e.to]=d[e.from]+e.cost;
	update=true;
      }
    }
    if(!update)break;
    cnt++;
    if(cnt==V)return 0;//負の閉路に到達する
  }
  return 1;//負の閉路に到達しない
}

//閉路があるか?
bool find_negative_loop(){
  memset(d,0,sizeof(d));
  for(int i=0;i<V;i++){
    for(int j=0;j<E;j++){
      edge e=es[j];
      if(d[e.to]>d[e.from]+e.cost){
	d[e.to]=d[e.from]+e.cost;
	if(i==V-1)return true;
      }
    }
  }  
  return false;
}
