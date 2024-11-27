#include<bits/stdc++.h>
using namespace std;
int arr[2][11];
bool check[2][11];
vector<int> v;
int ans;
void find(int d, int sum) {
    if(d == 4) {
        v.push_back(sum);
        return ;
    }
    if(d+2 <= 4) {
        find(d+2,sum);
    }
    int k = d%2;
    for(int i=1;i<=10;i++) {
        if(!check[k][i]) {
            check[k][i] = true;
            find(d+1,sum+arr[k][i]*(k?1:-1));
            check[k][i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<2;i++) {
        for(int j=1;j<=10;j++) {
            cin>>arr[i][j];
        }
    }
    find(0,0);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ans = v.size();
    cout<<ans<<"\n";
    return 0;
}