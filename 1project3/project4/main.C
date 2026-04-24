#include <iostream>
#include "Experiment.h"
#include "Computing.h"
#include <ctime>
#include <stdlib.h>


int main(){
    srand(time(NULL));
    DoExperiment(1000);
    return 0;

}