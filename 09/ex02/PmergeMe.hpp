#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <utility>

class PmergeMe
{
private:
	std::vector<unsigned int> _vec;
	std::deque<unsigned int> _deq;

	template <typename Container>
	void mergeInsertSort(Container& c);

	template <typename Container>
	void printSequence(const Container& c) const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void load(const std::vector<unsigned int>& input);
	void process();
};

template <typename Container>
void PmergeMe::printSequence(const Container& c) const
{
	typename Container::const_iterator it = c.begin();
	while (it != c.end())
	{
		std::cout << *it;
		typename Container::const_iterator next = it;
		++next;
		if (next != c.end())
			std::cout << " ";
		++it;
	}
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& c)
{
	using size_type = typename Container::size_type;
	using value_type = typename Container::value_type;

	size_type n = c.size();
	if (n <= 1)
		return;

	std::vector<std::pair<value_type, value_type>> pairs;
	pairs.reserve(n / 2);

	bool hasStraggler = (n % 2 != 0);
	value_type straggler = value_type();

	typename Container::iterator it = c.begin();
	while (it != c.end())
	{
		value_type first = *it;
		++it;
		if (it == c.end())
		{
			hasStraggler = true;
			straggler = first;
			break;
		}
		value_type second = *it;
		++it;

		if (first > second)
			std::swap(first, second);

		pairs.push_back(std::make_pair(first, second));
	}

	Container mainChain;
	for (typename std::vector< std::pair<value_type, value_type> >::const_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
		mainChain.push_back(pit->second);

	mergeInsertSort(mainChain);

	for (size_type i = 0; i < pairs.size(); ++i)
	{
		value_type small = pairs[i].first;
		typename Container::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), small);
		mainChain.insert(pos, small);
	}

	if (hasStraggler)
	{
		typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	c = mainChain;
}

#endif
