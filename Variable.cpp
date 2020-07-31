#include "Variable.hpp"

Variable::~Variable() {}
Variable::Variable(const Variable &other) {*this = other;}

Variable::Variable() {}

Variable::Variable(const string &line)
{
	type = line.substr(0, line.find_first_of(" "));
	name = line.substr(line.find_last_of(" ") + 1, line.length());
	getter = false;
	setter = false;
	constructor = false;
}

Variable& Variable::operator = (const Variable& other)
{
	type = other.type;
	name = other.name;
	getter = other.getter;
	setter = other.setter;
	constructor = other.constructor;
	return *this;
}

string Variable::getName() {return name;}

#ifdef DEBUG
void Variable::describe()
{
	std::cout << "type: " << type << std::endl <<
	"name: " << name << std::endl <<
	"opts: g: " << getter << "s: " << setter << "c:" << constructor << std::endl;
}
#endif

void Variable::printDeclaration(ofstream &o, const string &indent)
{
	o << indent << type << " " << name << ";\n";
}

//type getname();
void Variable::printGetterD(ofstream &o, const string &indent)
{
	if (getter) o << indent << type << " get" << name << "();\n";
}

//void setname(type name);
void Variable::printSetterD(ofstream &o, const string &indent)
{
	if (setter) o << indent << "void set" << name << "(" << type << " " << name << ");\n";
}

//type className::getname(){return name};
void Variable::printGetterI(ofstream &o, const string &className)
{
	if (getter) o << type << " " << className << "::" << "get" << name << "(){return " << name << ";}\n";
}

//void className::setname(type name){name = name}
void Variable::printSetterI(ofstream &o, const string &className)
{
	if (setter) o << "void " << className << "::set" << name << "(" << type << " " << name << "){" << name << " = " << name << ";}\n";
}

void Variable::printParam(ofstream &o)
{
	o << type << " " << name;
}

void Variable::setOpt(const string &line)
{
	if (line.find('g') < std::string::npos)
		getter = true;
	if (line.find('s') < std::string::npos)
		setter = true;
	if (line.find('c') < std::string::npos)
		constructor = true;
}
