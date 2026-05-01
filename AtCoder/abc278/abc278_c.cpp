#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> st;
int N,Q,T,A,B;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i=0;i<Q;i++) {
        cin>>T>>A>>B;
        if(T == 1) {
            st.insert({A,B});
        }
        else if(T == 2) {
            st.erase({A,B});
        }
        else if(T == 3) {
            if(st.count({A,B}) && st.count({B,A})) {
                cout<<"Yes"<<"\n";
            }
            else {
                cout<<"No"<<"\n";
            }
        }
    }
    return 0;
}