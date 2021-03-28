#include <iostream>
using namespace std;

class DeQueue {
private:
    int size, front, rear, number_items;
    int *queueArray;

public:
    DeQueue(int newSize) { //constructor
        size = newSize;
        queueArray = new int[size];
        front = 0; //front moves forward (+) upon remove
        rear = -1; //nothing there yet, rear moves forward (+) upon insert
        number_items = 0;
    }

    void insertLeft(int value){
        if(front == 0) {  
            front= size;
        }
        front--;
        queueArray[front] = value;
        number_items++;
    }
    
    void insertRight(int value){
        //deal with wraparound
        if(rear == size){
            rear = -1;
        }
        rear++;
        queueArray[rear] = value;
        number_items++;
    }

    int removeLeft(){
        int temp = queueArray[front++];
        if(front == size){
            front = 0;
        }
        number_items--;
        return temp;
    }

    int removeRight(){
        int temp = queueArray[rear--];
        if (rear == 0) {
            rear = size;
        }
        number_items--;
        return temp;
    }

    int peekFront() {
        return queueArray[front];
    }
    int peekRear(){
        return queueArray[rear];
    }
    bool isEmpty(){
        return (number_items == 0);
    }
    bool isFull(){
        return (number_items == size);
    }
    int qsize(){
        return number_items;
    }
    void showArray(){
        cout << "The array looks like:\n";
        for (int i = 0; i < number_items; i++) {
            cout << queueArray[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    DeQueue aQueue(5); //{   };                   front = 0, rear = -1

    cout << "Test 1\n";
    aQueue.insertLeft(15);
    aQueue.insertRight(25);
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 2\n";
    aQueue.insertLeft(5);
    cout << aQueue.peekFront() << " is in the front\n";

    cout << "Test 3\n";
    aQueue.removeLeft();
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 4\n";
    aQueue.insertRight(35);
    aQueue.insertRight(45);
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 5\n";
    aQueue.insertRight(55);
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    cout << "Test 6\n";
    aQueue.removeLeft();
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";

    aQueue.showArray();

    cout << "Test 7\n";
    aQueue.removeRight();
    cout << aQueue.peekFront() << " is in the front\n";
    cout << aQueue.peekRear() << " is in the rear\n";
}