#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e7+1;
bool isPrime[MAX];
int dp[MAX];
int T,N,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<MAX;j++) {
                isPrime[i*j] = false;
            }
        }
    }
}
void preset() {
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<MAX;i++){
        if (isPrime[i]) {
            dp[i] = dp[i-2]+1;
        }
        else {
            dp[i] = dp[i-1]+1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    preset();
    cin>>T;
    while(T--) {
        cin>>N;
        cout<<dp[N]<<"\n";
    }
    return 0;
}