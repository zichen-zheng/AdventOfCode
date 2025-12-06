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
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemF/ProblemF/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string buf;
  int a0,a1,b0,b1,p0,p1;
  int line = 0;
  int res = 0;
  while (getline(cin, buf)) {
    if (buf.length() == 0) {
      line = 0;
      continue;
    }
    FORZ(i,buf.length()) {
      if (buf[i] < '0' || buf[i] > '9') {
        buf[i] = ' ';
      }
    }
    stringstream ss(buf);
    if (line == 0) {
      ss >> a0 >> a1;
    } else if (line == 1) {
      ss >> b0 >> b1;
    } else if (line == 2) {
      ss >> p0 >> p1;
      int cost = INT_MAX;
      FORZ(i,101) {
        FORZ(j,101) {
          if (a0*i + b0*j == p0 && a1*i + b1*j == p1) {
            cost = min(cost, 3*i+j);
          }
        }
      }
      if (cost < INT_MAX) {
        res += cost;
      }
    }
    line++;
  }
  cout << res;
  
  return 0;
}
