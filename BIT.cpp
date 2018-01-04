#include<bits/stdc++.h>
using namespace std;
#define MAX_N (1<<17)
//[1,n]
int bit[MAX_N+1],n;

//sからtまでの和=(1からtまでの和)-(1からs-1までの和)

//1からiまでの和を求める
int sum(int i){
  int s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-1;
  }
  return s;
}

//iにxを加える
void add(int i,int x){
  while(i<=n){
    bit[i]+=x;
    i+=i&-i;
  }
}
