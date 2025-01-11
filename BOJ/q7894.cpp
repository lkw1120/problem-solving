#include<bits/stdc++.h>
using namespace std;
int T;
double N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        ans = 0;
        for(double i=1;i<=N;i++) {
            ans+=log10(i);
        }
        cout<<(int)ans+1<<"\n";
    }
    return 0;
}