#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+1;
bool isPrime[MAX];
int arr[1001][1001];
int dp[1001][1001];
int N,ans;
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            int tmp = stoi(to_string(i)+to_string(j));
            arr[i][j] = isPrime[tmp]? 1:0;
        }
    }
    for(int i=2;i<=N;i++) {
        dp[1][i] = dp[1][i-1]+arr[1][i];
        dp[i][1] = dp[i-1][1]+arr[i][1];
    }
    for(int i=2;i<=N;i++) {
        for(int j=2;j<=N;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+arr[i][j];
        }
    }
    ans = dp[N][N];
    cout<<ans<<"\n";
    return 0;
}