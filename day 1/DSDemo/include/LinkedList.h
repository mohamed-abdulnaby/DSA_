#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    public:



        LinkedList()
        {
            head = tail = NULL;
        }

        void add(int data)  // O(1)
        {
            // insert new node
            Node * node = new Node(data);

            // List if it was empty
            if(head == NULL)
            {
                head = tail = node;

            }
            else
            {

                // connect it
                node->prev = tail;
                tail->next = node;
                tail = node;

            }
        }

        void sorted_add(int data)
        {
            if(head == NULL)
            {
                add(data);
                return;
            }

            Node* current = head;



            if (data <= head->data)
            {
                insertBefore(data, head->data);
                return;
            }

            while(current != NULL)
            {
                if (data <= current->data)
                {
                    insertBefore(data, current->data);
                    return;
                }
                current = current->next;
            }
            add(data);

        }



        void insertAfter(int data,int afterData)
        {
            Node* node = getNode(afterData);
            if(node == NULL) return;

            Node *newNode = new Node(data);

            newNode->prev = node;
            newNode->next = node->next;

            if(node->next == NULL)
            {



                tail = newNode;

            }else
            {

                newNode->next->prev = newNode;

            }
            node->next = newNode;
            return;
        }

        void insertBefore(int data,int beforeData)
        {
            Node* node = getNode(beforeData);

            if(node == NULL) return;
            Node* newNode = new Node(data);

            newNode->next = node;
            newNode->prev = node->prev;

            if(node->prev != NULL)
            {
                newNode->prev->next = newNode;
            }else
            {
                head = newNode;
            }
            node->prev = newNode;
            return;
        }

        int Count()
        {
            int c = 0;
            Node* current = head;
            while(current != NULL) {c++; current = current->next;}

            return c;

        }

        int getDataByIndex(int index)
        {
            Node *current = head;
            int i = 0;
            for(; current != NULL ; i++)
            {
                if(i == index) return current->data;
                current = current->next;
            }
            return NULL;
        }

        void Reverse()
        {
            Node* inc = head;
            Node* dec = tail;
            while(inc != dec)
            {
                int temp = inc->data;
                inc->data = dec->data;
                dec->data = temp;
                inc = inc->next;
                dec = dec->prev;
            }
            return;


        }

        LinkedList* Reverse_()
        {
            LinkedList* LL = new LinkedList();

            Node* node = this->tail;
            while(node != NULL)
            {
                LL->add(node->data);
                node = node->prev;
            }

            return LL;
        }

        void Remove_k( int k)
        {
            if(k <=0) return;

            Node* current = head;
            for(int i = 1; current!= NULL; i++)
            {
                Node* nextNode = current->next;
                if(i%k == 0)
                {

                    Delete(current->data);

                }
                current = nextNode;
            }
            return;
        }

        LinkedList* intersect(LinkedList & L2)
        {
            LinkedList* Lr =new LinkedList();
             Node* current = head;

             while(current != NULL)
             {
                 if(L2.getNode(current->data) != NULL)
                 {
                     Lr->add(current->data);
                 }
                 current = current->next;
             }
             return Lr;
        }

        // for testing
        void Display()  // O(n)
        {

            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
                cout<<current->data<<"\t";

                //move next
                current = current->next;

            }
        }

        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=NULL)
                return true;
            else return false;
        }


        bool Delete(int data)
        {
            // search
            Node * node = getNode(data);
            if(node!=NULL)
            {
                // delete
                //one element
                if(head == node && tail == node)
                {
                    head = tail = NULL;
                }

                // head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = NULL;
                }

                // tail
                else if(node == tail)
                {
                     tail = node->prev;
                     tail->next = NULL;
                }

                // inbetween
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                delete node;

            }
            else return false;
        }



    private:
        Node * head;
        Node * tail;

    Node* getNode(int data)
    {
        Node * current = head;
        while(current != NULL)
        {
            // found
            if(data == current->data)
                return current;
            //move next
            current = current->next;
        }
        return NULL;
    }
};

#endif // LINKEDLIST_H
