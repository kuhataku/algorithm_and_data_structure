#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int>& a, int left, int right, int key) {
  int pos = (left+right)/2;
  cout << left << ", " << right << ", " << pos << endl;
  if ( a[pos] == key) {
    return pos;
  } else if ( a[pos] < key ) {
    return binary_search(a, pos, right, key);
  } else {
    return binary_search(a, left, pos, key);
  }
}

int main(int argc, char* argv[])
{
  int N;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand100(0,99);
  cin >> N;

  vector<int> a(N);
  vector<int> vals(N);

  for ( int i = 0; i < N; i++ ) {
    a[i] = rand100(mt);
    cout << a[i] << ", ";
  }
  cout << endl;

  vals = a;
  sort(vals.begin(),vals.end());

  for ( int i = 0; i < N; i++ ) {
    cout << vals[i] << ", ";
  }

  cout << endl;

  for ( int i = 0; i < N; i++ ) {
    auto iter = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    cout << iter << ", ";
  }
  cout << endl;
  for ( int i = 0; i < N; i++ ) {
    auto iter = binary_search(vals, 0, vals.size(), a[i]);
    cout << iter << ", " << endl;
  }


  return 0;
}

