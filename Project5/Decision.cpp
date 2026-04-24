#include <iostream>
#include "Decision.h"
#include <cstdlib>
using namespace std;


        Decision::Decision(double p):x(p){};
        int Decision::MakeDecision(int Weather){
            double poss1 = (double)rand() /RAND_MAX;
            double poss2 = (double)rand() /RAND_MAX;
            double poss3 = (double)rand() /RAND_MAX;

            if (poss1 < x) return 0;
            else
            {
                switch (Weather){
                    case 1:
                        if (poss2< (x/2.0) && poss3<x) return 1;
                        else return 0;
                        break;
                    case 2:
                        if (poss2< (x/2.0) && poss3>=x/2.0) return 1;
                        else return 0;
                        break;
                    case 3:
                        if (poss2 >= x && poss3 <x) return 1;
                        else return 0;
                        break;
                    case 4:
                        if (poss2 >= x && poss3>=x/2.0) return 1;
                        else return 0;
                        break;
                    case 5:
                        return 1;
                        break;
                    default:
                        return -1;
                        break;
                }
            }
        }
