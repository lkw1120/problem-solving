#include<bits/stdc++.h>
using namespace std;
char arr[21][21];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,H,W,ans;
void find(int x, int y) {
    queue<pair<int,int>> q;
    q.push({1,1});
    arr[1][1] = 'M';
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= H && 0 < dy && dy <= W && arr[dx][dy] == 'O') {
                arr[dx][dy] = 'M';
                q.push({dx,dy});
            }
        }
    }
}
void print() {
    for(int i=0;i<=H*2;i++) {
        if(i%2) {
            for(int j=0;j<=W*4;j++) {
                if(j%2) {
                    cout<<" ";
                }
                else {
                    if(j%4) {
                        if(arr[i/2+1][j/4+1] == 'O') {
                            cout<<" ";
                        }
                        else {
                            cout<<arr[i/2+1][j/4+1];
                        }
                    }
                    else {
                        cout<<"|";
                    }
                }
            }
        }
        else {
            for(int j=0;j<=W*4;j++) {
                if(j%4) {
                    cout<<"-";
                }
                else {
                    cout<<"+";
                }
            }
        }
        cout<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>H>>W;
        for(int i=1;i<=H;i++) {
            for(int j=1;j<=W;j++) {
                cin>>arr[i][j];
            }
        }
        if(arr[1][1] == 'O') {
            find(1,1);
        }
        
        cout<<"Case: "<<t<<"\n";
        print();
        if(arr[H][W] == 'M') {
            cout<<"Minions can cross the room"<<"\n";
        }
        else {
            cout<<"Minions cannot cross the room"<<"\n";
        }
    }
    return 0;
}