#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,q;
    cin>>n>>q;
    vll p(n);
    vp xy(q);
    f(i,n) cin>>p[i];
    f(i,q){
        lli x,y;
        cin>>x>>y;
        xy[i].first=x;
        xy[i].second=y;
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    for(auto &it:xy){
        lli a=it.first;
        lli b=it.second;
        lli sum=0;
        for(lli i=a-b;i<a;i++){
            sum+=p[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}