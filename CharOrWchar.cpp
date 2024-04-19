/*
	This example demonstrates the use of the _CT macro in templates where you need to define string literal types.
	Konstantin A. Pankov, 2024, explorus@mail.ru
*/

#include <iostream>

#ifndef _T
#define _T(x) L##x
#endif

namespace detail
{
	template<typename T, typename C, typename W>
	decltype(auto) NarrowOrWide(C&& c, W&& w)
	{
		if constexpr (std::is_same_v<typename std::remove_reference_t<typename std::remove_const_t<T>>, wchar_t>)
			return w;
		else
			return c;
	}
} // end of detail namespace

#define _CT( T, V ) (NarrowOrWide<T>(V, _T(V)))

template<typename T>
void appendFoo(std::basic_string<T>& str)
{
	str += _CT(T, "Foo");
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
