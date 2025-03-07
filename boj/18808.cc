#include <iostream>

using namespace std;

int n, m, k;
int board[42][42];
int stickers[102][12][12];
int sticker_size[102][2];
int sticker_extent[102];

bool stick(int x, int y, int sticker_num, int dir)
{
    int sticker[12][12] = {0,};
    int sticker_x_size;
    int sticker_y_size;

    if (dir == 0) { 
        for (int x = 0; x < sticker_size[sticker_num][0]; x++) {
            for (int y = 0; y < sticker_size[sticker_num][1]; y++) {
                sticker[x][y] = stickers[sticker_num][x][y];
            }
        }
        sticker_x_size = sticker_size[sticker_num][0];
        sticker_y_size = sticker_size[sticker_num][1];
    } 
    else if (dir == 1) { 
        for (int x = 0; x < sticker_size[sticker_num][0]; x++) {
            for (int y = 0; y < sticker_size[sticker_num][1]; y++) {
                sticker[y][sticker_size[sticker_num][0] - 1 - x] = stickers[sticker_num][x][y];
            }
        }
        sticker_x_size = sticker_size[sticker_num][1];
        sticker_y_size = sticker_size[sticker_num][0];
    } 
    else if (dir == 2) { 
        for (int x = 0; x < sticker_size[sticker_num][0]; x++) {
            for (int y = 0; y < sticker_size[sticker_num][1]; y++) {
                sticker[sticker_size[sticker_num][0] - 1 - x][sticker_size[sticker_num][1] - 1 - y] = stickers[sticker_num][x][y];
            }
        }
        sticker_x_size = sticker_size[sticker_num][0];
        sticker_y_size = sticker_size[sticker_num][1];
    } 
    else if (dir == 3) { 
        for (int x = 0; x < sticker_size[sticker_num][0]; x++) {
            for (int y = 0; y < sticker_size[sticker_num][1]; y++) {
                sticker[sticker_size[sticker_num][1] - 1 - y][x] = stickers[sticker_num][x][y];
            }
        }
        sticker_x_size = sticker_size[sticker_num][1];
        sticker_y_size = sticker_size[sticker_num][0];
    }
    

    // OOB
    if (x + sticker_x_size > n || y + sticker_y_size > m) return false;
    // stick
    bool pass = false;
    for (int i = 0; i < sticker_x_size; i++) {
        for (int j = 0; j < sticker_y_size; j++) {
            if (sticker[i][j] == 1 && board[x + i][y + j] == 1) return false;
            if (i == sticker_x_size - 1 && j == sticker_y_size - 1) {
                pass = true;
            }
        }
    }

    if (pass) {
        for (int i = 0; i < sticker_x_size; i++) {
            for (int j = 0; j < sticker_y_size; j++) {
                if (sticker[i][j] == 1)
                    board[x + i][y + j] = sticker[i][j];
            }
        }
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        sticker_size[i][0] = x;
        sticker_size[i][1] = y;

        int tmp = 0;
        for (int xx = 0; xx < x; xx++) {
            for (int yy = 0; yy < y; yy++) {
                cin >> stickers[i][xx][yy];
                if (stickers[i][xx][yy] == 1) tmp++;
            }
        }
        sticker_extent[i] = tmp;
    }

    bool ok = false;
    for (int sticker_num = 0; sticker_num < k; sticker_num++) {
        ok = false;
        for (int dir = 0; dir < 4; dir++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (stick(x, y, sticker_num, dir)) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) ans++;
        }
    }

    cout << ans << '\n';
}