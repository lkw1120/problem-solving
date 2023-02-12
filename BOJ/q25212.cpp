#include<bits/stdc++.h>
using namespace std;
vector<double> cake;
vector<bool> checked;
int N,C,ans;
void solve(int n) {
    if(n == N) {
        double sum = 0;
        for(int i=0;i<N;i++) {
            if(checked[i]) {
                sum+=cake[i];
            }
        }
        sum*=100;
        if(0 <= sum-99 && sum-101 <= 0) {
            ans++;
        }
        return ;
    }
    checked[n] = true;
    solve(n+1);
    checked[n] = false;
    solve(n+1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cake.resize(N);
    checked.resize(N);
    for(int i=0;i<N;i++) {
        cin>>C;
        cake[i] = 1.0/C;
    }
    ans = 0;
    solve(0);
    cout<<ans<<"\n";
    return 0;
}