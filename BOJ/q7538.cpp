#include<bits/stdc++.h>
using namespace std;
int K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    for(int tc=1;tc<=K;tc++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        ans = ((a+b)%2 == (c+d)%2)? 0: 1;
        cout<<"Scenario #"<<tc<<":\n";
        cout<<ans<<"\n\n";
    }
    return 0;
}