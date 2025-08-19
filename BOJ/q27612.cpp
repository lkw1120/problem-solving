#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    int n = str.size();
    vector<int> A(n+1),T(n+1),G(n+1),C(n+1);
    for(int i=1;i<=n;i++) {
        A[i] = A[i-1];
        T[i] = T[i-1];
        G[i] = G[i-1];
        C[i] = C[i-1];
        if(str[i-1] == 'A') A[i]++;
        if(str[i-1] == 'T') T[i]++;
        if(str[i-1] == 'G') G[i]++;
        if(str[i-1] == 'C') C[i]++;
    }
    int m; 
    cin>>m;
    string atgc = "ATGC";
    while(m--) {
        int l,r;
        cin>>l>>r;
        int cnt[4] = {
            A[r]-A[l-1],
            T[r]-T[l-1],
            G[r]-G[l-1],
            C[r]-C[l-1]
        };
        vector<int> v = {0,1,2,3};
        sort(v.begin(),v.end(),[&](int a, int b) {
            return cnt[a] > cnt[b];
        });
        for(int idx: v) {
            cout<<atgc[idx];
        }
        cout<<"\n";
    }
    return 0;
}