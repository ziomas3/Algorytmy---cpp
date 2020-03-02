#include <bits/stdc++.h> 
using namespace std; 
  
/* lista jednokierunkowa */
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  
  
/* pull off the front node of the source and put it in dest */
void MoveNode(Node** destRef, Node** sourceRef);  
  
/* Pobiera dwie listy posortowane w porządku rosnącym i łączy ich węzły, tworząc jedną dużą posortowaną listę, która jest zwracana. */
Node* SortedMerge(Node* a, Node* b)  
{  
    /*pierwszy fikcyjny węzeł do zawieszenia wyniku */
    Node dummy;  
  
    /* tail wskazuje ostatni węzeł wyniku */
    Node* tail = &dummy;  
  
    /* so tail->next jest miejscem dodawania nowych węzłów do wyniku */
    dummy.next = NULL;  
    while (1)  
    {  
        if (a == NULL)  
        {  
            /* jeśli skończy się którakolwiek z list, użyj innej listy */
            tail->next = b;  
            break;  
        }  
        else if (b == NULL)  
        {  
            tail->next = a;  
            break;  
        }  
        if (a->data <= b->data)  
            MoveNode(&(tail->next), &a);  
        else
            MoveNode(&(tail->next), &b);  
  
        tail = tail->next;  
    }  
    return(dummy.next);  
}  
/* MoveNode() funkcja pobiera węzeł z przodu źródła i przesuwa go na przód dest. Błędem jest wywoływanie tego z pustą listą.  
Przed wywołaniem MoveNode():  
source == {1, 2, 3}  
dest == {1, 2, 3}   
Po wywołaniu MoveNode():  
source == {2, 3}  
dest == {1, 1, 2, 3} */

void MoveNode(Node** destRef, Node** sourceRef)  
{  
    /* przedni węzeł źródłowy */
    Node* newNode = *sourceRef;  
    assert(newNode != NULL);  
    /* Przesuń wskaźnik źródłowy */
    *sourceRef = newNode->next;  
    /* Link the old dest off the new node (Połącz stary dest z nowego węzła) */
    newNode->next = *destRef;  
    /* Przenieś dest, aby wskazać nowy węzeł */
    *destRef = newNode;  
}  
  
/*Funkcja wstawiania węzła na początek listy jednokierunkowej */
void push(Node** head_ref, int new_data)  
{  
    /* przydzielić węzeł */
    Node* new_node = new Node(); 
  
    /* umieść data */
    new_node->data = new_data;  
  
    /* link the old list off the new node (połącz starą listę z nowego węzła)*/
    new_node->next = (*head_ref);  
  
    /*przesuń głowę, aby wskazać nowy węzeł */
    (*head_ref) = new_node;  
}  
/* Funkcja tworzenia węzłów w danej liście jednokierunkowej */
void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    }  
}  
 
int main()  
{  
    /* zaczynamy z pustymi listami */
    Node* res = NULL;  
    Node* a = NULL;  
    Node* b = NULL;  
  
    /*Tworzymy listy a i b  (a: 5->10->15, b: 2->3->20 )*/
    push(&a, 15);  
    push(&a, 10);  
    push(&a, 5);  
  
    push(&b, 20);  
    push(&b, 3);  
    push(&b, 2);  
  
    /* Usuń dupliakty z list */
    res = SortedMerge(a, b);  
    cout << "Zmergowana lista to: \n";  
    printList(res);  
    return 0;  
}  
