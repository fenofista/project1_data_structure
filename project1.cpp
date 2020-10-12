#include <iostream>
#include "project1.h"
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;
int map[20][45];
int n, m;
int main(int argc, char *argv[])
{
    ifstream fin;
    fin.open(argv[1]);
    char N[10],trash, M[10];
    fin.getline(N,10);
    // fin.get(trash);
    // fin.get(M,10);
    //cout<<N<<M<<'\n';
    stringstream a(N);
    a >> n;
    a >> m;
    //cin >> n >> m;
    //cout<<n<<m<<'\n';
    int place, direction;
    char form1[100];
    while (!fin.eof())
    {

        fin.getline(form1, 10);
        cout<<form1<<'\n';
        stringstream ss(form1);
        string form;
        ss>>form;
        ss>>place;
        ss>>direction;
        cout<<form<<" "<<place<<" "<<direction<<'\n';
        if (form== "End")
        {
            break;
        }
         
        
        //cin >> place >> direction;
        block a(form, place, direction);
        if (place + direction > m || place + direction <= 0)
        {
            error();
        }
        a.falling(a);
        a.mov(a);
        a.falling(a);
        then();
        detect_error();
        int i;
    }
    for (int i = 5; i <= n + 4; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}
