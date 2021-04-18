#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <regex>
#include <memory>
#include "IntentValidator.h"
#include "GetWeatherCityIntent.h"
#include "GetWeatherIntent.h"
#include "CheckCalendarIntent.h"

std::string getUserQuestion() {
    
    std::cout << "Ask the question ? or q to exit\n";
    std::string question = "";
    std::getline(std::cin, question);
    return question;
}

void toPrintOnScreen(std::string words) {
    
    std::cout << "Intent : " << words << "\n";
}

std::string& toLower(std::string &words) {
    
    std::transform(words.begin(), words.end(), words.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return words;
}

void checkIfIdentExists(std::string &&statement) {

    statement = toLower(statement);
    std::unique_ptr<IntentValidator> checkCalendarIntent = std::make_unique<CheckCalendarIntent>(statement);
    std::unique_ptr<IntentValidator> getWeatherCityIntent = std::make_unique<GetWeatherCityIntent>(statement);
    std::unique_ptr<IntentValidator> getWeatherIntent = std::make_unique<GetWeatherIntent>(statement);

    getWeatherCityIntent->isvalid()
            ? toPrintOnScreen("Get Weather City") : getWeatherIntent->isvalid()
            ? toPrintOnScreen("Get Weather") : checkCalendarIntent->isvalid()
            ? toPrintOnScreen("Check Calendar") : statement.find("fact") != std::string::npos
            ? toPrintOnScreen("Get Fact") : toPrintOnScreen("Intent not avaiable");
}

void preDefinedQuestions() {

    std::cout << "-----------------------predefined question-------------------------\n";
    std::cout << "What is the weather like today? ----> ";
    checkIfIdentExists("What is the weather like today?");
    std::cout << "What is the weather like in Paris today? ----> ";
    checkIfIdentExists("What is the weather like in Paris today?");
    std::cout << "What is the weather like in New York today? ----> ";
    checkIfIdentExists("What is the weather like in New York today?");
    std::cout << "Am I free at 13:00 PM tomorrow? ---->";
    checkIfIdentExists("Am I free at 13:00 PM tomorrow?");
    std::cout << "Tell me an interesting fact.? ----> ";
    checkIfIdentExists("Tell me an interesting fact.");
    std::cout << "-----------------------------------------------------------------\n";

}

int main(int argc, char** argv) {

    preDefinedQuestions();
    std::string userOption;
    while (userOption != "q") {

        userOption = getUserQuestion();

        if (userOption == "q")
            break;

        checkIfIdentExists(std::move(userOption));

        std::cout << "\n\nPress Enter to continue and 'q' to exit\n";
        getline(std::cin, userOption);
        if (userOption == "q")
            break;
    }
    return 0;
}
