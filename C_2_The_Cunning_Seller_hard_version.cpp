#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vll vec(22);
void precompute(){
    vec[0]=1,vec[1]=3;
    ff(2,22,1){
        vec[i]=vec[i-1]*3;
    }
}
void solve(){
    lli n,k;
    cin>>n>>k;
    lli c=0,kTry=0;
    map<lli,lli> mpp;
    while(n>0){
        kTry++;
        auto it=upper_bound(all(vec),n);
        lli indx=it-vec.begin();
        indx--;
        mpp[indx]++;
        if(indx==0){
            n--;
            c+=3;
        }
        else{
            n-=vec[indx];
            c+=(vec[indx+1]+indx*vec[indx-1]);
        }
    }
    // cout<<c<<endl;
    // debug(mpp);
    if(kTry>k){
        cout<<-1<<endl;
        return;
    }
    k-=kTry;
    while(k>1){
        // k-=2;
        auto it=mpp.end();
        it--;
        if(it->first==0) break;
        lli ct=mpp[it->first];
        if(k>=ct*2){
            k-=ct*2;
            mpp[it->first-1]+=ct*3;
            mpp.erase(it->first);
            c-=ct*pow(3,it->first-1);
        }
        else{
            ct=k/2;
            k=0;
            mpp[it->first-1]+=ct*3;
            mpp.erase(it->first);
            c-=ct*pow(3,it->first-1);
        }
    }
    // debug(mpp);
    cout<<c<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    precompute();
    while(t--){
        solve();
    }
    return 0;
}