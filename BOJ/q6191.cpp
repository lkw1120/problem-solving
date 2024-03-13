#include<bits/stdc++.h>
using namespace std;
char arr[114][78];
pair<int,int> p[114][78];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>C;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin>>arr[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    arr[1][1] = '*';
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= R && 0 < dy && dy <= C && arr[dx][dy] == '.') {
                arr[dx][dy] = '*';
                p[dx][dy] = {x,y};
                q.push({dx,dy});
            }
        }
    }
    stack<pair<int,int>> st;
    st.push({R,C});
    while(true) {
        int x = st.top().first;
        int y = st.top().second;
        if(x == 1 && y == 1) break;
        st.push(p[x][y]);
    }
    while(!st.empty()) {
        int x = st.top().first;
        int y = st.top().second;
        st.pop();
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}