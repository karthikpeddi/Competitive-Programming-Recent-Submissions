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
constexpr int MOD = 998244353;
 
vector<int> fact, invFact;
 
inline int mulmd(ll a, ll b){
  ll ret = (a * b) % MOD;
  return (int) ret;
}
 
inline int power(ll x, ll y, int m){
  ll res = 1;
  x = x % m;
  while(y > 0){
    if(y & 1){
      res = mulmd(res, x);
    }
    y = y >> 1;
    x = mulmd(x, x);
  }
  return (int) res;
}
 
inline int submd(ll a, ll b){
  ll ret = (a - b);
  if(ret < 0) ret += MOD;
  return (int) ret;
}
 
inline int addmd(ll a, ll b){
  ll ret = (a + b) % MOD;
  return (int) ret;
}
 
inline int invPow(ll a){
  return power(a, MOD - 2, MOD);
}
 
inline int divmd(ll a, ll b){
  ll ret = mulmd(a, invPow(b));
  return (int) ret;
}
 
void precomputeFact(int N){
  fact.assign(N + 1, 0);
  invFact.assign(N + 1, 0);
  fact[0] = fact[1] = 1;
  for(int i = 2; i <= N; i++){
    fact[i] = mulmd(fact[i - 1], i);
  }
  invFact[N] = invPow(fact[N]);
  for(int i = N - 1; i >= 0; i--){
    invFact[i] = mulmd(invFact[i + 1], i + 1);
  }
}
 
int C(int N, int R){
  if(R > N) return 0;
  return mulmd(fact[N], mulmd(invFact[R], invFact[N - R]));
}
 
void solve(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  precomputeFact(N);
  if(A[N - 1] == A[N - 2]) {
    cout << fact[N] << '\n';
    return;
  }
  else if(A[N - 1] - A[N - 2] >= 2) {
    cout << 0 << '\n';
    return;
  }
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] == A[N - 2]) cnt++;
  }
  int ans = 0;
  int rem = N - cnt - 1;
  for(int i = N - 1; i >= cnt; i--) {
    ans = addmd(ans, mulmd(fact[i], mulmd(C(rem, N - 1 - i), fact[N - 1 - i])));
  }
  ans = submd(fact[N], ans);
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