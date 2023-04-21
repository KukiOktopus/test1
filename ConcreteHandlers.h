#ifndef CONCRETEHANDLERS_H
#define CONCRETEHANDLERS_H

#include "IHandler.h"
#include <string>

class MonkeyHandler : public BaseHandler {
public:
    virtual std::string handle(const std::string& request) override {
        if (request == "Banana")
            return "Monkey: I eat the " + request + "\n";
        // wpp. przekaż request do nastepnego obiektu obslugujacego
        return BaseHandler::handle(request); 
    }
};

class SquirrelHandler : public BaseHandler {
public:
    virtual std::string handle(const std::string& request) override {
        if (request == "Nut")
            return "Squirrel: I eat the " + request + "\n";
        return BaseHandler::handle(request);
    }
};

class DogHandler : public BaseHandler {
public:
    virtual std::string handle(const std::string& request) override {
        if (request == "MeatBall")
            return "Dog: I eat the " + request + "\n";
        return BaseHandler::handle(request);
    }
};

#endif