#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

class Replace
{
	private:
		std::string _inFile;
		std::string _outFile;
		std::string _s1;
		std::string _s2;

		std::string replaceLine(const std::string& line) const;

	public:
		Replace(std::string filename, std::string s1, std::string s2);
		~Replace();

		bool process();
};

#endif
