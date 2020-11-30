#include <stdexcept>
using namespace std; 

class BinaryFormatException : public logic_error
{
public: 
    BinaryFormatException(string invalidBinaryString) : logic_error("Invalid binary string")
    {
        this->invalidBinaryString = invalidBinaryString;
    }

    string getInvalidBinaryString()
    {
        return invalidBinaryString;
    }

private:
    string invalidBinaryString;
};