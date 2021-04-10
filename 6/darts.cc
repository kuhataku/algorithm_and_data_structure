#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{

  int N, M;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand1000(0,999);
  cin >> N >> M;

  vector<int> a(N);
  vector<int> aa(N*N);

  for (int i = 0; i < N; i++) {
    a[i] = rand1000(mt);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      aa[i * N + j] = a[i] + a[j];
    }
  }

  sort(aa.begin(), aa.end());

  for (int i = 0; i < N*N; i++) {
    cout << aa[i] << ", ";
  }
  cout << endl;

  long long int ans = 0;
  for (int i = 0; i < N*N; i++) {
    if ( aa[i] > M ) {
      break;
    }
    auto it = upper_bound(aa.begin(), aa.end(), (M-aa[i]));
    if ( it == aa.begin() ) continue;
    long long int sum = aa[i] + *(it-1);
    if ( ans < sum) {
      ans = sum;
    }
  }

  cout << ans << endl;

  return 0;
}



