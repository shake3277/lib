#include<bits/stdc++.h>
using namespace std;

#define MAX_V 10000000
#define INF 1111111111
struct edge{int to,cost;};
typedef pair<int ,int> P; //firstは最短距離、secondは頂点の番号

int V; //頂点数
vector<edge> G[MAX_V]; //添字がfrom
int d[MAX_V]; //最短コスト

int prim(){
  priority_queue<P,vector<P>,greater<P> > que;
  fill(d,d+V,INF);
  int res=0;
  d[0]=0;
  que.push(P(0,0));
  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]!=INF)continue;
    res+=d[v]=p.first;
    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      if(d[v]==INF)que.push(P(e.cost,e.to));
    }
  }
  return res;
}
