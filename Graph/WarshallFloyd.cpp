#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
#define int long long
#define MOD 1e9+7
typedef pair<int,int> P;
typedef pair<int,P> PP;

struct WF{
  int v;
  vector<vector<int> > d;
  const int INF = 1LL<<60; 
  WF(int n):
    v(n),
    d(n,vector<int>(n))
  {
    for(int i=0;i<v;i++){
	 for(int j=0;j<v;j++){
	   if(i==j)d[i][j]=0;
	   else d[i][j]=INF;
	 }
    }
  }

  void add(int s,int t,int cost){
    d[s][t]=min(d[s][t],cost);
  }

  void wf(){
    for(int k=0;k<v;k++){
	 for(int i=0;i<v;i++){
	   for(int j=0;j<v;j++){
		if(d[i][k]!=INF&&d[k][j]!=INF)
		  d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	   }
	 }
    }
  }

  int get(int i,int j){
    return d[i][j];
  }
};

//AOJ2200
signed main(){
  int n,m;
  const int INF=1LL<<60;
  while(1){
    cin>>n>>m;
    if(n+m==0)break;
    WF land(n),sea(n);
    for(int i=0;i<m;i++){
	 int x,y,t;
	 char s;
	 cin>>x>>y>>t>>s;
	 x--,y--;
	 if(s=='L'){
	   land.add(x,y,t);
	   land.add(y,x,t);
	 }else{
	   sea.add(x,y,t);
	   sea.add(y,x,t);
	 }
    }
    land.wf();
    sea.wf();
  
    int r;
    cin>>r;
    vector<int> z(r);
    for(int i=0;i<r;i++){
	 cin>>z[i];
	 z[i]--;
    }

    vector<vector<int> > dp(r,vector<int>(n,INF));
    dp[0][z[0]]=0;
    for(int i=0;i<r-1;i++){
	 for(int j=0;j<n;j++){
	   if(dp[i][j]==INF)continue;
	   dp[i+1][j]=min(dp[i+1][j],dp[i][j]+land.get(z[i],z[i+1]));
	   for(int k=0;k<n;k++){
		int cost=land.get(z[i],j)+sea.get(j,k)+land.get(k,z[i+1]);
		dp[i+1][k]=min(dp[i+1][k],dp[i][j]+cost);
	   }
	 }
    }

    int mi=INF;
    for(int i=0;i<n;i++){
	 mi=min(mi,dp[r-1][i]);
    }
    cout<<mi<<endl;
  }
  return 0;
}
