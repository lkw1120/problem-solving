#include<bits/stdc++.h>
using namespace std;
char field[12][6];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int cnt, ans;
void dfs(bool check[][6], int y, int x, char p) {
    cnt++;
    for(int i=0;i<4;i++) {
        if(0 <= y+dY[i] && y+dY[i] < 12
        && 0 <= x+dX[i] && x+dX[i] < 6
        && !check[y+dY[i]][x+dX[i]]
        && p == field[y+dY[i]][x+dX[i]]) {
            check[y+dY[i]][x+dX[i]] = true;
            dfs(check,y+dY[i],x+dX[i],p);
        }
    }
}
void puyo(bool check[][6]) {
    for(int i=0;i<12;i++) {
        for(int j=0;j<6;j++) {
            if(check[i][j]) field[i][j] = '.';
        }
    }
}
void move() {
    for(int j=0;j<6;j++) {
        queue<char> q;
        for(int i=0;i<12;i++) {
            if(field[12-1-i][j] != '.') {
                q.push(field[12-1-i][j]);
                field[12-1-i][j] = '.';
            }
        }
        for(int i=0;!q.empty();i++) {
            field[12-1-i][j] = q.front();
            q.pop();
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    for(int i=0;i<12;i++) {
        string str;
        cin>>str;
        for(int j=0;j<6;j++) {
            field[i][j] = str[j];
        }
    }
    ans = 0;
    while(true) {
        bool chain = false;
        for(int i=0;i<12;i++) {
            for(int j=0;j<6;j++) {
                if(field[i][j]!='.') {
                    bool check[12][6] = {};
                    check[i][j] = true;
                    cnt = 0;
                    dfs(check,i,j,field[i][j]);
                    if(cnt >= 4) {
                        puyo(check);
                        chain = true;
                    }
                }
            }
        }
        if(!chain) break;
        move();
        ans++;
    }
    cout<<ans<<"\n";
	return 0;
}