#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int arr[501];
int dp[501];
bool isPrime[MAX];
int N,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(isPrime[i]) {
            for(int j=i*2;j<MAX;j+=i) {
                isPrime[j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        dp[i]+=arr[i]+dp[i-1];
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<=N;j++) {
            int tmp = dp[j]-dp[i];
            if(isPrime[tmp] && isPrime[j-i]) {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}