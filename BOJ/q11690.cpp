#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull MOD = 1ULL<<32;
const int MAX_N = 1e8+1;
bool isPrime[MAX_N];
ull N,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX_N,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX_N;i++) {
        if(!isPrime[i]) continue;
        for(int j=i*i;j<MAX_N;j+=i) {
            isPrime[j] = false;
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
        ull t = i;
        while(t*i <= N) {
            t*=i;
        }
        ans = (ans*t)%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}