#include<bits/stdc++.h>
using namespace std;
set<int> st;
int N,A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    bool flag = true;
    for(int i=0;i<N;i++) {
        cin>>A;
        if(st.count(A)) {
            flag = false;
            break;
        }
        st.insert(A);
    }
    cout<<(flag? "YES": "NO")<<"\n";
    return 0;
}