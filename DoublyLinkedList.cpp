/*
 * DoublyLinkedList.cpp 
 * defines all the functions required for different oprations in 
 * doubly linked list
 * Created on: Sep 6, 2013
 * Author: Sanjog
 */


#include "DoublyLinkedList.h"
#include<string>
#include<iostream>
using namespace std;

/*
Constructing an instance of class node. Non Parameterized constructor
*/
DoublyLinkedList::Node::Node()
{
     	this->next=NULL;
     	this->prev=NULL;
     	this->data=NULL;
}


/*
Constructing an instance of class node.Parameterized constructor
Node *prevNode : this is a pointer variable pointing to the previous node
Node *nextNode : this is a pointer variable pointing to the next node
string &passedData : this is a song which is string variable passed by reference
*/
DoublyLinkedList::Node::Node(Node *prevNode,Node *nextNode,string &passedData)
{
   this->next=nextNode;
   this->prev=prevNode;
   this->data = new string;
   this->data->assign(passedData);
}


/*
Destructing an instance of class node. 
*/
DoublyLinkedList::Node::~Node()
{
	delete(this->data);
	this->prev=NULL;
	this->next=NULL;
}


/*
* Constructing and instance of class DoublyLinkedList.
* Non Parameterized constructor
*/
DoublyLinkedList::DoublyLinkedList()
{
    headNode = NULL;
    tailNode = NULL;
    currentNode= NULL;
}


/*
* Destructing and instance of class node. 
*/
DoublyLinkedList::~DoublyLinkedList()
{
  Node *tempNode = this->headNode;
  while(tempNode!=NULL)
  {
    this->headNode=tempNode->next;
    delete tempNode;
    tempNode = this->headNode;
  }
}


/*
* Returns true if the List is empty
*/
bool DoublyLinkedList::empty()
{
   if(this->headNode==NULL) //to do: in delete node : set all 
	                        //nodes to null for null list
   {
	   return true;
   }
   return false;
}


/*
* Append a new node at the end of the list.
* string &s is the song which is passed by reference
* and appended at the end of the lists
*/
void DoublyLinkedList::append(string &s)
{
   Node *tempNode = new Node(NULL,NULL,s);
   //assigning the address of passed variable to 
   //the string pointer data.

   if(this->empty())
   {
	   this->headNode=tempNode;
	   this->currentNode=tempNode;  //while inserting the first node 
	                                //assign all the pointers to first node.
	   this->tailNode=tempNode;
   }
   else
   {
		this->tailNode->next = tempNode;
		tempNode->prev=this->tailNode;
		this->tailNode=tempNode;    //pointing the lastly created node to 
		                            //tailNode pointer.     

		this->currentNode = this->tailNode; // current node should also point 
		                                    //to the last object created.
   }
}


/*
* inserting a new node before the current node.
* string &s : it is the song which is passed by reference
* and inserted before the current song
*/
void DoublyLinkedList::insertBefore(string &s)
{
	//create a node and insert the data
    Node *tempNode1 = new Node(NULL,NULL,s);
	
	if(!this->empty())
	{
		//if node is to be inserted before head node
		if(this->currentNode!=this->headNode)
		{
		  tempNode1->prev = this->currentNode->prev;
		  this->currentNode->prev->next=tempNode1;
		}
	
		tempNode1->next=this->currentNode;
		this->currentNode->prev=tempNode1;
	
		this->currentNode = tempNode1;
	
		//if node is inserted before head node
	    if(this->currentNode->prev==NULL)
		{ 
			this->headNode=this->currentNode;
		}
	}
	
	//if the list is empty.
	else
	{
	  this->headNode=tempNode1;
	  this->tailNode=tempNode1;
	  this->currentNode=tempNode1;   
	}
}


/*
* Inserting a new node after the current node.
* string &s : is the song which is passed by reference
*/
void DoublyLinkedList::insertAfter(string &s)
{
	//create a node and insert the data
    Node *tempNode1 = new Node(NULL,NULL,s);
	if(!this->empty())
	{
		//if node is any node other than tail node
		if(this->currentNode!=this->tailNode)
		{
		  tempNode1->next = this->currentNode->next;
		  this->currentNode->next->prev=tempNode1;
		}
	
		tempNode1->prev=this->currentNode;
		this->currentNode->next=tempNode1;
	
		this->currentNode=tempNode1;
	
		//if node is to be inserted after the last node
		if(this->currentNode->next==NULL)
		{
			this->tailNode = this->currentNode;
		}
	}

	//if the list is empty
	else
	{
	  this->headNode=tempNode1;
	  this->tailNode=tempNode1;
	  this->currentNode=tempNode1;
	}
}


/*
* removing the node containing the value passed.
* string &s : it is the song which is passed by reference
* and is removed from the list
*/
void DoublyLinkedList::remove(string &s)
{
	//finding the object
	if(this->find(s))
	{
	   // setting the links i.e remove the objects.
	   // setting the current node pointer to appropriate node  
		Node *tempNode = this->currentNode;

		//for all the nodes other than tail node.
		if(tempNode!=this->tailNode)
		{
		   tempNode->next->prev = tempNode->prev;		   
		}

		//for all the nodes other than head node
		if(tempNode!=this->headNode)
		{
		   tempNode->prev->next = tempNode->next;		
		}
		
		//if head node is to be removed
		if(tempNode == this->headNode)
		{
		   this->headNode = this->headNode->next;
		   this->currentNode=this->headNode;
		}

		//if tail Node is to be removed
		else if(tempNode == this->tailNode)
	    {
		   this->tailNode = this->tailNode->prev;
		   this->currentNode=this->tailNode;
		}

		//node other than head or tail node is removed.
		else
		{
			this->currentNode = tempNode->next;
		}

     	// are all the pointers are free or they sill point to the location? in case of 1 node.	
 	    // destruct the removed object
	    delete(tempNode);
		//to do : check if all head tail and current are also destroyed.
	}
}


/*
* set the current node to the head node.
* goto the first song
*/
void DoublyLinkedList::begin()
{
	if(!this->empty())                    //validity check , also check while calling this function.
	this->currentNode = this->headNode;
}


/*
* set the current node to the tail node.
* goto the last song
*/
void DoublyLinkedList::end()
{
	if(this->tailNode!=NULL)             //validity check , also check while calling this function.
	this->currentNode=this->tailNode;
}


/*
* moving the current node pointer to the next node.
* return true if operation is successful 
*/
bool DoublyLinkedList::next()
{
	if(!this->empty() && this->currentNode->next!=NULL) 
	{
	  this->currentNode = this->currentNode->next;
	  return true;
	}
	
	// if next node of the current node is empty or
	// if the list is empty return false
	return false;
}


/*
* moving the current node pointer to the previous node.
* return true if the operation is unsuccessful
*/
bool DoublyLinkedList::prev()
{
	if(!this->empty() && this->currentNode->prev!=NULL) 
	{
	  this->currentNode = this->currentNode->prev;
	  return true;
	}
	
	// if previous node of the current node is empty or
	// if the list is empty return false
	return false;
}


/*
* to find the specified data in the linked list
* string &s : it is the song which is passed by reference
*/
bool DoublyLinkedList::find(string &s)
{
	//add validation check
	Node *tempNode= this->headNode;

	//check till the node consisting the required data is found
	while(!this->empty()&&tempNode->data->compare(s)!=0)
	{
		tempNode=tempNode->next;
		if(tempNode==NULL)                //validity check to avoid crash
		{
			break;
		}
	}

	//if data is found 
	if(tempNode!=NULL)
	{
		this->currentNode = tempNode;
		return true;
	}

	//if no data is found
	return false;
}


/*
* return the string pointed by the current pointer.
*/
const string& DoublyLinkedList::getData()
{
  //the null check for this is in playlist.cpp
	return *(this->currentNode->data);
}

//end of file.