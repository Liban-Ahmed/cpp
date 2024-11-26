#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)

    return 0;
}

/*
Question #1

Write a constexpr function template with a non-type template parameter that returns the factorial of the template argument.
The following program should fail to compile when it reaches factorial<-3>().


*/

#include <cassert>
template <int N>
constexpr int factorial()
{
    static_assert(N >= 0);

    int product{1};
    for (int i{2}; i <= N; ++i)
        product *= i;

    return product;
}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    // should fail to compile

    return 0;
}
