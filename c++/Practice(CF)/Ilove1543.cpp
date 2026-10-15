#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vector<string> grid;
        f(i,n){
            string s;
            cin>>s;
            grid.push_back(s);
        }
        lli ct=0;
        if(n>=m){
            f(i,m/2){
                vector<char> temp;
                lli row=i,column=m-1-i;
                for(lli j=i;j<m-i;j++){
                    temp.push_back(grid[row][j]);
                }
                for(lli j=1+i;j<n-i;j++){
                    temp.push_back(grid[j][column]);
                }
                row=n-1-i;
                for(lli j=m-2-i;j>=i;j--){
                    temp.push_back(grid[row][j]);
                }
                column=i;
                for(lli j=n-2-i;j>i;j--){
                    temp.push_back(grid[j][column]);
                }
                lli p=temp.size();
                for(lli k=0;k<p-3;k++){
                    if(temp[k]=='1' && temp[k+1]=='5' && temp[k+2]=='4' && temp[k+3]=='3') ct++;
                }
                if(temp[p-1]=='1' && temp[0]=='5' && temp[1]=='4' && temp[2]=='3') ct++;
                if(temp[p-1]=='5' && temp[0]=='4' && temp[1]=='3' && temp[p-2]=='1') ct++;
                if(temp[p-1]=='4' && temp[0]=='3' && temp[p-3]=='1' && temp[p-2]=='5') ct++;
            }
        }
        else{
            f(i,n/2){
                vector<char> temp;
                lli row=i,column=m-1-i;
                for(lli j=i;j<m-i;j++){
                    temp.push_back(grid[row][j]);
                }
                for(lli j=1+i;j<n-i;j++){
                    temp.push_back(grid[j][column]);
                }
                row=n-1-i;
                for(lli j=m-2-i;j>=i;j--){
                    temp.push_back(grid[row][j]);
                }
                column=i;
                for(lli j=n-2-i;j>i;j--){
                    temp.push_back(grid[j][column]);
                }
                lli p=temp.size();
                for(lli k=0;k<p-3;k++){
                    if(temp[k]=='1' && temp[k+1]=='5' && temp[k+2]=='4' && temp[k+3]=='3') ct++;
                }
                if(temp[p-1]=='1' && temp[0]=='5' && temp[1]=='4' && temp[2]=='3') ct++;
                if(temp[p-1]=='5' && temp[0]=='4' && temp[1]=='3' && temp[p-2]=='1') ct++;
                if(temp[p-1]=='4' && temp[0]=='3' && temp[p-3]=='1' && temp[p-2]=='5') ct++;
                
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}