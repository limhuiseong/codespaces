#include <iostream>
#include <algorithm>

#define D 1000000000

using namespace std;

int n;
long long d[105][15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                d[i][j] = d[i - 1][j + 1] % D;
            }
            else if (j == 9) {
                d[i][j] = d[i - 1][j - 1] % D;
            }
            else {
                d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % D;
            }
        }
    }

    long long s = 0;
    for (int i = 0; i <= 9; i++) {
        // s += d[n][i] % D;
        s = (s + d[n][i]) % D;
    }
    cout << s<< '\n';
}