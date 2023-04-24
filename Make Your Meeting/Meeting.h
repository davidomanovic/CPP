#pragma once
#include "Person.h"
#include <ostream>
#include <vector>
#include <utility>
#include <memory>

enum Campus{Trondheim, Aalesund, Gjoevik};
// Operator overload for campus enum
std::ostream& operator<<(std::ostream& os, const Campus &c);

class Meeting
{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;    
        std::string subject;
        const std::shared_ptr<Person> leader;
        std::vector<std::shared_ptr<Person>> participants;

    public:
        // Class constructor
        Meeting(int d, int start, int end, Campus c, std::string sub, std::shared_ptr<Person> l);


        // Get methods to get private member variables
        int getDay() const{return day;}
        int getStartTime() const{return startTime;}
        int getEndTime() const{return endTime;}
        Campus getLocation() const{return location;}
        std::string getSubject() const{return subject;}
        std::shared_ptr<Person> getLeader() const{return leader;}
        std::vector<std::shared_ptr<Person>>getParticipants() const{return participants;}

        void addParticipant(std::shared_ptr<Person> pp);
        std::vector<std::string>getParticipantList() const;
        
        std::vector<std::shared_ptr<Person>> 
        findPotentialCoDriving(Meeting meet);
};

// Operator overload for meeting
std::ostream& operator<<(std::ostream& os, const Meeting& meet);
