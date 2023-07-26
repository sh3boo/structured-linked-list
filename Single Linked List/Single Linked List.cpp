#include <iostream>
#include<vector>
using namespace std;

struct node {
    int data;
    node* next;
    node(){};
    node(int t)
    {
        data=t;
    }
};
node* head = NULL;
void display();
void insertAtHead(int value);
void insertAtTail(int value);
void removeAtHead();
void removeAtTail();
bool isEmpty();
void clear();
int linkedListSize();
bool isExist(int value);
void removeAt(int index);
void insertAt(int value, int index);
int retrieveAt(int index);
void replaceAt(int value, int index);
bool isItemAtEqual(int value, int index);

void LinkedListProblem1() {
    node* current = head;
    int sum = 0;
    while (current != NULL && current->next != NULL) {
        if (current->data == 0 && current->next->data != 0) {
            sum = 0;
            node* temp = current->next;
            while (temp != NULL && temp->data != 0) {
                sum += temp->data;
                temp = temp->next;
            }
            current->next = temp;
            current->data = sum;
        }
        else {
            current = current->next;
        }
    }
    removeAtTail();
}

int main()
{

    insertAtTail(0);
    insertAtTail(1);
    insertAtTail(0);
    insertAtTail(3);
    insertAtTail(0);
    insertAtTail(2);
    insertAtTail(2);
    insertAtTail(0);
    LinkedListProblem1();
    // in this problem we calc the nodes between zeros and delete zeros
    display();



}
void insertAtHead(int value)
{
    node* new_node =  new node;
    new_node->data = value;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void display()
{
    if (head == NULL)
    {
        cout << "The Linked List Is underdlow..." << endl;
    }
    else
    {
        node* current;
        current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}
void insertAtTail(int value)
{
    node* new_node = new node;
    new_node->data = value;
    if (head == NULL)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next= new_node;
        new_node->next = NULL;
    }
}
void removeAtHead()
{
    node* current = head;
    if (head == NULL)
    {
        cout << "The Linked List Is Underflow..." << endl;
    }
    else
    {
        head = head->next;
        delete(current);
    }
}
void removeAtTail()
{
    node* current, * previous;
    if (head == NULL)
    {
        cout << "The Linked List Is Underflow..." << endl;
    }
    else
    {
        current = head;
        previous = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        delete(current);
        previous->next = NULL;
    }
}
bool isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}
void clear()
{
    if (isEmpty())
    {
        cout << "We Cannot Clear Empty Linked List..." << endl;
    }
    else
    {
        head = NULL;
    }
}
int linkedListSize()
{
    int count = 0;
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        node* current = head;
        while (current != NULL)
        {
            ++count;
            current = current->next;
        }
    }
    return count;
}
bool isExist(int value)
{
    node* current = head;
    while (current != NULL)
    {
        if (current->data == value)
            return true;
        else
            current = current->next;
    }
    return 0;
}

void removeAt(int index)
{
    if (head == NULL) {
        return;
    }

    node* current = head;
    if (index == 0) {
        head = head->next;
        delete current;
        return;
    }

    int count = 0;
    while (count < index - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (current->next == NULL || count != index - 1) {
        return;
    }

    node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void insertAt(int value, int index)
{
    node* new_node = new node;
    new_node->data = value;
    if (index == 0)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        int current_index = 0;
        node* current_node = head;
        node* previous_node = head;
        while (current_node != NULL && current_index < index)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }
        if (current_index = index)
        {
            previous_node->next = new_node;
            new_node->next = current_node;
        }
        else
        {
            cout << "The Index Is Out Of Range" << endl;
        }
    }
}

int retrieveAt(int index)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        node* current_node = head;
        node* previous_node = head;
        int current_index = 0;
        while (current_node != 0 && current_index < index)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }
        if (current_index == index)
        {
            return current_node->data;
        }
        else
        {
            return 0;
        }
    }

}

void replaceAt(int value, int index)
{
        int current_index = 0;
        node* current_node = head;
        while (current_node != NULL && current_index < index)
        {
            current_node = current_node->next;
            current_index++;
        }
        if (current_node!=NULL)
        {
            current_node->data = value;
        }
        else
        {
            cout << "The Index Is Out Of Range..." << endl;
        }
}
bool isItemAtEqual(int value, int index)
{
    node* current_node = head;
    int current_index = 0;
    while (current_node != NULL && current_index < index)
    {
        current_node = current_node->next;
        current_index++;
    }
    if (current_node != NULL)
    {
        if (current_node->data == value)
        {
            return 1;
        }
        else
            return 0;
    }
    else
    {

        return 0;
    }

}




