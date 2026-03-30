#include <bits/stdc++.h>

using namespace std;

int n, m;

// map을 사용해서 삽입
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    map<string, int> poketmonMap; // 문자나올때 숫자 맞추는법
    string poketmonArr[n+1]; // 숫자나올때 문자 맞추는법  
      
    // 입력 받음
    for (int i = 1; i <= n; i++){
        string a;
        cin >> a;
        poketmonMap.insert({a, i});
        poketmonArr[i] = a;
    }

    // 포켓몬 찾는 거
    for (int i = 0; i < m; i++){
        string input;

        cin >> input;

        // 입력값이 숫자면
        if (isdigit(input[0])){
            int num = stoi(input);

            cout << poketmonArr[num] << "\n";
        } 
        // 입력값이 문자면
        else {
            cout << poketmonMap[input] << "\n";
        }
    }

}