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
vector<llong> nums;

bool next(string& tgt) {
  FORZ(i,s.size()) {
    if (s[i] == '?') {
      if (tgt[i] == '.') {
        tgt[i] = '#';
        return true;
      } else {
        tgt[i] = '.';
      }
    }
  }
  return false;
}

bool check(const string& tgt) {
  int j = 0;
  string _s(tgt);
  _s.pb('.');
  char prev = '.';
  llong cnt = 0;
  FORZ(i,_s.size()) {
    if (_s[i] == '.' && cnt > 0) {
      if (j >= nums.size()) {
        return false;
      }
      if (nums[j++] != cnt) {
        return false;
      }
      cnt = 0;
    } else if (_s[i] == '#') {
      cnt++;
    }
    prev = _s[i];
  }
  return j == nums.size();
}

void solve() {
  string buf;
  llong res = 0;
  while (getline(cin, buf)) {
    FORZ(i,buf.size()) if (buf[i] == ',') buf[i] = ' ';
    stringstream ss(buf);
    ss >> s;
    llong num;
    nums.clear();
    while (ss >> num) {
      nums.pb(num);
    }
    string tgt(s);
    FORZ(i,tgt.size()) {
      if (tgt[i] == '?') {
        tgt[i] = '.';
      }
    }
    llong cnt = 0;
    do {
      bool good = check(tgt);
//      cout << tgt << " " << good << endl;
      if (good) {
        cnt++;
      }
    } while (next(tgt));
//    cout << cnt << endl;
    res += cnt;
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
