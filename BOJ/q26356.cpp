#include<bits/stdc++.h>
using namespace std;
int dX[8] = {-2,-2,2,2,-1,1,-1,1};
int dY[8] = {-1,1,-1,1,-2,-2,2,2};
int T,N,A,B,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>N>>A>>B>>C>>D;
        int arr[21][21] = {0};
        queue<pair<int,int>> q;
        q.push({A,B});
        ans = 0;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == C && y == D) {
                ans = arr[x][y];
                break;
            }
            for(int i=0;i<8;i++) {
                int dx = x+dX[i];
                int dy = y+dY[i];
                if(0 < dx && dx <= N && 0 < dy && dy <= N && !arr[dx][dy]) {
                    arr[dx][dy] = arr[x][y]+1;
                    q.push({dx,dy});
                }
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n\n";
    }
    return 0;
}