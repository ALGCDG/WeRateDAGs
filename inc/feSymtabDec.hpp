#ifndef FESYMTABDEC_HPP
#define FESYMTABDEC_HPP

#include <vector>
#include <string>
#include <utility>

//declare global variable
//stack of
//  vector of
//      pair of
//          (string, bool) : (name, is_typename)
extern std::vector<std::vector<std::pair<std::string, bool> > > tieinSymtab;

#endif