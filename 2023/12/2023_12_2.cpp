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

string s;
vector<llong> nums;
vector<vector<llong>> dp;

llong comp(int ii, int jj);

llong getsharp(int ii, int jj) {
  llong num = nums[jj];
  int i = ii;
  for (; i < ii + num; i++) {
    if (i >= s.size()) {
      return 0;
    }
    if (s[i] == '.') {
      return 0;
    }
  }
  if (i < s.size() && s[i] == '#') {
    return 0;
  }
  return comp(i+1, jj+1);
}

llong comp(int ii, int jj) {
  if (ii >= s.size()) {
    return 0;
  }
  llong& res = dp[ii][jj];
  if (res >= 0) {
    return res;
  }
  if (jj == nums.size()) {
    bool good = true;
    FOR(i, ii, s.size()) {
      if (s[i] == '#') {
        good = false;
        break;
      }
    }
    if (good) {
      res = 1;
    } else {
      res = 0;
    }
  } else if (s[ii] == '.') {
    res = comp(ii+1, jj);
  } else if (s[ii] == '#') {
    res = getsharp(ii, jj);
  } else {
    res = getsharp(ii, jj) + comp(ii+1, jj);
  }
  return res;
}

void solve() {
  string buf;
  llong res = 0;
  while (getline(cin, buf)) {
    FORZ(i,buf.size()) if (buf[i] == ',') buf[i] = ' ';
    stringstream ss(buf);
    ss >> s;
    llong num;
    nums.clear();
    while (ss >> num) {
      nums.pb(num);
    }
    int n = (int)s.length();
    int m = (int)nums.size();
    FORZ(i,4) {
      s.pb('?');
      FORZ(j,n) {
        s.pb(s[j]);
      }
      FORZ(j,m) {
        nums.pb(nums[j]);
      }
    }
    s.pb('.');
    s.pb('.');
    dp.clear();
    dp = vector<vector<llong>>(s.size(), vector<llong>(nums.size() + 1, -1));
    llong cnt = comp(0, 0);
//    cout << cnt << endl;
    res += cnt;
  }
  cout << res << endl;
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
