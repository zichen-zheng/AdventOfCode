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

/**
 * This solution makes the following assumptions on the test case:
 * 1) The map is square (n x n, n is odd)
 * 2) The starting point is at the center
 * 3) There are no blockers along the row and the column where the starting point is
 * 4) There are no blockers along the four edges
 * 5) The furthest points are the four corners, each of which takes n-1 steps to reach from the starting point
 */

vector<string> g;
int n;
const llong GOAL = 26501365;
llong odd, even;
const int D[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

llong count(int si, int sj, llong steps) {
  vector<pairii> v;
  v.emplace_back(si, sj);
  FORZ(k, steps) {
    for (auto p : v) {
      int i = p.first, j = p.second;
      FORZ(x, 4) {
        int ii = i + D[x][0], jj = j + D[x][1];
        if (ii >= 0 && ii < n && jj >= 0 && jj < n && g[ii][jj] != '#') {
          g[ii][jj] = 'O';
        }
      }
    }
    v.clear();
    FORZ(i,n) {
      FORZ(j,n) {
        if (g[i][j] == 'O') {
          v.emplace_back(i, j);
          g[i][j] = '.';
        }
      }
    }
  }
  return v.size();
}

void solve() {
  string buf;
  while (getline(cin, buf)) {
    g.pb(buf);
  }
  n = (int)g.size();
  assert(g[0].size() == n);
  assert(n % 2 == 1);
  FORZ(i,n) FORZ(j, n) if (g[i][j] == 'S') {
    assert(i == n/2 && j == n/2);
    g[i][j] = '.';
    break;
  }
  odd = count(n/2, n/2, n);
  even = count(n/2, n/2, n+1);
  llong res = 0;
  llong rounds = GOAL / n, rem = GOAL % n;
  llong r0 = even, r1 = odd;
  if (GOAL % 2 == 1) swap(r0, r1);
  if (rem > 0) {
    res += (count(0, 0, rem-1) + count(0, n-1, rem-1) + count(n-1, 0, rem-1) + count(n-1, n-1, rem-1)) * rounds;
  }
  res += (count(0, 0, n+rem-1) + count(0, n-1, n+rem-1) + count(n-1, 0, n+rem-1) + count(n-1, n-1, n+rem-1)) * (rounds-1);
  llong tmp = 0;
  FORZ(i, rounds-2) {
    if (i%2 == 0) tmp += r0 * (i+1);
    else tmp += r1 * (i+1);
  }
  res += tmp * 4;
  rounds = (GOAL - n/2) / n;
  rem = (GOAL - n/2) % n;
  if (rem > 0) {
    res += count(0, n/2, rem-1) + count(n/2, n-1, rem-1) + count(n-1, n/2, rem-1) + count(n/2, 0, rem-1);
  }
  res += count(0, n/2, n+rem-1) + count(n/2, n-1, n+rem-1) + count(n-1, n/2, n+rem-1) + count(n/2, 0, n+rem-1);
  res += r0 + (rounds/2)*4*r1 + ((rounds-1)/2)*4*r0;
  cout << res << endl;
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemC/ProblemC/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  solve();
  return 0;
}
