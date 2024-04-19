#include <iostream>

//#define _TT( T, V ) NarrowOrWide<T>((V), _T(V))
#define _TT( V ) NarrowOrWide<T>((V), _T(V))

template<typename T>
void appendFoo(std::basic_string<T>& str)
{
	if constexpr (std::is_same_v<T, wchar_t>)
		str += L"Foo";
	else
		str += "Foo";
}

int main()
{
	std::string str{ "append" };
	appendFoo(str);
    std::cout << str << "\n";

	std::wstring wstr{ L"append" };
	appendFoo(wstr);
	std::wcout << wstr << "\n";

}
