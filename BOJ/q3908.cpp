#include<bits/stdc++.h>
using namespace std;
const int MAX = 1121;
vector<int> v;
bool isPrime[MAX] = {false};
int dp[1130][15] = {0};
int T,N,K,ans;
void init(){
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    int size = (int)sqrt(MAX);
    for(int i=2;i<=size;i++) {
        if(isPrime[i]) {
            for(int j=i*i;j<MAX;j+=i) {
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<MAX;i++) {
        if(isPrime[i]) {
            v.push_back(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int size=v.size();
    dp[0][0]=1;
    for(int i=0;i<size;i++) {
        for(int j=MAX-1;j>=v[i];j--) {
            for(int k=1;k<15;k++) {
                dp[j][k]+=dp[j-v[i]][k-1];
            }
        }
    }
    cin>>T;
    while(T--){
        cin>>N>>K;
        ans = dp[N][K];
        cout<<ans<<"\n";
    }
    return 0;
}