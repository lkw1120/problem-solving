#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 20001;
bool isPrime[MAX_N];
int T,M,N;
string ans;
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
    cin>>T;
    while (T--) {
        cin>>M>>N;
        int tmp = M*M+N*N;
        if(M == 0 || N == 0) {
            int k = abs(M)+abs(N);
            ans = (k > 1 && isPrime[k] && (k%4 == 3))? "P": "C";
        }
        else {
            ans = isPrime[tmp]? "P": "C";
        }
        cout<<ans<<"\n";
    }
    return 0;
}