#include <iostream>
#include "../header/doublyNode.h"

void CDLL::display(NODE *&head)
{
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    std::cout << "Linked List: " << std::endl;
    if (head == NULL)
    {
        std::cout << "The Linked List is empty!";
        std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        return;
    }
    NODE *temp = head;
    std::cout << "Head -> ";
    while (temp->next != head)
    {
        temp->displayNode();
        temp = temp->next;
    }
    temp->displayNode();
    std::cout << " Head";
}

void CDLL::insertAtFront(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    NODE *temp = head;
    n->prev = temp->prev;
    n->next = temp;
    (temp->prev)->next = n;
    temp->prev = n;
    head = n;
}

void CDLL::insertAtEnd(NODE *&head)
{
    NODE *n = new NODE();
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    NODE *temp = head;
    n->prev = temp->prev;
    (temp->prev)->next = n;
    n->next = temp;
    temp->prev = n;
}

void CDLL::deleteFromEnd(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    if (temp->next == temp)
    {
        head = NULL;
        delete temp;
        return;
    }
    temp = temp->prev;
    NODE *temp2 = temp->prev;
    temp2->next = head;
    head->prev = temp2;
    delete temp;
}

void CDLL::deleteFromFront(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    NODE *temp = head;
    if (temp->next == temp)
    {
        head = NULL;
        delete temp;
        return;
    }
    NODE *temp2 = head;
    temp2 = temp2->prev;
    (temp->next)->prev = temp2;
    temp2->next = temp->next;
    head = temp->next;
    delete temp;
}