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

vector<string> g;
vector<vector<bool>> vis;
int n, m;
const int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<bool>> sides[2];

int dfs(int i, int j, char c) {
  vis[i][j] = true;
  int res = 1;
  sides[0][i][j] = sides[0][i+1][j] = sides[1][i][j] = sides[1][i][j+1] = true;
  FORZ(k,4) {
    int ii = i+DIR[k][0];
    int jj = j+DIR[k][1];
    if (ii >= 0 && jj >= 0 && ii < n && jj < m && g[ii][jj] == c) {
      if (k == 0) {
        sides[0][i+1][j] = false;
      } else if (k == 1) {
        sides[0][i][j] = false;
      } else if (k == 2) {
        sides[1][i][j+1] = false;
      } else {
        sides[1][i][j] = false;
      }
      if (!vis[ii][jj]) {
        res += dfs(ii, jj, c);
      }
    }
  }
  return res;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemE/ProblemE/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string buf;
  while (getline(cin, buf)) {
    g.emplace_back(buf);
  }
  n = (int)g.size();
  m = (int)g[0].length();
  vis = vector<vector<bool>>(n, vector<bool>(m, false));
  int res = 0;
  FORZ(i,n) {
    FORZ(j,m) {
      if (!vis[i][j]) {
        sides[0] = sides[1] = vector<vector<bool>>(n+1, vector<bool>(m+1, false));
        int x = dfs(i, j, g[i][j]);
        int y = 0;
        FORZ(ii,n+1) {
          FORZ(jj,m+1) {
            bool hasV = sides[1][ii][jj];
            if (ii > 0) {
              hasV |= sides[1][ii-1][jj];
            }
            if (sides[0][ii][jj] && hasV) {
              y++;
            }
          }
        }
        FORZ(jj,m+1) {
          FORZ(ii,n+1) {
            bool hasH = sides[0][ii][jj];
            if (jj > 0) {
              hasH |= sides[0][ii][jj-1];
            }
            if (sides[1][ii][jj] && hasH) {
              y++;
            }
          }
        }
//        cout << g[i][j] << ": " << x << ", " << y << endl;
        res += x * y;
      }
    }
  }
  cout << res;
  
  return 0;
}
