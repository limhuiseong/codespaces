#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[505][505];
int dp[505][505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    dp[1][1] = a[1][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
            else if (j == n) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
            }
        }
    }

    cout << *max_element(dp[n] + 1, dp[n] + n + 1) << '\n';
}