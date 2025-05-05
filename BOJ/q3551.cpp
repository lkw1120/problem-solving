#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5+1;
vector<int> v[MAX_N];
bool active[MAX_N];
string str;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>str;
        if(str == "cancel") {
            int a;
            cin>>a;
            v[a].push_back(i);
        }
    }
    for(int i=N;i>=1;i--) {
        bool isActive = true;
        for(int j: v[i]) {
            if(active[j]) {
                isActive = false;
                break;
            }
        }
        active[i] = isActive;
    }
    vector<int> res;
    for(int i=1;i<=N;i++) {
        if(active[i]) {
            res.push_back(i);
        }
    }
    cout<<res.size()<<"\n";
    for(int idx: res) {
        cout<<idx<<" ";
    }
    cout<<"\n";
    return 0;
}