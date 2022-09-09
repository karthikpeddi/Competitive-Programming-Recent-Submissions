#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <functional>
#include <array>
#include <climits>
//#include "debug.h"
using namespace std;
 
#define A first
#define B second
 
typedef long long ll;
constexpr int MOD = 1e9 + 7;
 
bool cmp(pair<int, int>& x, pair<int, int>& y) {
  if(x.B < y.B) return true;
  else if(x.B == y.B && (x.A < y.A)) return true;
  return false;
}
 
void solve(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> X(N), Y(M);
  set<int> XP, YP;
  for(int i = 0; i < N; i++) {
    cin >> X[i];
    XP.insert(X[i]);
  }
  for(int i = 0; i < M; i++) {
    cin >> Y[i];
    YP.insert(Y[i]);
  }
 
  vector<pair<int, int>> P(K);
  for(int i = 0; i < K; i++) {
    cin >> P[i].A >> P[i].B;
  }
  sort(P.begin(), P.end());
  map<int, map<int, int>> mp;
  map<int, int> cnt;
  for(int i = 0; i < K; i++) {
    int idx = lower_bound(X.begin(), X.end(), P[i].A) - X.begin();
    if(P[i].A == X[idx]) continue;
    idx--;
    mp[idx][P[i].B]++;
    cnt[idx]++;
  }
  ll ans1 = 0;
  for(auto x: mp) {
    map<int, int> mp2 = x.B;
    for(auto y: mp2) {
      ll rem = cnt[x.A] - y.B;
      ans1 += rem * y.B;
    }
  }
  ll ans = ans1 / 2;
 
  sort(P.begin(), P.end(), cmp);
  mp.clear();
  cnt.clear();
  for(int i = 0; i < K; i++) {
    int idx = lower_bound(Y.begin(), Y.end(), P[i].B) - Y.begin();
    if(P[i].B == Y[idx]) continue;
    idx--;
    mp[idx][P[i].A]++;
    cnt[idx]++;
  }
 
  ll ans2 = 0;
  for(auto x: mp) {
    map<int, int> mp2 = x.B;
    for(auto y: mp2) {
      ll rem = cnt[x.A] - y.B;
      ans2 += rem * y.B;
    }
  }
  ans += ans2 / 2;
  cout << ans << '\n';
  
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  T = 1;
  cin >> T;
  while(T--){
    solve();
  }
}