#include<bits/stdc++.h>
using namespace std;
int dp[201][201];
string str1,str2;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        cin>>str1>>str2;
        if(cin.eof()) break;
        fill(&dp[0][0],&dp[200][201],0);
        int size1,size2;
        size1 = str1.size();
        size2 = str2.size();
        for(int i=1;i<=size1;i++) {
            for(int j=1;j<=size2;j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        ans = 0;
        for(int j=1;j<=size2;j++) {
            ans = max(ans,dp[size1][j]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}