#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e7+1;
int prime[MAX];
int N,M,ans;
void eratosthenes() {
    fill(prime,prime+MAX,1);
    for(int i=2;i*i<MAX;i++) {
        if(prime[i]) {
            for(int j=2;i*j<MAX;j++) {
                prime[i*j] = 0;
            }
        }   
    }
    for(int i=2;i<MAX;i++) {
        prime[i]+=prime[i-1];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    while(1) {
        cin>>M>>N;
        if(cin.eof()) break;
        ans = prime[N]-prime[M];
        if(prime[M-1] < prime[M]) ans++;
        cout<<ans<<"\n\n";
    }
    return 0;
}