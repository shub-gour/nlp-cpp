#include "../include/nlp_cpp/stemmer.hpp"

namespace nlp_cpp {

    std::string stem(
        const std::string& word
    ) {

        std::string result = word;

        bool removed_ing_or_ed = false;

        // ies -> i
        if (result.length() > 4 &&
            result.substr(
                result.length() - 3
            ) == "ies") {

            result =
                result.substr(
                    0,
                    result.length() - 3
                ) + "i";
        }

        // es removal
        else if (result.length() > 3 &&
                 result.substr(
                     result.length() - 2
                 ) == "es") {

            result =
                result.substr(
                    0,
                    result.length() - 2
                );
        }

        // ing removal
        else if (result.length() > 4 &&
                 result.substr(
                     result.length() - 3
                 ) == "ing") {

            result =
                result.substr(
                    0,
                    result.length() - 3
                );

            removed_ing_or_ed = true;
        }

        // ed removal
        else if (result.length() > 3 &&
                 result.substr(
                     result.length() - 2
                 ) == "ed") {

            result =
                result.substr(
                    0,
                    result.length() - 2
                );

            removed_ing_or_ed = true;
        }

        // plural s
        else if (result.length() > 2 &&
                 result.back() == 's') {

            result.pop_back();
        }

        // remove double letter ONLY after ing/ed
        if (removed_ing_or_ed &&
            result.length() >= 2 &&
            result.back() ==
            result[result.length() - 2]) {

            result.pop_back();
        }

        return result;
    }

}