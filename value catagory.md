```
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
```

##1. concepts of each value
    ###a. pure left value
        int x = 10;
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        int *p = nullptr;

    the object can change, take usage of memory;

    ###b. right value
        10;
        a + b;
        string("hello");
        function()```

    the object has **no identity**, and we only wonder its value.

    ###c. xvalue
        move(x);



    the object is deemed as a temporary object, and will be destroyed after the expression is evaluated.
    caution:
        1.essentially,xvlue is a type of lvalue;
        2.but compiler think xvalue is equivalent to rvalue reference(&&);


##2. variables of each reference type
    ###a. lvalue reference
        int &ref = x;
    ###b. rvalue reference
        int &&ref = 10;
    ###c. xvalue reference 
        int &&ref = move(x);

    then let's combine them together:
        vector<int> vec = {2,2,3,9,11,6,7,1,4,10};
        void L_sortVec(vector<int>& vec){
            sort(vec.begin(),vec.end());
        }
        //this is a function that sort the vector in ascending order,using lvalue reference;

        void R_sortVec(vector<int>&& vec){//the parameter is rvalue reference;
            sort(vec.begin(),vec.end());
        }
        //how will it work if we let R_sortVec accept xvalue?

        int main(){
        vector<int> vec = {2,2,3,9,11,6,7,1,4,10};
        L_sortVec(vec);
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i]<<endl;
        }
        **R_sortVec(move(vec));**
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i]<<endl;
        }
    }
    ```
    Both way work,even the same result;
    we use "std::move" to convert lvalue to xvalue;
    and xvalue reference is equivalent to rvalue reference in complier's perspective;
    so that parameter of R_sortVec can be xvalue;
    That testify our initial concept of rvalue reference!
        
    another example:
    int main(){
        int x = 0;
        cout << x << endl; //the result is 0;
        **int &a = x;**
        a = 1;
        cout << x << endl; //the result is 1;
        **int &&b = move(x);** //b is rvalue reference,so we have to use move to convert it to xvalue(just a laber!);
        b = 2;
        cout << b << endl; //the result is 2;
        cout << x << endl; //the result is 2;
    }
    rvalue reference also can bind to xvalue and change it;

##3. moving constructor and moving assignment operator in definition


    using rvalue reference to avoid deep copy,thus improve performance;


    class MyClass{
        public:
            MyClass(int x){
                data = new int(x);
            }
            ~MyClass(){
                delete data;
            }
            MyClass(MyClass&& other){//moving constructor
                data = other.data;
                other.data = nullptr;
            }
            MyClass& operator=(MyClass&& other){//moving assignment operator
                if(this != &other){
                    delete data;
                    data = other.data;
                    other.data = nullptr;
                }
                return *this;
            }
        private:
            int *data;
    };

##4.auto keyword in reference
    auto a = 10;
    a is int type;
    auto &b = a;
    b is int& type;
    auto &&c = move(a);
    c is int&& type;

    "auto &&" is a universal reference, it can bind to lvalue and rvalue;

