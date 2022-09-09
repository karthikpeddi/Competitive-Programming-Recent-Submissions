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
  string S;
  cin >> S;
  int ab = 0, ba = 0;
  if(S.size() == 1) {
    cout << S << '\n';
    return;
  }
  for(int i = 1; i < S.size(); i++) {
    if(S[i] == 'b' && S[i - 1] == 'a') ab++;
    else if(S[i] == 'a' && S[i - 1] == 'b') ba++;
  }
  if(ab == ba) {
    cout << S << '\n';
    return;
  } else if(ab > ba) {
    S[0] = 'b';
    cout << S << '\n';
  } else if(ab < ba) {
    S[0] = 'a';
    cout << S << '\n';
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
