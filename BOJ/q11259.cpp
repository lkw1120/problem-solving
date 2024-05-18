#include<bits/stdc++.h>
using namespace std;
char arr[11][11];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
map<string,int> mp;
int R,C,L;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>C>>L;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin>>arr[i][j];
        }
    }
    queue<pair<pair<int,int>,string>> q;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if(arr[i][j] != 'a' && arr[i][j] != 'c' && arr[i][j] != 'm') {
                string str = "";
                str+=arr[i][j];
                q.push({{i,j},str});
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        string str = q.front().second;
        q.pop();
        int size = str.size();
        if(size == L) {
            mp[str]++;
        }
        else {
            for(int i=0;i<4;i++) {
                int dx = x+dX[i];
                int dy = y+dY[i];
                if(0 < dx && dx <= R && 0 < dy && dy <= C) {
                    if(arr[dx][dy] != 'a' && arr[dx][dy] != 'c' && arr[dx][dy] != 'm') {
                        q.push({{dx,dy},str+arr[dx][dy]});
                    }
                }
            }
        }
    }
    int cnt,uniq;
    cnt = 0;
    uniq = mp.size();
    for(auto item: mp) {
        cnt+=item.second;
    }
    cout<<cnt<<"\n";
    cout<<uniq<<"\n";
    return 0;
}