#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    do {
        cin >> k;
        
        int s[13];

        for (int i = 0; i < k; i++){
            cin >> s[i];
        }

        int check[13] = {0};
        
        for (int i = 0; i < 6; i++){
            check[i] = 1;
        }

        // next_permutation 
        do {
            for (int i = 0; i < k; i++){
                if (check[i] == 1)
                    cout << s[i] << " ";
            }
            cout << "\n";
        } while(prev_permutation(check, check+k));

        cout << "\n";
    } while(k != 0);
    
}