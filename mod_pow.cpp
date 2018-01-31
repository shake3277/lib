#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//a^(p-2)=a^(-1) (mod p)
//(x^n)%mod
ll mod_pow(ll x,ll n,ll mod){
  if(n==0)return 1;
  ll res=mod_pow(x*x%mod,n/2,mod);
  if(n&1)res=res*x%mod;
  return res;
}
