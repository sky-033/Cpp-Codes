// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,x;
//         cin>>n>>x;
//         vector<int> a(n),b(n);
//         for(int i=0;i<n;i++){
//             cin>>a[i];
//             b[i]=a[i];
//         }
//         int ct=0;
//         sort(b.begin(),b.end());
//         for(int i=n-1;i>=0;i++){
//             if(a[0]==b[i]) ct=i;
//         }
//         if(ct<=x) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
// }