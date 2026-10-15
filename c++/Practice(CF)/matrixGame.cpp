#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=1e5+10;
const lli M=1e9+7; 

vll fact(N);

void factorial(){
    fact[0]=1;
    ff(1,N,1){
        fact[i]=(fact[i-1]*i)%M;
    }
}

lli binExpItr(lli a,lli b){
    a%=M;
    lli ans=1;
    while(b>0){
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

lli nCr(lli n,lli r){
    lli num=1;
    ff(0,r,1){
        num=(num*((n-i+M)%M))%M;
    }
    lli den=binExpItr(fact[r],M-2)%M;
    return (num*den)%M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    factorial();
    while(t--){
        lli a,b,k;
        cin>>a>>b>>k;
        lli n=((a-1)*k)+1;                    //isse koi ek '1 to k' me "a" times repeat ho jaane ke liye jagah ho jayega aur baaki sab (a-1) times
        lli ncr=nCr(n,a);                        //isse koi ek column me a jagah choose karo
        lli m=(((ncr*k)%M)*(b-1)%M)%M;          // nCa*k se koi ek 'k' milega aur *(b-1) karke (b-1) times repeat karo sab 'k' ko
        m=(m+1)%M;                              // m+1 karke koi ek k b times repeat kara do
        cout<<n<<" "<<m<<endl; 
    }
    return 0;
}