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

llong get(const string& u) {
  if (dp.find(u) != dp.end() && dp[u] >= 0) {
    return dp[u];
  }
  if (u == "you") {
    dp[u] = 1;
    return 1;
  }
  llong cnt = 0;
  for (auto it = adj.begin(); it != adj.end(); it++) {
    const string& from = it->first;
    const vector<string>& to = it->second;
    FORZ(i,to.size()) {
      if (to[i] == u) {
        cnt += get(from);
        break;
      }
    }
  }
  dp[u] = cnt;
  return dp[u];
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
  cout << get("out");
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
