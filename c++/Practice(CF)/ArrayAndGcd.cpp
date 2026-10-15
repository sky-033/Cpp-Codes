#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vpw vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=1e7;
const lli M=1e9+7; 

vector<bool> primes(N+1,true);
vll prime;
void sieve(){
    primes[0]=primes[1]=false;
    for(lli i=2;i*i<=N;i++){
        if(primes[i]){
            for(lli j=2*i;j<=N;j+=i) primes[j]=false;
        }
    }
    for(lli i=1;i<=N;i++){
        if(primes[i]) prime.push_back(i);
    }
}

lli check(vll &a,lli mid){
    lli j=0;
    lli coins=0;
    for(lli i=mid;i<a.size();i++){
        coins+=(a[i]-prime[j]);
        j++;
    }
    return coins;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        sor(a);
        lli coins=0;
        f(i,n){
            coins+=(a[i]-prime[i]);
        }
        if(coins>=0) cout<<0<<endl;
        else{
            lli l=0,h=n-1,mid;
            while(h-l>1){
                mid=(l+h)/2;
                if(check(a,mid)>0) h=mid;
                else l=mid;
            }
            if(check(a,l)>=0) cout<<l<<endl;
            else cout<<h<<endl;
        }
    }
    return 0;
}