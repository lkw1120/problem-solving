#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
ll dp[300];
ll P,ans;
void eratosthenes() {
    bool isPrime[P+1];
    fill(isPrime,isPrime+P+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=P;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<=P;j++) {
                isPrime[i*j] = false;
            }
        }
    }
    for(int i=2;i<=P;i++) {
        if(isPrime[i]) v.push_back(i);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>P;
    eratosthenes();
    int size = v.size();
    dp[0] = 1;
    for(int i=1;i<size;i++) {
        for(int j=i-1;j>=0;j--) {
            if(14 < v[i]-v[j]) break;
            dp[i]+=dp[j];
        }
    }
    ans = dp[size-1];
    cout<<ans<<"\n";
    return 0;
}