#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,b;
set<ll> st;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    b.resize(N);
    for(int i=0;i<N;i++) {
        cin>>b[i];
        st.insert(b[i]);
    }
    ll start = -1;
    for(auto item: b) {
        bool flag = false;
        if(st.count(item*3)) flag = true;
        if(item%2 == 0 && st.count(item/2)) flag = true;
        if(!flag) {
            start = item;
            break;
        }
    }
    ll tmp = start;
    for(int i=0;i<N;i++) {
        a.push_back(tmp);
        if(st.count(tmp*2)) {
            tmp*=2;
        }
        else if(tmp%3 == 0 && st.count(tmp/3)) {
            tmp/=3;
        }
    }
    for(auto item: a) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}