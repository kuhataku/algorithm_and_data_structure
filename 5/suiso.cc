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
  
  int N, M;
  cin >> N;
  cin >> M;

  vector<int> value(N);
  vector<vector<double>> dp(N+1, vector<double>(M+1, 0));
  vector<vector<double>> ave(N+1, vector<double>(N+1, 0.0));

  for ( int i = 0; i < N; i++ ) {
    cin >> value[i];
  }

  for ( int i = 1; i <= N; i++ ) {
    for ( int j = 0; j < i; j++ ) {
      double sum = 0.0;
      for ( int k = j; k < i; k++ ) {
        sum += value[k];
      }
      // cout << "[" << j << "," << i << ")" << "," << sum << endl;
      ave[j][i] = sum/(i-j);
    }
  }

  dp[0][0] = 0.0;

  for ( int i = 0; i <= N; i++ ) {
    for ( int j = 0; j < i; j++ ) {
      for ( int k = 1; k <= M; k++ ) {
        chmax(dp[i][k], dp[j][k-1] + ave[j][i]);
      }
    }
  }

  for ( int n = 0; n <= N; n++ ) {
    cout << n << ": ";
    for ( int m = 0; m <= M; m++ ) {
      cout << dp[n][m] << ",";
    }
    cout << endl;
  }

  cout <<  dp[N][M] << endl;


  return 0;
}
