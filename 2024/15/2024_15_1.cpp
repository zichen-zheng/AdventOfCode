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

const string DS = "^v<>";
const int DIR[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

string ins;
vector<string> g;
int n,m;

int getd(char c) {
  int i = 0;
  for(; i<4; i++) {
    if (DS[i] == c) {
      break;
    }
  }
  return i;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemA/ProblemA/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string buf;
  bool isg = true;
  while (getline(cin, buf)) {
    if (buf.length() == 0) {
      isg = false;
      continue;
    }
    if (isg) {
      g.emplace_back(buf);
    } else {
      ins.append(buf);
    }
  }
  n = (int)g.size();
  m = (int)g[0].length();
  int ri=0, rj=0;
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] == '@') {
        ri = i;
        rj = j;
      }
    }
  }
  FORZ(q,ins.length()) {
    int d = getd(ins[q]);
    int ti = ri, tj = rj;
    while (g[ti][tj] != '#' && g[ti][tj] != '.') {
      ti += DIR[d][0];
      tj += DIR[d][1];
    }
    if (g[ti][tj] == '.') {
      g[ti][tj] = 'O';
      g[ri][rj] = '.';
      ri += DIR[d][0];
      rj += DIR[d][1];
      g[ri][rj] = '@';
    }
  }
  int res = 0;
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] == 'O') {
        res += 100*i + j;
      }
    }
  }
  cout << res;
  
  return 0;
}
