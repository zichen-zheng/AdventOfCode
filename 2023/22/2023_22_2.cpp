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

vector<vector<int>> g;
int n;

void rplc(string& s, char src, char tgt = ' ') {
  FORZ(i,s.length()) {
    if (s[i] == src) {
      s[i] = tgt;
    }
  }
}

bool comp(const vector<int>& v1, const vector<int>& v2) {
  return v1[2] < v2[2];
}

int sim(vector<vector<int>>& g) {
  int n = (int)g.size();
  int cnt = 0;
  FORZ(i, n) {
    auto& v = g[i];
    int z = 0;
    FORZ(j, i) {
      const auto& u = g[j];
      if (v[0] <= u[3] && v[3] >= u[0] && v[1] <= u[4] && v[4] >= u[1]) {
        z = max(z, u[5]);
      }
    }
    llong dz = v[2] - z - 1;
    if (dz > 0) {
      cnt++;
    }
    assert(dz >= 0);
    v[2] -= dz;
    v[5] -= dz;
  }
  return cnt;
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    rplc(buf, ',');
    rplc(buf, '~');
    stringstream ss(buf);
    vector<int> v(6, 0);
    FORZ(i, 6) {
      ss >> v[i];
    }
    if (v[0] > v[3] || v[1] > v[4] || v[2] > v[5]) {
      FORZ(j,3) swap(v[j], v[j+3]);
    }
    g.pb(v);
  }
  n = (int)g.size();
  sort(g.begin(), g.end(), comp);
  sim(g);
  int res = 0;
  FORZ(i, n) {
    vector<vector<int>> gg;
    FORZ(j, n) {
      if (i != j) {
        gg.pb(g[j]);
      }
    }
    res += sim(gg);
  }
  cout << res << endl;
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
