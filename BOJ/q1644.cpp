#include<bits/stdc++.h>
#define MAX 4000001
using namespace std;
bool isPrime[MAX];
int N,sum,ans;
int main() {
    ios_base::sync_with_stdio(false);
    fill(isPrime,isPrime+MAX,true);
    cin>>N;
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=N;i++) {
        for(int j=2;j*i<=N;j++) {
            isPrime[i*j] = false;
        }
    }
    ans = 0;
    sum = 0;
    int a=0,b=1;
    while(a<b) {
        if(sum < N) {
            while(!isPrime[++b]) {}
            sum+=b;
        }
        else if(sum >= N) {
            if(sum == N) ans++;
            while(!isPrime[++a]) {}
            sum-=a;
        }
    }
    cout<<ans<<"\n";
    return 0;
}