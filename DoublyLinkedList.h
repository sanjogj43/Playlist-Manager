/*
 * DoublyLinkedList.h
 * Declares all the functions mentioned for 
 * different operations of the doubly linked list
 * Created on: Sep 6, 2013
 * Author: Sanjog
 */
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include<string>
#include<iostream>
using namespace std;

/*Class Doubly Linked List
* declares all the functions required for operations 
* in doubly linked list.
*/
class DoublyLinkedList
{
   private:
   class Node
   {
      public:
		  Node *next;
          Node *prev;
          string *data;
          Node();
          Node(Node*,Node*,string&);
          ~Node();
   };

   Node *headNode;
   Node *tailNode;
   Node *currentNode;

   public:
      DoublyLinkedList();
      DoublyLinkedList(const DoublyLinkedList& list);
      ~DoublyLinkedList();
      bool empty();
      void append(string &);
      void insertBefore(string &);
      void insertAfter(string &);
      void remove(string &);
      void begin();
      void end();
      bool next();
      bool prev();
      bool find(string &);
      const string& getData();
};

#endif
