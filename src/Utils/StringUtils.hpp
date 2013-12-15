#ifndef _StringUtils_hpp_
#define _StringUtils_hpp_

#include <string>

#include <sstream>
//#include <boost/lexical_cast.hpp>

std::string& ltrim(std::string& s);
std::string& rtrim(std::string& s);
std::string& trim(std::string& s);

std::string formatString(const char* format, ...);
std::string numberString(int number);

/*
template<typename T> inline std::string toString(T var)
{
    return boost::lexical_cast<std::string>(var);
}

template<typename T> inline T fromString(std::string str)
{
    return boost::lexical_cast<T>(str);
}
*/

template <typename T>
T fromString(const std::string& s, std::ios_base& (*f)(std::ios_base&) = std::dec)
{
    std::istringstream iss(s);

    T t;
    iss >> f >> t;
    return t;
}

template<class T>
std::string toString(const T& t)
{
     std::ostringstream stream;
     stream << t;
     return stream.str();
}

#endif // _StringUtils_hpp_

