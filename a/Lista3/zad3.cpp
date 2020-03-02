#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;

/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
// Funkcja wstawiania danego węzła do posortowanej listy 
void sortedInsert(struct Node**, struct Node*); 
  
// funkcja sortuje listę jednkierunkową urzywająć insertion sort 
void insertionSort(struct Node **head_ref) 
{ 
    // inicjalizujemy listę jednokierunkową
    struct Node *sorted = NULL; 
  
    // Przejście przez podaną listę i wstawianie danego węzeł do posortowania
    struct Node *current = *head_ref; 
    while (current != NULL) 
    { 
        // Zapisz następny do następnej iteracji 
        struct Node *next = current->next; 
  
        // wstaw bieżący w posortowanej liście 
        sortedInsert(&sorted, current); 
  
        // zaktualizuj bieżący węzeł na następny 
        current = next; 
    } 
  
    //  Zaktualizuj head_ref, aby wskazać posortowaną listę 
    *head_ref = sorted; 
} 
  
/*funkcja wstawiająca new_node na liście 
 funkcja oczekuje wskaźnika do head_ref, ponieważ może to zmienić głowę listy wejściowej 
*/
void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{ 
    struct Node* current; 
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        /* Znajdź węzeł przed miejscem wstawienia */
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 
  
/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */
  
/* Function to print linked list */
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while(temp != NULL) 
    { 
        cout << temp->data << " " ; 
        temp = temp->next; 
    } 
} 
  
/* Funkcja wstawijąca węzeł na początku listy jednokierunkowej */
void push(struct Node** head_ref, int new_data) 
{ 
    /* przydzielanie węzła */
    struct Node* new_node = new Node; 
  
    /* umieść dane  */
    new_node->data  = new_data; 
  
    /* połącz starą listę z nowym węzłem */
    new_node->next = (*head_ref); 
  
    /* przesuń głowę, aby wskazać nowy węzeł */
    (*head_ref)    = new_node; 
} 
  
int main() 
{ 
    struct Node *a = NULL; 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 4); 
    push(&a, 3); 
    push(&a, 30); 
  
    cout << "Lista jednokierunkowe przed sortowaniem \n"; 
    printList(a); 
  
    insertionSort(&a); 
  
    cout << "\nLista jednokierunkowa po sortowaniu \n"; 
    printList(a); 
  
    return 0; 
} 
