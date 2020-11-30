#include <stdexcept>
using namespace std;

class IllegalSubscriptException : public logic_error
{
public:
    IllegalSubscriptException(int subscript) : logic_error("Invalid subscript")
    {
        this->subscript = subscript; 
    }

    int getSubscript() const
    {
        return subscript;
    }

private: 
    int subscript; 
};