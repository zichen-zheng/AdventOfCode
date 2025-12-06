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

string s;
vector<vector<pair<string, llong>>> boxes;
const int N = 256;

llong getHash(const string& s) {
  llong res = 0;
  FORZ(i,s.length()) {
    res += s[i];
    res *= 17;
    res %= 256;
  }
//  cout << s << " " << res << endl;
  return res;
}

void solve() {
  string label;
  int op = 0;
  llong f = 0;
  FORZ(i,s.length()) {
    if (s[i] == '=') {
      op = 1;
    } else if (s[i] == '-') {
      op = 2;
    } else if (op == 0) {
      label.pb(s[i]);
    } else {
      f = s[i] - '0';
    }
  }
  llong b = getHash(label);
//  cout << label << " " << b << " " << op << " " << f << endl;
  if (op == 1) {
    bool found = false;
    FORZ(i, boxes[b].size()) {
      if (boxes[b][i].first == label) {
        boxes[b][i].second = f;
        found = true;
        break;
      }
    }
    if (!found) {
      boxes[b].emplace_back(label, f);
    }
  } else {
    FORZ(i, boxes[b].size()) {
      if (boxes[b][i].first == label) {
        boxes[b].erase(boxes[b].begin() + i);
      }
    }
  }
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemD/ProblemD/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  string buf;
  getline(cin, buf);
  buf.pb(',');
  llong res = 0;
  boxes.resize(N);
  FORZ(i,buf.size()) {
    if (buf[i] == ',') {
      solve();
      s.clear();
    } else {
      s.pb(buf[i]);
    }
  }
  FORZ(i,N) {
//    cout << i << endl;
    FORZ(j,boxes[i].size()) {
//      cout << "  [" << boxes[i][j].first << " " << boxes[i][j].second << "]\n";
      llong tmp = (i+1) * (j+1) * boxes[i][j].second;
      res += tmp;
    }
  }
  cout << res << endl;
  return 0;
}
