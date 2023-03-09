#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int arr[182][182] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M;
void bfs() {
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(v[i][j] == '1') {
                q.push({{i,j},0});
                arr[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < N && 0 <= dy && dy < M) {
                if(d+1 < arr[dx][dy]) {
                    arr[dx][dy] = d+1;
                    q.push({{dx,dy},d+1});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    fill(&arr[0][0],&arr[181][182],INT_MAX);
    bfs();
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}