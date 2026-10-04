/*
Pure virtual function
定义：virtual double area() = 0;    // 函数末尾加上“ = 0 ”
Abstract base class
包含纯虚函数的类称为抽象类，无法直接实例化对象
抽象类的派生类必须覆盖基类所有的纯虚函数，不然派生类也为抽象类
Why use them?
-Modeling
-Force correct behavior
-Define interface without defining an implementation
*/

/*
Copy Ctor 拷贝构造 don't rely on the default
用一个已存在的对象创建一个全新的完全相同的对象
第一个参数必须是同类对象的引用
如果没有显式定义，编译器会自动生成一个默认的拷贝构造函数
class Myclass {
public:
    Myclass(const Myclass& other){}
};
调用拷贝构造
1 初始化
Myclass a;
Myclass b = a;  // copy ctor
Myclass c(a);   // copy ctor
2 pass-by-value
void func(Myclass obj) {}
func(a);    // copy ctor 把a拷贝给形参 同时调用结束return tmp;也会copy ctor
*/

/*
Static
internal linkage
只能在当前.cpp文件中可见，别的.cpp文件不可见，即使声明了extern，但是在.h文件里不一样
and static storage
静态存储，只分配一次而且地址固定
eg: 
class X {
    X(int x);
    ~X();
};
void f() {
    static X my_X(10);  // 无论f调用多少次，my_X只会被构造一次
}
void f() {
    if (x > 10) {
        static X my_X();    // conditional construction
    }
}
用static修饰类成员
静态成员仍然遵循类访问的控制规则，但是生命周期独立于类的实例，程序启动时分配内存，程序结束后释放
静态成员函数不能直接访问非静态的成员变量（生命周期不同，没有this指针）
have no implicit receiver "this"
静态成员函数 only access member variables or other globals
can't be dynamically overriden 
静态成员变量不允许放在函数内部（类级别的成员，在类内声明）
静态成员变量不允许在ctor中初始化列表中初始化（生命周期不同）
*/

/*
Global object
ctors are called before main() is entered
*/

/*
STL = standard template library
标准模板库 all the identifiers in library are in std namespace
Container
    Sequence Container: vector, queue, list, array, forward_list
    Associative Containers: set, map...
    Unorder Associative Containers: ...
map, vector, list
map (sorted)
any key type, any vlaue type
vector like a c array, but auto-extending
list double-linked list
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(5);  // initialize {0,0,0,0,0}
    vector<int> v3(5, 10);
    vector<int> v4(v3); // copy

    v1.push_back(1);    // 尾部添加
    v1.push_back(2);
    v1.push_back(3);

    int a = v4[0];  // a = 1 不检查越界
    int b = v4.at(1);   // at()会检查越界，抛出异常
    int first = v4.front(); // first = 1 获取第一个元素的值
    int last = v4.back();
    // 遍历
    for (int i = 0; i < v4.size(); ++i) {;}
    for (vector<int>::iterator it = v4.begin(); \
    it != v4.end(); ++it) // 终止条件是 !=
        cout << *it << " "; // 容器第一个元素的迭代器（类似指针）
    cout << endl;
    // 大小与容量
    int _size = v4.size();
    bool _empty = v4.empty();
    v4.resize(10);  // 改大小，多的改零
    // 删除元素
    v4.pop_back(); // delete the back
    v4.erase(v4.begin());   // delete the first
    v4.clear();     // clear all
    // v4.insert(pos, ele);   insert
    // 也可以 for (int x : v4) cout << x << " "; cout << endl;


    list<int> lst;
    list<int> lst(5, 10);   // 5个10
    list<int> lst2(lst.begin(), lst.end()); // 拷贝 参数是范围
    // 常用成员函数
    // lst.empty(); lst.size(); lst.clear();
    // lst.front(); lst.back();    // 首元素引用
    // lst.push_back(x); lst.push_front(x);
    // lst.pop_back(); lst.pop_front();    // 尾插，头插，尾删，头删
    // lst.insert(it, x);  // 在迭代器it前面插入x
    // lst.erase(it);      // 删除迭代器it指向的元素，返回下一个迭代器
    // lst.sort();     // 默认升序
    // lst.merge(lst2);    // 合并前两个list需要排序，lst2会变空
    // lst.reverse();  // 反转
    // lst.unique();   // 需要排序，删除重复元素
    // lst.splice(it, lst2);   // 把lst2所有元素移到it前一个位置，lst2清空
    // lst.splice(it, lst2, it2);  // 只移动it2指向的元素
    // 迭代器 正向 begin() / end()
    //        反向 rbegin() / rend()
}