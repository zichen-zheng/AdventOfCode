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
vector<vector<bool>> vis;
int n, m, res;
const int DIRS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int ri, int rj, int len) {
//  cout << ri << " " << rj << " " << len << endl;
  vis[ri][rj] = true;
  if (ri == n-1) {
    res = max(res, len);
    vis[ri][rj] = false;
    return;
  }
  FORZ(k, 4) {
    if ((g[ri][rj] == '>' && k != 0)
        || (g[ri][rj] == '<' && k != 1)
        || (g[ri][rj] == 'v' && k != 2)
        || (g[ri][rj] == '^' && k != 3)) {
      continue;
    }
    int di = DIRS[k][0], dj = DIRS[k][1];
    int i = ri+di, j = rj+dj;
    if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && g[i][j] != '#') {
      dfs(i, j, len+1);
    }
  }
  vis[ri][rj] = false;
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  n = (int)g.size();
  m = (int)g[0].size();
  vis = vector<vector<bool>>(n, vector<bool>(m ,false));
  res = 0;
  dfs(0, 1, 0);
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
