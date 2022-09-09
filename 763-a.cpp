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
  int N;
  cin >> N;
  string S;
  cin >> S;
  for(int i = 0; i < N - 1; i++) {
    if(S[i] != S[i + 1]) {
      cout << i + 1 << ' ' << i + 2 << '\n';
      return;
    }
  }
  cout << -1 << ' ' << -1 << '\n';
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
