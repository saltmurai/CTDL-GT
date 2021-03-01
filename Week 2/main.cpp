#include <iostream>
using namespace std;
#define MAX 10
template <class T>
class Stack
{
    T info[MAX];
    unsigned int n;

public:
    void initialize()
    {
        this->n = 0;
    }
    bool is_empty()
    {
        return this->n == 0 ? 1 : 0;
    }
    bool is_full()
    {
        return this->n == MAX ? 1 : 0;
    }
    void push(T K)
    {
        if (this->is_full())
            return;
        else
        {
            this->info[this->n] = K;
            this->n++;
        }
    }
    T pop()
    {
        if (this->is_empty())
            return 0;
        else
        {
            this->n--;
            return this->info[this->n];
        }
    }
    T top()
    {
        if (this->is_empty())
            return NULL;
        else
            return this->info[this->n - 1];
    }
};

int main() { 
    Stack<int> stack1;
    stack1.initialize();
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    
    for(int i = 0; i < 4; ++ i) 
    cout << stack1.pop() << endl;
}
