#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int n;
int D[1001];
int main(){
    cin >> n;

    // D[i] = 2*i 크기의 직사각형 채우는 방법의 수

    D[1] = 1;
    D[2] = 2;

    // D[n] = D[n-1] + D[n-2]

    for (int i = 3; i <= n ; i++){
        D[i] = ( D[i-1] + D[i-2] ) % 10007;
    }

    cout << D[n] % 10007;
}