//: C03:stringConv.h
// Chuck Allison's string converter

#ifndef STRINGCONV_H
#define STRINGCONV_H

#include <string>
#include <sstream>
template<typename T>
T fromString(const std::string& s) {
std::istringstream is(s);
T t;
is >> t;
return t;
}
template<typename T>
std::string toString(const T& t){
std::ostringstream s;
s << t;
return s.str();
}

//: :arraySize.h
// Uses template type induction to
// discover the size of an array
template<typename T, int size>
int asz(T (&)[size]) { return size; }

inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

#endif // STRINGCONV_H ///:~

