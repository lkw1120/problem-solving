#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M;
    for(int i=1;i<=M;i++) {
        v.push_back(i);
    }
    for(int i=M;i>=1;i--) {
        v.push_back(i);
    }
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}