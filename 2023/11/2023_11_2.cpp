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
vector<pairii> gl;
int n, m;
llong M = 1000000;

void solve() {
  string buf;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  unordered_set<llong> rows, cols;
  n = (int)g.size();
  m = (int)g[0].size();
  FORZ(i,n) {
    bool has = false;
    FORZ(j,m) {
      if (g[i][j] == '#') {
        has = true;
        break;
      }
    }
    if (!has) {
      rows.insert(i);
    }
  }
  FORZ(j,m) {
    bool has = false;
    FORZ(i,n) {
      if (g[i][j] == '#') {
        has = true;
        break;
      }
    }
    if (!has) {
      cols.insert(j);
    }
  }
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] == '#') {
        gl.emplace_back(i, j);
      }
    }
  }
  llong res = 0;
  FORZ(i, gl.size()) {
    FOR(j, i+1, gl.size()) {
      llong x1 = gl[i].first, x2 = gl[j].first, y1 = gl[i].second, y2 = gl[j].second;
      llong tmp = 0;
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      for (llong x = x1+1; x <= x2; x++) {
        if (rows.find(x) != rows.end()) {
          tmp += M;
        } else {
          tmp++;
        }
      }
      for (llong y = y1+1; y <= y2; y++) {
        if (cols.find(y) != cols.end()) {
          tmp += M;
        } else {
          tmp++;
        }
      }
      //cout << tmp << endl;
      res += tmp;
    }
  }
  cout << res << endl;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemE/ProblemE/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  solve();
  return 0;
}
