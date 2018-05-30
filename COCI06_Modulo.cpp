#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    vector <int> rj;
    for (int i=0;i<10;i++)
    {
        int a;
        cin>>a;

        if ( i == 0 ) rj.push_back(a%42);
        else
        {
            a%=42;

            bool flag=true;
            for (int j=0;j<rj.size();j++)
                if ( rj[j] == a ) {flag=false;break;}

            if ( flag ) rj.push_back(a);
        }
    }

    cout<<rj.size()<<endl;
    return 0;
}
