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
        lli ctO=0LL,ctE=0LL,ct1=0LL;
        f(i,n){
            cin>>a[i];
            a[i]*=1LL;
            if(a[i]%2LL==0LL) ctE+=1LL;
            else ctO+=1LL;
            if(a[i]==1LL) ct1+=1LL;
        }
        sort(a.begin(),a.end());
        lli sumE=0LL,sumO=0LL;
        lli maxi=a[n-1]*1LL;
        for(lli i=0;i<n-1;i++){
            if(a[i]%2LL==0LL) sumE+=a[i]*1LL;
            else sumO+=a[i]*1LL;
        }
        // sumO-=ct1*1LL;
        if((ctE==0LL || ctO==0LL)) cout<<maxi<<endl;
        // else if(ct1!=0LL && sumO==0LL){
        //     cout<<maxi+sumE+1LL<<endl;
        // }
        // else if(ct1!=0LL) cout<<maxi+sumO+sumE<<endl;
        else{
            if(maxi%2LL==0){
                // if(ctE==1LL) cout<<maxi+sumO+sumE<<endl;
                cout<<maxi+sumE+sumO-(ctO)+1<<endl;
            }
            else{
                // if(ctO==1LL) cout<<maxi+sumE+sumO<<endl;
                cout<<maxi+sumE+sumO-(ctO)+1<<endl;
            }
        }
    }
    return 0;
}