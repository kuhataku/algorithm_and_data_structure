#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int judge(int distance, vector<int>& a) {
  int last_pos = 0;
  for ( int i = 0; i < M; i++ ) {
    int cur_pos = last_pos + 1;
    while(1) {
      if ( (a[(cur_pos)] - a[last_pos]) < distance ) {
        cur_pos++;
      } else {
        break;
      }
      if ( cur_pos >= N ) return 0;
    }
    last_pos = cur_pos;
  }
  return 1;
}

int main(int argc, char* argv[])
{

  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand1000(0,999);
  cin >> N >> M;
  vector<int> a(N);

  for (int i = 0; i < N; i++) {
    a[i] = rand1000(mt);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < N; i++) {
    cout << a[i] << ", ";
  }
  cout << endl;

  int left = 0;
  int right = a[N-1];
  while ( (right - left) > 1 ) {
    int mid = (right + left)/2;
    cout << mid << endl;
    if ( judge(mid, a) ) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;

  return 0;
}




