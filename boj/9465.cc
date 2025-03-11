#include <iostream>
#include <algorithm>

using namespace std;

int t;
int a[100005][2];
int d[100005][2];

void solve()
{
    int n;
    cin >> n;

    
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        d[i][0] = 0; d[i][1] = 0;
    }

    d[0][0] = a[0][0];
    d[0][1] = a[0][1];

    d[1][0] = a[0][1] + a[1][0];
    d[1][1] = a[0][0] + a[1][1];

    for (int i = 2; i < n; i++) {
        d[i][0] = max(d[i - 1][1], d[i - 2][1]) + a[i][0];
        d[i][1] = max(d[i - 1][0], d[i - 2][0]) + a[i][1];
    }

    int mx1 = max(d[n - 1][0], d[n - 1][1]);
    int mx2 = max(d[n - 2][0], d[n - 2][1]);

    cout << max(mx1, mx2) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
}