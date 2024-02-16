#include <iostream>
using namespace std;

// Single linked list implementastion for training
// 

template <typename T>
class List{

public:
    // Constructor
    List(){
        Size = 0;
        head = nullptr;
    }

    // Destructor
    ~List(){

    }
    int size(){
        return Size;
    }
    T& operator[](const int index){
        

        int counter = 0;
        Node<T> *current = this->head;
        while (current != nullptr){

            if(counter == index){
                return current->data;
            }
            current = current->pNext;
            counter++;

        }
    }

    void push_back(T data){
        if(head == nullptr){
            head = new Node<T>(data);
        }
        else{
            Node<T> *current = this->head;
            while(current->pNext != nullptr){
                current = current->pNext;
            }
            current ->pNext = new Node<T>(data);
        }
        Size++;
    }
    void pop_front(){
        Node<T> *temp = head;
        head = head->pNext;
        delete temp;
        Size--;
    }
private:
    // Node class that has the data and the pointer to the next node
    template <typename Type>
    class Node{
        //Constructor
        public:
        Node(Type data = T(), Node *pNext = nullptr){
                    this->data = data;
                    this->pNext = pNext;
                }
        Node *pNext;
        T data;
        
    };
    
    Node<T> *head;
    int Size;
};

int main(){
    List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(11);
    cout<<lst.size()<<endl;
    lst.pop_front();
    cout<<lst.size();
    return 0;
}