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

unordered_map<string, vector<string>> dict;

void rplc(string& s, char src, char tgt = ' ') {
  FORZ(i,s.length()) {
    if (s[i] == src) {
      s[i] = tgt;
    }
  }
}

int idx(char part) {
  switch (part) {
    case 'x':
      return 0;
    case 'm':
      return 1;
    case 'a':
      return 2;
    case 's':
      return 3;
    default:
      return -1;
  }
}

bool parse(const vector<llong>& parts, string wf = "in") {
  vector<string> instrs = dict[wf];
  FORZ(i, instrs.size()) {
    string instr = instrs[i];
    string next;
    bool good = i == instrs.size() - 1;
    if (good) {
      next = instr;
    } else {
      rplc(instr, ':');
      stringstream ss(instr);
      char part, op;
      llong num;
      ss >> part >> op >> num >> next;
      int j = idx(part);
      good = op == '>' ? parts[j] > num : parts[j] < num;
    }
    if (good) {
      if (next == "R") {
        return false;
      } else if (next == "A") {
        return true;
      } else {
        return parse(parts, next);
      }
    }
  }
  assert(false);
  return false;
}

void solve() {
  string buf;
  bool partone = true;
  llong res = 0;
  while (getline(cin, buf)) {
    if (buf.empty()) {
      partone = false;
      continue;
    }
    rplc(buf, '{');
    rplc(buf, '}');
    if (partone) {
      stringstream ss(buf);
      string name, content;
      ss >> name >> content;
      dict[name] = vector<string>();
      rplc(content, ',');
      ss = stringstream(content);
      string instr;
      while (ss >> instr) {
        dict[name].pb(instr);
      }
    } else {
      rplc(buf, ',');
      rplc(buf, '=');
      stringstream ss(buf);
      string part;
      llong num;
      vector<llong> parts;
      while (ss >> part >> num) {
        parts.pb(num);
      }
      if (parse(parts)) {
        FORZ(i,parts.size()) {
          res += parts[i];
        }
      }
    }
  }
  cout << res << endl;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemA/ProblemA/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  solve();
  return 0;
}
