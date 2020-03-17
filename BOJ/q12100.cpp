#include<bits/stdc++.h>
#define MAX 20
using namespace std;
int N, ans;
enum Dist {
    TOP = 0, BOTTOM, LEFT, RIGHT, 
};
void moveNumber(int move[][MAX], int dist) {
    for(int i=0;i<N;i++) {
        queue<int> q;
        switch(dist) {
            case TOP: 
                for(int j=0;j<N;j++) {
                    if(move[j][i] != 0) {
                        q.push(move[j][i]);
                        move[j][i] = 0;
                    }
                }
                for(int j=0;!q.empty();j++) {
                    if(q.front() != 0) {
                        move[j][i] = q.front();
                    }
                    q.pop();
                }
                break;
            case BOTTOM:
                for(int j=0;j<N;j++) {
                    if(move[N-1-j][i] != 0) {
                        q.push(move[N-1-j][i]);
                        move[N-1-j][i] = 0;
                    }
                }
                for(int j=0;!q.empty();j++) {
                    move[N-1-j][i] = q.front();
                    q.pop();
                }
                break;
            case LEFT:
                for(int j=0;j<N;j++) {
                    if(move[i][j] != 0) {
                        q.push(move[i][j]);
                        move[i][j] = 0;
                    }
                }
                for(int j=0;!q.empty();j++) {
                    move[i][j] = q.front();
                    q.pop();
                }
                break;
            case RIGHT:
                for(int j=0;j<N;j++) {
                    if(move[i][N-1-j] != 0) {
                        q.push(move[i][N-1-j]);
                        move[i][N-1-j] = 0;
                    }
                }
                for(int j=0;!q.empty();j++) {
                    move[i][N-1-j] = q.front();
                    q.pop();
                }
                break;
        }
    }
}
void sumNumber(int move[][MAX], int dist) {
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<N;j++) {
            switch(dist) {
                case TOP:
                    if(move[i][j] == move[i+1][j]) {
                        move[i][j]*=2;
                        move[i+1][j] = 0;
                    }
                    break;
                case BOTTOM:
                    if(move[N-1-i][j] == move[N-1-(i+1)][j]) {
                        move[N-1-i][j]*=2;
                        move[N-1-(i+1)][j] = 0;
                    }
                    break;
                case LEFT:
                    if(move[j][i] == move[j][i+1]) {
                        move[j][i]*=2;
                        move[j][i+1] = 0;
                    }
                    break;
                case RIGHT:
                    if(move[j][N-1-i] == move[j][N-1-(i+1)]) {
                        move[j][N-1-i]*=2;
                        move[j][N-1-(i+1)] = 0;
                    }
                    break;
            }
        }
    }
}
void game(int board[][MAX], int dist, int depth) {
    int move[MAX][MAX] = {0};
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            move[i][j] = board[i][j];
        }
    }
    moveNumber(move,dist);
    sumNumber(move,dist);
    moveNumber(move,dist);
    if(depth == 5) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                ans = max(ans, move[i][j]);
            }
        }
        return ;
    }
    else {
        for(int i=0;i<4;i++) {
            game(move,i,depth+1);
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    int board[MAX][MAX] = {0};
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>board[i][j];
        }
    }
    ans = 0;
    for(int i=0;i<4;i++) {
        game(board,i,1);
    }
    cout<<ans<<"\n";
	return 0;
}