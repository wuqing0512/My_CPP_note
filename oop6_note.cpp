/*
Map key-value pair
内部自动对键进行升序排序（std::less<Key>）key是唯一的
std::map<KeyType, ValueType> 变量名;
Typdefs map<Name, list<Phone_Number>> PB
PB phonebook;
PB::interator mp;

Iterator
list<int>::iterator li;
list<int> L;
li = L.begin();
++li;   // can increment

Algorithm:
list<int> L;
vector<int> V;
copy(L.begin(), L.end(), V.begin());
*/

/*
运算符重载 operation overload
运算符的优先级 结合性不变 操作数不变
只能重载存在的操作符 有一部分操作符无法被重载 如::
class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0 , double i = 0.0) : real(r), imag(i) {}
    Complex operator+(const Complex& c2) const {
        return Complex(this->real + c2.real, this->imag + c2.imag);
    }

    // 友元函数形式重载输出运算符 << 的左操作数是cout（ostream对象），不是complex
    friend osrteam& operator<<(ostream& out, const Complex& c);
};

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;
    if (c.imag > 0) {
        out << "+" << c.imag << "i";
    }
    else if {;}
    return out;
}
Global operator version:
class Integer {
    friend const Integer operater+ (
        const Integer& lhs, const Integer& rhs);
    }
}
const Integer operator(...) {
    return Integer( lhs.i + rhs.i);
}
前置++与后置++
const Integer& Integer::operator++() {
    *this += 1;
    return *this;
}

const Integer& Integer::operator++( int ) {
    Interger old( *this );
    ++( *this );
    return old;
}
operator [] if vector<int> vec[4] , return *vec[4]
深赋值 复制数据并分配新内存
Vector& operator=(const Vector& other)
{
    if (this == &other) { // check for self-assignment
        return *this;
    }
    cout << "in operator=" << endl;

    int* newData = new int[other.size];
    copy(other.data, other.data + other.size, newData);
    // 三个参数：起始地址 终止地址（左闭右开） 内存块首地址
    delete[] data; // free the old space
    data = newData;
    size = other.size; // copy the new data

    return *this;   // 支持链式赋值 v1 = v2 = v3
}

operator<<(ostream& os, const T& obj) {
    // code
    return os;
}
    eg: ostream& tab ( ostream& out ) {
        return out << "\t";
    }
// istream 类似 都支持链式调用

static_cast explicit type conservation

char a = 'a';   // "a" 是一个const char[2]字符串字面量，会隐式转换const char*
int b = static_cast<int>(a); // legal
double *c = new double;
void *d = static_cast<void*>(c); // legal
static_cast 遵守小转大规则，不能把const转成非const，不能downcast父类转子类
移除添加const_cast
const int g = 2;
int *h = const_cast<int *>(&g)  // legal
int *p = &a;
const int *cp = const_cast<const int *>(p);
*/