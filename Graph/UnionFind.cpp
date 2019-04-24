#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
  int n;
  vector<int> p,r;
  UnionFind(){}
  UnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
  int find(int x){
    if(p[x]==x)return x;
    else return p[x]=find(p[x]);
  }
  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(r[x]<r[y])p[x]=y;
    else {
      p[y]=x;
      if(r[x]==r[y])r[x]++;
    }
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
};

int main(){
  int n,q;
  cin>>n>>q;
  UnionFind uf(n);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c)cout<<uf.same(x,y)<<endl;
    else uf.unite(x,y);
  }
  return 0;
}
