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
    for (int i = 0; i < weatherKeywords.size(); i++) {
        if (statement.find(weatherKeywords[i]) == std::string::npos)
            return false;

    }
    return true;

}

bool GetWeatherIntent::isvalid() {
    return checkWeatherIntentExists();
}

