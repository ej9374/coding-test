#include <bits/stdc++.h>

using namespace std;

// (r,c)를 방문하는 순서를 반환하는 함수
int func(int n, int r, int c){
    // base condition n = 0;
    if (n == 0){
        return 0;
    }
    int half = pow(2, n-1);
    // (r,c)의 위치가 어디냐에 따라
    if (r < half && c < half) return func(n-1, r, c);
    if (r < half && c >= half) return half*half + func(n-1, r, c-half);
    if (r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
    return 3*half*half + func(n-1, r-half, c-half);
}  

int main(){
    // (r,c)의 위치가 어디냐에 따라
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;

    cout << func(N, r, c);
}