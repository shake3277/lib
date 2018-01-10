#include<bits/stdc++.h>
using namespace std;
#define MAX_V 100000
int V; 
vector<int> G[MAX_V];  //グラフの隣接リスト
vector<int> rG[MAX_V]; //逆に辺を貼ったグラフの隣接リスト
vector<int> vs;        //帰り掛け順の並び
bool used[MAX_V];      //すでに調べたか
int cmp[MAX_V];        //属する強連結成分のトポロジカル順序

void add_edge(int from,int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v]=true;
  for(int i=0;i<G[v].size();i++)
    if(!used[G[v][i]])dfs(G[v][i]);
  vs.push_back(v); //探索終了したものから追加
}

void rdfs(int v,int k){
  used[v]=true;
  cmp[v]=k;
  for(int i=0;i<rG[v].size();i++)
    if(!used[rG[v][i]])rdfs(rG[v][i],k);
}

int scc(){
  memset(used,0,sizeof(used));
  vs.clear();
  for(int v=0;v<V;v++)
    if(!used[v])dfs(v);

  memset(used,0,sizeof(used));
  int k=0;
  for(int i=vs.size()-1;i>=0;i--)
    if(!used[vs[i]])rdfs(vs[i],k++);

  return k;
}
