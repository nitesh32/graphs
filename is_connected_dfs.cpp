#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
typedef long long ll;
#define nit( i, n) for(i=0;i<n;i++)
int gcd(int a,int b){ if(b==0) return a; else return gcd(b,a%b);}
bool iseven(int n){return ((n&1)==0)?true:false;}
int pov(int n,int m){ int c=1;  while(m>0){  if(!iseven(m)){ c=c*n; } n=n*n; m=m>>1;  }  return c; }
unsigned int intlen(unsigned int n){return n ? intlen(n/10)+1 : 0;}
bool isprime(int x) { for (int d = 2; d * d <= x; d++) { if (x % d == 0) return false; }return true; }
void dfs(int** ed,ll st,ll n,int* visit){
    //cout<<st<<" ";
    visit[st]=1;
    for(int i=0;i<n;i++){
        if(i==st){
            continue;
        }
        else{
            if(ed[st][i]==1&&visit[i]!=1){
                dfs(ed,i,n,visit);
            }
        }
    }

}
int main(){

    ll t;
    cin>>t;
    while(t--){
        ll e;
        cin>>n>>e;
        ll st,ew;
        //cin>>st>>ew;
        int** ed=new int*[n];
        for(int i=0;i<n;i++){
            ed[i]=new int[n];
            for(int j=0;j<n;j++){
                ed[i][j]=0;
            }
        }
        ll con;
        for(int i=0;i<e;i++){
            ll x,y;
            con =x;
            cin>>x>>y;
            ed[x][y]=1;
            ed[y][x]=1;
        }
        int* visit= new int[n];
        for(int i=0;i<n;i++){
            visit[i]=0;
        }
        dfs(ed,con,n,visit);
        int f=0;
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
return 0;
}