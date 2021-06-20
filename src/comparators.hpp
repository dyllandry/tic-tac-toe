#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <cstring>

// A functor, a higher order function. Overloading the function call operator
// lets you call this class as if it was a function.
// <https://stackoverflow.com/a/2349878/7933478>
class CompareCStrings
{
public:
	bool operator()(const char *a, const char *b) const
	{
		return std::strcmp(a, b) < 0;
	}
};

#endif // COMPARATORS_H
