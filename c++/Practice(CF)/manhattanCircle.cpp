#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n);
        for(int i=0;i<n;i++){
            grid[i].resize(m);
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int x1=0,y1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#'){
                    x1=i+1;
                    y1=j+1;
                }
            }
        }
        int x2=0,y2=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#'){
                    x2=i+1;
                    y2=j+1;
                }
            }
        }
        cout<<(x1+x2)/2<<" "<<(y1+y2)/2<<endl;
    }
    return 0;
}