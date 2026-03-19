#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10]; //8까지입력받으니까
bool isused[10];

// 백트래킹 -> 재귀적으로 구현
void func(int k){ // 현재까지 k개의 수를 선택함
    if (k == m){ //다 선택함
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++){
        if(!isused[i]){ //아직 사용 안됐으면
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    func(0);
}