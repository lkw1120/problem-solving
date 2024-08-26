#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
vector<pair<int,int>> v;
bool visited[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,R,C,A,B,X,Y,P,ans;
void find() {
    queue<pair<pair<int,int>,int>> q;
    for(auto [a,b]: v) {
        q.push({{a,b},0});
        visited[a][b] = true;
    }
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(arr[x][y]) {
            ans = min(arr[x][y]*d,ans);
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M && !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.push({{dx,dy},d+1});
            }
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>R>>C;
    for(int i=0;i<R;i++) {
        cin>>A>>B>>P;
        arr[A][B] = P;
    }
    for(int i=0;i<C;i++) {
        cin>>X>>Y;
        v.push_back({X,Y});
    }
    ans = INT_MAX;
    find();
    cout<<ans<<"\n";
    return 0;
}