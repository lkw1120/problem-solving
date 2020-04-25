#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int A[MAX] = {0};
int dp[MAX] = {0};
int pi[MAX] = {0};
int N,p,len;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A[i];
    }
    fill(dp,dp+MAX,1);
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(A[i] > A[j] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                pi[i] = j;
            }
        }
    }
    p = 0;
    len = 0;
    for(int i=0;i<N;i++) {
        if(len < dp[i]) {
            len = dp[i];
            p = i;
        }
    }
    cout<<len<<"\n";
    stack<int> s;
    s.push(A[p]);
    while(--len) {
        p = pi[p];
        s.push(A[p]);
    }
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
    return 0;
}