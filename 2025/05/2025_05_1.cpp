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
  vector<pairll> ranges;
  while (getline(cin, buf)) {
    if (buf.empty()) {
      break;
    }
    FORZ(i, buf.length()) {
      if (buf[i] == '-') {
        buf[i] = ' ';
        break;
      }
    }
    llong l, r;
    stringstream iss(buf);
    iss >> l >> r;
    ranges.emplace_back(l, r);
  }
  int res = 0;
  llong ig;
  while (cin >> ig) {
    FORZ(i, ranges.size()) {
      if (ig >= ranges[i].first && ig <= ranges[i].second) {
        res++;
        break;
      }
    }
  }
  cout << res;
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
