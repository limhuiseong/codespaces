#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int k;
    cin >> k;
    while (k--) {
        int t;
        cin >> t;
        if (binary_search(a, a + n, t)) cout << "1\n";
        else cout << "0\n";
    }
}