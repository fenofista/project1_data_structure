#include<iostream>
using namespace std;
int map[15][40];
int n,m;
void T1(int place)
{
    int high = 0;
    while(map[place][high]==0 &&  map[place+2][high] ==0  && map[place+1][high+1]==0 && high<m-1){
        high++;
    }
    if(high==0 || place<0 || place>n-3){
        cout<<"game over"<<'\n';
    }
    map[place][high-1]=1;
    map[place+1][high-1]=1;
    map[place+2][high-1]=1;
    map[place+1][high-0]=1;
    
}
int main(){
    cin>>n>>m;
    int place, direction;
    string form;
    int type;
    while(cin>>form){
        if(form=="END"){
            break;
        }
        cin>>place>>direction;
        place--;
        if(form[0]=='T'){
            if(form[1]=='1'){
                T1(place+direction);
            }
            else if(form[1]=='2'){
                
            }
            else if(form[1]=='3'){
                
            }
            else if(form[1]=='4'){
                
            }
        }
        else if(form[0]=='L'){
            if(form[1]=='1'){

            }
            else if(form[1]=='2'){
                
            }
            else if(form[1]=='3'){
                
            }
            else if(form[1]=='4'){
                
            }
        }
        else if(form[0]=='J'){
            if(form[1]=='1'){

            }
            else if(form[1]=='2'){
                
            }
            else if(form[1]=='3'){
                
            }
            else if(form[1]=='4'){
                
            }
        }
        else if(form[0]=='S'){
            if(form[1]=='1'){

            }
            else if(form[1]=='2'){
                
            }
        }
        else if(form[0]=='Z'){
            if(form[1]=='1'){

            }
            else if(form[1]=='2'){
                
            }
        }
        else if(form[0]=='I'){
            if(form[1]=='1'){

            }
            else if(form[1]=='2'){
                
            }
        }
        else if(form[0]=='O'){
            if(form[1]=='1'){

            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<map[j][i];
            }
            cout<<'\n';
        }
    }
    return 0;
}

