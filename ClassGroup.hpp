/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassGroup.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:05:22 by lothieve          #+#    #+#             */
/*   Updated: 2020/07/31 11:48:55 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Class.hpp"

using std::vector;

class ClassGroup
{
	private:
	vector<Class> classes;
	static ClassGroup *instance;
	ClassGroup() {}

	public:
	static ClassGroup *getInstance() 
	{
		if (!instance)
			instance = new ClassGroup();
		return instance;
	}

	void add(Class c)
	{
		classes.insert(classes.end(), c);
	}

	void build()
	{
		for (Class c : classes)
		{
			c.buildCpp();
			c.buildHpp();
		}
	}
};

ClassGroup *ClassGroup::instance = nullptr;