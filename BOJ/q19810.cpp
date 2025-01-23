#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    switch(N%6) {
        case 1:
        case 5:
            ans = N*(N-1)/2;
            break;
        case 2:
        case 4:
            ans = N*(N-2)/2;
            break;
        case 3:
            ans = N*(3*N-7)/6;
            break;
        default:
            ans = N*(3*N-10)/6;
    }
    cout<<ans<<"\n";
    return 0;
}