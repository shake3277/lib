#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Comb{
  const int MOD = 1e9+7;
  vector<int> fact,infact;

  Comb(int N):
    fact(N+1),
    infact(N+1)
  {
    N++;
    fact[0] = 1;
    for( int i = 1 ; i < N ; i++ ){
	 fact[i] = fact[i-1] * i;
	 fact[i] %= MOD;
    }
    for( int i = 0 ; i < N ; i++ ){
	 infact[i] = mod_pow( fact[i] , MOD-2 , MOD );
    }
  }

  int mod_pow(int x,int n,int mod){
    if(n==0)return 1;
    int res=mod_pow( x*x%mod , n/2 , mod );
    if( n & 1 )res = res*x%mod;
    return res;
  }

  int comb(int a,int b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = infact[a-b]* infact[b] % MOD;
    return tmp * fact[a] % MOD; 
  }

  int perm(int a,int b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    return fact[a] * infact[a-b] % MOD;
  }
};
