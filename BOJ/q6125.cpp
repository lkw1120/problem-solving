#include<bits/stdc++.h>
using namespace std;
int arr[5001];
int P,NS,T,N,B1,B2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>P>>NS>>T;
    for(int i=0;i<NS;i++) {
        cin>>N>>B1>>B2;
        arr[B1] = arr[B2] = N;
    }
    stack<int> st;
    st.push(T);
    while(st.top() != 1) {
        int t = st.top();
        st.push(arr[t]);
    }
    int cnt = st.size();
    cout<<cnt<<"\n";
    while(!st.empty()) {
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}