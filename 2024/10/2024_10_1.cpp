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

vector<vector<int>> g;
int n,m;
const int DIR[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
unordered_set<int> st;

void dfs(int si, int sj, int d) {
  if (d == 9) {
    st.insert(si*m + sj);
  }
  FORZ(k,4) {
    int i = si + DIR[k][0];
    int j = sj + DIR[k][1];
    if (i >= 0 && j >= 0 && i < n && j < m && g[i][j] == d+1) {
      dfs(i, j, d+1);
    }
  }
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemC/ProblemC/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string buf;
  while (getline(cin, buf)) {
    g.pb(vector<int>());
    FORZ(i,buf.length()) {
      g[g.size()-1].pb(buf[i]-'0');
    }
  }
  n = (int)g.size();
  m = (int)g[0].size();
  int res = 0;
  FORZ(i,n) {
    FORZ(j,m) {
      if (g[i][j] == 0) {
        st.clear();
        dfs(i, j, 0);
        res += st.size();
      }
    }
  }
  cout << res;
  
  return 0;
}
