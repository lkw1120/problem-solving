#include<bits/stdc++.h>
using namespace std;
set<int> st;
int X,N,P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X>>N;
    for(int i=0;i<N;i++) {
        cin>>P;
        st.insert(P);
    }
    int d = 0;
    while(true) {
        if(!st.count(X-d)) {
            ans = X-d;
            break;
        }
        if(!st.count(X+d)) {
            ans = X+d;
            break;
        }
        d++;
    }
    cout<<ans<<"\n";
    return 0;
}