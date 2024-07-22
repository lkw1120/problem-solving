#include<bits/stdc++.h>
using namespace std;
char arr[102][102];
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
string str;
int N,M;
bool find(int x, int y, int k) {
    int size = str.size();
    for(int i=0;i<size;i++) {
        int dx = x+dX[k]*i;
        int dy = y+dY[k]*i;
        if(arr[dx][dy] != str[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    int size = str.size();
    if(size <= N || size <= M) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                if(arr[i][j] == str[0]) {
                    for(int k=0;k<8;k++) {
                        int dx = i+dX[k]*(size-1);
                        int dy = j+dY[k]*(size-1);
                        if(0 < dx && dx <= N && 0 < dy && dy <= M) {
                            if(find(i,j,k)) {
                                cout<<1<<"\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<0<<"\n";
    return 0;
}