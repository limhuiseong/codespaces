#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1005];
int d[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    cout << *max_element(d + 1, d + n + 1) << '\n';

    return 0;
}