#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
    public:
       int ID;
       string name;
       int age;
       string work;
       int height;

       Node * right;
       Node * left;

       Node(int _ID, string _name = "mohsen", int _age = 69, string _work = "sabak")
       {
           // set data
           ID = _ID;
           name = _name;
           age = _age;
           work = _work;
           left = right = NULL;
           height = 1;

       }

};

#endif // NODE_H

