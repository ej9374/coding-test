#include <bits/stdc++.h>

using namespace std;
void func(int n, int start, int end){
    if (n == 1) {
        cout << start << ' ' << end << '\n';
        return;
    }
    func(n - 1, start, 6 - start - end);
    cout << start << ' ' << end << '\n';
    func(n - 1, 6 - start - end, end);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;

    int N;
    cin >> N;

    count = pow(2, N) - 1;
    cout << count << '\n';
    func(N, 1, 3);

}