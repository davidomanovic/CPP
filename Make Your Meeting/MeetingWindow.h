#pragma once
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include "AnimationWindow.h"
#include "Meeting.h"
#include "Person.h"
#include <vector>
#include <utility>
#include <memory>

class MeetingWindow : public TDT4102::AnimationWindow
{
    private:
        // These are unchangable
        constexpr static int pad = 30;
        constexpr static int btnW = 100;
        constexpr static int btnH = 50;
        constexpr static int fieldW = 400;
        constexpr static int fieldH = 50;
        constexpr static int fieldPad = 200;
        
        // Get some objects
        TDT4102::TextInput personName, personEmail;
        TDT4102::Button quitBtn, personNewBtn;
        std::vector<std::shared_ptr<Person>> people;

    public:
        // Constructor
        MeetingWindow(int x, int y, int w, int h, const std::string& title);

        // member funcs
        void cb_quit(); // quit window
        void newPerson(); // make new pers
        void printPersons() const; // check if works in terminal
};
