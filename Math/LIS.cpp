#include<bits/stdc++.h>
using namespace std;
#define MAX_N 111111

struct LIS{
  int n;
  vector<int> a,dp;
  LIS(){}
  LIS(int _n,vector<int> _a):n(_n),a(_a),dp(_n,INT_MAX){}

  int res(){
    dp[0]=a[0];
    int ans=1;
    for(int i=1;i<n;i++){
      if(dp[ans-1]<a[i])dp[ans++]=a[i];
      else *lower_bound(dp.begin(),dp.begin()+ans,a[i])=a[i];
    }
    return ans;
  }
};

int main(){
  int n;
  cin>>n;
  vector<int> a(n);  
  for(int i=0;i<n;i++)cin>>a[i];
  LIS lis(n,a);
  cout<<lis.res()<<endl;
  return 0;
}
