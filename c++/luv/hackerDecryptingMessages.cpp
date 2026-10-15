#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli N=1e6+10;
const lli M=1e9+7; 

vll lp(N);  // isko nikal rhe hai taake X ka primefactors nikaal sake
vll hsh(N); // isme given array ka saari element ka square,cube...nth power ko 1 mark kar rhe hai

vll primefactor(lli X){
    vll factors;
    while(X>1){
        lli pff=lp[X];
        while(X%pff==0) X/=pff;
        factors.push_back(pff);
    }
    return factors;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(lli i=2;i<N;i++){
        if(lp[i]==0){                   //iska matlb abhi tak lowest prime mark nhi hua hai
            for(lli j=i;j<N;j+=i){
                if(lp[j]==0) lp[j]=i;
            }
        }
    }

    lli n,q;
    cin>>n>>q;
    f(i,n){
        lli x;
        cin>>x;
        hsh[x]=1;            // saare element jo array me hai usko hsh[] me 1 mark krde
    }

    for(lli i=2;i<N;i++){
        if(hsh[i]==1){
            for(lli j=i;j<N;j*=i){
                hsh[j]=1;          
            }
        }
    }

    while(q--){
        lli X;
        cin>>X;
        vll pf=primefactor(X);  // maximum different primefactors 10 hee ho skta hai
        lli s=pf.size();
        bool flag=false;
        f(i,s){
            for(lli j=i;j<s;j++){
                lli div=pf[i]*pf[j];
                if(i==j && X%div!=0) continue;      // iska matlb same primes nhi hai uska factor
                lli toRemove=X/div;
                if(hsh[toRemove]==1 || toRemove==1){  // iska matlb wahi hsh[] me X/div hai ya X/dic agar 1 hua toh sahi hee hai na
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}