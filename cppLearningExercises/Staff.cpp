#include "Staff.h"

Staff::Staff()
{
    title = "Ms.";
}

Staff::Staff(const string& title)
{
    this->title = title;
}

string Staff::getTitle()
{
    return title;
}

void Staff::setTitle(const string& title)
{
    this->title = title;
}

string Staff::toString()
{
    return "Staff: " + getName();
}

