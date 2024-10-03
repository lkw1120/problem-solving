#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e6+1;
bool isPrime[MAX];
int T,N,A,B;
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
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=2;i<N;i++) {
            if(isPrime[i] && isPrime[2*N-i]) {
                A = i,B = 2*N-i;
                break;
            }
        }
        cout<<A<<" "<<B<<"\n";
    }
    return 0;
}