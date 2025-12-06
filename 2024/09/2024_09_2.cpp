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

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemB/ProblemB/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string s;
  cin >> s;
  vector<int> v;
  bool file=true;
  int id = 0;
  FORZ(i,s.length()) {
    int cnt = s[i] - '0';
    FORZ(j, cnt) {
      if (file) {
        v.pb(id);
      } else {
        v.pb(-1);
      }
    }
    if (file) id++;
    file = !file;
  }
  id--;
  int n = (int)v.size();
  int i = 0, j = n-1;
  while (id >= 0) {
    if (v[i] >= 0) {
      i++;
      continue;
    }
    if (v[j] != id) {
      j--;
      continue;
    }
    int ii = i, jj = j;
    if (i >= j) {
      i = 0;
      while (jj >= 0 && v[jj] == id) jj--;
      j = jj;
      id--;
      continue;
    }
    while (v[ii] == -1) ii++;
    while (v[jj] == id) jj--;
    int space = ii - i, size = j - jj;
    if (space < size && i < j) {
      i += space;
      continue;
    }
    if (space >= size && i < j) {
      FORZ(k, size) {
        swap(v[i], v[j]);
        i++;
        j--;
      }
      i = 0;
    } else {
      j -= size;
    }
    id--;
  }
  llong res = 0;
//  FORZ(i,n) cout << v[i] << " ";
//  cout << endl;
  FORZ(i,n) {
    if (v[i] < 0) continue;
    res += (llong)v[i] * (llong)i;
  }
  cout << res;
  
  return 0;
}
