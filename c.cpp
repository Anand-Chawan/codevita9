//railway
#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(i=a;i<b;i++)
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n],b[n],i,j,minp=1,res=1;
    loop(i,0,n) cin>>a[i]>>b[i],b[i]+=a[i];
    sort(a,a+n); sort(b,b+n);
    i=1;j=0;
    while(i<n&&j<n){
        if(a[i]<=b[j]){
            minp++;i++;
            res=max(res,minp);
        }else{
            minp--;j++;
        }
    }
    cout<<res;
}