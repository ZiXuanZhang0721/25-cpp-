#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Decision.h"
using namespace std;



int *decision = nullptr;
int *weather = nullptr;
int cnt = 0;
int MakeDecision(int i){

    int a1 =rand()%14;
    int a2 =rand()%5;
    int a3 =rand()%13;
    int a4 =rand()%7;
    int a5 =rand()%12;

    switch(i){
        case 1:
            weather[cnt]=1;
            if (a1<9 && a4<2 && a3<9)
                decision[cnt]=1   ;    
            else 
                decision[cnt]=0;
            return decision[cnt];
            break;

        case 2:
            weather[cnt] = 2;
            if (a1<9 && a4<2 && a4<2)
                decision[cnt]=1;       
            else 
                decision[cnt]=0;
            return decision[cnt];
            break;  

        case 3:
            weather[cnt] = 3;
            if (a1<9 && a2<3 && a4<2)
                decision[cnt]=1;     
            else 
                decision[cnt]=0;
            return decision[cnt];
            break;

        case 4:
            weather[cnt] = 4;
            if (a1<9 && a2<3 && a5<9)
                decision[cnt]=1;    
            else 
                decision[cnt]=0;
            return decision[cnt];
            break;

        case 5:
            weather[cnt] = 5;
            if (a1<9)
                decision[cnt]=1;    
            else 
                decision[cnt]=0;
            return decision[cnt];
            break;
        default:
            return -1;
            break;     
    }
         
}
void PrintResults(int*decision,int*weather ,int cnt){
    
    for (int i = 0;i<cnt;i++){
        switch(weather[i]){  
            case 1:
                cout<<i+1<<".Weather:sunny and humid"<<endl;
                if (decision[i]==1){
                    cout<<" Decision:play"<<endl;
                }else{
                    cout<<" Decision:not play"<<endl;
                }break;
            case 2:
                cout<<i+1<<".Weather:sunny and not humid"<<endl;
                if (decision[i]==1){
                    cout<<" Decision:play"<<endl;
                }else{
                    cout<<" Decision:not play"<<endl;
                }break;
            case 3:
                cout<<i+1<<".Weather:raining and windy"<<endl;
                if (decision[i]==1){
                    cout<<" Decision:play"<<endl;
                }else{
                    cout<<" Decision:not play"<<endl;
                }break;
            case 4:
                cout<<i+1<<".Weather:raining and not windy"<<endl;
                if (decision[i]==1){
                    cout<<" Decision:play"<<endl; 
                }else{
                    cout<<" Decision:not play"<<endl;
                }break;
            case 5:
                cout<<i+1<<".Weather:overcast"<<endl;
                if (decision[i]==1){
                    cout<<" Decision:play"<<endl; 
                }else{
                    cout<<" Decision:not play"<<endl;
                }break;
        }
    }
}


int CompPlayPercentage(int*decision){
    int i =0,sum=0;
    while (i<cnt){
        if (decision[i]==1){
        sum++;
        }
        i++;
    }
    double dev = (double)sum/cnt;
    cout << "the percentage is " << dev * 100 << '%' << endl;
    
    return 0;

}