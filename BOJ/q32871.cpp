#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>M;
        if(1 < min(N,M) && N%2 == M%2) {
            cout<<"NO"<<"\n";
        }
        else {
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}