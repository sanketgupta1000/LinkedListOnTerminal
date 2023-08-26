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
        Node(const T & d):data(d), next(nullptr){}
    };

    //data members for linked list
    Node * head;
    int size;
    Node * tail;

public:
    //constructor for linked list
    LinkedList():head(nullptr), tail(nullptr), size(0){}

    //method for adding a node at the last
    void addNode(const T & ele)
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

    //an overload to add element at any specified index
    void addNode(T ele, int index)
    {
        //validating index
        if((index<0) || (index>size))
        {
            throw ListException("Invalid Index");
        }

        //checking if adding at last
        if(index==size)
        {
            addNode(ele);
        }
        else
        {
            //creating a new node
            Node * newnode = new Node(ele);

            //traversing to a node after which to insert
            Node * ptr = head;
            for(int i = 0; i<(index-1); i++)
            {
                ptr = (ptr->next);
            }

            (newnode->next) = (ptr->next);
            (ptr->next) = newnode;
            size++;
        }
    }

    
};


int main()
{

    return 0;
}