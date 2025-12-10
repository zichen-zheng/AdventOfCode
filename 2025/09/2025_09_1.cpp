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
  vector<pairll> pts;
  while (getline(cin, buf)) {
    FORZ(i,buf.length()) if (buf[i] == ',') buf[i] = ' ';
    int x, y;
    stringstream iss(buf);
    iss >> x >> y;
    pts.emplace_back(x, y);
  }
  llong res = 0;
  int n = (int)pts.size();
  FORZ(i,n) {
    FOR(j,i+1,n) {
      llong area = (abs(pts[i].first - pts[j].first) + 1) * (abs(pts[i].second - pts[j].second) + 1);
      res = max(res, area);
    }
  }
  cout << res;
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
