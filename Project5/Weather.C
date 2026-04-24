#include "Weather.h"
#include <ctime>
#include <stdlib.h>


Weather::Weather():current(rand()%5+1){}

int Weather::Getweather(){
    return current;
}

void Weather::UpdateWeather(){
    double p1 = (double)rand()/RAND_MAX;
    switch (current)
    {
    case 1:
        if (p1<0.1)current =1;
        else if(p1<0.4)current = 2;
        else if(p1<0.8)current = 5;
        else if(p1<1.0)current = 3;
        break;
    
    case 2:
        if (p1<0.2)current =2;
        else if(p1<0.5)current = 1;
        else if(p1<0.8)current = 5;
        else if(p1<0.9)current = 3;
        else if(p1<1.0)current = 4;
        break;
    
    case 3:
        if (p1<0.1)current =3;
        else if(p1<0.4)current = 5;
        else if(p1<0.6)current = 1;
        else if(p1<0.9)current = 4;
        else if(p1<1.0)current = 2;
        break;

    case 4:
        if (p1<0.2)current =4;
        else if(p1<0.4)current = 5;
        else if(p1<0.7)current = 1;
        else if(p1<0.9)current = 3;
        else if(p1<1.0)current = 2;
        break;

    case 5:
        if (p1<0.2)current =5;
        else if(p1<0.4)current = 1;
        else if(p1<0.6)current = 2;
        else if(p1<0.8)current = 3;
        else if(p1<1.0)current = 4;
        break;
        
    default:
        break;
    }
}