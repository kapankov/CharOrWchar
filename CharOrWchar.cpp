#include <iostream>

//#define _TT( T, V ) NarrowOrWide<T>((V), _T(V))

template<typename T>
void appendFoo(std::basic_string<T>& str)
{
	str += "Foo";
}

int main()
{
	std::string str{ "append" };
	appendFoo(str);
    std::cout << str << "\n";
}
