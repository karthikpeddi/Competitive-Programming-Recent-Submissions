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
 
void solve(){
  ll N, K;
  cin >> N >> K;
  ll i = 0;
  while((1LL << i) <= K && (1LL << i) < N) {
    i++;
  }
  ll moves = i;
  ll done = 1LL << i;
  //cout << done << '\n';
  if(done >= N) {
    cout << moves << '\n';
  } else {
    ll rem = (N - done) / K + ((N - done) % K == 0 ? 0 : 1);
    cout << moves + rem << '\n';
  }
  
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
