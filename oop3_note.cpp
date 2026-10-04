/*
C'tor and D'tor

class X:
{
    public:
        X();    // constructor 没有写的话编译器会自动生成 c++里struct也可以有构造函数
        ~X();   // destructor 当object生命周期终止时调用 一般没有参数
};

void f() {  // 进入左括号opening brace（作用域scope）分配空间
    X a;    // equavalent to a.X(); 若自己定义了带参数的C'tor，那么调用时一定要带参数，否则报错
            // 调用C'tor
}   // D'tor调用
*/

#include<iostream>

using namespace std;

class Point // 初始化列表时直接在内存分配时候完成赋值，比先初始化再赋值效率更高
{
    private:
        const float x, y;   // const常量的值必须在对象创建时就确定，因此必须使用初始化列表
        Point (float xa = 0.0, float ya = 0.0): y(ya), x(xa) {  // C'tor
            // ...
        }   // 伪构造函数，其实相当于直接赋值
};  // x先声明，y后声明，初始化顺序x前y后，销毁y前x后 注意不是列表里的顺序

    /*
    initialization: Stud::Stud(string s) :name(s) {}    // 初始化列表 在构造函数执行前完成 name(s)直接带参构造，跳过default C'tor
    assignment: Stud::Stud(string s) { name = s }       // 在构造函数内部进行，先调用string的默认构造函数初始化name  再赋值
                                                           开销更大 适用普通成员，而且必须要有默认构造函数
    */

    /*
    Default Construtor 默认构造函数 不传入任何参数的情况下创建对象
    class Stud {
    public:
        Stud() {}   eg: Stud s; Stud arr[5];    // 编译器会为每个元素调用默认构造函数
    };

    class Point {
    public:
        Point(float x = 0.0, float y = 0.0) {   // Point p1; x: 0, y: 0;
            this->x = x;                        // Point p2(5.0); x: 5.0, y: 0; x改变y默认
            this->y = y;
        }
    };
    */
int main() {
    // Aggregate initialization
    int arr1[6] = {5};   // [5,0,0,0,0,0]
    // for (int i = 0; i < 6; i++) {
    //     cout << arr[i] << endl;
    // }
    int arr2[] = {1, 2, 3, 4};  // num = sizeof(arr2) / sizeof(*arr2) 第一个元素
    /*
    fields (member variables) lifetime as long as objects, maintian current state of object
    have scope（作用域）
    parameters 形参 local variable 局部变量 lifetime: a function call
    */

    /*
    overload and the default argument
    to define a function with default argumnets
    defaults must be added from right to left
    int f(int n, int m = 6, int j); // illegal

    Const member function can't call a no const function
    */

    /*
    inline 请求（一种建议，并非强制）编译器直接把函数的代码嵌入调用处，而非通过“函数调用”进行，减小开销
    适合短小，频繁使用，类内定义成员函数会默认inline eg:
    class Stud {
    private:
        int age;
    public:
        inline int getAge() const { return age ;}   // 建议写成const如果函数确定不改变data
        inline void setAge(int a) { age = a; }
    }
    can put inline functions' bodies in header files // 普通函数不能放头文件
    相比宏来说，检查了数据的类型，有作用域，会检查递归（过于复杂编译器会不认可作为inline）
    too large or call itself(recursion) 编译器会调用函数，不认为是inline
    在头文件里的都认为是inline
    */
    return 0;
}