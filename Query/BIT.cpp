#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_N (1<<17)

struct BIT{
  //[1,n]
  ll bit[MAX_N+1],n;
  BIT(ll N){
	fill_n(bit,MAX_N+1,0);
	n=N;
  }
  
  //sum[1,r]
  ll sum(ll i){
	ll s=0;
	while(i>0){
	  s+=bit[i];
	  i-=i&-1;
	}
	return s;
  }

  //sum[l,r]
  ll lrsum(ll l,ll r){
	return sum(r)-sum(l-1);
  }
  
  //a_i=x
  void add(ll i,ll x){
	while(i<=n){
	  bit[i]+=x;
	  i+=i&-i;
	}
  }

};

int main(){
  ll n,q;
  cin>>n>>q;
  BIT bit(n);
  cout<<bit.n<<endl;
  for(int i=0;i<q;i++){
	ll com,x,y;
	cin>>com>>x>>y;
	if(com)cout<<bit.lrsum(x,y)<<endl;
	else bit.add(x,y);
  }
  return 0;
}
