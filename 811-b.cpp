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

template<typename T>
void print(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
  if (start < 0) start = 0;
  if (end < 0) end = int(v.size());
 
  for (int i = start; i < end; i++)
    cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void solve(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int cnt = 0;
  vector<int> twos;
  for(int i = 0; i < N; i++) {
    if(S[i] == '2') {
      cnt++;
      twos.push_back(i);
    }
  }
  print(twos);
  if(cnt == 1) {
    cout << "NO\n";
    return;
  }
  vector<string> ans(N);
  for(int i = 0; i < N; i++) {
    string T = "";
    for(int j = 0; j < N; j++) T += '#';
      ans[i] = T;
  }

  for(int i = 0; i < N; i++) {
    ans[i][i] = 'X';
  }
  for(int i = 0; i < twos.size() - 1; i++) {
    ans[twos[i]][twos[i + 1]] = '+';
    ans[twos[i + 1]][twos[i]] = '-';
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(S[i] == '2') {
        if(S[j] == '1') ans[i][j] = '-';
        else if(ans[i][j] != '#') ans[i][j] = '='; 
      } else {
        if(S[j] == '2') ans[i][j] = '+';
        else ans[i][j] = '=';
      }
    }
  }
  cout << "YES\n";
  for(int i = 0; i < N; i++) {
    cout << ans[i] << '\n';
  }
  
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
