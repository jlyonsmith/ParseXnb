#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#include <algorithm>
#include <exception>
// Needs C++ 11 support
//#include <type_traits>
#include <string>
#include <vector>

using namespace std;

class app_exception : public exception 
{
private:
	std::string msg;
public:
	app_exception() throw() { }
	app_exception(const char *msg)
	{
		this->msg = msg;
	}
	virtual ~app_exception() throw()
	{
	}

	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
};

#define ARRAY_SIZE(a)                               \
  ((sizeof(a) / sizeof(*(a))) /                     \
  static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))
  
  
