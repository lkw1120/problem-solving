#include<bits/stdc++.h>
using namespace std;
const int MAX = 2007;
char arr[MAX][MAX];
int dH[MAX][MAX];
int dW[MAX][MAX];
int H,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>H>>W;
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=W;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=W;j++) {
            if(arr[i][j] == '.') {
                dW[i][j] = dW[i][j-1]+1;
            }
        }
        for(int j=W;j>=1;j--) {
            if(arr[i][j] == '.') {
                dW[i][j] = max(dW[i][j],dW[i][j+1]);
            }
        }
    }
    for(int j=1;j<=W;j++) {
        for(int i=1;i<=H;i++) {
            if(arr[i][j] == '.') {
                dH[i][j] = dH[i-1][j]+1;
            }
        }
        for(int i=H;i>=1;i--) {
            if(arr[i][j] == '.') {
                dH[i][j] = max(dH[i][j],dH[i+1][j]);
            }
        }
    }
    ans = 0;
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=W;j++) {
            if(arr[i][j] == '.') {
                ans = max(ans,dW[i][j]+dH[i][j]-1);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}