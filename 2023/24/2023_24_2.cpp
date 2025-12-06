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

vector<vector<llong>> g;
int n;

void rplc(string& s, char src, char tgt = ' ') {
  FORZ(i,s.length()) {
    if (s[i] == src) {
      s[i] = tgt;
    }
  }
}

void printLinearEquation() {
  cout << "Equation: ax + by + cz + dv + eu +fw = k\n\n";
  FOR(i,1,5) {
    llong x0 = g[0][0], y0 = g[0][1], v0 = g[0][3], u0 = g[0][4];
    llong x1 = g[i][0], y1 = g[i][1], v1 = g[i][3], u1 = g[i][4];
    cout << u1-u0 << " " << v0-v1 << " 0 " << y0-y1 << " " << x1-x0 << " 0 " << x1*u1 - x0*u0 - y1*v1 + y0*v0 << endl;
  }
  FOR(i,1,3) {
    llong x0 = g[0][0], z0 = g[0][2], v0 = g[0][3], w0 = g[0][5];
    llong x1 = g[i][0], z1 = g[i][2], v1 = g[i][3], w1 = g[i][5];
    cout << w1-w0 << " 0 " << v0-v1 << " " << z0-z1 << " 0 " << x1-x0 << " " << x1*w1 - x0*w0 - z1*v1 + z0*v0 << endl;
  }
  // Use an online tool to solve the linear equation and get the result:
  llong x = 454198524200037, y = 345331129547776, z = 234240489673806;
  llong v = -299, u = -98, w = 79;
  cout << "\nSolutoion:\nx = " << x << "\ny = " << y << "\nz = " << z << "\nv = " << v << "\nu = " << u << "\nw = " << w << "\n\n";
  cout << "x + y + z = " << x + y + z << "\n";
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    rplc(buf, ',');
    rplc(buf, '@');
    stringstream ss(buf);
    vector<llong> tg;
    FORZ(i, 6) {
      llong tmp;
      ss >> tmp;
      tg.pb(tmp);
    }
    g.pb(tg);
  }
  n = (int)g.size();
  printLinearEquation();
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
