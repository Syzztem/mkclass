/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkclass.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 10:01:32 by lothieve          #+#    #+#             */
/*   Updated: 2020/07/28 14:28:43 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <string.h>

using std::string;
using std::ofstream;
void shellmode();

void write_cpp(ofstream& file, const string name)
{
    file << "#include \"" << name << ".hpp\"\n" << std::endl <<
    name << "::~" << name << "() {}" << std::endl <<
    name << "::" << name << "(const " << name << " &other) {*this = other;}\n" << std::endl <<
    name << "::" << name << "()\n{\n\n}\n" << std::endl <<
    name << "& " << name << "::" << "operator = (const " << name << "& other)\n{\n\n}\n" << std::endl;
	file.close();
}

void write_hpp(ofstream& file, const string name)
{
    string symbol = name;
    std::transform(symbol.begin(), symbol.end(),symbol.begin(), ::toupper);
    file << 
    "#ifndef " << symbol << "_HPP" << std::endl <<
    "#define " << symbol << "_HPP\n" << std::endl <<
    "class " << name << std::endl << 
    "{" << std::endl <<
    "    private:" << std::endl << std::endl <<
    "    public:" << std::endl <<
    "    ~" << name << "();" << std::endl <<
    "    " << name << "();" << std::endl <<
    "    " << name << "(const " << name << "&);" << std::endl <<
    "    " << name << " & operator = (const " << name << "&);" << std::endl <<
    "};" << std::endl << std::endl <<
    "#endif\n";
    file.close();
}

void mkclass(string name)
{
    string hpp_name = name + ".hpp";
    string cpp_name = name + ".cpp";
    ofstream file;

    try
    {
        file.open(hpp_name, std::ios::trunc);
        write_hpp(file, name);
        file.open(cpp_name, std::ios::trunc);
        write_cpp(file, name);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
        throw e;
    }
}

int main(int ac, char **av)
{
	if (ac == 1)
		shellmode();
    for (int i = 1; i < ac; i++)
        mkclass(av[i]);
}
