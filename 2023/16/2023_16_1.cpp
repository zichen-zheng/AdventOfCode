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

#define R 1
#define D 2
#define L 4
#define U 8

#define Rv {i,j+1,R}
#define Dv {i+1,j,D}
#define Lv {i,j-1,L}
#define Uv {i-1,j,U}

vector<string> g;
vector<vector<int>> en;
int n,m;

void solve() {
  string buf;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  n = (int)g.size();
  m = (int)g[0].size();
  en = vector<vector<int>>(n, vector<int>(m, 0));
  queue<vector<int>> q;
  q.push({0,0,1});
  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    int i = curr[0], j = curr[1], dir = curr[2];
    en[i][j] |= dir;
    vector<vector<int>> next;
    const char& c = g[i][j];
    if (c == '.') {
      if (dir == R) {
        next.pb(Rv);
      } else if (dir == D) {
        next.pb(Dv);
      } else if (dir == L) {
        next.pb(Lv);
      } else {
        next.pb(Uv);
      }
    } else if (c == '/') {
      if (dir == R) {
        next.pb(Uv);
      } else if (dir == D) {
        next.pb(Lv);
      } else if (dir == L) {
        next.pb(Dv);
      } else {
        next.pb(Rv);
      }
    } else if (c == '\\') {
      if (dir == R) {
        next.pb(Dv);
      } else if (dir == D) {
        next.pb(Rv);
      } else if (dir == L) {
        next.pb(Uv);
      } else {
        next.pb(Lv);
      }
    } else if (c == '|') {
      if (dir == R || dir == L) {
        next.pb(Dv);
        next.pb(Uv);
      } else if (dir == U) {
        next.pb(Uv);
      } else {
        next.pb(Dv);
      }
    } else {
      if (dir == U || dir == D) {
        next.pb(Lv);
        next.pb(Rv);
      } else if (dir == R) {
        next.pb(Rv);
      } else {
        next.pb(Lv);
      }
    }
    FORZ(k, next.size()) {
      int ii = next[k][0], jj = next[k][1], dd = next[k][2];
      if (ii >= 0 && ii < n && jj >= 0 && j < m && (en[ii][jj] & dd) == 0) {
        q.push(next[k]);
      }
    }
  }
  int res = 0;
  FORZ(i,n) {
    FORZ(j,m) {
      if (en[i][j] > 0) {
        res++;
      }
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
