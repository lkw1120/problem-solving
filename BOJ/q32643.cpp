#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 5e6+1;
bool isPrime[MAX_N];
int prefix[MAX_N];
int N,M,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX_N,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=0;i*i<MAX_N;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<MAX_N;j++) {
                isPrime[i*j] = false;    
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes();
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        prefix[i] = prefix[i-1]+(isPrime[i]? 1: 0);
    }
    while(M--) {
        int a,b;
        cin>>a>>b;
        ans = prefix[b]-prefix[a-1];
        if(a <= 1 && 1 <= b) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}