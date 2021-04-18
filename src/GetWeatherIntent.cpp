#include "IntentValidator.h"
#include "GetWeatherIntent.h"

GetWeatherIntent::GetWeatherIntent(std::string &question) : statement(question) {
}

GetWeatherIntent::~GetWeatherIntent() {
}

bool GetWeatherIntent::checkWeatherIntentExists() {
    return findalloccuranceInSentence();
}

bool GetWeatherIntent::findalloccuranceInSentence() {
    for(const auto &weatherKeyword : weatherKeywords) {
        if (statement.find(weatherKeyword) == std::string::npos)
            return false;

    }
    return true;

}

bool GetWeatherIntent::isvalid() {
    return checkWeatherIntentExists();
}