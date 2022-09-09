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
constexpr ll MOD = 1e18 + 7;
 
inline ll mulmd(ll a, ll b){
  ll ret = (a * b) % MOD;
  return ret;
}
 
inline ll power(ll x, ll y){
  ll res = 1;
  while(y > 0){
    if(y & 1){
      res = res * x;
    }
    y = y >> 1;
    x = x * x;
  }
  return res;
}
 
void solve(){
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  ll used = 0;
  for(int i = 0; i < N - 1; i++) {
    ll sum = (power(10, A[i + 1] - A[i]) - 1);
    ll diff = sum * power(10, A[i]);
    if(used + sum >= K + 1) {
      ll d = K + 1 - used;
      used += d;
      ll req = d * power(10, A[i]);
      ans += req;
    } else {
      ans += diff;
      used += sum;
    }
  }
  if(used < K + 1){
    ll d = K + 1 - used;
    ll req = d * power(10, A[N - 1]);
    ans += req;
  }
  cout << ans << '\n';
  
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  T = 1;
  cin >> T;
  while(T--) {
    solve();
  }
}
