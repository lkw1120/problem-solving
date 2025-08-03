#include<bits/stdc++.h>
using namespace std;
unordered_set<int> dp[1001];
vector<int> v;
int N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    dp[0].insert(N*2);
    for(int i=1;i<=K;i++) {
        for(auto item: dp[i-1]) {
            if(1 <= item) {
                dp[i].insert(item-1);
            }
            if(item%2 == 0) {
                dp[i].insert(item/2);
            }
        }
    }
    for(auto item: dp[K]) {
        v.push_back(item);
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(auto item: v) {
        double apple = item/2.0;
        cout<<apple<<" ";
    }
    cout<<"\n";
    return 0;
}