/*
Composition: reusing the implementation
Inheritance
class Item {}
class CD : public Item {}
*/

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string m_name;
    string m_ssn;
public:
    Employee(const string& name, const string& ssn) // 传参的时候，实参写一个string进去，然后编译器会隐式创建一个临时的引用来指向传入的实参
        : m_name(name), m_ssn(ssn) {}
    
    const string& getName() const {
        return m_name;
    }
    void print(ostream& out, const string& msg) const { // 实参为cout
        out << msg << "；姓名 = " << m_name << "，社保号 = " << m_ssn;
    }
};

class SalariedEmployee : public Employee {  // 继承了Employee 内存开销是base + derive class
private:
    double m_salary;
public:
    SalariedEmployee(const string& name, const string& ssn, double salary)
        : Employee(name, ssn), m_salary(salary) {}

    void print(ostream& out, const string& msg ) const {
        Employee::print(out, msg);
        out << "，月薪 = " << m_salary << endl;
    }
};

int main() {
    SalariedEmployee emp("张三", "123456789", 8000);
    emp.print(cout, "员工信息");     // 实参是cout 子类中有和父类的同名函数时，父类的函数会被隐藏
    return 0;                       // 可以通过using Base::func; 声明，在子类中使用父类同名函数
}

/*
传参使用引用：避免了数据拷贝，提升性能，引用也可以对原始对象进行修改
无需通过return传递返回值
比传指针更安全，减少了空指针异常的风险
*/

/*
ostream的作用？
*/

/*
public: visible to all
protected: visible to classes derived from self and to friends
private: visible only to self and friends

Friends: a member function / a class 
class B;
class A {
public:
    friend void print_A_Info(A& a_obj) {}   // 声明全局函数为友元
    friend class B; // 声明B为友元类，B的成员函数可以调用A的private
    friend void B::show(A& a_obj); // B中一个成员函数为友元
}
*/ 

/*
Upcasting 把衍生类当作父类使用 eg:
Employee: base class    Manager: derived class
Manager pete("Pete", "444-55-6666", "Bakery");
Employee* ep = &pete;   // upcast 向上转型 指针 编译器自动隐式完成 不需要显示类型转换
Employee& er = pete;    // upcast 引用 本质上仍然是派生类对象

Dynamic binding 函数会根据传参是子类还是父类来决定调用哪一个class的成员函数
*/

/*
Polymorphism 多态 同名不同参
Virture function
在子类中override父类的虚函数
class Base {
public:
    virtual void func() const;
};

class Derived : public Base {
public:
    void func(int x) const override;    // 派生类的重写函数的访问权限不能比基类更严格
}

虚函数的核心价值是实现多态，运行时多态 调用哪个函数只有运行时才确定
基类有虚函数的时候，析构函数也要声明为虚函数，避免内存泄漏
eg:
class Employee {
public:
    virtual void showInfo() const {
        cout << "name: " << name;
    }
    virtual ~Employee() {}  // derived class析构函数也要virtual 
};

class Manager : public Employee {
public:
    void showInfo() const override {
        Employee::showInfo();   // 复用基类逻辑
        cout << ", 【经理】负责部门" << department << endl;
    }
};

class Salesman : public Employee {
public:
    void showInfo() const override {
        Employee::showInfo();
        cout << "，【销售】月销总额" << sales <<endl;
    }
};

虚函数覆盖 override eg:
class Expr {
public:
    virtual Expr* newExpr();
    virtual Expr* clone();
    virtual Expr self();
};

class BinaryExpr : public Expr {
public:
    virtual BinaryExpr* newExpr();
    virtual BinaryExpr& clone();
    virtual BinaryExpr self();  // illegal
};
前两个是正确的虚函数覆盖，返回的是基类中对应虚函数的返回类型的协变类型
BinaryExpr* 是 Expr*的派生类指针 Upcasting，另一个是派生类引用
self()报错是因为试图返回BinaryExpr对象，基类返回的是Expr对象，c++中，
虚函数的返回值不能是普通对象的协变，只有是指针或者引用的时候才允许使用协变
普通对象也可以做虚函数覆写的返回值，但必须完全一致

虚函数的定义都是静态绑定的（编译时绑定），虚函数的调用是可以动态绑定的
*/