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

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemG/ProblemG/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  
  string buf;
  llong res = 0;
  while (getline(cin, buf)) {
    FORZ(i, buf.length()) {
      if (buf[i] == ':') {
        buf[i] = ' ';
      }
    }
    stringstream ss(buf);
    llong x;
    llong r = -1;
    vector<llong> v;
    while (ss >> x) {
      if (r >= 0) {
        v.pb(x);
      } else {
        r = x;
      }
    }
    bool good = false;
    int n = (int)v.size();
    FORZ(i, 1 << (n-1)) {
      llong r2 = v[0];
      FORZ(j, n-1) {
        if (i & (1 << j)) {
          r2 += v[j+1];
        } else {
          r2 *= v[j+1];
        }
      }
      if (r2 == r) {
        good = true;
        break;
      }
    }
    if (good) {
      res += r;
    }
  }
  cout << res;
  
  return 0;
}
