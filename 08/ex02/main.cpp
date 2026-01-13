#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::stack<int> s(mstack);
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it_list = lst.begin();
	std::list<int>::iterator ite_list = lst.end();
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	std::cout << std::endl;

	MutantStack<int> copy(mstack);
	std::cout << "copy size = " << copy.size() << std::endl;
	if (!copy.empty())
		std::cout << "copy top = " << copy.top() << std::endl;
	std::cout << std::endl;

	const MutantStack<int> const_stack(mstack);
	MutantStack<int>::const_reverse_iterator crit = const_stack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = const_stack.rend();
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	return 0;
}
