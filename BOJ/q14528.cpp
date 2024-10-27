#include<bits/stdc++.h>
using namespace std;
char arr[1001][51];
set<pair<pair<int,int>,int>> st;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N*2;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    ans = 0;
    for(int i=1;i<=M;i++) {
        for(int j=i+1;j<=M;j++) {
            for(int k=j+1;k<=M;k++) {
                st.clear();
                bool flag = true;
                for(int n=1;n<=N;n++) {
                    st.insert({{arr[n][i],arr[n][j]},arr[n][k]});
                }
                for(int n=N+1;n<=2*N;n++) {
                    if(st.count({{arr[n][i],arr[n][j]},arr[n][k]})) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}