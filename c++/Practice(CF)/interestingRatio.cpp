#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 
const int N = 1e6 + 1;
vector<bool> isPrime(N, true);
 
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    sieve();
    while(t--){
        int n;
        cin>>n;
        int l=2;
        int ct=0;
        for(int i=1;i<=n;i++){
            if(isPrime[i]) ct++;
        }
        while(l<=n/2){
            for(int i=l;i<=n;i+=l){
                int temp=i/l;
                if(isPrime[temp]) ct++;
            }
            l++;
        }
        cout<<ct<<endl;
    }
    return 0;
}