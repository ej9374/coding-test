#include <bits/stdc++.h>

using namespace std;

int n;
int tri[501][501]; // 삼각형 저장
int d[501][501]; // 현재 위치의 최댓값
int main(){

    cin >> n;
    
    // 입력
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> tri[i][j];
        }
    }

    d[1][1] = tri[1][1];

    // d[k][i] = max(d[k - 1][i - 1], d[k - 1][i]) + tri[k][i]
    
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            d[i][j] = max(d[i - 1][j-1], d[i- 1][j]) + tri[i][j];
        }
    }
    
    int max = 0;
    for (int i = 1; i <= n; i++){
        if (d[n][i] > max)
            max = d[n][i];
    }

    cout << max;
}