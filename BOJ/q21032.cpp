#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int odd = 0;
    for(int i=0;i<N;i++) {
        int a;
        cin>>a;
        if(a&1) odd++;
    }
    ans = min(N/2,odd);
    cout<<ans<<"\n";
    return 0;
}