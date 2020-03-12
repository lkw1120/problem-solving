#include<bits/stdc++.h>
#define MAX 50
using namespace std;
int room[MAX][MAX] = {0,};
int dX[4] = {0,-1,0,1};
int dY[4] = {-1,0,1,0};
int R, C, D;
int N, M, ans;
void clean(int r, int c, int d) {
    room[r][c] = 9;
    bool hasSpace = false;
    while(true) {
        hasSpace = false;
        for(int i=4;i>0;i--) {
            if(0 <= r+dX[(d+i)%4] && r+dX[(d+i)%4] < N
            && 0 <= c+dY[(d+i)%4] && c+dY[(d+i)%4] < M
            && room[r+dX[(d+i)%4]][c+dY[(d+i)%4]] == 0) {
                hasSpace = true;
                d=(d+i)%4;
                r+=dX[d];
                c+=dY[d];
                d=(d+3)%4;
                room[r][c] = 9;
                break;
            }
        }
        if(!hasSpace) {
            int rev = (d+3)%4;
            if(room[r+dX[rev]][c+dY[rev]] == 1) {
                return ;
            }
            else {
                r+=dX[rev];
                c+=dY[rev];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    cin>>R>>C>>D;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>room[i][j];
        }
    }
    clean(R, C, D);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(room[i][j] == 9) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}