#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<lli>
#define vp vector<pair<lli,lli>>
#define fo(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
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
        lli te=n;
        vll v;
        if(n==0){
            cout<<"YES"<<"\n";
            continue;
        }
        if((n&(n-1))==0){
            cout<<"NO"<<"\n";
            continue;
        }
        while(te>0){
            lli rem=te%2;
            te/=2;
            v.push_back(rem);
        }
        lli in=-1;
        fo(i,v.size()){
            if(v[i]==0) in=i;
            else break;
        }
        vll tie;
        for(lli i=in+1;i<v.size();i++) tie.push_back(v[i]);

        lli low=0,high=tie.size()-1;

        bool ch=true;

        while(low<high){
            if(tie[low]!=tie[high]){
                ch=false;
                break;
            }
            low++,high--;
        }
        lli SIz=tie.size();
        if(SIz%2==1){

            if(tie[(SIz)/2]==1) ch=false;
        }
       cout<<(ch?"YES":"NO")<<"\n";
        
    }
    return 0;
}