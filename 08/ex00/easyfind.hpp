#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
auto easyfind(T &container, int value) -> decltype(container.begin());

#include "easyfind.tpp"

#endif
