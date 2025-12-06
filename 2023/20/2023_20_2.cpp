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

llong gcd(llong x, llong y) {
  if(y != 0) return gcd(y, x%y);
  return x;
}

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
  vector<string> nodes = {"sr", "sn", "rf", "vq"}; // modules leading to "hp", which leads to "rx"
  vector<bool> found(4, false);
  vector<llong> count(4, 0);
  while (true) {
    queue<Pulse> q;
    q.push({"button", "broadcaster", false});
    FORZ(k, nodes.size()) {
      if (!found[k]) {
        count[k]++;
      }
    }
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      FORZ(k, nodes.size()) {
        if (!found[k] && p.hi && nodes[k] == p.src) {
          found[k] = true;
        }
      }
      auto& mod = g[p.dest];
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
    bool allfound = true;
    FORZ(k, nodes.size()) {
      if (!found[k]) {
        allfound = false;
        break;
      }
    }
    if (allfound) {
      break;
    }
  }
  llong lcm = 1;
  for (llong x : count) lcm *= x / gcd(lcm, x);
  cout << lcm << endl;
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
