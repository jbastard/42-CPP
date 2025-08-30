#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Base{
	public:
		virtual ~Base();
	};

Base* generate();
void identify(Base* p);
void identify(Base& p);
