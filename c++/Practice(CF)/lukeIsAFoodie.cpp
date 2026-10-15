// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define fa(v) for (auto &it : v) 

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         lli n,x;
//         cin>>n>>x;
//         vll a(n);
//         f(i,n) cin>>a[i];
//         lli i=0,j=i+1;
//         int ct=0;
//         lli mini=a[i];
//         lli maxi=a[i];
//         while(j<n){
//             mini=min(mini,a[j]);
//             maxi=max(maxi,a[j]);
//             if(abs(maxi-mini)<=2*x){
//                 j++;
//             }
//             else{
//                 ct++;
//                 j++;
//                 i=j-1;
//                 mini=a[i];
//                 maxi=a[i];
//             }
//         }
//         cout<<ct<<endl;
//     }
//     return 0;
// }

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
        lli n,x;
        cin>>n>>x;
        vll a(n);
        f(i,n) cin>>a[i];
        lli i=0,j=i+1;
        int ct=0;
        lli mini=min(a[i],a[j]);
        lli maxi=max(a[i],a[j]);
        while(j<n){
            mini=min(mini,a[j]);
            maxi=max(maxi,a[j]);
            if(abs(maxi-mini)<=2*x){
                
                j++;
            }
            else{
                ct++;
                j++;
                i=j-1;
                mini=a[i];
                maxi=a[i];
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}