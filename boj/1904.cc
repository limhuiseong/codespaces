#include <iostream>
#define D 15746

using namespace std;

int n;
long long d[1000005][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    d[1][0] = 0;
    d[1][1] = 1;
    
    d[2][0] = 1;
    d[2][1] = 1;

    d[3][0] = d[1][1];
    d[3][1] = d[2][0] + d[2][1];

    d[4][0] = d[2][0] + d[2][1];
    d[4][1] = d[3][0] + d[3][1];

    for (int i = 5; i <= n; i++) {
        d[i][0] = (d[i - 2][0] + d[i - 2][1]) % D;
        d[i][1] = (d[i - 1][0] + d[i - 1][1]) % D;
    }

    cout << (d[n][0] + d[n][1]) % D << '\n';
    
}