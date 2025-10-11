#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int rotate(int cur, int i) {
    int dist = abs(cur-i);
    return min(dist,4-dist);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N-2;i++) {
        string str;
        cin>>str;
        for(int j=0;j<4;j++) {
            if(str[j] == '0') {
                v.push_back(j+1);
                break;
            }
        }
    }
    ans = INT_MAX;
    for(int i=1;i<=4;i++) {
        int sum = 0;
        for(int item: v) {
            sum+=rotate(item,i);
        }
        int tmp = abs(i-1)+(N-1)+abs(4-i)+sum;
        ans = min(ans,tmp);
    }
    cout<<ans<<"\n";
    return 0;
}