#include "MutantStack.hpp"
#include <iterator>


void mutantTest()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << YELLOW << "top = " << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << YELLOW << "size = "<< mstack.size() << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << YELLOW << "---displaying stack from begin to end---" << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	{
		MutantStack<int> s;
		s = mstack;
		MutantStack<int>::iterator iit = s.begin();
		MutantStack<int>::iterator iti = s.end();
		while (iit != iti)
		{
			std::cout << *iit << std::endl;
			++iit;
		}
	}
	MutantStack<int>::iterator po = mstack.begin();
	po++;
	std::cout << *po << std::endl;
}

void listTest()
{
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::list<int>::iterator iter = mlist.begin();
	iter++;
	std::cout << YELLOW << "top should be = " << *iter << RESET << std::endl;
	mlist.remove(17);
	std::cout << YELLOW << "size = " << mlist.size() << RESET << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	std::cout << YELLOW << "---displaying list from begin to end---" << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mlist);
}

int main()
{
	std::cout << BOLDGREEN << "---STARTING MUTANTTEST---" << RESET << std::endl;
	mutantTest();
	std::cout << BOLDYELLOW << "---END OF MUTANTTEST---" << RESET << std::endl;
	std::cout << BOLDGREEN << "---STARTING LISTTEST---" << RESET << std::endl;
	listTest();
	return (0);
}