#include<bits/stdc++.h>
using namespace std;
int arr[52][52] = {0};
bool visited[52][52][4] = {false};
int dX[4] = {1,0,-1,0};
int dY[4] = {0,-1,0,1};
int T,N,R,X,Y,U,V;
void solve(int x, int y, int d) {
    int dx = x+dX[d];
    int dy = y+dY[d];
    if(dx == 0 || dy == 0 || dx == N+1 || dy == N+1) {
        X = dx,Y = dy;
    }
    if(0 <= dx && dx <= N+1 && 0 <= dy && dy <= N+1 && !visited[dx][dy][d]) {
        visited[dx][dy][d] = true;
        if(arr[dx][dy]) {
            solve(dx,dy,(d+1)%4);
        }
        else {
            solve(dx,dy,d);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        fill(&arr[0][0],&arr[51][52],0);
        fill(&visited[0][0][0],&visited[51][51][4],false);
        cin>>N>>R;
        for(int i=0;i<R;i++) {
            cin>>X>>Y;
            arr[X][Y] = 1;
        }
        cin>>U>>V;
        X = Y = 0;
        if(U == 0) {
            solve(U,V,0);
        }
        else if(V == 0) {
            solve(U,V,3);
        }
        else if(U == N+1) {
            solve(U,V,2);
        }
        else if(V == N+1) {
            solve(U,V,1);
        }
        cout<<X<<" "<<Y<<"\n";
    }
    return 0;
}