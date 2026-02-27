#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 987654321;
const int MAX_N = 1e6+1;
bool isPrime[MAX_N];
ll N,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX_N,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX_N;i++) {
        if(isPrime[i]) {
            for(int j=i*i;j<MAX_N;j+=i) {
                isPrime[j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes();
    cin>>N;
    ans = 1;
    for(int i=2;i<=N;i++) {
        if(!isPrime[i]) continue;
        ll p = i;
        while(p <= N/i) {
            p*=i;
        }
        ans = (ans*(p%MOD))%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}