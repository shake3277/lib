#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1<<17
int n,dat[2*(MAX_N)-1];
//数列番号は0-index

//0で初期化
void init(int n_){
  n=1;
  while(n<n_)n*=2;
  for(int i=0;i<2*n-1;i++)dat[i]=0;
}

//k番目の要素の値を返す
int find(int k){
  k+=n-1;
  int ans=dat[k];
  while(k>0){
    k=(k-1)/2;
    ans+=dat[k];
  }
  return ans;
}

//[a,b)の最小値を求める
void update(int a,int b,int x,int k=0,int l=0,int r=n){
  if(r<=a||b<=l)return;
  if(a<=l&&r<=b){
    dat[k]+=x;
  }else{
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
  }
}

int main(){
  int q;
  cin>>n>>q;
  init(n);
  for(int i=0;i<q;i++){
    int com,s,t,x;
    cin>>com;
    if(com){
      cin>>t;
      cout<<find(t)<<endl;
    }else{
      cin>>s>>t>>x;
      update(s,t+1,x);//[s,t)にxを加算
    }
  }
  return 0;
}
