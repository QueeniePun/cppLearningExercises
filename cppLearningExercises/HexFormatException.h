#include <stdexcept>
using namespace std; 

class HexFormatException : public logic_error
{
public: 
    HexFormatException(string invalidHexString) : logic_error("Invalid hex string")
    {
        this->invalidHexString = invalidHexString;
    }

    string getInvalidHexString()
    {
        return invalidHexString;
    }

private:
    string invalidHexString; 
};