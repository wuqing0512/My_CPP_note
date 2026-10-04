/*
template
// 定义函数模板：通用加法函数
template <typename T>
T add(T a, T b) {
    return a + b;
}
call:
// 调用方式1：显式指定类型
int res1 = add<int>(10, 20);
// 调用方式2：编译器自动推导类型（推荐）
double res2 = add(3.14, 2.86);

// 非类型参数：编译期确定的常量（比如数组大小）
template <typename T, int N>
T sum(T (&arr)[N]) { // 接收大小为N的数组 不能写arr[N]，编译器会退化成T* N无法被推导
    T total = 0;
    for (int i = 0; i < N; i++) {
        total += arr[i];
    }
    return total;
}
call:
    int arr[] = {1,2,3,4,5};
    // 编译器自动推导 T=int，N=5
    int total = sum(arr);
*/