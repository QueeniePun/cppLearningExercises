#include <stdexcept>
using namespace std;

class EmptyStackException : public logic_error
{
public: 
    EmptyStackException(int size) : logic_error("Stack is empty")
    {
        this->size = size; 
    }

    int getSize() const
    {
        return size; 
    }
private:
    int size; 
};