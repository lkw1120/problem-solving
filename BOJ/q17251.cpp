#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+3;
int arr[MAX];
int dp[2][MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    for(int i=1;i<N;i++) {
        dp[0][i] = max(dp[0][i-1],arr[i]);
        dp[1][N-i+1] = max(dp[1][N-i+2],arr[N-i+1]);
    }
    int left,right;
    left = right = 0;
    for(int i=1;i<N;i++) {
        if(dp[0][i] < dp[1][i+1]) {
            right++;
        }
        if(dp[0][i] > dp[1][i+1]) {
            left++;
        }
    }
    if(left == right) {
        cout<<"X"<<"\n";
    }
    else if(left < right) {
        cout<<"B"<<"\n";
    }
    else if(right < left) {
        cout<<"R"<<"\n";
    }
    return 0;
}