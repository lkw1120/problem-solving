#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[501][501];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,X1,Y1,X2,Y2,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X1>>Y1>>X2>>Y2;
        for(int j=min(X1,X2);j<=max(X1,X2);j++) {
            for(int k=min(Y1,Y2);k<=max(Y1,Y2);k++) {
                arr[j][k] = -1;
            }
        }
    }
    cin>>M;
    for(int i=0;i<M;i++) {
        cin>>X1>>Y1>>X2>>Y2;
        for(int j=min(X1,X2);j<=max(X1,X2);j++) {
            for(int k=min(Y1,Y2);k<=max(Y1,Y2);k++) {
                arr[j][k] = INF;
            }
        }
    }
    deque<pair<pair<int,int>,int>> deq;
    deq.push_back({{0,0},0});
    arr[0][0] = 1;
    ans = -1;
    while(!deq.empty()) {
        int x = deq.front().first.first;
        int y = deq.front().first.second;
        int p = deq.front().second;
        deq.pop_front();
        if(x == 500 && y == 500) {
            ans = p;
            break;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx <= 500 && 0 <= dy && dy <= 500 && arr[dx][dy] <= 0) {
                if(arr[dx][dy] == 0) {
                    deq.push_front({{dx,dy},p});
                }
                else {
                    deq.push_back({{dx,dy},p+1});
                }
                arr[dx][dy] = arr[x][y]+1;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}