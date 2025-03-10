#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int board[105][105];
int visited[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int mx[105];

void bfs(int height)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] <= height || visited[i][j]) continue;
            visited[i][j] = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] <= height || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            mx[height]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= 100; i++) {
        bfs(i);
    }

    int mx_element = *max_element(mx, mx + 103);
    if (mx_element == 0)
        cout << 1 << '\n';
    else
        cout << mx_element << '\n';
}