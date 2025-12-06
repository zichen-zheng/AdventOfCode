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
      if (g[ii][jj] == 'S' && (ri != pi || rj != pj)) {
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

void solve() {
  string buf;
  si = 0, sj = 0;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  n = (int)g.size();
  m = (int)g[0].size();
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
  queue<pair<pairii, int>> q;
  q.push({{si, sj}, 0});
  int res = 0;
  while (!q.empty()) {
    pair<pairii, int> p = q.front();
    q.pop();
    res = max(res, p.second);
    int i = p.first.first, j = p.first.second;
//    cout << "(" << i << "," << j << "): " << p.second << endl;
    vis[i][j] = true;
    FORZ(k, 4) {
      bool* t = gett(i, j);
      if (!t[k]) {
        continue;
      }
      int di = DIR[k][0], dj = DIR[k][1];
      int ii = i+di, jj = j+dj;
      if (ii >= 0 && ii < n && jj >= 0 && jj < m && loop[ii][jj] && !vis[ii][jj]) {
        int ddi = i - ii, ddj = j - jj;
        if (valid(ii, jj, ddi, ddj)) {
          q.push({{ii, jj}, p.second + 1});
        }
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
