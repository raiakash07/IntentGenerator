#ifndef INDENT_H
#define INDENT_H

#include <string>

class IntentValidator {
public:
    virtual bool isvalid() = 0;

    virtual ~IntentValidator() {
    };
};

#endif /* INDENT_H */
