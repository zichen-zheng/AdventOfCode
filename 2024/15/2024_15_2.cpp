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
      string tmp;
      FORZ(i,buf.length()) {
        if (buf[i] == '#') {
          tmp.append("##");
        } else if (buf[i] == 'O') {
          tmp.append("[]");
        } else if (buf[i] == '.') {
         tmp.append("..");
        } else if (buf[i] == '@') {
         tmp.append("@.");
        }
      }
      g.emplace_back(tmp);
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
    if (d >= 2) {
      while (g[ti][tj] != '#' && g[ti][tj] != '.') {
        tj += DIR[d][1];
      }
      if (g[ti][tj] == '.') {
        for (int j = tj; j != rj + DIR[d][1]; j -= DIR[d][1] * 2) {
          if (DIR[d][1] == -1) {
            g[ti][j] = '[';
            g[ti][j+1] = ']';
          } else {
            g[ti][j-1] = '[';
            g[ti][j] = ']';
          }
        }
        g[ri][rj] = '.';
        rj += DIR[d][1];
        g[ri][rj] = '@';
      }
    } else {
      bool good = true;
      while (ti >= 0 && ti < n) {
        FORZ(j,m) {
          if (g[ti][j] == '@' || g[ti][j] == '{' || g[ti][j] == '}') {
            int ni = ti + DIR[d][0];
            if (g[ni][j] == '[') {
              g[ni][j] = '{';
              g[ni][j+1] = '}';
            } else if (g[ni][j] == ']') {
              g[ni][j] = '}';
              g[ni][j-1] = '{';
            } else if (g[ni][j] == '#') {
              good = false;
              break;
            }
          }
        }
        if (!good) {
          break;
        }
        ti += DIR[d][0];
      }
      if (good) {
        if (d == 0) {
          FORZ(i,n-1) {
            FORZ(j,m) {
              if (g[i+1][j] == '{') {
                g[i][j] = '[';
                g[i+1][j] = '.';
              } else if (g[i+1][j] == '}') {
                g[i][j] = ']';
                g[i+1][j] = '.';
              } else if (g[i+1][j] == '@') {
                g[i][j] = '@';
                ri = i;
                rj = j;
                g[i+1][j] = '.';
              }
            }
          }
        } else {
          for (int i = n-1; i > 0; i--) {
            FORZ(j,m) {
              if (g[i-1][j] == '{') {
                g[i][j] = '[';
                g[i-1][j] = '.';
              } else if (g[i-1][j] == '}') {
                g[i][j] = ']';
                g[i-1][j] = '.';
              } else if (g[i-1][j] == '@') {
                g[i][j] = '@';
                ri = i;
                rj = j;
                g[i-1][j] = '.';
              }
            }
          }
        }
      }
      FORZ(i,n) FORZ(j,m) {
        if (g[i][j] == '{') g[i][j] = '[';
        if (g[i][j] == '}') g[i][j] = ']';
      }
    }
//    cout << ins[q] << endl;
//    FORZ(i,n) {
//      cout << g[i] << endl;
//    }
//    cout << endl;
  }
  int res = 0;
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] == '[') {
        res += 100*i + j;
      }
    }
  }
  cout << res;
  
  return 0;
}
