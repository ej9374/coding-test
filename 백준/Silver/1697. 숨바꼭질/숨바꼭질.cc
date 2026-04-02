#include <bits/stdc++.h>

using namespace std;

int n,k;
int dist[100002];
int main(){
    cin >> n >> k;
    fill(dist, dist+100001,-1);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while(dist[k] == -1){
        int a = q.front();
        q.pop();

        for (int nxt : {a-1, a+1, a*2}){
            if (nxt < 0 || nxt > 100000) continue;
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[a] + 1;
            q.push(nxt);
        }
    }
    cout << dist[k];
}