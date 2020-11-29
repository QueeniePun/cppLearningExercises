#include "Faculty.h"


Faculty::Faculty()
{
    officeHours = "MONDAY/WEDNESDAY: 9 AM to 10 AM";
    rank = 1;
}

Faculty::Faculty(string officeHours, int rank)
{
    this->officeHours = officeHours;
    this->rank = rank;
}

string Faculty::getOfficeHours()
{
    return officeHours;
}

int Faculty::getRank()
{
    return rank;
}

void Faculty::setOfficeHours(string officeHours)
{
    this->officeHours = officeHours;
}

void Faculty::setRank(int rank)
{
    this->rank = rank;
}

string Faculty::toString()
{
    return "Faculty: " + getName();
}