#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int A,B,V,ans;
    cin>>A>>B>>V;
    ans = (V-B-1)/(A-B)+1;
    cout<<ans<<"\n";
} 