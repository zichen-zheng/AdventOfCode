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
  vector<vector<llong>> nums;
  string ops;
  while (getline(cin, buf)) {
    stringstream iss(buf);
    vector<llong> tv;
    string tmp;
    while (iss >> tmp) {
      if (tmp[0] >= '0' && tmp[0] <= '9') {
        llong tll = atoll(tmp.c_str());
        tv.pb(tll);
      } else {
        ops.pb(tmp[0]);
      }
    }
    if (!tv.empty()) {
      nums.emplace_back(tv);
    }
  }
  int n = (int)nums.size();
  int m = (int)nums[0].size();
  llong res = 0;
  FORZ(j,m) {
    llong tmp;
    if (ops[j] == '*') {
      tmp = 1;
      FORZ(i,n) {
        tmp *= nums[i][j];
      }
    } else {
      tmp = 0;
      FORZ(i,n) {
        tmp += nums[i][j];
      }
    }
    res += tmp;
  }
  cout << res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemA/ProblemA/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  solve();
  
  return 0;
}
