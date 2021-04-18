#ifndef CHECKCALENDARINTENT_H
#define CHECKCALENDARINTENT_H

#include "IntentValidator.h"

class CheckCalendarIntent : public IntentValidator {
public:
    CheckCalendarIntent(std::string &question);
    CheckCalendarIntent(const CheckCalendarIntent& orig);
    virtual ~CheckCalendarIntent();
    bool isvalid() override;
private:
    std::string sentence;
    std::string firstPattern = R"( (((((([0-1][0-9])|(2[0-3])):[0-5][0-9])|(24:00)) ?[ap][m]|[AP][M])))";
    std::string secondPattern = R"(( today| tomorrow| yesterday))";
    std::string finalPattern1 = firstPattern + R"(.*)" + secondPattern + R"( ?[\?\.]?)";
    std::string finalPattern2 = secondPattern + R"(.*)" + firstPattern;
    std::string allPattern = finalPattern1 + R"(|)" + finalPattern2;
};

#endif /* CHECKCALENDARINTENT_H */