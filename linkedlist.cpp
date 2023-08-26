#include<iostream>
#include<exception>
using namespace std;

//will create a class for linked list

template <typename T>
class LinkedList
{
private:
    //struct for a node
    struct Node
    {
        T data;
        Node * next;

        //constructor for node
        Node(T d):data(d), next(nullptr){}
    };

    //data members for linked list
    Node * head;
    int size;
    Node * tail;

public:
    //constructor for linked list
    LinkedList():head(nullptr), tail(nullptr), size(0){}

    //method for adding a node
    void addNode(T ele)
    {
        //creating new node
        Node * newnode  = new Node(ele);

        //checking if adding first node
        if(size==0)
        {
            head = tail = newnode;
        }
        else
        {
            Node * ptr = head;

            //traversing to last node
            while((ptr->next)!=nullptr)
            {
                ptr = (ptr->next);
            }

            (ptr->next) = newnode;
        }

        size++;
    }
};


int main()
{

    return 0;
}