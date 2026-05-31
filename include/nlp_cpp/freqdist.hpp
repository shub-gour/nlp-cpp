#ifndef FREQDIST_HPP
#define FREQDIST_HPP

#include <string>
#include <vector>
#include <unordered_map>

namespace nlp_cpp {

    std::unordered_map<std::string, int> freq_dist(
        const std::vector<std::string>& tokens
    );

}

#endif