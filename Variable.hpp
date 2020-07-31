/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Variable.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:53:14 by lothieve          #+#    #+#             */
/*   Updated: 2020/07/31 13:55:51 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ofstream;

class Variable
{
    private:
	string type;
	string name;
	bool getter;
	bool setter;
	bool constructor;

    public:
    ~Variable();
    Variable();
	Variable(const string &);
    Variable(const Variable&);
    Variable & operator = (const Variable&);
	string getName();
	void printDeclaration(ofstream &o, const string &indent);
	void printGetterD(ofstream &o, const string &indent);
	void printSetterD(ofstream &o, const string &indent);
	void printGetterI(ofstream &o, const string &className);
	void printSetterI(ofstream &o, const string &className);
	void printParam(ofstream &o);
	void setOpt(const string &);
	#ifdef DEBUG
	void describe();
	#endif
};

#endif
