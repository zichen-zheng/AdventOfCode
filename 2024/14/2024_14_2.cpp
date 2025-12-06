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
 In the output file, search a long sequence of "*" to find the
 Christmas tree.
 */

//const int N=11, M=7;
const int N=101, M=103;
vector<pairii> p,v;
int g[N][M] = {0};
int n;

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemG/ProblemG/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif

  string buf;
  while (getline(cin, buf)) {
    FORZ(i,buf.length()) {
      if ((buf[i] < '0' || buf[i] >'9') && buf[i] != '-') {
        buf[i] = ' ';
      }
    }
    stringstream ss(buf);
    int px,py,vx,vy;
    ss >> px >> py >> vx >> vy;
    p.emplace_back(px, py);
    v.emplace_back(vx, vy);
  }
  n = (int)p.size();
  FORZ(q,10000) {
    FORZ(i,n) {
      p[i].first = (p[i].first + v[i].first + N) % N;
      p[i].second = (p[i].second + v[i].second + M) % M;
    }
    FORZ(i,n) {
      g[p[i].first][p[i].second]++;
    }
    cout << "#" << q+1 << ":\n";
    FORZ(j,M) {
      FORZ(i,N) {
        if (g[i][j] == 0) {
          cout << '.';
        } else {
          cout << '*';
        }
      }
      cout << endl;
    }
    cout << "\n\n";
    FORZ(i,N) memclear(g[i]);
  }
  
  return 0;
}
