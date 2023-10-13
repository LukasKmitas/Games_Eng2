/* DLinkedList.h --- 
 * 
 * Filename: DLinkedList.h
 * Description: Testing DLinked Lists using make file 
 * Author: Lukas
 * Maintainer: 
 * Created: Wed Oct  4 18:44:47 2023 (+0100)
 * Last-Updated: Wed Oct  4 20:39:12 2023 (+0100)
 *           By: Lukas
 *     Update #: 7
 * 
 * Commentary: 
 * 
 * 
 * 
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#include <stdbool.h>

        /**
       * node_t
       *
       * Struct representing Node in a doubly linked list
       */
struct node_t
{
  struct node_t *previous,*next;
  int data;
};

        /**
       * DLList
       *
       * Struct representing a doubly linked list data type
       */
struct DLList_t
{
  struct node_t *first;
  struct node_t *current;
  int size;
};

#define DLList struct DLList_t

/**
* List constructor.
* @return Pointer to the new list
*/
DLList* createDLList()
{
       DLList* newList = (DLList*)malloc(sizeof(DLList));
       newList->first = 0;
       newList->current = 0;
       newList->size = 0;
       return newList;
}

      /**
       * returns the number of items in the list
       * @param theList a pointer to the DLList struct
       * @return The number of elements in the DLList
       */
int size(DLList *theList)
{
       return theList->size;
}

      /**
       * Adds an item to the front of the list
       * @param theList a pointer to the DLList struct
       * @param newData the data item to be added (an integer).
       * @return The number of elements in the DLList
       */
int push(DLList * theList, int newData)
{
       struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));

       newNode->data = newData;
       newNode->previous = 0;
       newNode->next = theList->first;

       if(theList->first != 0) 
       {
              theList->first->previous = newNode;
       }

       theList->first = newNode;
       theList->current = newNode;
       theList->size++;
       return theList->size;
}

      /**
       * removes an item to the front of the list
       * @param theList a pointer to the DLList struct
       * @return The data item - an integer
       */
int pop(DLList* theList)
{
       if (theList->size == 0)
       {
              return 0;
       }
       int data = theList->first->data;
       struct node_t* temp = theList->first;

       if(theList->first == theList->current) 
       {
              theList->current = theList->current->next;
       }

       theList->first = theList->first->next;
       if (theList->first != 0) 
       {
              theList->first->previous = 0;
       }

       free(temp);
       theList->size--;
       return data;
}

      /**
       * removes an item to the front of the list returns the current element of the list
       * @param theList a pointer to the DLList struct
       * @return The data at the current position- an integer
       */
int getCurrent(DLList* theList)
{
       if (theList->current != 0) 
       {
              return theList->current->data;
       }
       return 0;
}

      /**
       * Moves current to the start of the list
       * @param theList a pointer to the DLList struct
       * @return void
       */
void first(DLList* theList)
{
       theList->current = theList->first;
}

      /**
       * Moves current to next element of the list
       * @param theList a pointer to the DLList struct
       * @return void
       */
void next(DLList *theList)
{
       if (theList->current != 0) 
       {
          theList->current = theList->current->next;
       }
}

      /**
       * states whether current is the last element or not
       * @param theList a pointer to the DLList struct
       * @return true if current is at end otherwise false
       */
bool atEnd(DLList *theList)
{
       return (theList->current->next == 0);

       /*if(theList->current != 0)
       {
              return (0 == theList->current->next);
       }
       else
       {
              return false;
       }*/
}

      /**
       * Deletes the current element
       * @param theList a pointer to the DLList struct
       * @return number of elements remaining in list
       */
int deleteCurrent(DLList* theList)
{
       if (theList->current == 0) 
       {
              return 0;
       }
       struct node_t* temp = theList->current;
       if(temp->previous != 0) 
       {
              temp->previous->next = temp->next;
       }   
       else 
       {
              theList->first = temp->next;
       }
       if(temp->next != 0) 
       {
              temp->next->previous = temp->previous;
       }
       theList->current = temp->next;
       free(temp);
       theList->size--;
       return theList->size;
}

      /**
       * Inserts data after the current element
       * @param theList a pointer to the DLList struct
       * @param newData the data to be inserted
       * @return void
       */
void insertAfter(DLList* theList, int newData)
{
       if (theList->current == 0) 
       {
              push(theList, newData);
       }   
       else 
       {
              struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));
              newNode->data = newData;
              newNode->previous = theList->current;
              newNode->next = theList->current->next;

              if(theList->current->next != 0)
              {
                     theList->current->next->previous = newNode;
              }

              theList->current->next = newNode;
              theList->current = newNode;
              theList->size++;
       }
}

      /**
       * Inserts data before the current element
       * @param theList a pointer to the DLList struct
       * @param newData the data to be inserted
       * @return void
       */
void insertBefore(DLList* theList, int newData)
{
       if (theList->current == 0) 
       {
              push(theList, newData);
       }
       else 
       {
              struct node_t* newNode = (struct node_t*)malloc(sizeof(struct node_t));
              newNode->data = newData;
              newNode->next = theList->current;
              newNode->previous = theList->current->previous;

              if(theList->current->previous != 0) 
              {
                     theList->current->previous->next = newNode;
              } 
              else 
              {
                     theList->first = newNode;
              }

              theList->current->previous = newNode;
              theList->current = newNode;
              theList->size++;
       }
}

      /**
       * Prints the entire list
       * @param theList a pointer to the DLList struct
       * @return void
       */
void printList(DLList* theList)
{
       struct node_t* currentNode = theList->first;
       while(currentNode != 0) 
       {
              printf("%d ", currentNode->data);
              currentNode = currentNode->next;
       }
       printf("\n");
}

  
/* DLinkedList.h ends here */
