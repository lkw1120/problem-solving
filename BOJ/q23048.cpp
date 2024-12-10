#include<bits/stdc++.h>
using namespace std;
const int MAX = 500001;
bool p[MAX];
int arr[MAX];
int N,K;
void eratosthenes() {
    fill(p,p+MAX,true);
    p[0] = p[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(p[i]) {
            for(int j=2;i*j<MAX;j++) {
                if(p[i*j]) p[i*j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>N;
    arr[1] = 1;
    K = 2;
    for(int i=2;i<=N;i++) {
        if(p[i]) {
            for(int j=1;i*j<=N;j++) {
                arr[i*j] = K;
            }
            K++;
        }
    }
    cout<<K-1<<"\n";
    for(int i=1;i<=N;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}