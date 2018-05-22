/**
 * files.hpp
 * 
 * \author Daniel Salib* \date Thu 17 May 16:05:36 2018
 *
 */

#ifndef FILES_HPP
#define FILES_HPP

#include <vector>
#include <map>
#include <string>

std::map<std::string, std::vector<std::string>> _files = {
    ("test.cpp", {"bst.hpp", "myvec.hpp", "util.hpp", "test.hpp"}),
    ("bst.cpp", {"bst.hpp", "myvec.hpp", "util.hpp"}),
    ("myvec.cpp", {"myvec.hpp", "util.hpp"}),
};

std::vector<std::string> get_deps(std::string fname) {
    if (_files.count(fname)) {
        return _files[fname];
    } else {
        return {};
    }
}

#endif /* FILES_HPP */
