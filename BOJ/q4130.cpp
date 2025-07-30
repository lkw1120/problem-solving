#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>D;
    for(int i=0;i<M;i++) {
        int x,price;
        cin>>x>>price;
        v.push_back(x);
    }
    v.push_back(D);
    sort(v.begin(),v.end());
    int dist = N*10;
    int p = 0;
    int cnt = 0;
    int idx = 0;
    int size = v.size();
    bool flag = true;
    while(p+dist < D) {
        int tmp = idx;
        while(tmp < size && v[tmp] <= p+dist) {
            tmp++;
        }
        if(tmp == idx) {
            flag = false;
            break;
        }
        p = v[tmp-1];
        cnt++;
        idx = tmp;
    }
    ans = -1;
    if(flag) {
        ans = cnt;
    }
    cout<<ans<<"\n";
    return 0;
}