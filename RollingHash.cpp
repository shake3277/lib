#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;//mod2^64
ull B=100000007; //基数2

//aはbに含まれているのか？
bool contain(string a,string b){
  int al=a.size(),bl=b.size();
  if(al>bl)return false;
  
  //B^alを計算
  ull t=1;
  for(int i=0;i<al;i++)t*=B;
  
  //aとbのハッシュ値を計算
  int ah=0,bh=0;
  for(int i=0;i<al;i++)ah=ah*B+a[i];
  for(int i=0;i<al;i++)bh=bh*B+b[i];

  //bのハッシュ値をチェック
  for(int i=0;i+al<=bl;i++){
    if(ah==bh)return true;
    if(i+al<bl)bh=bh*B+b[i+al]-b[i]*t;
  }
  return false;
}

