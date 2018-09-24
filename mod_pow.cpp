#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
const ll N = 1e6;

//a^(p-2)=a^(-1) (mod p)
//(x^n)%mod
ll mod_pow(ll x,ll n,ll mod){
  if(n==0)return 1;
  ll res=mod_pow(x*x%mod,n/2,mod);
  if(n&1)res=res*x%mod;
  return res;
}

ll rev[N];
ll inr[N];

void make_comb(void){
  rev[0]=1;
  for(ll i=1;i<N;i++){
    rev[i]=rev[i-1]*i;
    rev[i]%=MOD;
  }
  for(ll i=0;i<N;i++){
    inr[i]=mod_pow(rev[i],MOD-2,MOD);
  }
}

ll comb(ll a,ll b){
  if(a == 0 && b == 0)return 1;
  if(a < b || a < 0)return 0;
  ll tmp = inr[a-b]* inr[b] % MOD;
  return tmp * rev[a] % MOD; 
}

