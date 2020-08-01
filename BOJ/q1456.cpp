#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 10000001;
bool isPrime[MAX];
ll A,B,N,ans;
void init() {
    fill(isPrime,isPrime+MAX,true);
    for(int i=2;i<MAX;i++) {
        if(!isPrime[i]) continue;
        for(int j=2;j*i<MAX;j++) {
            isPrime[i*j] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin>>A>>B;
    ans = 0;
    for(int i=2;i<MAX;i++) {
        if(isPrime[i]) {
            N = i;
            while(i <= B/N) {
                if(A <= N*i) {
                    ans++;
                }
                N*=i;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}