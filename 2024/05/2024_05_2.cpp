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

vector<vector<int>> g(100, vector<int>());

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemE/ProblemE/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  
  string buf;
  bool top = true;
  int res = 0;
  
  while (getline(cin, buf)) {
    if (buf.length() == 0) {
      top = false;
      continue;
    }
    if (top) {
      FORZ(i,buf.length()) {
        if (buf[i] == '|') {
          buf[i] = ' ';
        }
      }
      stringstream ss(buf);
      int u,w;
      ss >> u >> w;
      g[u].pb(w);
    } else {
      FORZ(i,buf.length()) {
        if (buf[i] == ',') {
          buf[i] = ' ';
        }
      }
      stringstream ss(buf);
      vector<int> v;
      int x;
      while (ss >> x) {
        v.pb(x);
      }
      int n = (int)v.size();
      bool good = true;
      FORZ(i,n) {
        int u = v[i];
        FOR(j,i+1,n) {
          int w = v[j];
          if (find(g[u].begin(), g[u].end(), w) == g[u].end()) {
            good = false;
            break;
          }
        }
        if (!good) {
          break;
        }
      }
      if (!good) {
        vector<int> v2;
        for (int u:v) {
          auto it = v2.begin();
          for (; it != v2.end(); it++) {
            int w = *it;
            if (find(g[w].begin(), g[w].end(), u) == g[w].end()) {
              break;
            }
          }
          v2.insert(it, u);
        }
        res += v2[n/2];
      }
    }
  }
  
  cout << res;
  
  return 0;
}
