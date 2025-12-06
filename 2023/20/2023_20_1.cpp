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

typedef struct Module {
  int type;
  bool on;
  unordered_map<string, bool> mem;
  vector<string> dest;
} Module;

typedef struct Pulse {
  string src;
  string dest;
  bool hi;
} Pulse;

unordered_map<string, Module> g;

void solve() {
  string buf;
  while (getline(cin, buf)) {
    FORZ(i, buf.size()) {
      if (buf[i] == ',') {
        buf[i] = ' ';
      }
    }
    stringstream ss(buf);
    string src, _arrow;
    ss >> src >> _arrow;
    if (src == "broadcaster") {
      g[src].type = 0;
    } else {
      char t = src[0];
      src = src.substr(1);
      if (t == '%') {
        g[src].type = 1;
        g[src].on = false;
      } else {
        g[src].type = 2;
      }
    }
    string dest;
    while (ss >> dest) {
      g[src].dest.pb(dest);
    }
  }
  for (auto node : g) {
    auto& mod = node.second;
    string src = node.first;
    for (string d : mod.dest) {
      if (g[d].type == 2) {
        g[d].mem[src] = false;
      }
    }
  }
  llong lo = 0, hi = 0;
  FORZ(x, 1000) {
    queue<Pulse> q;
    q.push({"button", "broadcaster", false});
    while (!q.empty()) {
      auto p = q.front();
//      cout << p.src << " -" << p.hi << "-> " << p.dest << endl;
      q.pop();
      auto& mod = g[p.dest];
      if (p.hi) {
        hi++;
      } else {
        lo++;
      }
      for (string d : mod.dest) {
        if (mod.type == 0) {
          q.push({p.dest, d, p.hi});
        } else if (mod.type == 1) {
          if (!p.hi) {
            q.push({p.dest, d, !mod.on});
          }
        } else {
          mod.mem[p.src] = p.hi;
          bool allhi = true;
          for (auto m : mod.mem) {
            if (!m.second) {
              allhi = false;
              break;
            }
          }
          q.push({p.dest, d, !allhi});
        }
      }
      if (mod.type == 1 && !p.hi) {
        mod.on = !mod.on;
      }
    }
//    cout << hi << " " << lo << endl;
//    cout << "-------------\n";
  }
  cout << hi * lo << endl;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemB/ProblemB/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  solve();
  return 0;
}
