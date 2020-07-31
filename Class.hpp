/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:24:55 by lothieve          #+#    #+#             */
/*   Updated: 2020/07/28 14:24:31 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP
#include <vector>
#include "Variable.hpp"
#include "Function.hpp"

using std::vector;

class Class
{
    private:
	string name;
	vector<Variable> vars[3];
	vector<Function> funcs[3];

    public:
    ~Class();
    Class();
	Class(string &name);
    Class(const Class&);
    Class & operator = (const Class&);
	void editCategory(int i);
	void buildCpp();
	void buildHpp();
};

#endif
