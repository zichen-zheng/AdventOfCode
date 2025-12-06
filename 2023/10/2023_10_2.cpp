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
vector<vector<bool>> vis, loop;
int n, m, si, sj;
int DIR[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
bool TS[4] = {true, true ,true, true};
bool T7[4] = {true, false, false, true};
bool TJ[4] = {false, false, true, true};
bool TL[4] = {false, true, true, false};
bool TF[4] = {true, true, false, false};
bool TH[4] = {false, true, false, true};
bool TV[4] = {true, false, true, false};

bool* gett(int i, int j) {
  switch (g[i][j]) {
    case 'S':
      return TS;
    case '7':
      return T7;
    case 'J':
      return TJ;
    case 'L':
      return TL;
    case 'F':
      return TF;
    case '|':
      return TV;
    case '-':
      return TH;
  }
  return NULL;
}

bool valid(int i, int j, int di, int dj) {
  bool* t = gett(i, j);
  FORZ(k, 4) {
    if (di == DIR[k][0] && dj == DIR[k][1]) {
      return t[k];
    }
  }
  assert(false);
}

bool dfs(int ri, int rj, int pi, int pj, stack<pairii>& st) {
  st.emplace(ri, rj);
  vis[ri][rj] = true;
  bool found = false;
  FORZ(i,4) {
    bool* t = gett(ri, rj);
    if (!t[i]) {
      continue;
    }
    int di = DIR[i][0], dj = DIR[i][1];
    int ii = ri + di, jj = rj + dj;
    if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
      if ((ii == si && jj == si) && (ri != pi || rj != pj)) {
        return true;
      }
      if (!vis[ii][jj] && g[ii][jj] != '.') {
        int ddi = ri - ii, ddj = rj - jj;
        if (valid(ii, jj, ddi, ddj)) {
          found |= dfs(ii, jj, ri, rj, st);
        }
      }
    }
  }
  if (!found) {
    st.pop();
  }
  return found;
}

void dfs2(int ri, int rj) {
  vis[ri][rj] = true;
  g[ri][rj] = '*';
  FORZ(k,4) {
    int di = DIR[k][0], dj = DIR[k][1];
    int i = di + ri, j = dj + rj;
    if (i >= 0 && i < n && j >= 0 && j < m) {
      if (!loop[i][j] && !vis[i][j]) {
        dfs2(i, j);
      }
    }
  }
}

void solve() {
  string buf;
  si = 0, sj = 0;
  vector<string> tmpg;
  while (getline(cin, buf)) {
    tmpg.pb(buf);
  }
  n = (int)tmpg.size() + 2;
  m = (int)tmpg[0].size() + 2;
  g = vector<string>(n, string(m, '.'));
  FORZ(i, n-2) {
    FORZ(j, m-2) {
      g[i+1][j+1] = tmpg[i][j];
    }
  }
  vis = vector<vector<bool>>(n, vector<bool>(m, false));
  FORZ(i,n) FORZ(j,m) {
    if (g[i][j] == 'S') {
      si = i;
      sj = j;
      break;
    }
  }
  
  stack<pairii> st;
  assert(dfs(si, sj, -1, -1, st));
  vis.clear();
  vis = loop = vector<vector<bool>>(n, vector<bool>(m, false));
  while (!st.empty()) {
    pairii p = st.top();
    st.pop();
    loop[p.first][p.second] = true;
//    cout << p.first << " " << p.second << endl;
  }
  dfs2(0, 0);
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] != '*' && !loop[i][j]) {
        g[i][j] = '.';
      }
    }
  }
  int res = 0;
  FORZ(i,n) {
    bool in = false;
    char last = '.';
    FORZ(j,m) {
      if (loop[i][j] && g[i][j] != '-') {
        if ((last == 'F' && g[i][j] == 'J') || (last == 'L' && g[i][j] == '7')) {
          last  = g[i][j];
          continue;
        }
        last  = g[i][j];
        in = !in;
      } else if (g[i][j] == '.' && in) {
        res++;
      }
    }
  }
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
