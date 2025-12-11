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

unordered_map<string, vector<string>> adj;
unordered_map<string, llong> dp;

llong _get(const string& u, const string& src, const string& tgt) {
  if (dp.find(u) != dp.end() && dp[u] >= 0) {
    return dp[u];
  }
  if (u == src) {
    dp[u] = 1;
    return 1;
  }
  llong cnt = 0;
  for (auto it = adj.begin(); it != adj.end(); it++) {
    const string& from = it->first;
    const vector<string>& to = it->second;
    FORZ(i,to.size()) {
      if (to[i] == u) {
        cnt += _get(from, src, tgt);
        break;
      }
    }
  }
  dp[u] = cnt;
  return dp[u];
}

llong get(const string& src, const string& tgt) {
  for (auto it = dp.begin(); it != dp.end(); it++) {
    it->second = -1;
  }
  return _get(tgt, src, tgt);
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    FORZ(i,buf.length()) if (buf[i] == ':') buf[i] = ' ';
    stringstream iss(buf);
    string u;
    iss >> u;
    adj[u] = vector<string>();
    dp[u] = -1;
    string v;
    while (iss >> v) {
      adj[u].pb(v);
    }
  }
  llong x, y, z, res;
  x = get("svr", "fft");
  y = get("fft", "dac");
  z = get("dac", "out");
  res = x * y * z;
  x = get("svr", "dac");
  y = get("dac", "fft");
  z = get("fft", "out");
  res += x * y * z;
  cout << res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemF/ProblemF/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  solve();
  
  return 0;
}
