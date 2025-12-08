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

vector<vector<int>> pts;
vector<bool> vis;
vector<pairii> idx;
int n;

llong get_dist(pairii pi) {
  int i = pi.first, j = pi.second;
  llong res = 0;
  FORZ(k,3) {
    llong d = pts[i][k] - pts[j][k];
    res += d*d;
  }
  return res;
}

bool comp(pairii pi, pairii pj) {
  llong di = get_dist(pi), dj = get_dist(pj);
  return di < dj;
}

int dfs(int r, int Q) {
  vis[r] = true;
  int res = 1;
  FORZ(q,Q) {
    pairii p = idx[q];
    int u = -1;
    if (r == p.first) {
      u = p.second;
    } else if (r == p.second) {
      u = p.first;
    }
    if (u >= 0 && !vis[u]) {
      res += dfs(u, Q);
    }
  }
  return res;
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    FORZ(i,buf.length()) {
      if (buf[i] == ',') {
        buf[i] = ' ';
      }
    }
    stringstream iss(buf);
    vector<int> v(3);
    iss >> v[0] >> v[1] >> v[2];
    pts.pb(v);
  }
  n = (int)pts.size();
  vector<vector<llong>> dist(n, vector<llong>(n));
  FORZ(i,n) FOR(j, i+1,n) {
    idx.emplace_back(i, j);
  }
  sort(idx.begin(), idx.end(), comp);
  int Q = 0;
  while(true) {
    vis = vector<bool>(n, false);
    int cnt = dfs(0, Q);
    // This is a hack
    if (cnt == n-1) {
      int u = -1;
      FORZ(i,n) {
        if (!vis[i]) {
          u = i;
          break;
        }
      }
      FORZ(i,idx.size()) {
        pairii p = idx[i];
        if (p.first == u || p.second == u) {
          Q = i+1;
          break;
        }
      }
      break;
    }
    Q++;
  }
  pairii p = idx[Q-1];
  cout << (llong)pts[p.first][0] * (llong)pts[p.second][0];
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
