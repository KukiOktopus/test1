#ifndef IHANDLER_H
#define IHANDLER_H

#include <memory>
#include <string>

class IHandler;
using IHandlerPtr = std::shared_ptr<IHandler>; 

class IHandler {
public:
     virtual IHandlerPtr setNext(const IHandlerPtr& nextHandler) = 0;
     virtual std::string handle(const std::string& request) = 0;
     virtual ~IHandler() = default;
};

// podstawowa klasa obiektow obslugujacych
class BaseHandler : public IHandler {
public:
    BaseHandler(const IHandlerPtr& nextHandler = nullptr) : next_handler_(nextHandler) {}
    // zwaraca IHandlerPtr zeby mozna bylo settery laczyć w lancuchy
    virtual IHandlerPtr setNext(const IHandlerPtr& nextHandler) {
        next_handler_ = nextHandler;
        return next_handler_;
    }
    // przekazuje żądanie do nastepnego obiektu w łańcuchu
    virtual std::string handle(const std::string& request) override {
        if (next_handler_ != nullptr)
            return next_handler_->handle(request);
        return {}; // wpp., tzn. gdy nie ma w łańcuchu nastepnego handlera, czyli żądanie nie zostalo obsluzone, zwroc pusty string
    }
private:
    IHandlerPtr next_handler_;
};

#endif