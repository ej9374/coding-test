#include <bits/stdc++.h>

using namespace std;

int n;
long d[91][2];
int main(){

    cin >> n;

    // 지금 k번째자리가 1일때 되는 이친수 개수 d[k][1] = d[k - 1][0]
    // 지금 k번째자리가 0일때 되는 이친수 개수 d[k][0] = d[k - 1][1] + d[k - 1][0]

    d[1][0] = 0;
    d[1][1] = 1;

    for (int i = 2; i <= n; i++){
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0];
    }

    cout << d[n][0] + d[n][1];
}