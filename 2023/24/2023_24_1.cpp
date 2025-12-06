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

vector<vector<double>> g;
int n;
double MIN = 200000000000000, MAX = 400000000000000;

void rplc(string& s, char src, char tgt = ' ') {
  FORZ(i,s.length()) {
    if (s[i] == src) {
      s[i] = tgt;
    }
  }
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    rplc(buf, ',');
    rplc(buf, '@');
    stringstream ss(buf);
    vector<double> tg;
    FORZ(i, 6) {
      llong tmp;
      ss >> tmp;
      tg.pb(tmp);
    }
    g.pb(tg);
  }
  n = (int)g.size();
  int res = 0;
  FORZ(i,n) {
    FOR(j, i+1, n) {
      double x0 = g[i][0], y0 = g[i][1], v0 = g[i][3], u0 = g[i][4];
      double x1 = g[j][0], y1 = g[j][1], v1 = g[j][3], u1 = g[j][4];
      if (fabs(u0*v1 - u1*v0) < 10e-10) {
        continue;
      }
      double x = (u0*x0*v1 - v0*v1*y0 - u1*x1*v0 + v0*v1*y1) / (u0*v1 - u1*v0);
      double y = u0*x/v0 - u0*x0/v0 + y0;
      double t0 = (x - x0) / v0,  t1 = (x - x1) / v1;
      if (x < MIN || x > MAX || y < MIN || y > MAX || t0 < 0 || t1 < 0) {
        continue;
      }
      res++;
    }
  }
  cout << res << endl;
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
