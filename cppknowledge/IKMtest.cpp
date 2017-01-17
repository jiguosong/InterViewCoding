//
// Created by songjiguo on 1/16/17.
//

/*
 * inheritance.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: songjiguo
 */

// these are some note code: IKM

#include <iostream>
#include <string>
#include "pprint.h"

using namespace std;

// http://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance#1372858

/////////////////////
///////   0  ///////
/////////////////////

//#define X 1   // this will display #error x is 1
//
//#if X == 2
//#error x is 2
//
//#elif X == 3
//#error x is 3
//
//#else
//    #if X == 1
//        #error x is 1
//    #else
//        #error x is not 1
//    #endif
//#endif


/////////////////////
///////   1   ///////
/////////////////////
class Person {
    string *namePtr;
public:
    Person()
    {
        namePtr = new string;
    }

    void setName(char *s)
    {
        *namePtr = s;
    }

    string *getName()
    {
        return namePtr;
    }
};

/////////////////////
///////   2   ///////
/////////////////////

class Object1 {
    virtual ~Object1()
    {
    }
};

class Object2 {
    virtual ~Object2()
    {
    }
};

/////////////////////
///////   3   ///////
/////////////////////

class widget {
};

/////////////////////
///////   4   ///////
/////////////////////

class Sup {
protected:
    int storage;
public:
    void set(int val)
    {
        storage = val;
    }

    int get()
    {
        return storage;
    }
};

class Sub : public Sup {
public:
    void print(void)
    {
        cout << "storage in sub " << storage << endl;
    }
};

/////////////////////
///////   5   ///////
/////////////////////

class Fruit {
public:
    int weight;
    char season;
};

class Apple : public Fruit {
public:
    enum variety {
        Gala, Fuji, Granny
    };

    void setVariety(variety v)
    {
        type = v;
    }

private:
    variety type;
};

class Orange : Fruit {
    enum use {
        Easting, Juice
    };

public:
    using Fruit::season;
    use type;
};


/////////////////////
///////   6   ///////
/////////////////////
class Record {
    //version 1
    bool operator<(const Record &rhs)
    {
        return this->num > rhs.num;
    }

    //version 2
    friend bool operator<(const Record &lhs, const Record &rhs) //friend claim has to be here
    {
        return lhs.num > rhs.num;
    }

private:
    char c;
    int num;
};

////version 3
//inline bool operator<(const Record &lhs, const Record &rhs)
//{
//    return lhs.num > rhs.num;
//}





/////////////////////
///////   7 catch   ///////
/////////////////////
//http://stackoverflow.com/questions/233127/how-can-i-propagate-exceptions-between-threads

//catch blocks are processed in program order to find a matching type, an ellipsis handler must be the last handler for the associated try block. Use catch(...) with caution; do not allow a program to continue unless the catch block knows how to handle the specific exception that is caught. Typically, a catch(...) block is used to log errors and perform special cleanup before program execution is stopped.
//
//A throw expression that has no operand re-throws the exception currently being handled. We recommend this form when re-throwing the exception, because this preserves the original exception’s polymorphic type information. Such an expression should only be used in a catch handler or in a function that's called from a catch handler. The re-thrown exception object is the original exception object, not a copy.
//
//try {
//throw CSomeOtherException();
//}
//catch(...) {
//// Catch all exceptions – dangerous!!!
//// Respond (perhaps only partially) to the exception, then
//// re-throw to pass the exception to some other handler
//// ...
//throw;
//}
#include <exception>      // std::exception_ptr, std::current_exception, std::rethrow_exception
#include <stdexcept>      // std::logic_error
#include <sstream>
#include <algorithm>


/////////////////////
///////   8 inheritance   ///////
/////////////////////
//IMPORTANT NOTE: Classes B, C and D all contain the variables x, y and z. It is just question of access.
class A {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};


/////////////////////
///////   10    ///////
/////////////////////

class Dwelling {
    int sqaureFootage;
    int levels;
    char type;
};

class House : public Dwelling {
public:
    enum {
        flat, gable, hip
    } roofStyle;
};

class MultiUnit : public Dwelling {
    int numUnits;
};

/////////////////////
///////   11   operator overloading  ///////
/////////////////////

// http://stackoverflow.com/questions/4421706/operator-overloading#4421719
// http://stackoverflow.com/questions/12077322/why-operator-can-not-be-overloaded-in-c#12077422
// http://stackoverflow.com/questions/1145022/difference-between-global-operator-and-member-operator#1145058

/////////////////////
///////  12 casting  ///////
/////////////////////
//http://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast
// http://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used#332086
// can not use dynamic_cast for downcasting
// You cannot use dynamic_cast if you downcast and the argument type is not polymorphic
// An "up-cast" is always valid with both static_cast and dynamic_cast, and also without any cast,
// as an "up-cast" is an implicit conversion


class MyClass {
    int a;
};

void func(void *data)
{
    // Conversion from MyClass* -> void* is implicit
    MyClass *c = static_cast<MyClass *>(data);
}


/////////////////////
///////   13   ///////
/////////////////////
double getSince(double d)
{ return std::sin(d); }


/////////////////////
///////   14   ///////
/////////////////////
class SomeClass {
protected:
    int data;

    friend class AnotherClass;
};

void SomeFunc(SomeClass sc)
{
    //sc.data = 5;  //error: ‘int SomeClass::data’ is protected
    int a = 1;
}

class AnotherClass {
public:
    void Another(SomeClass sc)
    {
        sc.data = 25;
    }

    friend void SomeFunc(SomeClass sc);
};


/////////////////////
///////   15   ///////
/////////////////////

template<class T>
class Some {
public:
    static int stat;
};

template<class T>
int Some<T>::stat = 10;


/////////////////////
///////   16  car ///////
/////////////////////
class Car {
    int position;
public:
    Car() : position(0)
    { };

    virtual void drive()
    { position += 1; };
};


class Taxi : public Car {

};

class Limo : public Car {

};

void startMeter()
{ cout << " where to ?" << endl; }




/////////////////////
///////   17  fn ptr ///////
/////////////////////

class MyClass2 {
    double scores[100];
public:
    double avg()
    { };
};


/////////////////////
///////   18 ///////
/////////////////////
int b = 1;
int x() {b++; return b;}
int y() {b*=3; return b-1;}
int z() {b = b + 8; return b+2;}


// http://en.cppreference.com/w/cpp/language/type_alias



/////////////////////
///////   19 declare pointer///////
/////////////////////
class SomeClassforPtr {
public:
    int iData;
};

int main()
{

    /////////////////////
///////   19   ///////
/////////////////////
    //SomeClassforPtr sc;
    //int *SomeClassforPtr::pData = &SomeClassforPtr::iData;  //wrong
    //SomeClassforPtr::*pData = &sc.iData;   //wrong
    //int * SomeClassforPtr::pData = &sc.iData; //wrong
    //SomeClassforPtr::*pData = &SomeClassforPtr::iData; //wrong
    int SomeClassforPtr::*pData = &SomeClassforPtr::iData;  // OK




/////////////////////
///////   12   ///////
/////////////////////
    MyClass c;
    //start_thread(&func, &c)  // func(&c) will be called
    //        .join();

/////////////////////
///////   1   ///////
/////////////////////
    Person president;
    Person chairman;

    president.setName("Tom");
    chairman = president;

    cout << *chairman.getName() << endl;


    //delete &president;  //this will cause fault

    chairman.setName("ASDASDASDASDS");
    cout << *president.getName() << endl;
    cout << *chairman.getName() << endl;

    //class D3 : B { / ... / }; // B private by default
    //struct D6 : B { / ... / }; // B public by default

    Orange f1;
    Apple f2;
    // how to generate access error here?
    f1.season = 'S';
    //f1.type = Orange::Juice;  //  error: ‘Orange::use Juice’ is private
    //f1.weight = 12;           //  error: ‘int Fruit::weight’ is inaccessible
    f2.setVariety(Apple::Fuji);
    f2.weight = 14;

    Sup object;
    object.set(100);
    int ans = object.get();
    cout << ans << endl;

    Sub object_sub;
    object_sub.set(101);
    int ans_sub = object_sub.get();
    cout << ans_sub << endl;
    object_sub.print();

    /////////////////////
    ///////   4 enum   ///////
    /////////////////////
    cout << "---4---" << endl;
    enum DAY {
        Mon = 11, Tue = 12
    };
    enum DAY var = Mon;
    cout << var << endl;
    enum DAY var2 = DAY::Mon;
    cout << var2 << endl;
    enum DAY var3 = static_cast<enum DAY>(Mon);
    cout << var3 << endl;
    /////////////////////
    ///////   5    ///////
    /////////////////////
    cout << "---5---" << endl;
    widget const *cw = new widget;
    widget *w;

    w = const_cast<widget *>(cw);

    Object2 *obj3 = new Object2;
    std::cout << obj3 << std::endl;
    std::cout << dynamic_cast<Object1 *>(obj3) << std::endl;

    /////////////////////
    ///////   6   ///////
    /////////////////////
    cout << "---6---" << endl;

    short high = 0x0060;
    short low = 0x0003;
    short res = low | high;

    cout << res << endl;

    /////////////////////
    ///////   7  ///////
    /////////////////////
    cout << "---7---" << endl;
    //for (;;)          // endless
    for (int i = 15; i; i--);

    //for(true);   // wrong
    for (double d = 1.0; d <= 1.9; d += 0.1) {
        cout << "sdfsdf " << d << endl;
    }
    //for(int i = 0, i < 10, i++);  // wrong


    /////////////////////
    ///////   8 exception ///////
    /////////////////////
    // http://stackoverflow.com/questions/9562053/do-the-default-catch-throw-statements-in-c-pass-by-value-or-reference#9562110
    cout << "---8---" << endl;
    std::exception_ptr p;
    try {
        throw std::logic_error("some logic_error exception");   // throws
    } catch (const std::exception &e) {
        p = std::current_exception();
        std::cout << "exception caught, but continuing...\n";
    }

    std::cout << "(after exception)\n";

    try {
        std::rethrow_exception(p);
    } catch (const std::exception &e) {
        std::cout << "exception caught: " << e.what() << '\n';
    }

    /////////////////////
    ///////   9 stringstream   ///////
    /////////////////////
    cout << "---9---" << endl;
    int iAge;
    string sAge = "24";
    istringstream ins;
    ins.str(sAge);

    ins >> iAge;
    cout << iAge << endl;

    /////////////////////
    ///////   10   ///////
    /////////////////////
    cout << "---10---" << endl;
    Dwelling hut;
    House home;
    MultiUnit building;
    //home.roofStyle = 1;

    cout << sizeof(home) << endl;

    Dwelling myResidence = static_cast<Dwelling>(home);
    cout << sizeof(myResidence) << endl;

    /////////////////////
    ///////   13   ///////
    /////////////////////
    cout << "---13---" << endl;


    const double PI = 3.14159;
    vector<double> angles;
    vector<double> sines;

    angles.push_back(-PI / 2);
    angles.push_back(-PI / 3);
    angles.push_back(-PI / 4);
    angles.push_back(-PI / 6);

    //cout << angles.size() << endl;
    //transform(angles.begin(), angles.end(), sines.begin(),
    //         getSince);  // sines must have some space !!!!  --> this line faults
    //cout << pprint::to_string(sines) << endl;

    angles.empty();
    angles.push_back(0);
    angles.push_back(PI / 6);
    angles.push_back(PI / 4);
    angles.push_back(PI / 3);
    angles.push_back(PI / 2);

    //cout << angles.size() << endl;
    //cout << pprint::to_string(angles) << endl;
    //transform(angles.begin(), angles.end(), sines.end(), getSince);

    /////////////////////
    ///////   14   ///////
    /////////////////////
    cout << "---14---" << endl;
    SomeClass sc;
    SomeFunc(sc);
    //cout << sc.data;  // error: ‘int SomeClass::data’ is protected

    /////////////////////
    ///////   15   ///////
    /////////////////////
    cout << "---15---" << endl;
    Some<int>::stat = 5;
    cout << Some<int>::stat << "    ";
    cout << Some<char>::stat << "    ";
    cout << Some<float>::stat << "    ";
    cout << Some<long>::stat << endl;

    /////////////////////
    ///////   16   ///////
    /////////////////////
    cout << "---16---" << endl;

    Car c1;
    Taxi c2;
    Limo c3;
    Car *Cars[3] = {&c1, &c2, &c3};
    Car *cp;

    for (int j = 0; j < 3; ++j) {
        cp = Cars[j];

        //cout << typeid(*cp).name() << endl;
        //cout << typeid(c2).name() << endl;
        //if (typeid(*cp) == typeid(c2)) { startMeter(); }

        cout << typeid(*cp).name() << endl;
        cout << typeid(Taxi).name() << endl;
        if (typeid(*cp) == typeid(Taxi)) { startMeter(); }

//        cout << typeid(cp).name() << endl;
//        cout << typeid(c2).name() << endl;
//        if (typeid(cp) == typeid(c2)) { startMeter(); }

//        cout << typeid(cp).name() << endl;
//        cout << typeid(Taxi).name() << endl;
//        if (typeid(cp) == typeid(Taxi)) { startMeter(); }

        cp->drive();
    }


    /////////////////////
    ///////   17   fn ptr ///////
    /////////////////////
    cout << "---17---" << endl;

    double (MyClass2::*f)();
    f = &MyClass2::avg;  // ok
    //double (MyClass2::ptr)();   ptr = &MyClass2::avg;  // wrong
    //double (*fptr)();   fptr = &MyClass2::avg;  // wrong
    //double (MyClass2::*f4());  *f4 = &MyClass2::avg;  // wrong
    double (MyClass2::*f3)() = &MyClass2::avg;  // ok


    /////////////////////
    ///////   18 ///////
    /////////////////////
    cout << "---18---" << endl;
    int a = x() - y() + z();
    cout << a << endl;  // 13


    /////////////////////
    ///////   20 convert ///////
    /////////////////////
    cout << "---20---" << endl;
    char *str = "123";
    int aa;
    // scanf(str, "%d", &aa); cout << aa << endl;  // wrong
    // aa = atoi(str); cout << aa << endl;   // OK
    //sscanf(str, "%d", &aa);cout << aa << endl;  // OK
    // atoi(str, &aa); cout << aa << endl;     // wrong
    aa = atof(str); cout << aa << endl;  // OK


    cout << "---end---" << endl;
}