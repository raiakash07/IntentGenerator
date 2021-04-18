#include "IntentValidator.h"
#include "GetWeatherCityIntent.h"

#include <vector>

GetWeatherCityIntent::GetWeatherCityIntent(std::string &question) : statement(question) {

}

GetWeatherCityIntent::~GetWeatherCityIntent() {
}

bool GetWeatherCityIntent::checkWeatherCityIntentExists() {
    return findallOccuranceInSentence() && findAnyOfCityOccurance() && findAnyOfDayAdverbsOccurance();
}

bool GetWeatherCityIntent::findallOccuranceInSentence() {
    for(const auto & weatherCityKeyword: weatherCityKeywords) {
        if (statement.find(weatherCityKeyword) == std::string::npos)
            return false;
    }
    return true;
}

bool GetWeatherCityIntent::findAnyOfCityOccurance() {
    return findAnyOccurance(cityKeywords);
}

bool GetWeatherCityIntent::findAnyOfDayAdverbsOccurance() {
    return findAnyOccurance(dayAdverbs);
}

bool GetWeatherCityIntent::findAnyOccurance(const std::vector<std::string>& toMatch) {
    for (const auto & word : toMatch) {
        if (statement.find(word) != std::string::npos)
            return true;
    }
    return false;
}

bool GetWeatherCityIntent::isvalid() {
    return checkWeatherCityIntentExists();
}