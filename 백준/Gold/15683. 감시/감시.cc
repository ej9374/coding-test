#include <bits/stdc++.h>

using namespace std;
int n, m;

int dx[4] = {1, 0, -1, 0}; // 남 동 북 서
int dy[4] = {0, 1, 0, -1};
vector<pair<int,int>> cctv;
int min_square = 67;

int board[8][8]; //최초 입력
bool vis[8][8];

int ans = 100;
void check(int x, int y, int dir){
    dir %= 4;
    while (true){
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) return;
        if (board[x][y] >= 1 && board[x][y] <= 6) continue;
        board[x][y] = 7; 
    }
}

// 백트래킹 -> cctv의 방향을 정함
void func(int index){
    
    if (index == cctv.size()){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }


    int x = cctv[index].first;
    int y = cctv[index].second;

    // 방향 정함
    for (int dir = 0 ; dir < 4; dir++){
        int temp[n][m];
        // 1 현재 보드 저장 후 복사
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                temp[i][j] = board[i][j];
            }
        }

        // 2 현재 방향에 맞게 감시구역 7로 채움
        int num = board[x][y];

        if (num == 1){
            check(x, y, dir);
        } else if (num ==2){
            check(x, y, dir);
            check(x, y, dir + 2);
        } else if (num == 3){
            check(x, y, dir);
            check(x, y, dir + 1);
        } else if (num == 4){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2); 
        } else if (num == 5){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }
        // 3 다음 cctv 정하러감
        func(index + 1);

        // 4 다시 돌아왔을때 board 되돌림
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                board[i][j] = temp[i][j];
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int answer = 0; // 사각 지대 최소 크기
    // board[0][0]부터 마지막 칸까지 -1로 채우기
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6)
                cctv.push_back({i,j});
            if(board[i][j] == 0) answer++;
        }
    }
    func(0);
    cout << ans;
}