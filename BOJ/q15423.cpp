#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX_N = 101;
const int MAX_M = 2000001;
int arr[MAX_N];
int dp[MAX_M];
int N;
int greedy(int a) {
    int cnt = 0;
    for(int i=N;i>0;--i) {
        if(arr[i] <= a) {
            cnt+=(a/arr[i]);
            a%=arr[i];
        }
        if(a == 0) break;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    fill(dp,dp+MAX_M,INF);
    dp[0] = 0;
    int M = arr[N]+arr[N-1]-1;
    for(int j=1;j<=M;j++) {
        for(int i=1;i<=N && arr[i] <= j;i++) {
            int tmp = dp[j-arr[i]] + 1;
            if(tmp < dp[j]) {
                dp[j] = tmp;
            }
        }
    }
    bool flag = true;
    for (int j=1;j<=M;j++) {
        if(greedy(j) != dp[j]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout<<"canonical"<<"\n";
    }
    else {
        cout<<"non-canonical"<<"\n";
    }
    return 0;
}