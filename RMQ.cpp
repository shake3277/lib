#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

struct RMQ{

  static const int MAX_N = 1<<17;
  static const ll INF = (1LL<<31)-1;
  
  ll n;
  ll dat[2*(MAX_N)-1];

  RMQ(){}
  RMQ(ll n_){init(n_);}
  
  void init(ll n_){
    n=1;
    while(n<n_)n*=2;
    for(int i=0;i<2*n-1;i++)dat[i]=INF;
  }

  void update(int k,ll a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
	 k=(k-1)/2;
	 dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
  }
  
  //[a,b)
  ll query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l)return INF;
    if(a<=l&&r<=b)return dat[k];
    else{
	 ll vl=query(a,b,k*2+1,l,(l+r)/2);
	 ll vr=query(a,b,k*2+2,(l+r)/2,r);
	 return min(vl,vr);
    }
  }
  
  ll query(int a,int b){
    return query(a,b,0,0,n);
  }
};

//DLS_2_A
int main(){
  int n,q;
  cin>>n>>q;
  RMQ t(n);
  for(int i=0;i<q;i++){
    int com,x,y;
    cin>>com>>x>>y;
    if(com)cout<<t.query(x,y+1)<<endl;
    else t.update(x,y);
  }
  return 0;
}
