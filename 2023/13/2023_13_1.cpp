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

vector<string> g;
llong res;
int n,m;

bool checkrow(int r) {
  bool good = true;
  for (int i = r, ii = r+1; i >= 0 && ii < n; i--, ii++) {
    FORZ(j,m) {
      if (g[i][j] != g[ii][j]) {
        good = false;
        break;
      }
    }
    if (!good) {
      break;
    }
  }
  return good;
}

bool checkcol(int c) {
  bool good = true;
  for (int j = c, jj = c+1; j >= 0 && jj < m; j--, jj++) {
    FORZ(i,n) {
      if (g[i][j] != g[i][jj]) {
        good = false;
        break;
      }
    }
    if (!good) {
      break;
    }
  }
  return good;
}

void solve() {
  n = (int)g.size();
  m = (int)g[0].size();
  FORZ(i,n-1) {
    if (checkrow(i)) {
      res += (i+1)*100;
      return;
    }
  }
  FORZ(j,m-1) {
    if (checkcol(j)) {
      res += j+1;
      return;
    }
  }
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemB/ProblemB/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  string buf;
  res = 0;
  while (getline(cin, buf)) {
    if (buf.empty()) {
      solve();
      g.clear();
      continue;
    }
    g.pb(buf);
  }
  if (!g.empty()) {
    solve();
  }
  cout << res << endl;
  return 0;
}

