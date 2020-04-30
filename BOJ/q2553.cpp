#include<bits/stdc++.h>
using namespace std;
long long N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    ans = 1;
    for(int i=1;i<=N;i++) {
        ans*=i;
        ans%=10000000000;
        while(ans%10 == 0) {
            ans/=10;
        }
    }
    cout<<ans%10<<"\n";
    return 0;
}