#include<iostream>
#include<exception>
using namespace std;

//class for List Exceptions
class ListException:public exception
{
private:
    string err;

public:
    //constructor
    ListException(string s):err(s){}

    //redefining virtual method of parent
    const char * what() const throw()
    {
        return err.c_str();
    }
};

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

public:
    //constructor for linked list
    LinkedList():head(nullptr), size(0){}

    //method for adding a node at the last
    void addNode(const T & ele)
    {
        //creating new node
        Node * newnode = new Node(ele);

        //checking if adding first node
        if(size==0)
        {
            head = newnode;
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

    //method to delete a node at a specific index
    void deleteNode(int index)
    {
        //validating index
        if((index<0)||(index>=size))
        {
            throw ListException("Invalid Index");
        }

        //checking if deleting first node
        if(index==0)
        {
            Node * newhead = (head->next);
            delete head;
            head = newhead;
        }
        else
        {
            //traversing to a node before the node to be deleted
            Node * ptr = head;
            for(int i = 0; i<(index-1); i++)
            {
                ptr = (ptr->next);
            }

            Node * to_be_del = (ptr->next);

            (ptr->next) = (to_be_del->next);
            delete to_be_del;
        }
        size--;
    }

    //method to print the linked list
    void printList()
    {
        cout<<"head --> ";

        Node * ptr = head;
        while(ptr!=nullptr)
        {
            cout<<(ptr->data)<<" --> ";
        }
        cout<<"null"<<endl;
    }

    //method to show a menu on terminal
    void showMenu()
    {
        cout<<"Menu for Linked List: \n"
            <<"1. Add node at last\n"
            <<"2. Add node at a specific index\n"
            <<"3. Delete node from a specific index\n"
            <<"4. Print Linked list\n"
            <<"5. Exit\n";

        cout<<"Enter an option: ";

        int option;
        cin>>option;

        try
        {
            switch(option)
            {
                case 1:
                {
                    T val;
                    cout<<"Enter value of the new node: ";
                    cin>>val;
                    addNode(val);
                    break;
                }
                case 2:
                {
                    T val;
                    int i;
                    cout<<"Enter value of the new node: ";
                    cin>>val;
                    cout<<"Enter index: ";
                    cin>>i;
                    addNode(val, i);
                    break;
                }
                case 3:
                {
                    int i;
                    cout<<"Enter index from which to delete node: ";
                    cin>>i;
                    deleteNode(i);
                    break;
                }
                case 4:
                {
                    printList();
                }
                case 5:
                {
                    exit(0);
                }
                default:
                {
                    throw ListException("Invalid option");
                }
            }
            catch(const exception & e)
            {
                cout<<e.what()<<endl;
            }
            showMenu();
        }
    }
};


int main()
{
    
    return 0;
}