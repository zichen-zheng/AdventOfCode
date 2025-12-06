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
int n,m;

void rotateN() {
  for (int j = 0; j < m; j++) {
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (g[i][j] == '.') {
        if (last < 0) {
          last = i;
        }
      } else if (g[i][j] == '#') {
        last = -1;
      } else if (last >= 0) {
        g[i][j] = '.';
        g[last][j] = 'O';
        last++;
      }
    }
  }
}

void rotateS() {
  for (int j = 0; j < m; j++) {
    int last = -1;
    for (int i = n-1; i >= 0; i--) {
      if (g[i][j] == '.') {
        if (last < 0) {
          last = i;
        }
      } else if (g[i][j] == '#') {
        last = -1;
      } else if (last >= 0) {
        g[i][j] = '.';
        g[last][j] = 'O';
        last--;
      }
    }
  }
}

void rotateW() {
  for (int i = 0; i < n; i++) {
    int last = -1;
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '.') {
        if (last < 0) {
          last = j;
        }
      } else if (g[i][j] == '#') {
        last = -1;
      } else if (last >= 0) {
        g[i][j] = '.';
        g[i][last] = 'O';
        last++;
      }
    }
  }
}

void rotateE() {
  for (int i = 0; i < n; i++) {
    int last = -1;
    for (int j = m-1; j >= 0; j--) {
      if (g[i][j] == '.') {
        if (last < 0) {
          last = j;
        }
      } else if (g[i][j] == '#') {
        last = -1;
      } else if (last >= 0) {
        g[i][j] = '.';
        g[i][last] = 'O';
        last--;
      }
    }
  }
}

llong compute() {
  llong res = 0;
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] == 'O') {
        res += n - i;
      }
    }
  }
  return res;
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  n = (int)g.size();
  m = (int)g[0].size();
  // Starting from a certain cycle, pattern repeats every 72 cycles.
  // After computation, we hard-code 136 here.
  FORZ(q,136) {
//    cout << q << endl;
    rotateN();
    rotateW();
    rotateS();
    rotateE();
//    FORZ(i,n) {
//      cout << g[i] << endl;
//    }
//    cout << endl;
  }
  llong res = compute();
  cout << res << endl;
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
