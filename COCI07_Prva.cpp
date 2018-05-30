#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int r,c;
char m[21][21];
vector <string> rijec;

void top_down(int x, int y)
{
    string rj="";
    for (int i=x;i<r;i++)
        if ( isalpha(m[i][y]) ) rj+=m[i][y];
        else break;

    if ( rj.size() >= 2 ) rijec.push_back(rj);
}

void left_right(int x, int y)
{
    string rj="";
    for (int i=y;i<c;i++)
        if ( isalpha(m[x][i]) ) rj+=m[x][i];
        else break;

    if ( rj.size() >= 2 ) rijec.push_back(rj);
}

int main()
{
    scanf("%d %d",&r,&c);

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            cin>>m[i][j];

    for (int i=0;i<r;i++)
        for (int j=0;j<r;j++)
        {
            if ( i == 0 ) top_down(i,j);
            else if ( i > 0 && m[i-1][j] == '#' ) top_down(i,j);

            if ( j == 0 ) left_right(i,j);
            else if ( j > 0 && m[i][j-1] == '#' ) left_right(i,j);
        }

    sort(rijec.begin(),rijec.end());

    cout<<rijec[0]<<endl;
    return 0;
}
