#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Decision.h"
using namespace std;

extern int *decision, *weather;
extern int cnt;


int main(){

    decision = new int[20];weather = new int[20];
    int i;
    srand(time(0));
    cout<<"Please input numbers from 1 to 5"<<endl;
    cout<<"input -1 to stop"<<endl;
    while (cnt<20){
        cin>>i;
        if (i ==-1) break;
        if  (i>=1 && i<=5){
            MakeDecision(i);
            cnt++;
        }
    }
    PrintResults(decision,weather,cnt);
    CompPlayPercentage(decision);
    delete[]decision;delete[]weather;
    return 0;
}

