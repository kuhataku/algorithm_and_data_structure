#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{

  int N, K, C;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand1000(1,9);
  cin >> N;
  cin >> K;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> ab(N*N);

  for (int i = 0; i < N; i++) {
    a[i] = rand1000(mt);
    b[i] = rand1000(mt);
  }
  for (int i = 0; i < N; i++) {
    cout << a[i] << ",";
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << b[i] << ",";
  }
  cout << endl;
  // // logN
  // sort(a.begin(), a.end());
  // logN
  sort(b.begin(), b.end());

  C = a[N-1] * b[N-1];

  // for (int i = 0; i < N; i++) {
  //   // 各aに対してbの中から要素を探し掛け算する == candidate
  //   // candidateより小さい値がK個存在しない => bを大きくする
  //   // candidateより小さい値がK個より多い => bを小さくする
  //   int b_right = N;
  //   int b_left = 0;
  //   int b_middle = 0;
  //   long long int candidate;
  //   while ( (b_right - b_left) > 1 ) {
  //     b_middle = (b_right + b_left)/2;
  //     candidate = a[i] * b[b_middle];
  //   }
  // }
  
  long long int ans = 1000000000000;
  long long int right = C;
  int left = 0;
  while ( (right - left) > 1 ) {
    int middle = (right + left)/2;
    int count = 0;
    for (int i = 0; i < N; i++) {
      int upper_num = upper_bound(b.begin(), b.end(), (middle/a[i])) - b.begin();
      count += upper_num;
    }
    if ( count >= K ) {
      if ( ans > middle ) {
        ans = middle;
      }
      right = middle;
    } else {
      left = middle;
    }
    cout << middle << "," << count << endl;
  }
  cout << ans  << endl;
  return 0;
}
