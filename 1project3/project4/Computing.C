#include <iostream>
#include "Computing.h"
#include <ctime>
#include <stdlib.h>
#include <math.h>
using namespace std;

int MakeDecision(int weather,double p){
    double poss1 = (double)rand() /RAND_MAX;
    double poss2 = (double)rand() /RAND_MAX;
    double poss3 = (double)rand() /RAND_MAX;

    if (poss1 < p) return 0;
    else
    {
        switch (weather){
            case 1:
                if (poss2< (p/2.0) && poss3<p) return 1;
                else return 0;
                break;
            case 2:
                if (poss2< (p/2.0) && poss3>=p/2.0) return 1;
                else return 0;
                break;
            case 3:
                if (poss2 >= p && poss3 <p) return 1;
                else return 0;
                break;
            case 4:
                if (poss2 >= p && poss3>=p/2.0) return 1;
                else return 0;
                break;
            case 5:
                return 1;
        }
    }
}


double CompPlayPercentage(int *D,int count){
    int k =0;
    for (int i=0 ; i<count;i++){
        if (D[i]==1) k++;
    }
    double percent = k*1.0/count;
    return percent;
}   


void CompStatistics(double* percentages,int count,double& ave,double& std){
    double k =0.0;
    for (int i = 0;i<count;i++){
        k = k+percentages[i];
    }
    ave = k/count;
    double m = 0.0;
    for (int i = 0;i<count;i++){
        m = m + pow((percentages[i]-ave),2);
    }
    m = m/count;
    std = pow(m,0.5);
    
}