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
int n, m, si, sj;
const llong GOAL = 64;
const int DIRS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void solve() {
  string buf;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  n = (int)g.size();
  m = (int)g[0].size();
  FORZ(i,n) FORZ(j, m) if (g[i][j] == 'S') {
    si = i;
    sj = j;
    g[i][j] = '.';
    break;
  }
  vector<pairii> v;
  v.emplace_back(si, sj);
  FORZ(k, GOAL) {
    for (auto p : v) {
      int i = p.first, j = p.second;
      FORZ(x, 4) {
        int di = DIRS[x][0], dj = DIRS[x][1];
        int ii = i + di, jj = j + dj;
        if (ii >= 0 && ii < n && jj >= 0 && jj < m && g[ii][jj] != '#') {
          g[ii][jj] = 'O';
        }
      }
    }
    v.clear();
//    cout << k << endl;
    FORZ(i,n) {
//      cout << g[i] << endl;
      FORZ(j,m) {
        if (g[i][j] == 'O') {
          v.emplace_back(i, j);
          g[i][j] = '.';
        }
      }
    }
  }
  cout << v.size() << endl;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemC/ProblemC/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  solve();
  return 0;
}
