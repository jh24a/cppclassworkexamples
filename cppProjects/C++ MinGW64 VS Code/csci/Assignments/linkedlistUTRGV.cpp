#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};
Node *head = nullptr;

//*************PROBLEM ONE************
    //a.
        // function to traverse entire list
        void traverselist(){ 
            Node *curr = head;
            while(curr -> next != nullptr){
                curr = curr->next;
            }
        }

    //b.
        //  function to insert 68 pointer
        //assuming that: trail->next = last
        void insert68(Node *trail){
            Node *temp = nullptr;
            Node *newnode = new Node;
            newnode->info = 68;             
            newnode -> next = nullptr;
            temp = trail->next;
            trail->next = newnode;
            newnode->next = temp;              
        }

    //c.
        void deletelast(){
            Node *curr = head;
            Node *prev = nullptr;
            while (curr -> next != nullptr){
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            delete curr;               
        }

    //d.
        void delete10(){
            Node *curr = head, *prev = nullptr;

            while (curr->info != 10){
                prev = curr;
                curr = curr->next;
            }
            if (curr->next != nullptr){
                prev->next = curr->next;
            }
            else if (curr->next == nullptr){
                prev->next = nullptr;
                
            }
            delete curr;                
        }


//******PROBLEM TWO***********//
    int main(){

        //node list
            Node *node72 = new Node;
            node72 -> info  = 72;
            node72 -> next = nullptr;

            Node *node43 = new Node;
            node43 -> info = 43;
            node43 -> next = nullptr;

            Node *node8 = new Node;
            node8 -> info = 8;
            node8 -> next = nullptr;

            Node *node12 = new Node;
            node12 -> info = 12;
            node12 -> next = nullptr;

        Node *temp = nullptr;
        Node *curr = nullptr;

        //a.
            head = node72;

        //b.
            temp = head;
            head = node43;
            node43 -> next = temp;
        
        //c.
            curr = head;
            while (curr -> next != nullptr){
                temp = curr;
                curr = curr -> next;
            } 
            curr->next = node8;

        //d.
            curr = head;
            temp = head;
            while (curr -> info != 43){
                curr = curr -> next;
            }
            temp = curr -> next;
            curr -> next = node12;
            node12 -> next = temp;

        //e.
            curr = head;
            int counter = 0;
            cout << "node " <<counter +1 << ": "<< curr -> info <<endl;
            while (curr -> next != nullptr){
                counter++;
                curr = curr -> next;
                cout << "node " <<counter +1 << ": "<< curr -> info <<endl;
            }

        return 0;
    }



//*******PROBLEM THREE*******//
    /*
    a. list

    b. 25, 16, 12    (list -> ptr->ptr)
        
    c.  nodeType *head = list;                 
        nodeType *newnode = new nodeType;
        nodeType *temp = nullptr, *curr = nullptr;
        newnode -> info = 45;
        newnode -> link = nullptr;
        curr = head;
        while (curr -> info != 16){
            curr = curr -> link;
        }
        if (curr -> link != nullptr){
            temp = curr -> link;
            curr->link = newnode;
            newnode -> link = temp;
        }
        else{ curr -> link = newnode;}
        delete temp;                         //current linked list: 25,16,45,12

    d.  nodeType *head = list;
        nodeType *node58 = new nodeType;
        node58 -> info = 58;
        node58 -> link  = head;
        head = node58;                      //current linked list: 58,25,16,45,12  (node58 , list, ptr, newnode, ptr)

        yes, head was pointing to list, but in order to put node58 before list,
        head will have to point to node58 and node58 to list.

    e.  nodeType *head = node58;
        head ->link -> link = list -> link;
        delete list;

        no

    */
