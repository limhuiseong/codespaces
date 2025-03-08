#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> a;
vector<pair<int, int>> b;
int ans[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back({tmp, i});
        b.push_back({tmp, i});
    }
    
    sort(b.begin(), b.end());

    int j = 0;
    for (int i = 0; i < n; i++) {
        ans[b[i].second] = j;
        if (b[i].first == b[i + 1].first) continue;
        j++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}