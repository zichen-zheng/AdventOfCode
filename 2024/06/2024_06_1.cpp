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

const int DIR[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemF/ProblemF/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  
  string buf;
  vector<string> g;
  while (getline(cin, buf)) {
    g.emplace_back(buf);
  }
  
  int si = 0, sj = 0;
  int n = (int)g.size();
  int m = (int)g[0].length();
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] == '^') {
        si = i;
        sj = j;
      }
    }
  }
  int dir = 0;
  while (true) {
    int ni = si + DIR[dir][0];
    int nj = sj + DIR[dir][1];
    if (!(ni >= 0 && nj >= 0 && ni < n && nj < m)) {
      break;
    }
    if (g[ni][nj] == '#') {
      dir = (dir+1) % 4;
      continue;
    }
    si += DIR[dir][0];
    sj += DIR[dir][1];
    g[si][sj] = '^';
  }
  int res = 0;
  FORZ(i,n) {
//    cout << g[i] << endl;
    FORZ(j,m) {
      if (g[i][j] == '^') {
        res++;
      }
    }
  }
  cout << res;

  return 0;
}
