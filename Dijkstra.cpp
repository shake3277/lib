#include<bits/stdc++.h>
using namespace std;
#define MAX_V 10000000
#define INF 1111111111
struct edge{int to,cost;};
typedef pair<int ,int> P; //firstは最短距離、secondは頂点の番号

int V; //頂点数
vector<edge> G[MAX_V]; //添字がfrom
int d[MAX_V]; //最短コスト(経路が無い場合はINF)

void dijkstra(int s){
  priority_queue<P,vector<P>,greater<P> > que;
  fill(d,d+MAX_V,INF);
  d[s]=0;
  que.push(P(0,s));
  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
	d[e.to]=d[v]+e.cost;
	que.push(P(d[e.to],e.to));
      }
    }
  }
}
