#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 2001;
int arr[MAX][MAX];
int dX[6] = {0,1,1,0,-1,-1};
int dY[6] = {1,0,-1,-1,0,1};
int N,X,Y;
void init() {
    fill(&arr[0][0],&arr[MAX-1][MAX],INF);
    queue<pair<int,int>> q;
    q.push({1000,1000});
    arr[1000][1000] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<6;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < MAX && 0 <= dy && dy < MAX && arr[x][y]+1 < arr[dx][dy]) {
                arr[dx][dy] = arr[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>N;
    while(N--) {
        cin>>X>>Y;
        X+=1000;
        Y+=1000;
        cout<<arr[X][Y]<<"\n";
    }
    return 0;
}