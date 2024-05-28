#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> Tuple;
map<int,int> mp1,mp2;
vector<Tuple> v;
int N,C,X,Y,ans;
bool compare(Tuple a, Tuple b) {
    if(get<1>(a) == get<1>(b)) {
        return get<0>(a) < get<0>(b);
    }
    else {
        return get<1>(a) > get<1>(b);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>C;
    for(int i=1;i<=N;i++) {
        cin>>X;
        mp1[X]++;
        if(!mp2[X]) {
            mp2[X] = i;
        }
    }
    for(auto item: mp1) {
        int cnt = item.second;
        int n = item.first;
        v.push_back({mp2[n],cnt,n});
    }
    sort(v.begin(),v.end(),compare);
    for(auto item: v) {
        int cnt = get<1>(item);
        int n = get<2>(item);
        while(cnt--) {
            cout<<n<<" ";
        }
    }
    return 0;
}