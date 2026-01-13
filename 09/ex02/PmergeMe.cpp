#include "PmergeMe.hpp"

#include <chrono>

PmergeMe::PmergeMe()
	: _vec(), _deq()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vec(other._vec), _deq(other._deq)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() = default;

void PmergeMe::load(const std::vector<unsigned int>& input)
{
	_vec = input;
	_deq.assign(input.begin(), input.end());
}

void PmergeMe::process()
{
	typedef std::chrono::high_resolution_clock clock;
	typedef std::chrono::duration<double, std::micro> microseconds;

	clock::time_point startVec = clock::now();
	mergeInsertSort(_vec);
	clock::time_point endVec = clock::now();

	clock::time_point startDeq = clock::now();
	mergeInsertSort(_deq);
	clock::time_point endDeq = clock::now();

	std::cout << "After: ";
	printSequence(_vec);

	std::size_t size = _vec.size();
	microseconds durationVec = endVec - startVec;
	microseconds durationDeq = endDeq - startDeq;

	std::cout << "Time to process a range of " << size
		<< " elements with std::vector : " << durationVec.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << size
		<< " elements with std::deque : " << durationDeq.count() << " us" << std::endl;
}
