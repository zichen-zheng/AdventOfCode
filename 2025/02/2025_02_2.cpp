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
  cin >> buf;
  FORZ(i,buf.length()) {
    if (buf[i] == ',' || buf[i] == '-') {
      buf[i] = ' ';
    }
  }
  stringstream iss(buf);
  llong l, r, res = 0;
  while (iss >> l >> r) {
    for (llong num = l; num <= r; num++) {
      string s = to_string(num);
      int n = (int)s.length();
      FOR(k,1,n) {
        if (n % k != 0) {
          continue;
        }
        bool same = true;
        FORZ(i,k) {
          FOR(j,1,n/k) {
            if (s[i] != s[i+k*j]) {
              same = false;
              break;
            }
          }
          if (!same) {
            break;
          }
        }
        if (same) {
          res += num;
          break;
        }
      }
    }
  }
  cout << res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemB/ProblemB/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  solve();
  
  return 0;
}
