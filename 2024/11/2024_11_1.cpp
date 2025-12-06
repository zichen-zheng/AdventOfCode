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
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemD/ProblemD/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  vector<llong> v;
  llong x;
  while (cin >> x) {
    v.pb(x);
  }
  FORZ(i,25) {
    vector<llong> tv(v);
    v.clear();
    FORZ(j,tv.size()) {
      if (tv[j] == 0) {
        v.pb(1);
      } else {
        string s = to_string(tv[j]);
        if (s.length() % 2 == 0) {
          string sa = s.substr(0, s.length() / 2);
          string sb = s.substr(s.length() / 2);
          v.pb(atoi(sa.c_str()));
          v.pb(atoi(sb.c_str()));
        } else {
          v.pb(tv[j] * 2024);
        }
      }
    }
  }
  cout << v.size();
  
  return 0;
}
