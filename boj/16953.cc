#include <iostream>

using namespace std;

long long a, b;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    while (1) {
        if (a == b) break;

        if (b % 2 == 0) {
            b /= 2;
            ans++;
            continue;
        }
        if (b % 10 != 1) {
            ans = -1;
            break;
        }
        if (b < a) {
            ans = -1;
            break;
        }

        b /= 10;
        ans++;
    }

    if (ans == -1) cout << "-1\n";
    else cout << ans + 1 << '\n';


}