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

void solve() {
  string buf;
  vector<string> g;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  int n = (int)g.size(), m = (int)g[0].length();
  int removed = -1, res = 0;
  while (removed != 0) {
    removed = 0;
    FORZ(i,n) {
      FORZ(j,m) {
        if (g[i][j] == 'x') {
          g[i][j] = '.';
        }
      }
    }
    FORZ(i,n) {
      FORZ(j,m) {
        if (g[i][j] != '@') {
          continue;
        }
        int cnt = 0;
        FOR(di, -1, 2) {
          FOR(dj, -1, 2) {
            if (di == 0 && dj == 0) {
              continue;
            }
            int ii = i + di, jj = j + dj;
            if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
              if (g[ii][jj] == '@' || g[ii][jj] == 'x') {
                cnt++;
              }
            }
          }
        }
        if (cnt < 4) {
          g[i][j] = 'x';
          removed++;
        }
      }
    }
    res += removed;
  }
  cout << res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemD/ProblemD/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  solve();
  
  return 0;
}
