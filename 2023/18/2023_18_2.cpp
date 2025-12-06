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

// Shoelace formula: https://rosettacode.org/wiki/Shoelace_formula_for_polygonal_area
void solve() {
  string buf;
  llong ci = 0, cj = 0, perim = 0;
  vector<pairll> v;
  while (getline(cin, buf)) {
    stringstream ss(buf);
    char _dir;
    int _len;
    string s;
    ss >> _dir >> _len >> s;
    llong len;
    stringstream sslen;
    sslen << hex << s.substr(2, 5);
    sslen >> len;
    int dir = s[7] - '0';
    llong di = 0, dj = 0;
    if (dir == 0) {
      dj = 1;
    } else if (dir == 2) {
      dj = -1;
    } else if (dir == 3) {
      di = -1;
    } else {
      di = 1;
    }
//    cout << dir << ", " << len << endl;
    perim += len;
    ci += len * di;
    cj += len * dj;
    v.emplace_back(ci, cj);
//    cout << ci << " " << cj << endl;
  }
  llong suma = 0, sumb = 0;
  v.emplace_back(v[0]);
  FORZ(i,v.size()-1) {
    suma += v[i].first * v[i+1].second;
    sumb += v[i].second * v[i+1].first;
  }
  llong res = (abs(suma - sumb) + perim) / 2 + 1;
  cout << res << endl;
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
