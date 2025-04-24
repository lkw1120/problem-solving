#include<bits/stdc++.h>
using namespace std;
const int MAX = 30001;
bool isPrime[MAX];
int T,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<MAX;j++) {
                isPrime[i*j] = false;    
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    while(1) {
        cin>>T;
        if(!T) break;
        ans = 0;
        for(int i=2;i*3<=T;i++) {
            if(!isPrime[i]) continue;
            for(int j=i;i+j*2<=T;j++) {
                if(!isPrime[j]) continue;
                int k = T-i-j;
                if(k < j) continue;
                if(!isPrime[k]) continue;
                if(i+j <= k) continue;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}