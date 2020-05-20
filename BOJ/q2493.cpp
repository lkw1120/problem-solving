#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> vv;
stack<pair<int,int>> s;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    int tw;
    for(int i=0;i<N;i++) {
        cin>>tw;
        v.push_back(tw);
    }
    for(int i=0;i<N;i++) {
        while(!s.empty()) {
            if(s.top().first > v[i]) {
                vv.push_back(s.top().second);
                break;
            }
            s.pop();
        }
        if(s.empty()) {
            vv.push_back(0);
        }
        s.push({v[i],i+1});
    }
    for(auto ans:vv) {
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}