#include<bits/stdc++.h>
using namespace std;
int arr[21][21];
string str;
int T,N,M,ans;
void rotate() {
    int tmp[21][21];
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            tmp[i][j] = arr[N-j+1][i];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}
void game() {
    for(int i=1;i<=N;i++) {
        for(int j=2;j<=N;j++) {
            if(arr[i][j]) {
                for(int k=j-1;k>0;k--) {
                    if(!arr[i][k]) {
                        arr[i][k] = arr[i][k+1];
                        arr[i][k+1] = 0;
                    }
                }
            }
        }
        for(int j=2;j<=N;j++) {
            if(arr[i][j-1] == arr[i][j]) {
                arr[i][j-1]+=arr[i][j];
                arr[i][j] = 0;
            }
        }
        for(int j=2;j<=N;j++) {
            if(arr[i][j]) {
                for(int k=j-1;k>0;k--) {
                    if(!arr[i][k]) {
                        arr[i][k] = arr[i][k+1];
                        arr[i][k+1] = 0;
                    }
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        fill(&arr[0][0],&arr[20][21],0);
        cin>>N>>str;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                cin>>arr[i][j];
            }
        }
        if(str == "up") {
            M = 3;
        }
        else if(str == "right") {
            M = 2;
        }
        else if(str == "down") {
            M = 1;   
        }
        else {
            M = 0;
        }
        for(int i=0;i<M;i++) {
            rotate();
        }
        game();
        if(M) {
            for(int i=M;i<4;i++) {
                rotate();
            }
        }
        cout<<"Case #"<<t<<":"<<"\n";
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}