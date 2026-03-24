#include <bits/stdc++.h>

using namespace std;

// 백트래킹
// 순서 조합과 같다
// 결국은 총 갖고있는 + - x / 배열에서 5개를 뽑아 순서를 정하는 그런느낌이다!
// 그러면 next_permutation은 아닐까

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int A[15]; // 숫자
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<char> B; // 연산자 저장 배열

    while (a > 0){
        B.push_back('+');
        a--;
    }
    while (b > 0){
        B.push_back('-');
        b--;
    }
    while (c > 0){
        B.push_back('*');
        c--;
    }
    while (d > 0){
        B.push_back('/');
        d--;
    }

    sort(B.begin(), B.end());

    int max = -1000000000;
    int min = 1000000000;
    do {
        vector<char> result; // 최종 선택된 연산자 배열;

        for (int i = 0; i < n - 1; i++){
            result.push_back(B[i]);
        }

        int r = A[0];

        for (int i = 0; i < n - 1; i++){
            char c = result[i];
            int a = r;
            int b = A[i + 1];

            switch (c){
                case '+':
                    r += b;
                    break;
                case '-':
                    r -= b;
                    break;
                case '*':
                    r *= b;
                    break;
                case '/':
                    r /= b;
                    break;
            }
        }

        if (r > max) max = r;
        if (r < min) min = r;

    } while (next_permutation(B.begin(), B.begin()+n-1));

    cout << max << '\n' << min;
}