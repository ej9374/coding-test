#include <bits/stdc++.h>

using namespace std;

char a[5][5];

// bfs 준비
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int answer = 0;

bool isInSave(vector<pair<int,int>> v, int x, int y){
    bool isAnswer = false;
    for (int i = 0; i < v.size(); i++){
        if (v[i].first == x && v[i].second == y)
            isAnswer = true;
    }
    return isAnswer;
}

// bfs 일거같은 느낌?
// 25명중 7명을 뽑는 거니까 7명 뽑는 조합 전체 가져오고 -> next_permutation
// 그중에서 이어져있는 경우만 날리는 방식으로 가야되나
// 그중 또 솜 > 연 인거만 남기고
int main(){
    // 일단 입력 받음
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }
    int mask[25];
    for (int i = 0 ; i < 7; i++){
        mask[i] = 0;
    }
    for (int i = 7; i < 25; i++){
        mask[i] = 1;
    }


    do {
        vector<pair<int,int>> save;
        // 25개중 7개 뽑음
        for (int i = 0; i < 25; i++){
            if (mask[i] == 0)
                save.push_back(make_pair(i/5, i%5));
        }

        bool isAnswer = true;

        // bfs 검증
        // queue 필요한건 알겟는데 안 이어져있다는걸 어케알아?
        // 한 점에서 시작해서 탐색하는데 그게 save에 속하는애면 queue에 넣자 아님말고
        int visit = 0; // 방문한 수
        bool visited[5][5] = {0};
        queue<pair<int,int>> q;
        q.push(save[0]);
        visited[save[0].first][save[0].second] = 1;
        while (!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            visit++;

            for (int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || visited[nx][ny] || !isInSave(save, nx, ny))
                    continue;
                if (!visited[nx][ny]){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                }
            }
        }

        if (visit != 7)
            continue;
        // 솜 > 연 인지 검증
        int som = 0;
        int yeon = 0;
        for (int i = 0; i < 7; i++){
            if (a[save[i].first][save[i].second] == 'S')
                som++;
            else 
                yeon++;
        }
        if (yeon > som)
            isAnswer = false;

        if (isAnswer == true)
            answer++;
        else
            continue;

    } while(next_permutation(mask, mask+25));

    cout << answer;
}