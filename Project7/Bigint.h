#ifndef BIGINT_H
#define BIGINT_H
#include <cstring>
#include <iostream>
using namespace std;

class Bigint{
    size_t size;
    size_t len;
    char*s;
    bool isZero;

    public:
        Bigint(size_t);
        Bigint(const char*);
        Bigint(const Bigint&);
        ~Bigint();

        Bigint operator+(const Bigint& );
        Bigint &operator+=(const Bigint& );
        Bigint &operator=(const Bigint& );
        Bigint operator*(const Bigint&);
        bool operator==(const Bigint& );
        bool operator>(const Bigint& );
        bool operator<(const Bigint& );
        bool operator>=(const Bigint& );
        bool operator<=(const Bigint& );
        bool operator!=(const Bigint& );
        friend ostream& operator<<(ostream &os,const Bigint&);
};
#endif