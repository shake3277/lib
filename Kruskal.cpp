#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define MAX_E 100000

int par[MAX_N]; //親
int rank[MAX_N]; //木の深さ

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
}

int find(int x){
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(rank[x]<rank[y])par[x]=y;
  else {
    par[y]=x;
    if(rank[x]==rank[y])rank[x]++;

  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

//ここからクラスカル法
struct edge{int u,v,cost;};

bool comp(const edge& e1,const edge e2){
  return e1.cost < e2.cost;
}

edge es[MAX_E];
int V,E; //頂点数、辺数

int kruskal(){
  sort(es,es+E,comp);
  init(V);
  int res=0;
  for(int i=0;i<E;i++){
    edge e=es[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res+=e.cost;
    }
  }
  return res;
}
