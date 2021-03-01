#include <iostream>
#define MAX 10
using namespace std;

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
            exit(0);
        else
        {
            this->n--;
            return this->info[this->n];
        }
    }
    T top()
    {
        if (this->is_empty())
            exit(0);
        else
            return this->info[this->n - 1];
    }
};

template <class T>
class Queue
{
    Stack<T> s1, s2;

public:
    Queue() {
        s1.initialize();
        s2.initialize();
    }
    void en_queue(T K)
    {
        // Di chuyen cac phan tu tu s1 sang s2
        while (!s1.is_empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // Push vao s1
        s1.push(K);
        //Di chuyen lai s2 vao s1
        while (!s2.is_empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    T de_queue()
    {
        if (s1.is_empty())
        {
            cout << "Queue is empty";
            exit(0);
        }

        T K = s1.top();
        s1.pop();
        return K;
    }
};
int main()
{
    Stack<int> stack1;
    stack1.initialize();
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    cout << "Stack test: " << endl;
    for (int i = 0; i < 4; ++i)
        cout << stack1.pop() << endl;

    Queue<int> queue1;
    queue1.en_queue(5);
    queue1.en_queue(7);
    queue1.en_queue(8);
    cout << "Queue test: " << endl;
    for (int i = 0; i < 3; ++i)
        cout << queue1.de_queue() << endl;
}
