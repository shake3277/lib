#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define dmp(x) cerr<<#x<<":"<<x<<endl
#define FOR(i,a,b) for(int i=(int)a,c=(int)b;i<c;++i)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=b-1,c=(int)a;i>=c;--i)
#define per(i,b) ROF(i,0,b)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct MP{
  string s;
  int n;
  vector<int> v;
  MP(string ss){
    s=ss;
    n=s.size();
    v=vector<int>(n+1,-1);
    int j=-1;
    for(int i=0;i<n;i++){
	 while(j>=0&&s[i]!=s[j])j=v[j];
	 j++;
	 v[i+1]=j;
    }
  }

  int get(int i){
    return v[i+1];
  }
};

signed main(){
  string s;
  cin>>s;
  MP mp(s);
  for(int i=0;i<sz(s);i++){
    cout<<mp.get(i)<<endl;
  }
  return 0;
}
