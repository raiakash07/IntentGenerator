#ifndef GETWEATHERCITYINDENT_H
#define GETWEATHERCITYINDENT_H

#include <vector>
#include <string>

class GetWeatherCityIntent : public IntentValidator {
public:
    // ctor takes in string
    GetWeatherCityIntent(std::string &question);
    virtual ~GetWeatherCityIntent();
    bool isvalid() override;
    bool checkWeatherCityIntentExists();
    bool findallOccuranceInSentence();
    bool findAnyOfCityOccurance();
private:
    //list of keywords
    const std::vector <std::string> weatherCityKeywords{"weather", "today"};
    const std::vector <std::string> cityKeywords{"paris", "new york"};
    // to hold the questions
    const std::string &statement;

};

#endif /* GETWEATHERCITYINDENT_H */
