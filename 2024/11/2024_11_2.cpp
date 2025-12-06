#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <string>
#include <cassert>
using namespace std;

typedef long long llong;
typedef pair<int,int> pairii;
typedef pair<llong,llong> pairll;

#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))
#define memclear(ar) memset((ar), 0, sizeof(ar))
#define pb push_back

vector<llong> v;
unordered_map<llong, unordered_map<llong, llong>> _dp;

llong dp(llong i, llong j) {
  if (_dp.find(i) != _dp.end() && _dp[i].find(j) != _dp[i].end()) {
    return _dp[i][j];
  }
  vector<llong> u;
  if (i == 0) {
    u.pb(1);
  } else {
    string s = to_string(i);
    if (s.length() % 2 == 0) {
      string sa = s.substr(0, s.length() / 2);
      string sb = s.substr(s.length() / 2);
      u.pb(atoi(sa.c_str()));
      u.pb(atoi(sb.c_str()));
    } else {
      u.pb(i * 2024);
    }
  }
  if (j == 1) {
    _dp[i][j] = u.size();
    return _dp[i][j];
  }
  llong res = 0;
  FORZ(k, u.size()) {
    res += dp(u[k], j-1);
  }
  _dp[i][j] = res;
  return res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemD/ProblemD/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  llong x;
  while (cin >> x) {
    v.pb(x);
  }
  llong res = 0;
  FORZ(i,v.size()) {
    res += dp(v[i], 75);
  }
  cout << res;
  
  return 0;
}
