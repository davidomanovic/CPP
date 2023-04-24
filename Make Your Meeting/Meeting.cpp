#include "Meeting.h"

// Constructor with member initializer list
Meeting::Meeting(int d, int start, int end, Campus c, std::string sub, std::shared_ptr<Person> meetingLeader)
: day(d), startTime(start), endTime(end), location(c), subject(sub), leader(meetingLeader)
{
}

void Meeting::addParticipant(std::shared_ptr<Person> pp)
{
    // add person object to participant shared ptr vector
    participants.push_back(pp);
    participants.push_back(leader); // remember the leader too
}

std::vector<std::string> Meeting::getParticipantList() const
{
    std::vector<std::string> participantList;
    for (const auto& participant: participants)
    {
        participantList.push_back(participant->getName());
    }
    return participantList;
}

// Overloading campus << operator
std::ostream& operator<<(std::ostream& os, const Campus &c)
{
    const std::string campusName[] = {"Trondheim", "Ålesund", "Gjøvik"};
    return os << campusName[c];
}

// Overloading meeting class << operator (NOT FRIEND)
std::ostream& operator<<(std::ostream& os, const Meeting& meet)
{
    os << "Subject: " << meet.getSubject() << std::endl;
    os << "Location: " << meet.getLocation() << std::endl;
    os << "Start time: " << meet.getStartTime() << ".00" << std::endl;
    os << "End time: " << meet.getEndTime() << ".00" <<std::endl;
    os << "Leader: " << meet.getLeader()->getName() << std::endl;

    os << "List of participants: " << std::endl;

    std::vector<std::string> list = meet.getParticipantList();
    for (const auto& participant : list)
    {
        os << participant << std::endl;
    }

    return os;
}

std::vector<std::shared_ptr<Person>> 
Meeting::findPotentialCoDriving(Meeting meet)
{
    std::vector<std::shared_ptr<Person>> coDrivers;
    for (auto& participant : meet.participants) 
    {
        if (participant->hasAvailableSeats() 
            && meet.location == this->location
            && meet.day == this->day
            && meet.startTime >= this->startTime - 1
            && meet.endTime <= this->endTime + 1)
        {
            coDrivers.push_back(participant);
        }
    }
    return coDrivers;
}

