#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    int t;
    cin>>t;
    while(t--){
        lli x,y;
        cin>>x>>y;
        lli k=1e18;
        if(x==y){
            cout<<-1<<endl;
        }
        else{
            lli low=0,high=1e18;
            while(low<high){
                if(((x+low)&(y+low))==0){
                    cout<<low<<endl;
                    break;
                }
                else{
                    low++;
                }
            }
        
        }
    }
    
}