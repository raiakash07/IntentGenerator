#include "CheckCalendarIntent.h"
#include <regex>

CheckCalendarIntent::CheckCalendarIntent(std::string &question) : sentence(question) {

}

CheckCalendarIntent::CheckCalendarIntent(const CheckCalendarIntent& orig) {
}

CheckCalendarIntent::~CheckCalendarIntent() {
}

bool CheckCalendarIntent::isvalid() {
    std::regex r(allPattern);
    if (std::regex_search(sentence, r))
        return true;
    return false;
}