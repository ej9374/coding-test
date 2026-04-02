#include <bits/stdc++.h>

using namespace std;

int board[50][50];
bool vis[50][50];
int m, n, k;
int t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs(int x, int y){
    vis[x][y] = 1;
    q.push(make_pair(x, y));
    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(){
    cin >> t;

    while (t--){
        cin >> m >> n >> k;

        // 배추 심은 횟수
        for (int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;

            board[y][x] = 1;
        }

        int count = 0; // 지렁이 개수
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 1 && !vis[i][j]){
                    bfs(i, j);
                    count++;
                }
            }
        }
        cout << count << "\n";
        // board, vis 초기화
        for (int i = 0; i < n; i++){
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m,0);
        }
    }
}