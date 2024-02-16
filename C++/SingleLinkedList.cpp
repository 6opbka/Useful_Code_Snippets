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
        // [] operator overload for easier list interface
        // (Returns the item under said index)
        
        // Iterates over items until item under said index found
        int counter = 0;
        Node<T> *current = this->head;
        // While the current object is not nullptr
        while (current != nullptr){

            if(counter == index){
                // If the counter matches the searched index return the data of the object
                return current->data;
            }
            // Go to the next pointer and increase the counter value by 1
            current = current->pNext;
            counter++;

        }
    }

    void push_back(T data){
        // Push back method. 
        // Pushes the data variable to the back of the list

        // *If list is empty*, sets the data variable as a head
        if(head == nullptr){
            head = new Node<T>(data);
        }
        
        else{
            // Otherwise creates the "current" temp object
            // and sets it's address to a start of a list
            Node<T> *current = this->head;
            //Searching for the node which pointer is nullptr
            while(current->pNext != nullptr){
                current = current->pNext;
            }
            // creates a new Node object and adds its pointer to the previous last object of the list
            current ->pNext = new Node<T>(data);
            // (the pointer of the newly created object is set to nullptr by default)
        }
        // and increase the size of the list
        Size++;
    }
    void pop_back(){
        remove_at(Size-1);
    }
    void insert(T data, int index){
        if (index = 0){
            push_front(data);
        }
         
        Node<T> * previous = this->head;
        for (int i = 0; i<index-1;i++){
            previous = previous ->pNext;
        }
        Node<T> * new_node = new Node<T>(data,previous->pNext);
        previous->pNext = new_node; 
        Size++;

    }
    void push_front(T data){

        // Here we just assign ne head.
        // Constructor of the Node class sets the pointer to previous head
        head = new Node<T>(data,head);
        Size++
    }
    void pop_front(){

        // Method that pops the first object
        // First we create a temp pointer which points to the head of the list
        Node<T> *temp = head;
        // Then we set the head to the next element
        // And delete the element under according pointer from the memory
        head = head->pNext;
        delete temp;
        Size--;
    }
    void remove_at(int index){
        if (index = 0){
            pop_front(data);
        }
        Node<T> * previous = this->head;
        for (int i = 0; i<index-1;i++){
            previous = previous ->pNext;
        }
        Node<T> toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
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