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
bool vis[200][200][4][3];
int cc[200][200][4][3];
int DIR[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void bfs(int i, int j, int k, int p) {
  FORZ(i,n) FORZ(j,m) FORZ(k,4) FORZ(p,3) vis[i][j][k][p] = false;
  queue<vector<int>> q;
  q.push({i,j,k,p});
  while (!q.empty()) {
    vector<int> f = q.front();
    q.pop();
    int i=f[0], j=f[1], k=f[2], p=f[3];
    if (vis[i][j][k][p]) {
      continue;
    }
    vis[i][j][k][p] = true;
    FORZ(l,4) {
      if (abs(l-k) == 2) {
        continue;
      }
      int di = DIR[l][0], dj = DIR[l][1];
      int ni = i+di, nj = j+dj;
      if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
        continue;
      }
      int val = cc[i][j][k][p] < INT_MAX ? g[ni][nj] - '0' + cc[i][j][k][p] : INT_MAX;
      if (l == k) {
        if (p == 2) {
          continue;
        }
        cc[ni][nj][l][p+1] = min(cc[ni][nj][l][p+1], val);
        if (!vis[ni][nj][l][p+1]) {
          q.push({ni,nj,l,p+1});
        }
      } else {
        cc[ni][nj][l][0] = min(cc[ni][nj][l][0], val);
        if (!vis[ni][nj][l][0]) {
          q.push({ni,nj,l,0});
        }
      }
    }
  }
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  n = (int)g.size();
  m = (int)g[0].size();
  FORZ(i,n) FORZ(j,m) FORZ(k,4) FORZ(p,3) cc[i][j][k][p] = INT_MAX;
  cc[0][1][0][0] = g[0][1] - '0';
  cc[1][0][1][0] = g[1][0] - '0';
  int res = INT_MAX;
  while (true) {
    int tmp = INT_MAX;
    bfs(0,1,0,0);
    bfs(1,0,1,0);
    FORZ(k,2) FORZ(p,3) tmp = min(tmp, cc[n-1][m-1][k][p]);
    if (tmp == res) {
      break;
    }
    res = tmp;
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
