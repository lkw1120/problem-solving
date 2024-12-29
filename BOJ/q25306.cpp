#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    A--;
    if(A%4 == 1) {
        A = 1;
    }
    else if(A%4 == 2) {
        A++;
    }
    else if(A%4 == 3) {
        A = 0;
    }
    if(B%4 == 1) {
        B = 1;
    }
    else if(B%4 == 2) {
        B++;
    }
    else if(B%4 == 3) {
        B = 0;
    }
    ans = A^B;
    cout<<ans<<"\n";
    return 0;
}