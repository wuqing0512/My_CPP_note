#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	char char_arr1[20] = "learning";
	char char_arr2[20];
	// char_arr1 = char_arr2;	// illegal
	
	string str1 = "learning";
	string str2;
	// str2 = str1;	// legal
	// cout << str2 << endl;
	
	/* ctors 构造函数 创建类的对象时，自动被调用，用于完成对象初始化工作
	 * 函数名与类名称完全一致，没有返回值类型 */

	/* 成员函数，如a = substr(int pos, int len); a.assign();
	 * insert(int pos, const string &s); erase(); append(); */

	/* C++标准库里绝大多数实体都是属于std命名空间
	 * 区分类 class,类模板 class templplate,容器 container三个概念
	 * 类模板是创建类的模具，允许我们定义一个“不依赖数据类型”的类
	 * 容器是一系列用于存储和组织数据的类模板，是C++标准库的现成工具 */

	// ofstream File1("test1.txt");	// 打开文件 如果文件不存在则创建 向文件中写入
	// if (!File1.is_open()) {
	//  	cerr << "打开失败" << endl;
	// 	return 1;
	// }

	// File1 << "learning" << endl;
	// File1.close();

	// ifstream File2("test1.txt"); 	// 输入文件流 从外部读取内容进程序内部
	               				        // 文件不存在时打开失败
	// global data stack heap中存储的变量 PPT1 16页
	/* kinds of vars: global vars, static globle vars, local vars, global local vars, allogcated vars
	Global data存放: global vars, static globle var, static local vars
	stack存放: local cars
	heap存放: dynamically allocated vars
	global vars: 同一个proj下可以共享，使用extern, eg: extern int i;
	*/

	/*
	pointer:
	ps = &p;	(*ps).length等价于ps->length()
	*/

	/*
	Dynamic memory allocatic:
	int *p = new int;
	int *p_arr = new int(100);
	Stud *q = new Stud();	如果Stud是一个class,Stud()调用了构造函数
	Stud *q = (Stud *)malloc(sizeof(Stud));	q->num = 1234;	malloc无构造函数

	delete p;
	delete[] p;	释放连续内存，如数组
	delete不能释放未分配的内存，不能对同一个内存释放两次，可以释放空指针
	分配一个数组类型的内存(new []),也要delete[])
	delete完成后可以:	delete p;	p = nullptr;
	*/

	/*
	char& r = c;	// a reference to a character &是引用声明符，必须立即初始化，不能先声明后赋值
	不存在引用的引用，也没有指向引用的指针，即引用没有单独的地址
	int& *p;	// illegal
	有指向指针的引用
	int* &ref_p = p;	// 从右往左理解，ref_p是一个int *p指针的别名
	不可以对绑定的引用赋值
	在函数中
	void f(int& x);
	f(y);	// initialize when function is called
	f(i * 3)	// warning,普通非const引用只能绑定可修改的左值，i * 3是一个右值(临时值)
	*/

	/*
	Const
	const int x = 123;	int y = x;	const int z = y;	// legal
	编译时常量  
	运行时常量，如
	const int size = 12;
	int final_grade[size];	// legal
	cin >> x;
	const int size = x;
	int final_grade[size];	// illegal
	Aggregate 聚合类，可以在聚合类中使用const
	const int i[] = { 1, 2, 3, 4 };
	float f[i[3]];	// illegal 编译器只知道这一聚合类存放的是const的 但不知道具体的值
	
	char *const q = "abc";
	*q = "cba";	// legal
	q++;	// illegal const修饰q 指针是一个常量
	const char *p = "abc";
	*p = "bca";	//illegal 指针指向的内容是一个常量
	其实 const char *p 等价于 char *p 不能通过下标的方式改变字符串内容
	想要改变的话可以定义成 char s[] = "";

	const string *p = &pl;
	string const *p = &pl;	// 都代表指向的东西是一个常量 不能改变内容

	string *const p = &pl;	// 指针是一个常量
	非常量可以当作常量
	但是
	void f(const int i) {
		i++;	// illegal compile-time error
	}
		
	*/
	return 0;
}
