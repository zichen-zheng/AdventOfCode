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

llong all(const vector<pairll> ranges) {
  llong res = 1;
  FORZ(i,ranges.size()) {
    if (ranges[i].second < ranges[i].first) {
      return 0;
    }
    res *= (ranges[i].second - ranges[i].first + 1);
  }
  return res;
}

llong solve2(string wf, int i, vector<pairll> ranges);

llong compute(string instr, const vector<pairll> ranges) {
  if (instr == "R") {
    return 0;
  } else if (instr == "A") {
    return all(ranges);
  } else {
    return solve2(instr, 0, ranges);
  }
}

llong solve2(string wf, int i, vector<pairll> ranges) {
  vector<string> instrs = dict[wf];
  string instr = instrs[i];
  if (i == instrs.size() - 1) {
    return compute(instr, ranges);
  }
  rplc(instr, ':');
  stringstream ss(instr);
  char part, op;
  llong num;
  string next;
  ss >> part >> op >> num >> next;
  int j = idx(part);
  auto lr = ranges, rr = ranges;
  if (op == '<') num--;
  lr[j].second = min(lr[j].second, num);
  rr[j].first = max(rr[j].first, num+1);
  auto& sr = op == '<' ? lr : rr;
  auto& fr = op == '<' ? rr : lr;
  llong lres = compute(next, sr);
  llong rres = solve2(wf, i+1, fr);
  return lres + rres;
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    if (buf.empty()) {
      break;
    }
    rplc(buf, '{');
    rplc(buf, '}');
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
  }
  llong res = solve2("in", 0, vector<pairll>(4, {1, 4000}));
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
