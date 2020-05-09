#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000;
const int P = (MOD/10)*15;
int fibo[P] = {0,1};
long long N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=2;i<P;i++) {
        fibo[i] = fibo[i-1]+fibo[i-2];
        fibo[i]%=MOD;
    }
    ans = fibo[N%P];
    cout<<ans<<"\n";
    return 0;
}