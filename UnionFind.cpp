#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000

int par[MAX_N]; //親
int ran[MAX_N]; //木の深さ

//初期化
void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    ran[i]=0;
  }
}

//根を求める
int find(int x){
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}

//集合を合併
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(ran[x]<ran[y])par[x]=y;
  else {
    par[y]=x;
    if(ran[x]==ran[y])ran[x]++;

  }
}

//xとyが同じ集合に属するのか?
bool same(int x,int y){
  return find(x)==find(y);
}
