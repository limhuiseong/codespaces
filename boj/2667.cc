#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;

bool visited[27][27];
int board[27][27];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int num;
vector<int> extents;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || visited[i][j]) continue;
            num++;
            visited[i][j] = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            int area = 0;
            while (!q.empty()) {
                area++;
                pair<int, int> cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || board[nx][ny] != 1) continue;
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            extents.push_back(area);
        }
    }

    cout << num << '\n';
    sort(extents.begin(), extents.end());
    for (auto i: extents) {
        cout << i << '\n';
    }
}