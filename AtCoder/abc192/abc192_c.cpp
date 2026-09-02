#include<bits/stdc++.h>
using namespace std;
int N,K,ans;
int solve(int n) {
    string str = to_string(n);
    sort(str.begin(),str.end());
    int g2 = stoi(str);
    reverse(str.begin(),str.end());
    int g1 = stoi(str);
    return (g1-g2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<K;i++) {
        N = solve(N);
    }
    ans = N;
    cout<<ans<<"\n";
    return 0;
}