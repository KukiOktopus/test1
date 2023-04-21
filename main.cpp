#include "IHandler.h"
#include "ConcreteHandlers.h"
#include <memory>
#include <iostream>
using namespace std;

void ClientCode(IHandlerPtr handler) {
    string food [] = {"Nut", "Banana", "Cup of coffee"}; 
    
    for (const auto& f : food) {
        cout << "Client: Who wants a " << f << "?\n";
        string result = handler->handle(f);
        if (!result.empty())
            cout << "\t" << result << endl;
        else
            cout << "\t" << f << " was left untouched.\n";
    }
}

int main() {
    auto monkey = std::make_shared<MonkeyHandler>();
    auto squirrel = std::make_shared<SquirrelHandler>();
    auto dog = std::make_shared<DogHandler>();

    // tworze lancuch obiektow
    monkey->setNext(squirrel)->setNext(dog);
    
    ClientCode(monkey);
    cout << endl;

    // klient powinien miec mozliwosc wyslac zadanie do dowolnego handlera, a nie tylko pierwszego w łańcuchu
    cout << "Teraz żadanie zostalo przeslane do wiewiorki z pominieciem małpy\n";
    ClientCode(squirrel);
}