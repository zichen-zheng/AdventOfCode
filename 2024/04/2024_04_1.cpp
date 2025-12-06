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

const string WORD="XMAS";
const int inc[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemD/ProblemD/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  
  string buf;
  vector<string> v;
  while (getline(cin, buf)) {
    v.pb(buf);
  }
  int n = (int)v.size();
  int m = (int)v[0].size();
  int res=0;
  FORZ(i,n) {
    FORZ(j,m) {
      FORZ(k,8) {
        bool good=true;
        int ii=i;
        int jj=j;
        FORZ(p,4) {
          if (ii < 0 || ii >= n || jj < 0 || jj >= m || v[ii][jj] != WORD[p]) {
            good = false;
            break;
          }
          ii += inc[k][0];
          jj += inc[k][1];
        }
        if (good) res++;
      }
    }
  }
  
  cout << res;
  
  return 0;
}
