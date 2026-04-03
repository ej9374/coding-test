#include <bits/stdc++.h>

using namespace std;

int d[1001][3]; //이집까지 칠하는데 드는 총 비용
int m[1001][3]; //집 칠하는 비용
int n;
int main(){
    cin >> n;

    // 빨간색 d[k][0] = min(d[k-1][1], d[k-1][2]) + m[k][0]
    // 초록색 d[k][1] = min(d[k-1][0], d[k-1][2]) + m[k][1]
    // 파랑색 d[k][2] = min(d[k-1][0], d[k-1][1]) + m[k][2]

    for (int i = 1; i <= n; i++){
        cin >> m[i][0] >> m[i][1] >> m[i][2];
    }

    // 초기값 설정
    d[0][0] = 0;
    d[1][0] = 0;
    d[2][0] = 0;
    d[1][0] = m[1][0];
    d[1][1] = m[1][1];
    d[1][2] = m[1][2];

    for (int i = 2; i <= n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + m[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + m[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + m[i][2];
    }


    cout << min(min(d[n][0], d[n][1]), d[n][2]);
}