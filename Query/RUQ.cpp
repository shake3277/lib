#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1<<17
int n,dat[2*(MAX_N)-1];
int valu[2*(MAX_N)-1];//更新順

//INT＿MAXで初期化
void init(int n_){
  n=1;
  while(n<n_)n*=2;
  for(int i=0;i<2*n-1;i++){
    dat[i]=INT_MAX;
    valu[i]=-1;
  }
}

//k番目の要素を返す
int find(int k){
  k+=n-1;
  int ans=dat[k];
  int va=valu[k];
  while(k>0){
    k=(k-1)/2;
    if(valu[k]>va){
      ans=dat[k];
      va=valu[k];
    }
  }
  return ans;
}

//[a,b)の範囲を更新
void update(int a,int b,int x,int i,int k=0,int l=0,int r=n){
  if(r<=a||b<=l)return; 
  if(a<=l&&r<=b){
    valu[k]=i;
    dat[k]=x;
  }else{
    update(a,b,x,i,k*2+1,l,(l+r)/2);
    update(a,b,x,i,k*2+2,(l+r)/2,r); 
  }
}

int main(){
  int q;
  cin>>n>>q;
  init(n);
  for(int i=0;i<q;i++){
    int com,s,t,x;
    cin>>com; //com=1でfind,elseでupdate
    if(com){
      cin>>s;
      cout<<find(s)<<endl;
    }else{
      cin>>s>>t>>x;
      update(s,t+1,x,i);//[s,t)をxに書き換える iは更新時間
    }
  }
  return 0;
}
