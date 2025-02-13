#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
bool dp[MAX];
int T,N;
void preset() {
    for(int i=1;i*i<MAX;i++) {
        dp[i*i] = true;
    }
    for(int i=1;i<MAX;i++) {
        if(!dp[i]) {
            for(int j=1;j*j<=i;j++) {
                if(!dp[i-j*j]) {
                    dp[i] = true;
                    break;
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
    preset();
    while(T--) {
        cin>>N;
        if(dp[N]) {
            cout<<"koosaga"<<"\n";
        }
        else {
            cout<<"cubelover"<<"\n";
        }
    }
    return 0;
}