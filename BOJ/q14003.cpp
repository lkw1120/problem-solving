#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int A[MAX] = {0};
int dp[MAX] = {0};
vector<int> ans;
int N,M;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
    ans.push_back(A[1]);
    for(int i=2;i<=N;i++) {
        if(ans[M] < A[i]) {
            ans.push_back(A[i]);
            M++;
            dp[i] = M;
        }
        else {
            int idx = lower_bound(ans.begin(),ans.end(),A[i])-ans.begin();
            ans[idx] = A[i];
            dp[i] = idx;
        }
    }
    cout<<M+1<<"\n";
    stack<int> s;
    for(int i=N;i>0;i--) {
        if(dp[i] == M) {
            s.push(A[i]);
            M--;
        }
    }
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
	return 0;
}