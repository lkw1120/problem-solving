#include<bits/stdc++.h>
using namespace std;
char arr[11][11];
int N,ans;
void flip(int x, int y) {
    for(int i=1;i<=x;i++) {
        for(int j=1;j<=y;j++) {
            arr[i][j] = arr[i][j] == '1'?'0':'1';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    ans = 0;
    for(int i=N;i>0;i--) {
        for(int j=N;j>0;j--) {
            if(arr[i][j] == '1') {
                flip(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}