#include <iostream>
#include "Experiment.h"
#include "Computing.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

double SingleTest(int p,int count){
    
    int *D =new int[count];
    for (int i =0;i<count;i++){
        int a = rand()%5 +1;
        D[i] = MakeDecision(a,p/10.0);
    }
    return CompPlayPercentage(D,count);
}

void MultipleTest(double* percentageArray,int p,int count){
    for (int i =0;i<count;i++){
        percentageArray[i] = SingleTest(p,10000);
    }
}

void DoExperiment(int count){
    double **M=new double*[8];
    int P[8]={2,3,4,5,6,7,8,9};
    for (int i = 0;i<8;i++){
        M[i] = new double[count] ;
        MultipleTest(M[i],P[i],count);
        double ave,std;
        CompStatistics(M[i],count,ave,std);
        cout<<"p="<<P[i]/10.0<<": ave="<<ave<<",std="<<std<<endl;
    }
    for (int i=0;i<8;i++) delete [] M[i];
    delete [] M;
}