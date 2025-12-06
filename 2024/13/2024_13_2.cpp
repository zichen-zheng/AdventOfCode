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
  llong a0,a1,b0,b1,p0,p1;
  a0=a1=b0=b1=p0=p1=0;
  int line = 0;
  llong res = 0;
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
      p0 += 10000000000000;
      p1 += 10000000000000;
      llong xn = b0*p1-b1*p0, xd = a1*b0-a0*b1;
      if (xn % xd == 0) {
        llong x = xn / xd;
        llong yn = p0-a0*x;
        if (yn % b0 == 0) {
          llong y = yn/b0;
          res += x*3+y;
        }
      }
    }
    line++;
  }
  cout << res;
  
  return 0;
}
