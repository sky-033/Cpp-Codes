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
        if(n<4 || n%2) cout<<-1<<endl;
        else{
            lli maxi=n/4;
            lli mini=n/6;
            if(n%6!=0) mini+=1;
            if(n<6) cout<<maxi<<" "<<maxi<<endl;
            else cout<<mini<<" "<<maxi<<endl;
            
        }
    }
    return 0;
}