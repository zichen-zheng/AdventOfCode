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

void solve() {
  string buf;
  vector<string>(tmpg);
  while (getline(cin, buf)) {
    tmpg.pb(buf);
  }
  unordered_set<int> rows, cols;
  n = (int)tmpg.size();
  m = (int)tmpg[0].size();
  FORZ(i,n) {
    bool has = false;
    FORZ(j,m) {
      if (tmpg[i][j] == '#') {
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
      if (tmpg[i][j] == '#') {
        has = true;
        break;
      }
    }
    if (!has) {
      cols.insert(j);
    }
  }
  int nn = n + (int)rows.size();
  int mm = m + (int)cols.size();
  FORZ(i,n) {
    string s;
    FORZ(j,m) {
      if (cols.find(j) != cols.end()) {
        s.pb(tmpg[i][j]);
      }
      s.pb(tmpg[i][j]);
    }
    g.pb(s);
    if (rows.find(i) != rows.end()) {
      g.pb(string(mm, '.'));
    }
  }
  n = nn;
  m = mm;
//  FORZ(i,n) {
//    cout << g[i] << endl;
//  }
//  cout << endl;
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
      res += abs(gl[i].first - gl[j].first) + abs(gl[i].second - gl[j].second);
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
