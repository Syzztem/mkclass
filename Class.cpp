/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:25:07 by lothieve          #+#    #+#             */
/*   Updated: 2020/07/31 14:08:44 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"
#include <fstream>
#include <exception>
#include <iostream>

using std::ostream;

Class::~Class() {}
Class::Class(const Class &other) {*this = other;}

Class::Class()
{
}

Class::Class(string &name)
{
	this->name = name;
}

Class& Class::operator = (const Class& other)
{
	name = other.name;
	for (int i = 0; i < 3; i++)
	{
		vars[i] = other.vars[i];
		funcs[i] = other.funcs[i];
	}
	return *this;
}

void Class::buildCpp()
{
	string filename = name + ".cpp";
	ofstream file;
	try
	{
		file.open(filename, std::ios::trunc);
	}
	catch (std::exception e)
	{
		std::cerr << e.what();
	}
    file << "#include \"" << name << ".hpp\"\n" << std::endl <<
    name << "::~" << name << "() {}" << std::endl <<
    name << "::" << name << "(const " << name << " &other) {*this = other;}\n" << std::endl <<
    name << "::" << name << "()\n{\n\n}\n" << std::endl <<
    name << "& " << name << "::" << "operator = (const " << name << "& other)\n{\n";
	for (int i = 0; i < 3; i++)
		for (Variable var : vars[i])
			file << "\t" << var.getName() << " = other." << var.getName() << ";\n";
	file << "}\n" << std::endl;
	for (int i = 0; i < 3; i++)
		for (Variable var : vars[i])
		{
			var.printGetterI(file, name);
			var.printSetterI(file, name);
		}
	for (int i = 0; i < 3; i++)
		for (Function func : funcs[i])
			func.printImplementaion(file, name);
	file.close();
}

void Class::buildHpp()
{
	string filename = name + ".hpp";
	ofstream file;
	try
	{file.open(filename, std::ios::trunc);}
	catch (std::exception e){std::cerr << e.what();}
	file << "#pragma once\n" << std::endl <<
    "class " << name << std::endl << 
    "{" << std::endl <<
	//private members
    "\tprivate:" << std::endl;
	for (Variable var : vars[0])
		var.printDeclaration(file, "\t");
	for (Function func : funcs[0])
		func.printDeclaration(file, "\t");
	//protected members
    file << "\n\tprotected:" << std::endl;
	for (Variable var : vars[1])
		var.printDeclaration(file, "\t");
	for (Function func : funcs[1])
		func.printDeclaration(file, "\t");
	//public members
    file << "\n\tpublic:" << std::endl;
    file << "\t~" << name << "();" << std::endl <<
    "\t" << name << "();" << std::endl <<
    "\t" << name << "(const " << name << "&);" << std::endl <<
    "\t" << name << " & operator = (const " << name << "&);" << std::endl <<
    "};" << std::endl << std::endl;
	for (vector<Variable> vec : vars)
		for (Variable var : vec)
		{
			var.printGetterD(file, "\t");
			var.printSetterD(file, "\t");
		}
	for (Variable var : vars[2])
		var.printDeclaration(file, "\t");
	for (Function func : funcs[2])
		func.printDeclaration(file, "\t");
}
