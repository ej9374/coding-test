#include <bits/stdc++.h>

using namespace std;
int n, m, k;
bool monitor[41][41];
bool sticker[11][11];

// 90도 회전 하는 함수
void spin(bool sticker[][11], int &w, int &h){

    int temp[11][11] = {0, };
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            temp[j][h - 1 - i] = sticker[i][j];
        }
    }
    // temp 배열에 회전된 결과 저장
    swap(w, h);
    // sticker 배열에 옮기기
    for (int i = 0; i < h; i++){
        for (int j = 0; j <w; j++){
            sticker[i][j] = temp[i][j];
        }
    }
}

// 색칠 칸에 추가하기 // x, y는 좌표 // 스티커의 길이는 w, h
void paint(bool sticker[][11], int x, int y, int w, int h){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(sticker[i][j] == 1) monitor[x + i][y + j] = true;
        }
    }
}

// 색칠 되는지 체크하기
bool check(bool sticker[][11], int x, int y, int w, int h){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (sticker[i][j] == 1){
                // 모니터에 이미 채워져있으면
                if (monitor[x + i][y + j] == true){
                    return false;
                }
            }
        }
    }
    return true;
}

// 0(0) 1(90) 2(180) 3(270) 회전 정하기 // w, h는 가로 세로 길이
bool func(bool sticker[][11], int h, int w){

    for (int rot = 0; rot < 4; rot++){
        for (int i = 1; i <= n - h + 1; i++){
            for (int j = 1; j <= m - w + 1; j++){
                if (check(sticker, i, j, w, h)){
                    paint(sticker, i, j, w, h);
                    return true;
                }
            }
        }
        spin(sticker, w, h);
    }
    return false;
}

int main(){
    cin >> n >> m >> k;

    for (int a = 0; a < k; a++){

        int x, y;
        cin >> x >> y;
        memset(sticker, 0, sizeof(sticker));

        // 스티커 입력 받음
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                cin >> sticker[i][j];
            }
        }

        func(sticker, x, y);
    }

    int count = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (monitor[i][j] == true)
                count++;
        }
    }

    cout << count;
}