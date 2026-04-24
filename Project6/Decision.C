#include <math.h>
#include "Decision.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int Decision::MakeDecision (int weather)
{
    double dice;
    double x = p*100.0;
    dice = rand () % 100;
    if (dice < x) return 1;
    
    if (weather == 5) return 0;
    if (weather < 3)
    {
        dice = rand () % 100;

        if (dice >= x/2.0) return 1;
        if (weather == 1)
        {             //humid
            dice = rand () % 100;
            if (dice < x) return 0;  //play——
        }
        else
        {
            dice = rand () % 100;
            if (dice < x/2.0) return 1;
            else return 0;    //play
        }
    }
        else
    {
        dice = rand () % 100;
        if (dice < x) return 1;    //not play
        if (weather == 3)
        {            //windy
            dice = rand () % 100;
            if (dice < x) return 0;    //play
            else return 1;    //not play
        }
        else
        {
            dice = rand () % 100;
            if (dice < x/2.0) return 1;    //play
            else return 0;    //not play
        }
    }
}

Decision::Decision(double x) : p (x) {}


