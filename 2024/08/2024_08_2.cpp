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

int n,m;

bool inbound(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemA/ProblemA/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string buf;
  vector<string> g;
  while (getline(cin, buf)) {
    g.emplace_back(buf);
  }
  n = (int)g.size();
  m = (int)g[0].length();
  vector<string> atn(n, string(m, '.'));
  unordered_map<char, vector<pairii>> mp;
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] != '.') {
        mp[g[i][j]].emplace_back(i, j);
      }
    }
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    vector<pairii>& ids = it->second;
    FORZ(i, ids.size()) {
      FOR(j, i+1, ids.size()) {
        int i0 = ids[i].first, j0 = ids[i].second, i1 = ids[j].first, j1 = ids[j].second;
        int di = i1 - i0, dj = j1 - j0;
        int ii0 = i0, jj0 = j0;
        while (inbound(ii0, jj0)) {
          atn[ii0][jj0] = '#';
          ii0 -= di;
          jj0 -= dj;
        }
        int ii1 = i1, jj1 = j1;
        while (inbound(ii1, jj1)) {
          atn[ii1][jj1] = '#';
          ii1 += di;
          jj1 += dj;
        }
      }
    }
  }
  
  int res = 0;
  FORZ(i,n) {
//    cout << atn[i] << endl;
    FORZ(j,m) {
      if (atn[i][j] == '#') {
        res++;
      }
    }
  }
  cout << res;
  
  return 0;
}
