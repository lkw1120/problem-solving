#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
bool gray[2][60];
bool bi[2][60];
ll arr[2];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<2;i++) {
        cin>>str;
        for(int j=0;j<N;j++) {
            gray[i][j] = str[j] == '0'? false: true; 
        }
        bi[i][0] = gray[i][0];
        for(int j=1;j<N;j++) {
            bi[i][j] = bi[i][j-1]^gray[i][j];
        }
        for(int j=0;j<N;j++) {
            arr[i]<<=1;
            if(bi[i][j]) arr[i]++;
        }
    }
    ans = abs(arr[1]-arr[0])-1;
    cout<<ans<<"\n";
    return 0;
}