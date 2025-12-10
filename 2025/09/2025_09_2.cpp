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

vector<pairll> pts;
int n;

llong area(int i, int j) {
  return (abs(pts[i].first - pts[j].first) + 1) * (abs(pts[i].second - pts[j].second) + 1);
}

bool is_in(int a, int b) {
  llong xa = pts[a].first, ya = pts[a].second;
  llong xb = pts[b].first, yb = pts[b].second;
  if (xa > xb) swap(xa, xb);
  if (ya > yb) swap(ya, yb);
  FORZ(i,n) {
    llong x1 = pts[i].first, y1 = pts[i].second;
    llong x2 = pts[(i+1)%n].first, y2 = pts[(i+1)%n].second;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    // (xa, ya), (xb, ya)
    if (x1 == x2 && x1 > xa && x1 < xb && ya >= y1 && ya < y2) {
      return false;
    }
    // (xa, yb), (xb, yb)
    if (x1 == x2 && x1 > xa && x1 < xb && yb > y1 && yb <= y2) {
      return false;
    }
    // (xa, ya), (xa, yb)
    if (y1 == y2 && y1 > ya && y1 < yb && xa >= x1 && xa < x2) {
      return false;
    }
    // (xb, ya), (xb, yb)
    if (y1 == y2 && y1 > ya && y1 < yb && xb >=x1 && xb <= x2) {
      return false;
    }
  }
  return true;
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    FORZ(i,buf.length()) if (buf[i] == ',') buf[i] = ' ';
    int x, y;
    stringstream iss(buf);
    iss >> x >> y;
    pts.emplace_back(x, y);
  }
  llong res = 0;
  n = (int)pts.size();
  FORZ(i,n) {
    FOR(j,i+1,n) {
      if (is_in(i, j)) {
        res = max(res, area(i, j));
      }
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
