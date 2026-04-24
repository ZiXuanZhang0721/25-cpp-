#include "Bigint.h"
#include <math.h>
Bigint::Bigint(size_t x){
    if (x==0) isZero = true;
    else isZero = false;
    len = 0;
    size_t original =x;
    size_t temp =x;
    while (temp>0){
        temp/= 10;
        len++;
    }
    size =len+1;
    s = new char[size];
    for (size_t i=0;i<len;i++){
        s[len-i-1] = '0' + (original % 10); 
        original/=10;
    }
    s[len] = '\0';
}

Bigint::Bigint(const char* str){
    len = strlen(str);
    size = len+1;
    s = new char[size];
    strcpy(s,str);
    if (len==1 && str[0]=='0') isZero = true;
    else isZero = false;
}

Bigint::Bigint(const Bigint& x){
    size = x.size;
    len =x.len;
    isZero = x.isZero;
    s = new char[size];
    strcpy(s,x.s);
}

Bigint::~Bigint(){
    delete[] s;
}


Bigint Bigint::operator+(const Bigint &other) {
    size_t maxlen = (len > other.len) ? len : other.len;
    char* result_str = new char[maxlen + 2];
    int carry = 0;
    for (size_t i = 0; i < maxlen; i++) {
        int digit1 = (i < len) ? (s[len - 1 - i] - '0') : 0;
        int digit2 = (i < other.len) ? (other.s[other.len - 1 - i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        
        result_str[maxlen - 1 - i] = '0' + (sum % 10);
        carry = sum / 10;
    }
    
    if (carry > 0) {
        for (size_t i = maxlen; i > 0; i--) {
            result_str[i] = result_str[i - 1];
        }
        result_str[0] = '0' + carry;
        result_str[maxlen + 1] = '\0';
    } else {
        result_str[maxlen] = '\0';
    }
    
    Bigint result(result_str);
    delete[] result_str;
    return result;
}
//this: 123
//other:123
Bigint Bigint::operator*(const Bigint& other) {
    int x=0;
    if (isZero || other.isZero) {
        return Bigint(x);
    }
    
    Bigint result(x);
    
    for (size_t i = 0; i < other.len; i++) {
        int digit = other.s[other.len - 1 - i] - '0';
        
        if (digit > 0) {
            size_t total_len = len + i;
            char* temp_str = new char[total_len + 1];
            
            for (size_t j = 0; j < len; j++) {
                temp_str[j] = s[j];
            }
            for (size_t j = 0; j < i; j++) {
                temp_str[len + j] = '0';
            }
            temp_str[total_len] = '\0';
            
            Bigint temp_num(temp_str);
            delete[] temp_str;
            
            for (int j = 0; j < digit; j++) {
                result = result + temp_num;
            }
        }
    }
    
    return result;
}
Bigint& Bigint::operator+=(const Bigint& other) {
    *this = *this + other; 
    return *this;         
}

Bigint& Bigint::operator=(const Bigint& other){
    if (this == &other) {
        return *this; 
    }
    this->isZero = other.isZero;
    this->len = other.len;
    this->size = other.size;
    delete []s;
    s = new char[size];
    strcpy(s,other.s);
    return *this;
}

bool Bigint::operator==(const Bigint& other){
    bool flag =true;
    if (this->len != other.len) flag =false;
    else {
        for (size_t i =0;i<this->len;i++){
            if (this->s[i] != other.s[i]) {
                flag =false;
                break;
            }
        }
    }
    return flag;
}

bool Bigint::operator>(const Bigint& other){
    bool flag=true;
    if (this->len<other.len) flag =false;
    else if (this->len>other.len) flag= true;
    else if (*this==other) flag = false;
    else{
        for (size_t i =0;i<this->len;i++){
            if (this->s[i]<other.s[i]) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

bool Bigint::operator<(const Bigint& other){
    bool flag=true;
    if (this->len>other.len) flag =false;
    else if (this->len<other.len) flag= true;
    else if (*this==other) flag = false;
    else{
        for (size_t i =0;i<this->len;i++){
            if (this->s[i]>other.s[i]) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

bool Bigint::operator>=(const Bigint& other){
    return (*this>other || *this ==other);
}

bool Bigint::operator<=(const Bigint& other){
    return (*this<other || *this ==other);
}

bool Bigint::operator!=(const Bigint& other){
    return !(*this == other);
}

ostream& operator<<(ostream &os,const Bigint& x){
    for (size_t i =0;i<x.len;i++){
        os<<x.s[i];
    }
    return os; 
}