#include <iostream>

using namespace std;

int N;
int kim, lim;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> kim >> lim;

    while (true) {
        ans++;
        int min_value = min(kim, lim);
        int max_value = max(kim, lim);
        if (min_value % 2 == 1 && max_value % 2 == 0)
            if (max_value - min_value == 1)
                break;
        kim = kim % 2 == 0 ? kim / 2 : (kim + 1) / 2;
        lim = lim % 2 == 0 ? lim / 2 : (lim + 1) / 2;
    }

    cout << ans << '\n';
}