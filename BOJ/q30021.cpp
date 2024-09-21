#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    if(N == 2) {
        cout<<"NO"<<"\n";
    }
    else {
        cout<<"YES"<<"\n";
        if(N == 1) {
            cout<<1<<"\n";
        }
        else if(3 <= N) {
            cout<<1<<" "<<3<<" "<<2<<" ";
            for(int i=4;i<=N;i++) {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}