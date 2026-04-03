#include <bits/stdc++.h>

using namespace std;
int n;
int cnt = 0;
int d[1000001]; //1되는데 걸리는 횟수
int pre[1000001]; // 경로 복원용 최적을 저장하는 배열
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0;
    pre[0] = 0;
    
    // d[k] = min(d[k/3], d[k/2], d[k-1]) + 1

    for (int i = 2; i <= n ;i++){
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;

        if (i % 3 == 0){
            if (d[i/3] < d[i]){
                d[i] = d[i/3] + 1;
                pre[i] = i/3;
            }
        }

        if (i % 2 == 0){
            if (d[i/2] < d[i]){
                d[i] = d[i/2] + 1;
                pre[i] = i/2;
            }
        }
    }
    cout << d[n] << "\n";

    int k = n;

    while (k){
        cout << k << " ";
        k = pre[k];
    }

}