#include <bits/stdc++.h>

using namespace std;
int d[10001][3]; // 현재 몇번째 연속 마신건지 + 총마신 양
int amount[100001];
int n;
int main(){

    cin >> n;

    // d[k][0] = max(d[k-1][0], d[k-1][1], d[k-1][2])
    // d[k][1] = max(d[k-2][2], d[k-2][1], d[k-2][0]) + amount[k]
    // d[k][2] = d[k-1][1] + amount[k]

    for (int i = 1; i <= n; i++){
        cin >> amount[i];
    }

    d[1][0] = 0;
    d[1][1] = amount[1];
    d[1][2] = 0;
    d[2][0] = amount[1];
    d[2][1] = amount[2];
    d[2][2] = d[1][1] + amount[2];

    for (int i = 3; i <= n; i++){
        d[i][0] = max(d[i-1][0], max(d[i-1][1],d[i-1][2]));
        d[i][1] = max(d[i-2][2], max(d[i-2][1], d[i-2][0])) + amount[i];
        d[i][2] = d[i-1][1] + amount[i];
    }

    int max = 0;
    for (int i = 1; i <=n ; i++){
        for (int j =1; j <=2; j++){
            if (d[i][j] > max)
                max = d[i][j];
        }
    }

    cout << max;
}