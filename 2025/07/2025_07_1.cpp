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
    g.emplace_back(buf);
  }
  int n = (int)g.size(), m = (int)g[0].length();
  int res = 0;
  FORZ(i,n-1) {
    FORZ(j,m) {
      if (g[i][j] == 'S' || g[i][j] == '|') {
        if (g[i+1][j] == '^') {
          res++;
          if (j > 0) {
            g[i+1][j-1] = '|';
          }
          if (j < m-1) {
            g[i+1][j+1] = '|';
          }
        } else {
          g[i+1][j] = '|';
        }
      }
    }
  }
  cout << res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemB/ProblemB/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  solve();

  return 0;
}
