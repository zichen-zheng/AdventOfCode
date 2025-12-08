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
const int Q = 1000;
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

int dfs(int r) {
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
      res += dfs(u);
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
  vis = vector<bool>(n, false);
  priority_queue<int> pq;
  FORZ(i,n) {
    if (!vis[i]) {
      int cnt = dfs(i);
      pq.push(cnt);
    }
  }
  int res = 1;
  FORZ(i,3) {
    res *= pq.top();
    pq.pop();
  }
  cout << res;
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
