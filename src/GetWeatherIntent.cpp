#include "IntentValidator.h"
#include "GetWeatherIntent.h"

GetWeatherIntent::GetWeatherIntent(std::string &question) : statement(question) {
}

GetWeatherIntent::~GetWeatherIntent() {
}

bool GetWeatherIntent::checkWeatherIntentExists() {
    return findalloccuranceInSentence() && findAnyOfDayAdverbsOccurance();
}

bool GetWeatherIntent::findalloccuranceInSentence() {
    for(const auto &weatherKeyword : weatherKeywords) {
        if (statement.find(weatherKeyword) == std::string::npos)
            return false;

    }
    return true;
}

bool GetWeatherIntent::findAnyOfDayAdverbsOccurance() {
    return findAnyOccurance(dayAdverbs);
}

bool GetWeatherIntent::findAnyOccurance(const std::vector<std::string>& toMatch) {
    for (const auto & word : toMatch) {
        if (statement.find(word) != std::string::npos)
            return true;
    }
    return false;
}

bool GetWeatherIntent::isvalid() {
    return checkWeatherIntentExists();
}