#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e7+1;
vector<int> v;
bool dp[MAX];
int T,M,ans;
bool find(int n) {
    fill(dp,dp+MAX,false);
    v.clear();
    for(int i=1;i*i<=n;i++) {
        if(n%i == 0) {
            if(i < n) {
                v.push_back(i);
            }
            int tmp = n/i;
            if(tmp != i && tmp < n) {
                v.push_back(tmp);
            }
        }
    }
    dp[0] = true;
    for(int d: v) {
        for(int i=n;i>=d;i--) {
            if(dp[i-d]) {
                dp[i] = true;
            }
        }
    }
    return dp[n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>M;
        if(find(M)) {
            cout<<"Semiperfect"<<"\n";
        }
        else {
            cout<<"NOT Semiperfect"<<"\n";
        }
    }
    return 0;
}
