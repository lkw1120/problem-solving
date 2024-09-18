#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
bool isPrime[MAX];
int N,ans;
void prime() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[2] = true;
    for(int i=2;i*i<MAX;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<MAX;j++) {
                isPrime[i*j] = false;
            }
        }
    }
}
void find(int n, int cnt) {
    if(n <= 3) {
        ans = cnt;
        return ;
    }
    for(int i=2;i<=n/2;i++) {
        if(isPrime[i] && isPrime[n-i]) {
            find(n-i-i,cnt+1);
            break;
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime();
    cin>>N;
    find(N,0);
    cout<<ans<<"\n";
    return 0;
}