#include<iostream>

using namespace std;

class Point
{
    public: // 可以直接加上函数的定义，但是不推荐，应当声明放在头文件，实现放在.cpp
    void init(int x, int y);
    void move(int dx, int dy);
    void print() const; // const修饰的是this指针（当前类的实例对象） 这个函数只读取数据不修改

    private:
    int x;
    int y;
};

    // 在.cpp文件中实现函数 implementation
    /*
    <class name>::<function name> or ::<function name>  后者是全局下的函数
    */

    /*
    Stash typeless but stores objects of the same type
    expand when need (dynamically)
    */

    /*
    This
    在implementation中，函数的实现void Stash::init(int i) 等价于 void Stash::init(Stash *this, int i)
    在cpp文件里面实现的时候 a.init(i) 此时this指向a 等价于 Stash::init(&a, i)
    */

    /*
    Class declaration in the header file(.h) and the body of functions are in .cpp
    class.h class.cpp main.cpp(declare the "class.h")
    in class.h: extern vars functions prototype class/struct declaration
    
    Compile Unit
    compiler sees only one .cpp file and generate .obj file
    linker links all .obj into one executable file

    #include"xx.h" 现在源文件所在的目录找，没找到再去编译器预设的系统头文件目录里面找
    #include<xx.h> 和 #include<xx> 完全等价，编译器会自动补全，直接去预设的系统头文件找
    正常一个头文件里面声明一个class，头文件与声明一一对应 a.h a.cpp
    多个源文件引用同一个头文件，复杂引用时候，要做头文件保护
    #ifndef HEADER_FLAG // 如果没有被定义
    #define HEADER_FLAG
    // type declaration
    #endif
    #pragma once    equavalent to #ifndef...

    // eg: person.h

    #ifndef PERSON_H    // 如果没有 PERSON_H 这个宏
    #define PERSON_H    // 定义宏，标记头文件已被包含

    #include<string>

    class Person
    {
    private:
        std::string name;
        int age;
    public:
        Person(std::string name, int age);
        void show_info();
    };
    // 头文件内容结束

    #endif

    或者

    #pragma once

    #include<string>

    class Person
    {
    private:
        std::string name;
        int age;
    public:
        Person(std::string name, int age);
        void show_info();
    };

    Makefile utility
    
    */