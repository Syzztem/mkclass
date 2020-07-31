/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmode.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:42:07 by lothieve          #+#    #+#             */
/*   Updated: 2020/07/31 12:33:29 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassGroup.hpp"
#include <unistd.h>
#include <iostream>

using std::cin;

static const string cats[3] = {"private:", "protected:", "public:"};

void showHelp(string filename)
{
	int child = fork();
	int status;
	if(!child)
	{
		std::string command = "less " + filename;
		system(command.c_str());
	}
	waitpid(child, &status, 0);
}

Variable getVar(string def)
{
	Variable out(def);
	string line;
	while (getline(cin, line) && (line.length() > 3 || line.find_first_not_of("gsc") <= 3))
		if (line.at(0) == '!') showHelp("help_getVar");
		else std::cout << "Bad input, type '!' for help\n";
	out.setOpt(line);
	#ifdef DEBUG
	out.describe();
	#endif
	return out;
}

void Class::editCategory(int i)
{
	string prompt = name + "::" + cats[i];
	std::cout << prompt;
	for(string line; getline(cin, line) && line.find("/") != 0;)
	{
		line.substr(line.find_first_not_of(" "), line.find_last_not_of(" "));
		if (line.find("(") != std::string::npos)
			funcs[i].insert(funcs[i].begin(), Function(line));
		else
			vars[i].insert(vars[i].begin(), getVar(line));
		std::cout << prompt;
	}
}

Class buildClass(string &def)
{
	def = def.substr(def.find_first_not_of(" "), def.find_last_not_of(" ") + 1).substr(def.find_last_of(" ") + 1, std::string::npos);
	Class out(def);
	string prompt = def;
	std::cout << prompt << "::";
	for(string line; getline(cin, line) && line.find("/") != 0;)
	{
		if (line.find("pri") == 0)
			out.editCategory(0);
		else if (line.find("pro") == 0)
			out.editCategory(1);
		else if (line.find("pub") == 0)
			out.editCategory(2);
		else if (line.at(0) == '!') showHelp("help_buildClass");
		else std::cout << "Bad input, type '!' for help\n";
		std::cout << prompt << "::";
	}
	return (out);
}

void shellmode()
{
	ClassGroup *classGroup = ClassGroup::getInstance();
	std::cout << "mkclass <3 ";
	for(string line; getline(cin, line) && line.find("/") != 0;)
	{
		if (line.find("class") == 0)
			classGroup->add(buildClass(line));
		else if (line.at(0) == '!')
			showHelp("help_shellmode");
		else std::cout << "Bad input, type '!' for help\n";
		std::cout << "mkclass <3 ";
	}
	classGroup->build();
}
