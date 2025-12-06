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

bool isgood(const vector<int>& v) {
  int n=(int)v.size();
  if (v[1] == v[0]) {
    return false;
  }
  bool inc = v[1] > v[0];
  bool good=true;
  FOR(i,1,n) {
    int diff=abs(v[i]-v[i-1]);
    if (diff < 1 || diff > 3) {
      good = false;
      break;
    }
    if (((v[i] > v[i-1]) && !inc) || ((v[i] < v[i-1]) && inc)) {
      good = false;
      break;
    }
  }
  return good;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemB/ProblemB/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  
  string buf;
  int res = 0;
  while (getline(cin, buf)) {
    stringstream iss(buf);
    vector<int> v0;
    int x;
    while(iss >> x) {
      v0.pb(x);
    }
    int n=(int)v0.size();
    bool good = isgood(v0);
    if (good) {
      res++;
    } else {
      FORZ(i,n) {
        vector<int> v;
        FORZ(j,n) {
          if (i!=j) v.pb(v0[j]);
        }
        good = isgood(v);
        if (good) {
          break;
        }
      }
      if (good) {
        res++;
      }
    }
  }
  cout << res;
  return 0;
}
