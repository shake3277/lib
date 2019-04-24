#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
const ll N = 1e6;

//a^(p-2)=a^(-1) (mod p)
//(x^n)%mod
ll mod_pow(ll x,ll n,ll mod){
  if(n==0)return 1;
  ll res=mod_pow( x*x%mod , n/2 , mod );
  if( n & 1 )res = res*x%mod;
  return res;
}

ll fact[N];
ll infact[N];

void make_factorial(void){
  fact[0] = 1;
  for( ll i = 1 ; i < N ; i++ ){
    fact[i] = fact[i-1] * i;
    fact[i] %= MOD;
  }
  for( ll i = 0 ; i < N ; i++ ){
    infact[i] = mod_pow( fact[i] , MOD-2 , MOD );
  }
}

ll comb(ll a,ll b){
  if(a == 0 && b == 0)return 1;
  if(a < b || a < 0)return 0;
  ll tmp = infact[a-b]* infact[b] % MOD;
  return tmp * fact[a] % MOD; 
}

ll perm(ll a,ll b){
  if(a == 0 && b == 0)return 1;
  if(a < b || a < 0)return 0;
  return fact[a] * infact[a-b] % MOD;
}

