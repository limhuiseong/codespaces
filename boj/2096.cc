#include <iostream>
#include <algorithm>

#define LEFT 0
#define MID 1
#define RIGHT 2

using namespace std;

int n;
int mx, mn;
int a[3];
int d1[3];
int d2[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        d1[i] = d2[i] = a[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[j];
        }

        int d1_tmp[3];
        d1_tmp[LEFT] = max(d1[LEFT], d1[MID]) + a[LEFT];
        d1_tmp[MID] = *max_element(d1, d1 + 3) + a[MID];
        d1_tmp[RIGHT] = max(d1[MID], d1[RIGHT]) + a[RIGHT];

        int d2_tmp[3];
        d2_tmp[LEFT] = min(d2[LEFT], d2[MID]) + a[LEFT];
        d2_tmp[MID] = *min_element(d2, d2 + 3) + a[MID];
        d2_tmp[RIGHT] = min(d2[MID], d2[RIGHT]) + a[RIGHT];

        for (int i = 0; i < 3; i++) {
            d1[i] = d1_tmp[i];
            d2[i] = d2_tmp[i];
        }
    }

    mx = *max_element(d1, d1 + 3);
    mn = *min_element(d2, d2 + 3);

    cout << mx << ' ' << mn << '\n';
}