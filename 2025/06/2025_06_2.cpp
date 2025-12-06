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
  string buf, ops;
  vector<string> nums;
  while (getline(cin, buf)) {
    bool is_ops = false;
    FORZ(i,buf.length()) {
      if (buf[i] == '*' || buf[i] == '+') {
        is_ops = true;
        break;
      }
    }
    if (is_ops) {
      stringstream iss(buf);
      string s;
      while (iss >> s) {
        ops.pb(s[0]);
      }
    } else {
      nums.emplace_back(buf);
    }
  }
  int idx = 0, j = 0, n = (int)nums.size();
  llong res = 0;
  while (idx < ops.length()) {
    llong base = ops[idx] == '*' ? 1 : 0;
    while (true) {
      llong tmp = 0;
      FORZ(i,n) {
        if (j >= nums[i].size()) {
          continue;
        }
        if (nums[i][j] != ' ') {
          tmp = tmp * 10 + (nums[i][j] - '0');
        }
      }
      j++;
      if (tmp == 0) {
        break;
      }
      if (ops[idx] == '*') {
        base *= tmp;
      } else {
        base += tmp;
      }
    }
    res += base;
    idx++;
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
