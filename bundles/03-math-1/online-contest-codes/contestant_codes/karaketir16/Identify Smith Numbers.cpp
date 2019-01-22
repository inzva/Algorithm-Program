#include <bits/stdc++.h>

using namespace std;
typedef long long int lint;

lint digitSum(lint x)
{
    lint result=0;
    while(x>0)
    {
        result+=x%10;
        x/=10;
    }
    return result;
}
int main()
{
    vector<bool> isPrime(100000, true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<100000;i++)
    {
        if(isPrime[i])
            for(int j=i*i;j<100000;j+=i)
                isPrime[j]=false;
    }

    lint x;
    cin>>x;
    lint r1=digitSum(x);
    lint r2=0;
    lint temp=x;
    for(int i=2;i*i<=temp;i++)
    {

        //cout<<'i'<<i<<endl;
        while(temp%i==0)
        {
            //cout<<':'<<i<<endl;
            temp=temp/i;
            r2+=digitSum(i);  
        }
    }
    //if(isPrime[temp]) r2+=digitSum(temp);
    if(temp != 1) r2+=digitSum(temp);
    //cout<<r1<<endl<<r2<<endl;
    cout<<(int)(r1==r2);
    return 0;
}
