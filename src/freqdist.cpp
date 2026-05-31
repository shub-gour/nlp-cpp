#include "../include/nlp_cpp/freqdist.hpp"

namespace nlp_cpp {

    std::unordered_map<std::string, int> freq_dist(
        const std::vector<std::string>& tokens
    ) {

        std::unordered_map<std::string, int> frequency;

        for (const auto& token : tokens) {

            frequency[token]++;
        }

        return frequency;
    }

}