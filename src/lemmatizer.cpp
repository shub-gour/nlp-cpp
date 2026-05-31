#include "../include/nlp_cpp/lemmatizer.hpp"

#include <unordered_map>

namespace nlp_cpp {

    std::string lemmatize(
        const std::string& word
    ) {

        std::unordered_map<
            std::string,
            std::string
        > irregular_words = {

            {"mice", "mouse"},
            {"children", "child"},
            {"better", "good"},
            {"worse", "bad"},
            {"feet", "foot"},
            {"teeth", "tooth"}
        };

        auto it =
            irregular_words.find(word);

        if (it != irregular_words.end()) {
            return it->second;
        }

        std::string result = word;

        // studies -> study
        if (result.length() > 4 &&
            result.substr(
                result.length() - 3
            ) == "ies") {

            result =
                result.substr(
                    0,
                    result.length() - 3
                ) + "y";
        }

        // running -> run
        else if (result.length() > 4 &&
                 result.substr(
                     result.length() - 3
                 ) == "ing") {

            result =
                result.substr(
                    0,
                    result.length() - 3
                );

            if (result.length() >= 2 &&
                result.back() ==
                result[result.length() - 2]) {

                result.pop_back();
            }
        }

        // played -> play
        else if (result.length() > 3 &&
                 result.substr(
                     result.length() - 2
                 ) == "ed") {

            result =
                result.substr(
                    0,
                    result.length() - 2
                );
        }

        // cars -> car
        else if (result.length() > 2 &&
                 result.back() == 's') {

            result.pop_back();
        }

        return result;
    }

}