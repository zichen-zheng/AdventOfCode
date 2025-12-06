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

pairii dfs(int i, int j, char c) {
  vis[i][j] = true;
  pairii res(4, 1);
  FORZ(k,4) {
    int ii = i+DIR[k][0];
    int jj = j+DIR[k][1];
    if (ii >= 0 && jj >= 0 && ii < n && jj < m && g[ii][jj] == c) {
      res.first--;
      if (!vis[ii][jj]) {
        pairii tmp = dfs(ii, jj, c);
        res.first += tmp.first;
        res.second += tmp.second;
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
        pairii tmp = dfs(i, j, g[i][j]);
//        cout << g[i][j] << ": " << tmp.first << ", " << tmp.second << endl;
        res += tmp.first * tmp.second;
      }
    }
  }
  cout << res;
  
  return 0;
}
