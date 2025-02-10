#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull T,N,M,P,Q;
stack<bool> st;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>N;
        if(N == 1) {
            cin>>M;
            ull a,b;
            a = b = 1;
            while(1 < M) {
                st.push(M%2);
                M/=2;
            }
            while(!st.empty()) {
                if(st.top()) {
                    a+=b;
                }
                else {
                    b+=a;
                }
                st.pop();
            }
            cout<<"Case #"<<t<<": "<<a<<" "<<b<<"\n";
        }
        if(N == 2) {
            cin>>P>>Q;
            ull a;
            a = 1;
            while(1 < P || 1 < Q) {
                if(Q < P) {
                    st.push(true);
                    P-=Q;
                }
                else {
                    st.push(false);
                    Q-=P;
                }
            }
            while(!st.empty()) {
                a*=2;
                a+=st.top();
                st.pop();
            }
            cout<<"Case #"<<t<<": "<<a<<"\n";
        }
    }
    return 0;
}