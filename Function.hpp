#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ofstream;

class Function
{
    private:
	string type;
	string nameAndParams;

    public:
    ~Function();
    Function();
	Function(const string &);
    Function(const Function&);
    Function & operator = (const Function&);
	void printDeclaration(ofstream &o, const string &indent);
	void printImplementaion(ofstream &o, const string &className);
	#ifdef DEBUG
	void describe();
	#endif
};

#endif
