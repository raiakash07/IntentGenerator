#include "IntentValidator.h"
#include "GetWeatherCityIntent.h"

#include <vector>

GetWeatherCityIntent::GetWeatherCityIntent(std::string &question) : statement(question) {

}

GetWeatherCityIntent::~GetWeatherCityIntent() {
}

bool GetWeatherCityIntent::checkWeatherCityIntentExists() {
    return findallOccuranceInSentence() && findAnyOfCityOccurance();
}

bool GetWeatherCityIntent::findallOccuranceInSentence() {
    for(const auto & cityKeyword : cityKeywords) {
        if (statement.find(cityKeyword) == std::string::npos)
            return false;
    }
    return true;
}

bool GetWeatherCityIntent::findAnyOfCityOccurance() {
    for (const auto & cityKeyword : cityKeywords) {
        if (statement.find(cityKeyword) != std::string::npos)
            return true;
    }
    return false;
}

bool GetWeatherCityIntent::isvalid() {
    return checkWeatherCityIntentExists();
}
