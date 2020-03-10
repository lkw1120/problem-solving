#include<bits/stdc++.h>
#define MAX 11
using namespace std;
int op[MAX];
int A[MAX];
int N, Max, Min;
void swap(int i, int j) {
    int temp = op[i];
    op[i] = op[j];
    op[j] = temp;
}
void check() {
    int sum = A[0];
    for(int i=1;i<N;i++) {
        if(op[i-1] == 1) sum += A[i];
        if(op[i-1] == 2) sum -= A[i];
        if(op[i-1] == 3) sum *= A[i];
        if(op[i-1] == 4) sum /= A[i];
    }
    if(sum > Max) Max = sum;
    if(sum < Min) Min = sum;
}
void perm(int depth, int n, int k) {
    if (depth == k) {
        check();
        return;
    }
    for(int i = depth; i < n; i++) {
        swap(i, depth);
        perm(depth + 1, n, k);
        swap(i, depth);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A[i];
    }
    int k = 0;
    for(int i=1;i<=4;i++) {
        int j;
        cin>>j;
        for(;j>0;j--) {
            op[k] = i;
            k++;
        }
    }
    Max = -1000000001;
    Min = 1000000001;
    perm(0,N-1,N-1);
    cout<<Max<<"\n";
    cout<<Min<<"\n";
    return 0;
}