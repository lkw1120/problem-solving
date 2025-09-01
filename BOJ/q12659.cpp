#include<bits/stdc++.h>
using namespace std;
const string STR = "welcome to code jam";
const int SIZE = 19;
string str;
int dp[SIZE+1];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    getline(cin,str);
    for(int tc=1;tc<=N;tc++) {
        getline(cin,str);
        fill(dp,dp+SIZE+1,0);
        dp[0] = 1;
        for(char ch: str) {
            for(int j=SIZE;j>=1;j--) {
                if(ch == STR[j-1]) {
                    dp[j]+=dp[j-1];
                    dp[j]%=10000;
                }
            }
        }
        ans = dp[SIZE];
        cout<<"Case #"<<tc<<": ";
        cout<<setw(4)<<setfill('0')<<ans<<"\n";
    }
    return 0;
}