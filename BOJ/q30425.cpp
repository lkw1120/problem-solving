#include<bits/stdc++.h>
using namespace std;
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>str;
    vector<int> lps(N,0);
    for(int i=1,j=0;i<N;i++) {
        while(j > 0 && str[i] != str[j]) {
            j = lps[j-1];
        }
        if(str[i] == str[j]) {
            j++;
            lps[i] = j;
        }
    }
    int p = N-lps[N-1];
    ans = (N+p-1)/p;
    cout<<ans<<"\n";
    return 0;
}