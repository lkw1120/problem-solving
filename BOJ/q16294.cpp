#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int dX[6] = {-1,0,1,1,0,-1};
int dY[2][6] = {
    {1,1,1,0,-1,0},
    {0,1,0,-1,-1,-1}
};
vector<int> v;
int H,N,M,ans;
int honey(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    arr[x][y] = '*';
    int sum = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        sum++;
        for(int i=0;i<6;i++) {
            int dx = x+dX[i];
            int dy = y+dY[x%2][i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M && arr[dx][dy] == '.') {
                arr[dx][dy] = '*';
                q.push({dx,dy});
            }
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>H>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    ans = 0;
    if(0 < H) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                if(arr[i][j] == '.') {
                    v.push_back(honey(i,j));
                }
            }
        }
        sort(v.rbegin(),v.rend());
        int sum = 0;
        for(auto item: v) {
            sum+=item;
            ans++;
            if(H <= sum) break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}