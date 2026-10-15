#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n),b;
        f(i,n) cin>>a[i];
        lli l=0,h=n-1;
        while(l<h){
            b.push_back(abs(a[h]-a[l]));
            l++;
            h--;
        }
        sort(b.begin(),b.end());
        if(n==1){
            cout<<0<<endl;
        }
        // else if(b[0]==0){
        //     cout<<0<<endl;
        // }
        else{
            lli gcd=b[0];
            f(i,b.size()){
                gcd=__gcd(gcd,b[i]);
            }
            cout<<gcd<<endl;
        }
    }
    return 0;
}