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
  int res = 0;
  vector<int> sizes;
  while (getline(cin, buf)) {
    bool first_half = true;
    FORZ(i,buf.length()) {
      if (buf[i] == 'x') {
        buf[i] = ' ';
        first_half = false;
      }
      if (buf[i] == ':') {
        buf[i] = ' ';
      }
    }
    if (first_half) {
      int cnt = 0;
      while (getline(cin, buf)) {
        if (buf.empty()) {
          break;
        }
        FORZ(i,buf.size()) {
          if (buf[i] == '#') {
            cnt++;
          }
        }
      }
      sizes.pb(cnt);
      continue;
    }
    stringstream iss(buf);
    int w,h;
    iss >> w >> h;
    int total = w * h;
    int x;
    FORZ(i, sizes.size()) {
      iss >> x;
      total -= sizes[i] * x;
    }
    if (total >= 0) {
      res++;
    }
  }
  cout << res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemG/ProblemG/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  solve();
  
  return 0;
}
