#include<bits/stdc++.h>
using namespace std;
int T,N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>M;
        cout<<1+(N-M)*M<<"\n";
    }
    return 0;
}