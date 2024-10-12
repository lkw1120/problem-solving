#include<bits/stdc++.h>
using namespace std;
vector<int> v;
set<string,greater<string>> st;
int T,N,X;
void solve(int n, int sum, string str) {
    if(sum == T) {
        st.insert(str);
        return ;
    }
    int size = v.size();
    for(int i=n;i<size;i++) {
        if(sum+v[i] <= T) {
            solve(i+1,sum+v[i],str+to_string(v[i])+"+");
        }
        else {
            solve(i+1,sum,str);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>T>>N;
        if(!T && !N) break;
        v.clear();
        st.clear();
        for(int i=0;i<N;i++) {
            cin>>X;
            v.push_back(X);
        }
        sort(v.rbegin(),v.rend());
        solve(0,0,"");
        cout<<"Sums of "<<T<<":"<<"\n";
        if(!st.empty()) {
            for(auto item: st) {
                cout<<item.substr(0,item.size()-1)<<"\n";
            }
        }
        else {
            cout<<"NONE"<<"\n";
        }
    }
    return 0;
}