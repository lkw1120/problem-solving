#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
bool isPrime[MAX];
int T,N,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(isPrime[i]) {
            for(int j=i*2;j<MAX;j+=i) {
                isPrime[j] = false;
            }   
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>T;
    while(T--) {
        cin>>N;
        while(1) {
            bool flag = false;
            for(int i=2;i<N;i++) {
                if(isPrime[i] && isPrime[N/i] && N%i == 0 && i != N/i) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                ans = N;
                break;
            }
            else {
                N++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}