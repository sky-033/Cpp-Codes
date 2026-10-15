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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    f(i,n) cin>>a[i];
    int l=0,r=0,ct=0,maxi=0;
    while(r<n){
        if(a[r]==0){
            ct++;
        }
        if(ct>k){
            if(a[l]==0) ct--;
            l++;
        }
        if(ct<=k){
            maxi=max(maxi,r-l+1);
        }
        r++;
    }
    cout<<maxi<<endl;
    return 0;
}