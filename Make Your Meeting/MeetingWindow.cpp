#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string& title) :
        TDT4102::AnimationWindow(x, y, w, h, title),
        personName({fieldPad, pad}, fieldW, fieldH, ""),
        personEmail({fieldPad, pad+50},fieldW, fieldH,""),
        quitBtn({pad, pad}, btnW, btnH, "Quit"),
        personNewBtn({fieldPad+400, pad}, btnW+50, btnH+25, "New Person")
{

    // add buttons and fields bruh
    add(quitBtn); 
    add(personName);
    add(personEmail);
    add(personNewBtn);
    
    //Random ahh design
    draw_text({fieldPad+50, pad-25}, "Add participants to your meeting");
    draw_text({fieldPad-60, pad}, "Name: ");
    draw_text({fieldPad-65, pad+50}, "Email: ");

    draw_circle({pad, pad}, btnW-20);
    draw_circle({pad+400, pad+100}, btnW);
    draw_circle({pad+600, pad-40}, btnW);
    
    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this)); // make it so it quits window
    personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson, this)); // call back to the function toa dd personsss
}

void MeetingWindow::cb_quit()
{
    this->close();
}

void MeetingWindow::newPerson()
{
    people.emplace_back (new Person{personName.getText(),
    personEmail.getText()});
    this->personName.setText("");
    this->personEmail.setText("");
    printPersons(); // check if working.
}

void MeetingWindow::printPersons() const
{
    for (const auto& participant : people)
    {
        std::cout << "Added participant:\n" << "Name: "<< participant->getName() << 
        "\n" << "Email: " <<participant->getEmail() << "\n \n";
    }
}
