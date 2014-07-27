#ifndef _StringUtils_hpp_
#define _StringUtils_hpp_

#include <string>

std::string& ltrim(std::string& s);
std::string& rtrim(std::string& s);
std::string& trim(std::string& s);

std::string formatString(const char* format, ...);
std::string numberString(int number);

#endif // _StringUtils_hpp_

