#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
bool light[1001][1001];
vector<pair<int,int>> v;
int dX[4] = {-1,1,0,0};
int dY[4] = {0,0,-1,1};
map<char,int> mp = {
    {'U',0},{'D',1},{'L',2},{'R',3}
};
string str;
int R,C,X,Y,ans;
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
    cin>>X>>Y>>str;
    int size = str.size();
    for(int i=0;i<size;i++) {
        if(str[i] != 'W') {
            X+=dX[mp[str[i]]];
            Y+=dY[mp[str[i]]];
        }
        else {
            v.push_back({X,Y});
        }
    }
    queue<pair<int,int>> q;
    for(auto [x,y]: v) {
        q.push({x,y});
        light[x][y] = true;
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= R && 0 < dy && dy <= C && !light[dx][dy] && arr[x][y] == arr[dx][dy]) {
                light[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    light[X][Y] = true;
    for(int i=0;i<4;i++) {
        int dx = X+dX[i];
        int dy = Y+dY[i];
        if(0 < dx && dx <= R && 0 < dy && dy <= C) {
            light[dx][dy] = true;
        }
    }
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if(light[i][j]) {
                cout<<".";
            }
            else {
                cout<<"#";
            }
        }
        cout<<"\n";
    }
    return 0;
}