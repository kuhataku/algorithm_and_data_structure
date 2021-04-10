#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{

  int N, K;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand1000(0,999);
  cin >> N;
  cin >> K;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> ab(N*N);

  for (int i = 0; i < N; i++) {
    a[i] = rand1000(mt);
    b[i] = rand1000(mt);
  }


  // N^2
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ab[i*N+j] = a[i] * a[j];
      cout << ab[i*N+j] << ", ";
    }
  }

  cout << endl;
  // N^2logN
  sort(ab.begin(), ab.end());

  for(auto entry: ab) {
    cout << entry << ", ";
  }
  cout << endl;

  cout << ab[K];

  return 0;
}
