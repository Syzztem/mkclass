/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:09:23 by lothieve          #+#    #+#             */
/*   Updated: 2020/07/31 13:59:41 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Function.hpp"

Function::~Function() {}
Function::Function(const Function &other) {*this = other;}

Function::Function() {}

Function::Function(const string &line)
{
	if (line.find(">") == std::string::npos)
	{
		std::cout << line << std::endl;
		type = line.substr(0, line.find_first_of(" "));
		nameAndParams = line.substr(line.find_first_of(" ") + 1, std::string::npos).substr(line.find_first_not_of(" "), std::string::npos);
	}
	#ifdef DEBUG
	describe();
	#endif
}

#ifdef DEBUG	
void Function::describe()
{
	std::cout << "type: " << type << std::endl <<
	"nameAndParams: " << nameAndParams << std::endl;
}
#endif

Function& Function::operator = (const Function& other)
{
	type = other.type;
	nameAndParams = other.nameAndParams; 
	return *this;
}

void Function::printDeclaration(ofstream &o, const string &indent)
{
	o << indent << type << " " << nameAndParams << ";\n";
}

void Function::printImplementaion(ofstream &o, const string &className)
{
	o << type << " " << className << "::" << nameAndParams << "\n{\n\n}\n\n";
}
