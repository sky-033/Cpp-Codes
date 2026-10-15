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
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=3e3+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vll g1[N],g2[N];
vll dp1(N),dp2(N);

bool check(lli a1,lli a2,lli b1,lli b2,lli c1,lli c2){
    if((a1-a2)<0) return false;
    else if((a1-a2)==0){
        if((b1-b2)==0 && (c1-c2)>0) return true;
        return false;
    }
    else{
        if(((b1-b2)*(b1-b2)-4*(a1-a2)*(c1-c2))<0) return true;
        return false;
    }
}

void clear(lli n){
    f(i,n){
        dp1[i]=-1;
        dp2[i]=-1;
        g1[i].clear();
        g2[i].clear();
    }
}

lli solve1(lli vertex){
    if(dp1[vertex]!=-1) return dp1[vertex];
    lli ans=0;
    for(auto child : g1[vertex]){
        ans=max(ans,solve1(child));
    }
    return dp1[vertex]=ans+1;
}

lli solve2(lli vertex){
    if(dp2[vertex]!=-1) return dp2[vertex];
    lli ans=0;
    for(auto child : g2[vertex]){
        ans=max(ans,solve2(child));
    }
    return dp2[vertex]=ans+1;
}

void solve(){
    lli n;
    cin>>n;
    clear(n);
    vector<vector<lli>> fn(n,vll(3));
    f(i,n){
        lli a,b,c;
        cin>>a>>b>>c;
        fn[i][0]=a,fn[i][1]=b,fn[i][2]=c;
    }
    f(i,n){
        f(j,n){
            if(i==j) continue;
            lli a1=fn[i][0],b1=fn[i][1],c1=fn[i][2];
            lli a2=fn[j][0],b2=fn[j][1],c2=fn[j][2];
            if(check(a1,a2,b1,b2,c1,c2)){
                g1[i].push_back(j);
                g2[j].push_back(i);
            }
        }
    }

    f(i,n) cout<<solve1(i)+solve2(i)-1<<" ";
    cout<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}