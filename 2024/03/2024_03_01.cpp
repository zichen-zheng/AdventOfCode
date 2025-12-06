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

bool digit(char c) {
  return c >= '0' && c <= '9';
}

int main() {
#ifdef DEBUG
  string filedir = string(getenv("HOME")) + "/Desktop/Contests/coding/ProblemC/ProblemC/";
  freopen(string(filedir + "in.txt").c_str(), "r", stdin);
  freopen(string(filedir + "out.txt").c_str(), "w", stdout);
#endif
  
  string s, buf;
  while (getline(cin, buf)) {
    s.append(buf);
  }
  int n = (int)s.length();
  int res = 0;
  FORZ(i,n-3) {
    if (s[i]=='m' && s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(') {
      int j = i+4;
      int x=0, y=0;
      bool fst=false, snd=false, good=false;
      while (j < n) {
        if (s[j]==',') {
          if (snd || !fst) {
            break;
          }
          snd=true;
        } else if (digit(s[j])) {
          int tmp = s[j]-'0';
          if (snd) {
            y = y*10+tmp;
          } else {
            fst = true;
            x = x*10+tmp;
          }
        } else if (s[j] == ')') {
          good = true;
          break;
        } else {
          break;
        }
        j++;
      }
      if (good && fst && snd) {
//        cout << x << ", " << y << endl;
        res += x*y;
      }
    }
  }
  
  cout<<res;
  
  return 0;
}
