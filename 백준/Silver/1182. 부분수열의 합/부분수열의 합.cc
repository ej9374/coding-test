#include <bits/stdc++.h>

// n이 20이하니까 재귀/백트래킹이겟구나
using namespace std;

int n;
int s;
int num[30];
int cnt = 0;

void func(int index, int sum){
    // 마지막 index를 가리킨 순간 종료조건
    if (index == n){
        // 수열 합이 S가 되는 순간 종료조건
        if (sum == s){
            cnt++;
        }
        return;
    }
    func(index + 1, sum); // index 증가시켜 그냥
    func(index + 1, sum + num[index]); // 지금거 합해서 증가시켜
}


int main(){
    cin >> n >> s;
    
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }

    func(0, 0);
    if (s == 0) cnt--;
    cout << cnt;
}