#include "../include/nlp_cpp/stopwords.hpp"

#include <unordered_set>

namespace nlp_cpp {

    std::vector<std::string> remove_stopwords(
        const std::vector<std::string>& tokens
    ) {

        std::unordered_set<std::string> stopwords = {
            "i", "am", "is", "are",
            "the", "a", "an",
            "and", "or", "of",
            "to", "in"
        };

        std::vector<std::string> filtered_tokens;

        for (const auto& token : tokens) {

            std::string lower_token = token;

            for (char& c : lower_token) {
                c = tolower(c);
            }

            if (stopwords.find(lower_token)
                == stopwords.end()) {

                filtered_tokens.push_back(
                    token
                );
            }
        }

        return filtered_tokens;
    }

}