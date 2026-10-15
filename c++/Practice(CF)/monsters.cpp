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
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n);
        lli mini=1e18;
        vp v(n);
        f(i,n){
            cin>>a[i];
        }
        f(i,n){
            lli temp=a[i]/k;
            // cout<<temp<<endl;
            a[i]-=temp*k;
            v[i]={i+1,a[i]};
        }
        sort(v.begin(), v.end(), [](const pair<lli, lli> &a, const pair<lli, lli> &b) {
            return (a.second == b.second) ? (a.first < b.first) : (a.second > b.second);
        });
        fa(v){
            if(it.second==0) cout<<it.first<<" ";
        }
        fa(v){
            if(it.second!=0) cout<<it.first<<" ";
        }
        cout<<endl;
    }
    return 0;
}