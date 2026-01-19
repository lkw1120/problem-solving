#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000001;
bool isPrime[MAX_N];
int T,M,ans;
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
    cin>>T;
    while(T--) {
        cin>>M;
        int a = M-6;
        while(3 <= a && !isPrime[a]) {
            a--;
        }
        ans = a;
        cout<<ans<<"\n";
    }
    return 0;
}