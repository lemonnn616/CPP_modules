#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
	: _inFile(filename), _outFile(filename + ".replace"), _s1(s1), _s2(s2)
{
}

Replace::~Replace()
{
}

std::string Replace::replaceLine(const std::string& line) const
{
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(_s1, pos)) != std::string::npos) // ishem stroku  s1 v line, npos = ne naideno; find vozvrashet poziciu
	{
		result += line.substr(pos, found - pos); // kopiruem vse do naidenogo simvola, dobovlaem s2 i izmenaem dlinu
		result += _s2;
		pos = found + _s1.length();
	}
	result += line.substr(pos);
	return result;
}

bool Replace::process()
{
	if (_s1.empty())
	{
		std::cerr << "Warning: s1 empty." << std::endl;
		return false;
	}
	if (_s1 == _s2)
	{
		std::cerr << "Warning: s1 and s2 are the same." << std::endl;
		return false;
	} 
	std::ifstream infile(_inFile.c_str()); //ifstream dlya iz fila; c_str pointer na nachalo; c_str constant char a ne string, ifstream prinimaet
	if (!infile)
	{
		std::cerr << "Error: cannot open input file: " << _inFile << std::endl;
		return false;
	}
	if (infile.peek() == EOF) // peek smotrit sleduushie simvoli ne peredvigaya ukazatel
	{
		std::cerr << "Warning: input file is empty." << std::endl;
		infile.close();
		return false;
	}
	std::ofstream outfile(_outFile.c_str()); // to zhe samoe kak i ifstream
	if (!outfile)
	{
		std::cerr << "Error: cannot create output file: " << _outFile << std::endl;
		infile.close();
		return false;
	}
	std::string line; // sozdaem line potomuchto getline chitaet stroku i sohranaet ee v line
	while (std::getline(infile, line))
	{
		outfile << replaceLine(line) << std::endl;
	}
	infile.close();
	outfile.close();
	std::cout << "Done: File '" << _outFile << "' was created successfully." << std::endl;
	return true;
}

