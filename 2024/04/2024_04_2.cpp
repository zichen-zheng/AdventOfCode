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
  
  string buf;
  vector<string> v;
  while (getline(cin, buf)) {
    v.pb(buf);
  }
  int n = (int)v.size();
  int m = (int)v[0].size();
  int res=0;
  FORZ(i,n-2) {
    FORZ(j,m-2) {
      bool forward = (v[i][j]=='M' && v[i+2][j+2]=='S') || (v[i][j]=='S' && v[i+2][j+2]=='M');
      bool backward = (v[i+2][j]=='M' && v[i][j+2]=='S') || (v[i+2][j]=='S' && v[i][j+2]=='M');
      if (forward && backward && v[i+1][j+1]=='A') {
        res++;
      }
    }
  }
  
  cout << res;
  
  return 0;
}
