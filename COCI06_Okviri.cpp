#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    string a;
    cin>>a;

    int d=5+4*(a.size()-1);

    char b[5][d];

    for (int i=0;i<5;i++)
        for (int j=0;j<d;j++)
            b[i][j]='.';
    b[2][2]=a[0];

    int br1=0,br2=1;

    for (int i=3;i<d;i++)
    {
        br1++;
        if (br1==4)
        {
            b[2][i]=a[br2];
            br2++;
            br1=0;
        }
    }

    for (int i=0;i<5;i++)
    {
        int br=0;
        for (int j=0;j<d;j++)
        {
            if (b[i][j]!='#' && b[i][j]!='.' && b[i][j]!='*')
            {
                br++;
                char r='1';
                if (br!=0 && br % 3 == 0) r='*';
                else r='#';
                b[i-2][j]=r;
                b[i-1][j-1]=r;
                b[i-1][j+1]=r;
                if (b[i][j-2]!='*') b[i][j-2]=r;
                b[i][j+2]=r;
                b[i+1][j-1]=r;
                b[i+1][j+1]=r;
                b[i+2][j]=r;
            }
        }
    }

    for (int i=0;i<5;i++)
    {
        for (int j=0;j<d;j++)
        {
            cout<<b[i][j];
        }
        cout<<endl;
    }
    return 0;
}
