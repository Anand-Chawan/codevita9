//count pairs
#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define vi vector<int>
int main(){
    int n,k,i,indx,cnt=0;
    cin>>n>>k;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    loop(i,0,n){
        indx=1;
        if(i==0){
            while(a[i]==a[i+indx]) indx++;
            if(i+indx>n-1) continue;
            cnt+=(a[i+indx]-a[i])<=k;
        }else if(i==n-1){
            indx=1;
            while(a[i]==a[i-indx]) indx++;
            if(i-indx<0) continue;
            cnt+=(a[i]-a[i-indx])<=k;
        }
        else{
            indx=1;
            int indx2=1;
            while(a[i-indx2]==a[i]) indx2++; 
            if(i-indx2<0) indx2=-1;
            while(a[i+indx]==a[i]) indx++;
            if(i+indx>n-1) indx=-1;
            if(indx2==-1&&indx!=-1) cnt+=(a[i+indx]-a[i])<=k;
            else if(indx2!=-1&&indx==-1) cnt+=(a[i]-a[i-indx2])<=k;
            else if(indx2==-1&&indx==-1) continue;
            else{
                cnt+=(a[i]-a[i-indx2])<=k||(a[i+indx]-a[i])<=k;
            }
        }
    }
    cout<<cnt;
}