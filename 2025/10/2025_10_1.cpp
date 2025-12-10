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

int goal, n;
vector<vector<int>> btn;

void parse(const string& arg) {
  int i = 1;
  n = goal = 0;
  btn.clear();
  while (arg[i] != ']') {
    int mask = arg[i] == '#' ? 1 : 0;
    mask <<= n;
    goal += mask;
    n++;
    i++;
  }
  while (arg[i+2] != '{') {
    i += 3;
    string subs;
    while (arg[i] != ')') {
      subs.pb(arg[i] == ',' ? ' ' : arg[i]);
      i++;
    }
    stringstream iss(subs);
    int x;
    vector<int> tv;
    while (iss >> x) {
      tv.pb(x);
    }
    btn.pb(tv);
  }
}

int apply(int state, int btn_i) {
  FORZ(i,btn[btn_i].size()) {
    int mask = 1 << btn[btn_i][i];
    state ^= mask;
  }
  return state;
}

int solve(const string& arg) {
  parse(arg);
  vector<bool> vis(1 << n, false);
  queue<pairii> q;
  q.push(pairii(0, 0));
  vis[0] = true;
  while (!q.empty()) {
    pairii p = q.front();
    q.pop();
    int state = p.first, depth = p.second;
    if (state == goal) {
      return depth;
    }
    FORZ(i,btn.size()) {
      int next = apply(state, i);
      if (!vis[next]) {
        vis[next] = true;
        q.push(pairii(next, depth + 1));
      }
    }
  }
  return -1;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemE/ProblemE/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string buf;
  int res = 0;
  while (getline(cin, buf)) {
    res += solve(buf);
  }
  cout << res;
  
  return 0;
}
