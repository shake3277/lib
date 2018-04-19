#include<bits/stdc++.h>
using namespace std;
#define N 100001
#define LOG_MAX 30
int n,q;
vector<int> g[N];
int root;
int par[N][LOG_MAX];
int depth[N];

void dfs(int x,int d){
  depth[x]=d;
  for(int i=0;i<g[x].size();i++){
    par[g[x][i]][0]=x;
    dfs(g[x][i],d+1);
  }
}

int KthAns(int u,int k){
  for(int i=0;i<LOG_MAX;i++){
    if(u==-1)return -1;
    if(k>>i&1)u=par[u][i];
  }
  return u;
}

void build(){
  dfs(root,0);
  par[root][0]=-1;
  for(int i=1;i<LOG_MAX;i++)
    for(int j=0;j<n;j++){
      if(par[j][i-1]==-1)par[j][i]=-1;
      else par[j][i]=par[par[j][i-1]][i-1];
    }
}

int lca(int u,int v){
  if(depth[u]>depth[v])swap(u,v);
  v=KthAns(v,depth[v]-depth[u]);
  if(u==v)return u;
  for(int i=LOG_MAX-1;i>=0;i--){
    int up=par[u][i];
    int vp=par[v][i];
    if(up==vp)continue;
    u=up,v=vp;
  }
  return par[u][0];
}

int main(){
  root=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int k,c;
    cin>>k;
    for(int j=0;j<k;j++){
      cin>>c;
      g[i].push_back(c);
    }
  }
  build();
  cin>>q;
  for(int i=0;i<q;i++){
    int u,v;
    cin>>u>>v;
    cout<<lca(u,v)<<endl;
  }
  return 0;
}
