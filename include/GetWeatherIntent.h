#ifndef GETWEATHERINDENT_H
#define GETWEATHERINDENT_H

#include <vector>
#include <string>

class GetWeatherIntent : public IntentValidator {
public:
    GetWeatherIntent(std::string &question);
    GetWeatherIntent(const GetWeatherIntent& orig) = delete;
    virtual ~GetWeatherIntent();
    bool isvalid() override;
    bool checkWeatherIntentExists();
    bool findalloccuranceInSentence();
    bool findAnyOccurance(const std::vector<std::string>& toMatch);
    bool findAnyOfDayAdverbsOccurance();

private:
    const std::vector <std::string> weatherKeywords{"weather"};
    const std::vector <std::string> dayAdverbs{"today","tomorrow","yesterday"};
    const std::string &statement;
};

#endif /* GETWEATHERINDENT_H */