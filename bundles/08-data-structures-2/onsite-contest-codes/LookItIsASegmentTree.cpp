#include <bits/stdc++.h>
#define N 100005
#define mid ((lf+rg)/2)
using namespace std;
typedef long long int lint;
lint n,d[N];
lint sg[N*4];
lint init(int k,int lf,int rg)
{
    if(lf==rg)
        return sg[k]=d[lf];
    sg[k]=init(k*2,lf,(lf+rg)/2)+init((k*2)+1,(lf+rg)/2+1,rg);   
    return sg[k];
}
lint find(int k,int lf,int rg,int Qleft,int Qright)
{
    if(Qleft<=lf && rg<=Qright)
        return sg[k];
    if(lf>Qright || rg<Qleft)
        return 0;
    return find(2*k,lf,mid,Qleft,Qright) + find(2*k+1,mid+1,rg,Qleft,Qright);
}
void up(int k,int lf,int rg,int plc,int val) // plc yerini value arttir
{
    if(rg<plc || lf>plc)
        return ;
    sg[k]+=val;
    if(lf==rg) return ;
    up(2*k,lf,mid,plc,val);
    up(2*k+1,mid+1,rg,plc,val);
}
int main()
{
   lint q;
    scanf("%lld %lld",&n,&q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld",&d[i]);
    }
    init(1,1,n);
    for    (int i=0;i<q;i++)
    {
        lint o1,o2;
        lint qtype;
        scanf("%lld",&qtype);
        scanf("%lld %lld",&o1,&o2);
        if(qtype==1) cout << find(1,1,n,o1,o2) << endl;  
        else
        {
            lint diff = o2- find(1,1,n,o1,o1);
            up(1,1,n,o1,diff);
        }
    }
}
