#include<bits/stdc++.h>
using namespace std;
const int MAX =5e6+1;
bool prime[MAX];
int N,B,S;
void eratosthenes() {
    fill(prime,prime+MAX,true);
    prime[0] = prime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(prime[i]) {
            for(int j=2;i*j<MAX;j++) {
                prime[i*j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>N;
    if(N == 1) {
        cout<<1<<" "<<0<<"\n";
    }
    else {
        int p,x;
        p = x = 0;
        int prev = -1;
        for(int i=2;i<=N;i++) {
            if(prime[i]) {
                p++;
                if(prev == -1 || i != prev + 1){
                    x++;
                }
                prev = i;
            }
        }
        B = (N-p)-x;
        S = p+x;
        cout<<B<<" "<<S<<"\n";
    }
    return 0;
}
