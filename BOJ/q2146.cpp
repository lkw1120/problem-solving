#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
bool visited[101][101];
int N,ans;
int find(int x, int y, int k) {
    fill(&visited[0][0],&visited[100][101],false);
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(arr[x][y] != k && arr[x][y] != 0) {
            return d-1;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[dx][dy] != k && !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.push({{dx,dy},d+1});
            }
        }
    }
    return INT_MAX;
}
void island(int x, int y, int k) {
    queue<pair<int,int>> q;
    q.push({x,y});
    arr[x][y] = k;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[dx][dy] == 1) {
                arr[dx][dy] = k;
                q.push({dx,dy});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    if(1 < N) {
        int k = 2;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(arr[i][j] == 1) {
                    island(i,j,k);
                    k++;
                }
            }
        }
        ans = INT_MAX;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(arr[i][j]) {
                    bool flag = false;
                    for(int k=0;k<4;k++) {
                        int dx = i+dX[k];
                        int dy = j+dY[k];
                        if(0 < dx && dx <= N && 0 < dy && dy <= N && !arr[dx][dy]) {
                            flag = true;
                        }
                    }
                    if(flag) {
                        ans = min(find(i,j,arr[i][j]),ans);
                    }
                }
            }
        }
    }
    else {
        ans = 0;
    }
    cout<<ans<<"\n";
    return 0;
}