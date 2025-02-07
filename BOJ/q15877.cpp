#include<bits/stdc++.h>
using namespace std;
bool dp[1001][1001];
int A,B;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    dp[0][0] = false;
    for(int i=0;i<=A;i++) {
        for(int j=0;j<=B;j++) {
            dp[i][j] = false;
            if(0 <= i-1 && !dp[i-1][j]) {
                dp[i][j] = true;
            }
            if(0 <= j-1 && !dp[i][j-1]) {
                dp[i][j] = true;
            }
            if(0 <= i-1 && 0 <= j-3 && !dp[i-1][j-3]) {
                dp[i][j] = true;
            }
            if(0 <= i-3 && 0 <= j-1 && !dp[i-3][j-1]) {
                dp[i][j] = true;
            }
        }
    }
    if(dp[A][B]) {
        cout<<"Alice"<<"\n";
    }
    else {
		cout<<"Bob"<<"\n";
    }
    return 0;
}