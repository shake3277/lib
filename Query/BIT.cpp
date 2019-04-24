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

template<class T>
struct BIT{
  int n;
  vector<T> array;//1-indexed
  
  BIT(int _n):n(_n),array(_n+1,0){}

  //sum[1,r]
  T sum(int i){  
	T s=0;
	while(i>0){
	  s+=array[i];
	  i-=i&-i;
	}
	return s;
  }
  
  //sum[i,j]
  T sum(int i,int j){  
    T sum_i=sum(i-1);
    T sum_j=sum(j);
    return sum_j-sum_i;
  }
  
  void add(int i,T x){
	while(i<=n){
	  array[i]+=x;
	  i+=i&-i;
	}
  }
};

//ARC031-C
int main(){
  ll n;
  cin>>n;
  vector<ll> a(n+1);
  for(ll i=1;i<=n;i++){
    ll b;
    cin>>b;
    a[b]=i;
  }

  BIT<ll> bit(n);
  for(ll i=1;i<=n;i++){
    bit.add(i,1);
  }

  ll ans=0;
  for(ll i=1;i<=n;i++){
    ll b=a[i];
    bit.add(b,-1);
    if(b==1||b==n)continue;
    ans+=min(bit.sum(1,b),bit.sum(b,n));
  }

  cout<<ans<<endl;
  return 0;
}
