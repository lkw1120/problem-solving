#include<bits/stdc++.h>
using namespace std;
typedef pair<int,vector<int>> Pair;
vector<pair<int,vector<int>>> v;
int N,M,A;
bool compare(Pair a, Pair b) {
    return a.first > b.first;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        vector<int> vv;
        int sum = 0;
        for(int j=0;j<M;j++) {
            cin>>A;
            vv.push_back(A);
            sum+=A;
        }
        v.push_back({sum,vv});
    }
    sort(v.begin(),v.end(),compare);
    bool flag = true;
    for(int j=0;j<M;j++) {
        int check = v[0].second[j];
        for(int i=0;i<N;i++) {
            if(check < v[i].second[j]) {
                flag = false;
            }
            check = v[i].second[j];
        }
    }
    if(flag) {
        cout<<"YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}