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
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemB/ProblemB/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string s;
  cin >> s;
  vector<int> v;
  bool file=true;
  int id = 0;
  FORZ(i,s.length()) {
    int cnt = s[i] - '0';
    FORZ(j, cnt) {
      if (file) {
        v.pb(id);
      } else {
        v.pb(-1);
      }
    }
    if (file) id++;
    file = !file;
  }
  int n = (int)v.size();
  int i = 0, j = n-1;
  while (i < j) {
    if (v[i] >= 0) {
      i++;
      continue;
    }
    if (v[j] == -1) {
      j--;
      continue;
    }
    swap(v[i], v[j]);
    i++;
    j--;
  }
  llong res = 0;
  FORZ(i,n) {
    if (v[i] < 0) break;
    res += (llong)v[i] * (llong)i;
  }
  cout << res;
  
  return 0;
}
