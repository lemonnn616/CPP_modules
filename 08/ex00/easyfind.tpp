#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
auto easyfind(T &container, int value) -> decltype(container.begin())
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("easyfind: value not found");
	return it;
}

#endif
