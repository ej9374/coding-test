#include <bits/stdc++.h>

using namespace std;
int n;
int cnt = 0;

bool isused1[40]; // 열
bool isused2[40]; // 좌측하단 우측상단 대각선
bool isused3[40]; // 좌측상단 우측하단 대각선

// cur 번째 행에 말을 배치할 예정
// 같은 열 -> y좌표가 일치하지 않게 배치
// 대각선 -> x+y가 같은지 / x-y가 같은지
// 열/ 대각선 2개에 해당하는 isused
void queen(int cur){
    if (cur == n){
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++){
        if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) 
            continue;
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[cur - i + n - 1] = 1;
        queen(cur + 1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[cur - i + n - 1] = 0;
    }
}

int main(){
    cin >> n;
    
    queen(0);
    cout << cnt;
}