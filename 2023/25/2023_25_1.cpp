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
typedef vector<int> vi;

#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))
#define memclear(ar) memset((ar), 0, sizeof(ar))
#define pb push_back

vector<vi> mat;
int n;

void rplc(string& s, char src, char tgt = ' ') {
  FORZ(i,s.length()) {
    if (s[i] == src) {
      s[i] = tgt;
    }
  }
}

// Stoer-Wagner algorithm for min-cut:
// https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/GlobalMinCut.h
pair<int, vi> globalMinCut() {
  pair<int, vi> best = {INT_MAX, {}};
  vector<vi> co(n);
  FORZ(i,n) co[i] = {i};
  FOR(ph,1,n) {
    vi w = mat[0];
    size_t s = 0, t = 0;
    FORZ(it,n-ph) {
      w[t] = INT_MIN;
      s = t; 
      t = max_element(w.begin(), w.end()) - w.begin();
      FORZ(i,n) w[i] += mat[t][i];
    }
    best = min(best, {w[t] - mat[t][t], co[t]});
    co[s].insert(co[s].end(), co[t].begin(), co[t].end());
    FORZ(i,n) mat[s][i] += mat[t][i];
    FORZ(i,n) mat[i][s] = mat[s][i];
    mat[0][t] = INT_MIN;
  }
  return best;
}

void solve() {
  string buf;
  unordered_map<string, unordered_set<string>> tmpg;
  unordered_map<string, int> dict;
  n = 0;
  while (getline(cin, buf)) {
    rplc(buf, ':');
    stringstream ss(buf);
    string src, dst;
    ss >> src;
    if (dict.find(src) == dict.end()) {
      dict[src] = n++;
    }
    while (ss >> dst) {
      tmpg[src].insert(dst);
      if (dict.find(dst) == dict.end()) {
        dict[dst] = n++;
      }
    }
  }
  mat = vector<vi>(n, vi(n, 0));
  for (const auto& p : tmpg) {
    string r = p.first;
    for (const auto& u : p.second) {
      mat[dict[r]][dict[u]] = 1;
      mat[dict[u]][dict[r]] = 1;
    }
  }
  auto cut = globalMinCut();
  int x = (int)cut.second.size();
  int y = n - x;
  cout << x * y << endl;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemG/ProblemG/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  solve();
  return 0;
}
