#include<iostream>
#include "project1.h"
using namespace std;
extern int map[20][45];
extern int n,m;
block::block(string s,int place, int move)
{
    if(s=="T1"){
        x1 = place;
        y1 = 3;
        x2 = place+1;
        y2 = 3;
        x3 = place+2;
        y3 = 3;
        x4 = place+1;
        y4 = 4;
        this->move = move;
    }
    else if(s=="T2"){
        x1 = place;
        y1 = 3;
        x2 = place+1;
        y2 = 2;
        x3 = place+1;
        y3 = 3;
        x4 = place+1;
        y4 = 4;
        this->move = move;
    }
    else if(s=="T3"){
        x1 = place+1;
        y1 = 3;
        x2 = place;
        y2 = 4;
        x3 = place+1;
        y3 = 4;
        x4 = place+2;
        y4 = 4;
        this->move = move;
    }
    else if(s=="T4"){
        x1 = place;
        y1 = 2;
        x2 = place;
        y2 = 3;
        x3 = place+1;
        y3 = 3;
        x4 = place;
        y4 = 4;
        this->move = move;
    }
    else if(s=="L1"){
        x1 = place;
        y1 = 2;
        x2 = place;
        y2 = 3;
        x3 = place;
        y3 = 4;
        x4 = place+1;
        y4 = 4;
        this->move = move;
    }
    else if(s=="L2"){
        x1 = place;
        y1 = 3;
        x2 = place+1;
        y2 = 3;
        x3 = place+2;
        y3 = 3;
        x4 = place;
        y4 = 4;
        this->move = move;
    }
    else if(s=="L3"){
        x1 = place;
        y1 = 2;
        x2 = place+1;
        y2 = 2;
        x3 = place+1;
        y3 = 3;
        x4 = place+1;
        y4 = 4;
        this->move = move;
    }
    else if(s=="L4"){
        x1 = place;
        y1 = 4;
        x2 = place+1;
        y2 = 4;
        x3 = place+2;
        y3 = 4;
        x4 = place+2;
        y4 = 3;
        this->move = move;
    }
    else if(s=="J1"){
        x1 = place+1;
        y1 = 2;
        x2 = place+1;
        y2 = 3;
        x3 = place+1;
        y3 = 4;
        x4 = place;
        y4 = 4;
        this->move = move;
    }
    else if(s=="J2"){
        x1 = place;
        y1 = 2;
        x2 = place;
        y2 = 3;
        x3 = place+1;
        y3 = 4;
        x4 = place+2;
        y4 = 4;
        this->move = move;
    }
    else if(s=="J3"){
        x1 = place;
        y1 = 2;
        x2 = place;
        y2 = 3;
        x3 = place;
        y3 = 4;
        x4 = place+1;
        y4 = 2;
        this->move = move;
    }
    else if(s=="J4"){
        x1 = place;
        y1 = 3;
        x2 = place+1;
        y2 = 3;
        x3 = place+2;
        y3 = 3;
        x4 = place+2;
        y4 = 4;
        this->move = move;
    }
    else if(s=="I1"){
        x1 = place;
        y1 = 1;
        x2 = place;
        y2 = 2;
        x3 = place;
        y3 = 3;
        x4 = place;
        y4 = 4;
        this->move = move;
    }
    else if(s=="I2"){
        x1 = place;
        y1 = 4;
        x2 = place+1;
        y2 = 4;
        x3 = place+2;
        y3 = 4;
        x4 = place+3;
        y4 = 4;
        this->move = move;
    }
    else if(s=="O"){
        x1 = place;
        y1 = 3;
        x2 = place;
        y2 = 4;
        x3 = place+1;
        y3 = 3;
        x4 = place+1;
        y4 = 4;
        this->move = move;
    }
}
void error()
{
    cout<<"game over"<<'\n';
}
int* test()
{
    int high = 5;
    int flag = 0;
    int *f = new int[n+5];
    for(int i=0;i<=n+4;i++){
        f[i] = 0;
    }
    while(high<=n+4){
        flag=1;
        for(int i=1;i<=m;i++){
            if(map[high][i]==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            f[high]++;
        }
        high++;
    }
    // for(int i=1;i<=n+4;i++){
    //     cout<<f[i]<<" ";
    // }
    // cout<<'\n';
    return f;
}
void update(int *f)
{
    int stay[n+5];
    for(int i=0;i<=n+4;i++){
        if(f[i]==0){
            stay[i] = 1;
        }
        else{
            stay[i] = 0;
        }
    }
    for(int i=n+4;i>=1;i--){
        int j = i;
        if(stay[j]==1){
            while(stay[j+1]==0 && j<n+4){
                for(int k=1;k<=m;k++){
                    map[j+1][k] = map[j][k];
                }
                stay[j] = 0;
                stay[j+1] = 1;
                j++;
            }
        }
    }
}
void then()
{
    int* f;
    for(int i=0;i<4;i++){
        f = test();
        erase(f);
        update(f);
    }
}
void block::falling(block &a)
{
    while(map[a.y1+1][a.x1]==0 && map[a.y2+1][a.x2]==0 && map[a.y3+1][a.x3]==0 && map[a.y4+1][a.x4]==0 && y1+1<=n+4 && y2+1<=n+4 && y3+1<=n+4 && y4+1<=n+4){
        a.y1++;
        a.y2++;
        a.y3++;
        a.y4++;
    }
}
void block::mov(block &a)
{
    if(map[a.y1][a.x1+=a.move]==0 && map[a.y2][a.x2+=a.move]==0 && map[a.y3][a.x3+=a.move]==0 && map[a.y4][a.x4+=a.move]==0){
        while(map[a.y1+1][a.x1]==0 && map[a.y2+1][a.x2]==0 && map[a.y3+1][a.x3]==0 && map[a.y4+1][a.x4]==0 && y1+1<=n+4 && y2+1<=n+4 && y3+1<=n+4 && y4+1<=n+4){
            y1++;
            y2++;
            y3++;
            y4++;
        }
        map[a.y1][a.x1] = 1;
        map[a.y2][a.x2] = 1;
        map[a.y3][a.x3] = 1;
        map[a.y4][a.x4] = 1;
    }
    else{
        error();
    }
}
void detect_error()
{
    for(int i=1;i<=4;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]!=0){
                error();
                return ;
            }
        }
    }
}
void erase(int *f)
{
    for(int i=1;i<=n;i++){
        if(f[i]!=0){
            for(int j=1;j<=m;j++){
                map[i][j]=0;
            }
        }
    }
}