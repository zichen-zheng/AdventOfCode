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

llong solve() {
  llong res = 0;
  FORZ(i,s.length()) {
    res += s[i];
    res *= 17;
    res %= 256;
  }
  return res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemD/ProblemD/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  string buf;
  getline(cin, buf);
  buf.pb(',');
  llong res = 0;
  FORZ(i,buf.size()) {
    if (buf[i] == ',') {
      llong tmp = solve();
      res += tmp;
      s.clear();
    } else {
      s.pb(buf[i]);
    }
  }
  cout << res << endl;
  return 0;
}
