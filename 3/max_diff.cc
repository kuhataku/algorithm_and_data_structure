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
    a[i] = rand100(mt);
    cout << a[i] << endl;
  }

  int max_diff = -1;
  int max_i, max_j;
  for (int i=0; i < N-1; i++) {
    for (int j = i; j < N; j++) {
      int diff = abs(a[i] - a[j]);
      if ( diff > max_diff ) {
        max_i = a[i];
        max_j = a[j];
        max_diff = diff;
      }
    }
  }

  cout << "=====RESULTS====" << endl;
  cout << max_i << "," <<  max_j << endl;

  return 0;
}

