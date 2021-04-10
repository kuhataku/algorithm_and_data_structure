#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{

  int N;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand100(0,99);
  cin >> N;

  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N);

  for (int i = 0; i < N; i++) {
    a[i] = rand100(mt);
    b[i] = rand100(mt);
    c[i] = rand100(mt);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  for (int i = 0; i < N; i++) {
    cout << a[i] << ", ";
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << b[i] << ", ";
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << c[i] << ", ";
  }
  cout << endl;

  for (int i = 0; i < N; i++) {
    auto a_num = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    auto c_num = c.end() - lower_bound(c.begin(), c.end(), b[i]);
    cout << a_num << ", " << c_num << endl;
  }
  return 0;
}


