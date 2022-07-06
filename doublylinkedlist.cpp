#include <iostream>
#include <stdlib.h>
#define MAXSTRING 256
using namespace std;

 struct patient
{

    char name[MAXSTRING];
    int id;
};

 struct node 
{

    patient data;
    node *previous;
    node*next;

} ;



node *first;
node *head;
node *tail;
node *current;

// add node in list
void addNode(patient p)
{

    // create new node and allocate memmory
    node *ptr = new node();
    ptr = (node *)malloc(sizeof(*ptr));

    // check if new node is empty
    if (ptr == NULL)
    {
        cout << "ERROR" << endl
             << "WRONG" << endl;
    }
    // assign patient data to new node
    ptr->data = p;

    // next and prev node are empty

    ptr->next = NULL;
    ptr->previous = NULL;
    // if list is empty
    if (head == NULL)
    {
        head = ptr;
        first = ptr;
        tail = ptr;
    }

    current = tail;
    if (current == NULL)
    {
        current = ptr;
        head = current;
    }
    else
    {
        current = current->previous;
        current = NULL;
        current = ptr;
        head = current;
    }
}
void destroy(){

    while (current != NULL)
    {
        current = NULL ;
        free(current);
        current = current->previous;
    }
    free(first);
    free(head);
    free(tail);
}


int main(int argc, char const *argv[])
{
    patient p;
    p.id=18734;
    cout<<"Name:"<<endl;
    cin>>p.name;
    addNode(p);
    destroy();

    return 0;
}
