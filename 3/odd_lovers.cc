#include <iostream>
#include <random>
#include "math.h"
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand100(0,999);

  cout << "=====NUMS====" << endl;
  for (int i = 0; i < N; i++) {
    a[i] = rand100(mt)*128;
    cout << a[i] << endl;
  }

  int count = 0;
  int all_even = 1;
  while(1) {
    for (int i=0; i < N; i++) {
      if ( (a[i] & 0x1) == 1 ) {
        all_even = 0;
      }
    }
    if ( all_even ) {
      for (int i=0; i < N; i++) {
        a[i] >>= 1;
      }
      count++;
    } else {
      break;
    }
  }

  cout << "=====RESULTS====" << endl;
  for (int i = 0; i < N; i++) {
    cout << a[i] << endl;
  }
  cout << "COUNT:" << count << endl;

  return 0;
}

