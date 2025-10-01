#include <bits/stdc++.h>
using namespace std;
int R,C,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C>>K;
    ans = ((R*C)%2 == 0 || K == 1);
    cout<<ans<<"\n";
    return 0;
}