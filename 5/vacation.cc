#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
  if ( b > a ) {
    a = b;
  }
}

int main(int argc, char* argv[])
{
  
  int N;
  cin >> N;
  vector<int> happiness(3);
  vector<vector<int>> dp0(3, vector<int>(N, 0));
  vector<vector<int>> dp(N+1, vector<int>(3, 0));
  for ( int i = 0; i < 3; i++ ) {
    cin >> happiness[i];
  }

  // for(auto i: dp) {
  //   for(auto j: i) {
  //     cout << j;
  //   }
  // }

  for ( int day = 0; day < N; day++ ) {
    for ( int i = 0; i < 3; i++ ) {
      if ( i == 0 ) {
        chmax(dp[day+1][i], dp[day][1] + happiness[i]);
        chmax(dp[day+1][i], dp[day][2] + happiness[i]);
      }
      if ( i == 1 ) {
        chmax(dp[day+1][i], dp[day][0] + happiness[i]);
        chmax(dp[day+1][i], dp[day][2] + happiness[i]);
      }
      if ( i == 2 ) {
        chmax(dp[day+1][i], dp[day][0] + happiness[i]);
        chmax(dp[day+1][i], dp[day][1] + happiness[i]);
      }
    }
  }

  for(auto &&i: dp) {
    for(auto &&j: i) {
      cout << j << ",";
    }
    cout << endl;
  }
  return 0;
}
