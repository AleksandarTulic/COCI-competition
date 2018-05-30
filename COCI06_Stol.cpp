#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r,c;
char m[401][401];
vector <int> rec;

bool can(int x, int y, int br1, int br2)
{
    for (int i=x;i<x+br1;i++)
        for (int j=y;j<y+br2;j++)
            if ( m[i][j]=='X' ) return false;
    return true;
}

void rect_size(int x, int y)
{
    int br1=0;
    int br2=0;

    for (int i=x;i<r;i++)
        if (m[i][y]=='.') br1++;
        else break;
    for (int i=y;i<c;i++)
        if (m[x][i]=='.') br2++;
        else break;

    for (int i=br1;i>=1;i--)
        if (can(x,y,i,br2)) rec.push_back(2*i+2*br2-1);
    for (int i=br2;i>=1;i--)
        if (can(x,y,br1,i)) rec.push_back(2*br1+2*i-1);

    while (br1!=1 && br2!=1)
    {
        if (can(x,y,br1,br2)) rec.push_back(2*br1+2*br2-1);
        br1--;
        br2--;
    }
}

int main()
{
    cin>>r>>c;

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        cin>>m[i][j];

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            if ( m[i][j]=='.' ) rect_size(i,j);

    sort(rec.begin(),rec.end());

    cout<<rec[rec.size()-1]<<endl;
    return 0;
}
