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
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        lli l=0,h=1;
        f(i,n){
            if(a[i]==1) a[i]++;
        }
        while(h<n){
            if(a[h]%a[l]==0){
                a[h]++;
                
            }
            l++;
            h++;
        }
        f(i,n) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}