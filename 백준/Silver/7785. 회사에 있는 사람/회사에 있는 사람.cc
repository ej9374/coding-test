#include <bits/stdc++.h>

using namespace std;

unordered_set<string> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;

    for (int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;

        if (b == "enter")
            s.insert(a);
        else
            s.erase(a);
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string> ());
    for (auto x : ans)
        cout << x << "\n";
}