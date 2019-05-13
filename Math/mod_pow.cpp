#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
#define int long long
typedef pair<int,int> P;
typedef pair<int,P> PP;
#define MOD 1000000007

struct Comb{
  
  vector<int> fact,infact;
  int mod;
  
  Comb(int n,int m=1e9+7):
    fact(n+1),
    infact(n+1),
    mod(m)
  {
    n++;
    fact[0] = 1;
    for( int i = 1 ; i < n ; i++ ){
	 fact[i] = fact[i-1] * i;
	 fact[i] %= mod;
    }
    for( int i = 0 ; i < n ; i++ ){
	 infact[i] = mod_pow( fact[i] , mod-2 );
    }
  }

  int mod_pow(int x,int n){
    if(n==0)return 1;
    int res=mod_pow( x*x%mod , n/2 );
    if( n & 1 )res = res*x%mod;
    return res;
  }

  int comb(int a,int b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = infact[a-b]* infact[b] % mod;
    return tmp * fact[a] % mod; 
  }

  int perm(int a,int b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    return fact[a] * infact[a-b] % mod;
  }
};


// atcoder iroha2019-day2-e
signed main(){
  int n,m;
  cin>>n>>m;
  Comb c(211111);
  int sum=c.comb(n+m-2,n-1);
  int ans=0;
  for(int i=(n+1)/2;i<=n;i++){
    if(m<i)break;
    ans+=c.comb(i,n-i)*c.comb(m-1,i-1)%MOD;
    ans%=MOD;
  }
  //  dbg(ans);dbg(sum); 
  cout<<(MOD+sum-ans)%MOD<<endl;
  return 0;
}

