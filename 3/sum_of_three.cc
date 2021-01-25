#include <iostream>
#include <queue>
#include "math.h"
using namespace std;

int main() {
  int EQUAL, MAX;
  cin >> EQUAL >> MAX;
  typedef vector<int> element;
  queue<element> q;

  int remain;
  int count = 0;
  for (int i=0; i < EQUAL; i++) {
    for (int j = i; ((i+j) < EQUAL); j++) {
      remain = EQUAL - i - j;
      if ( (remain >= i) && (remain >=j) ) {
        if (remain <= MAX) {
          vector<int> a(3);
          a[0] = i; 
          a[1] = j; 
          a[2] = remain; 
          q.push(a);
          count++;
        } 
    } 
    cout << i << "," << j << "," << remain << endl;
    }
  }

  cout << "=====RESULTS====" << endl;
  while(!q.empty()) {
    element e = q.front();
    cout << e[0] << "," << e[1] << "," << e[2] << endl;
    q.pop();
  }
  cout << count << endl;

  return 0;
}
