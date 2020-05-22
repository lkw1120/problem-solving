#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
queue<pair<int,char>> turn;
queue<pair<int,int>> snake;
pair<pair<int,int>,int> head;
int matrix[MAX][MAX] = {0};
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int N,K,L,ans;
void rotate(char cmd) {
    int x,y,d;
    y = head.first.first;
    x = head.first.second;
    d = head.second+4;
    if(cmd == 'L') {
        d--;
        d%=4;
    }
    else if(cmd == 'D') {
        d++;
        d%=4;
    }
    head = {{y,x},d};
}
int dummy(int t) {
    int x,y,d;
    while(true) {
        y = head.first.first;
        x = head.first.second;
        d = head.second;
        y+=dY[d];
        x+=dX[d];
        if(y <= 0 || N < y || x <= 0 || N < x) break;
        head = {{y,x},d};
        snake.push({y,x});
        if(matrix[y][x] != 1) {
            if(matrix[y][x] == 2) break; 
            auto p = snake.front();
            matrix[p.first][p.second] = 0;
            snake.pop();
        }
        matrix[y][x] = 2;
        if(!turn.empty()) {
            if(t == turn.front().first) {
                rotate(turn.front().second);
                turn.pop();
            }
        }
        t++;
    }
    return t;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    cin>>K;
    int x,y;
    for(int i=0;i<K;i++) {
        cin>>y>>x;
        matrix[y][x] = 1;
    }
    cin>>L;
    char cmd;
    for(int i=0;i<L;i++) {
        cin>>x>>cmd;
        turn.push({x,cmd});
    }
    snake.push({1,1});
    head = {{1,1},0};
    matrix[1][1] = 2;
    ans = dummy(1);
    cout<<ans<<"\n";
    return 0;
}