#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+7;
vector<int> v;
int arr[MAX];
int dp[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];	
    }
    for(int i=N;i>0;i--) {
        int sum = arr[i];
        for(int j=i*2;j<=N;j+=i) {
            sum+=dp[j];	
        }
        dp[i] = sum%2;
    }
    for(int i=1;i<=N;i++) {
        if(dp[i]) {
            v.push_back(i);
        }
    }
    cout<<v.size()<<"\n";
    if(!v.empty()) {
        for(auto item: v) {
            cout<<item<<" ";	
        }
        cout<<"\n";
    }
    return 0;
}