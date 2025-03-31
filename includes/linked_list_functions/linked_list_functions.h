#ifndef LINKED_LIST_FUNCTIONS_H_
#define LINKED_LIST_FUNCTIONS_H_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "assert.h"
using namespace std;
#include "../../includes/node/node.h"

   //Linked List General Functions:
    template <typename ITEM_TYPE>
    void _print_list(node<ITEM_TYPE>* head);
    //recursive fun! :)
    template <typename ITEM_TYPE>
    void _print_list_backwards(node<ITEM_TYPE> *head);

    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,ITEM_TYPE key);


    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,
                                ITEM_TYPE insert_this);

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,
                                 node<ITEM_TYPE> *after_this,
                                 ITEM_TYPE insert_this);

    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,
                                  node<ITEM_TYPE>* before_this,
                                  ITEM_TYPE insert_this);

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,
                                  node<ITEM_TYPE>* prev_to_this);

    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,
                         node<ITEM_TYPE>* delete_this);

    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head);

    //duplicate list and return the last node of the copy
    template <typename T>
    node<T> *_copy_list(node<T>* &dest, node<T> *src);


    //delete all the nodes
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head);

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos);

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,       //insert
                                  ITEM_TYPE item,
                                  bool ascending=true);

    //insert or add if a dup
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,
                                          ITEM_TYPE item,
                                          bool ascending=true);
    //node after which this item goes order: 0 ascending
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,
                                   ITEM_TYPE item,
                                   bool ascending=true);
    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head);

    template <typename ITEM_TYPE>
    bool search_ptrs (node <ITEM_TYPE>* head, node <ITEM_TYPE>* ptr);
    
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //Linked List General Functions:
    template <typename ITEM_TYPE>
    void _print_list(node<ITEM_TYPE>* head){
        for (node <ITEM_TYPE> *w=head; w!=nullptr;w=w->_next){
         cout<<*w<<"->";
        }
        cout<<"+++\n";
    }

    //recursive fun! :)
    template <typename ITEM_TYPE>
    void _print_list_backwards(node<ITEM_TYPE> *head){

    }

    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head, ITEM_TYPE key){
    // node <ITEM_TYPE> *temp = new node <ITEM_TYPE>;
        for (node <ITEM_TYPE> *w=head; w!=nullptr;w= w->_next){
            // cout<<" "<<w->_item<<"\n";
        if (w->_item == key){
            return w;
            //if found
            }
        }
        //if not found
        return nullptr;
    }


    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,ITEM_TYPE insert_this){
        // assert (!(head==nullptr));
        node <ITEM_TYPE> *temp = new node <ITEM_TYPE>;
        temp->_item = insert_this;
        temp->_next = head;
        head = temp;
        return head;
    }

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,node<ITEM_TYPE> *after_this,ITEM_TYPE insert_this){
        // assert (!(after_this == nullptr));
        // if (search_ptrs (head,after_this)){
            if (head==nullptr){
                // cout<<"Backfired!\n";
                return _insert_head (head, insert_this);
            }
            node<ITEM_TYPE> * temp = new node <ITEM_TYPE>;
            temp->_item=insert_this;
            temp->_next = after_this ->_next;
            after_this->_next = temp;
            return temp;
        // }
        //  else
        //     assert (search_ptrs <ITEM_TYPE> (head,after_this));
    }

    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,node<ITEM_TYPE>* before_this,ITEM_TYPE insert_this){
        if (search_ptrs (head, before_this)){
            if (head==nullptr||before_this==head){
                // cout<<"Backfired!\n";
                return _insert_head (head, insert_this);
            }
            node <ITEM_TYPE> *temp = new node <ITEM_TYPE>;
            temp->_item = insert_this;
            node <ITEM_TYPE> *search= _previous_node (head, before_this);
            search->_next=temp;
            temp->_next = before_this;
            return temp;
        }
        else
            assert (search_ptrs <ITEM_TYPE> (head,before_this));
    }

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,node<ITEM_TYPE>* prev_to_this){
        if (prev_to_this==head){
            return nullptr;
        }
        for (node <ITEM_TYPE> *w=head; w!=nullptr;w=w->_next){
            if (w->_next == prev_to_this){
                return w;
            }
        }
        return nullptr;
    }

    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* delete_this){
        if (search_ptrs <ITEM_TYPE> (head,delete_this)){
            if (delete_this==head){
                assert (!(head==nullptr));
                node<ITEM_TYPE>* temp = head;
                ITEM_TYPE ans = temp->_item;
                head = head->_next;
                delete temp;
                return ans;
            }
            node<ITEM_TYPE>* temp = _previous_node (head, delete_this);
            ITEM_TYPE ans = delete_this->_item;
            temp->_next = delete_this->_next;
            delete delete_this;
            return ans;
        }
        else{
            assert (search_ptrs <ITEM_TYPE> (head,delete_this));
            //??
        return  head->_item;
            //??
            }
        }

    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head){
        //?
        if (head==nullptr){
            return nullptr;
        }
        //?
        //
        node <ITEM_TYPE> *copy =new node <ITEM_TYPE> (head->_item);
        node <ITEM_TYPE>* w = head->_next;
        int count =0;
        // cout<<"flag\n";
        while (w!=nullptr){
            node <ITEM_TYPE> *temp_ptr = nullptr;
            ITEM_TYPE temp=_at (copy,count);
            temp_ptr=_search_list (copy, temp);
            // cout<<"flag\n";
            node <ITEM_TYPE> *runner= _insert_after (copy, temp_ptr, w->_item);               
            count++;
            w=w->_next;
        }
        return copy;
        //!
    }

    //duplicate list and return the last node of the copy
    template <typename T>
    node<T> *_copy_list(node<T>* &dest, node<T> *src){
        node<T> * d_w = dest;
        for (node<T> * w = src ; w!=nullptr; w=w->_next,d_w=d_w->_next){
            d_w->_item=w->_item; 
         }
         return _last_node (d_w);
    }


    //delete all the nodes
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head){
        node <ITEM_TYPE> * w = head;
        while (w!=nullptr){
        node <ITEM_TYPE> * next_w = w->_next;

            delete w;
            w = next_w;
        }
        head=w;
    }
        // ITEM_TYPE temp;
        // node <ITEM_TYPE> *w = _last_node(head);
        // while (head->_next!=nullptr)
        // {
        // temp = _delete_node (head, _last_node (head));
        // }
        // delete head;

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos){
        node <ITEM_TYPE> *w = head;
        int count = 0;
        while (w!=nullptr){
            if (count == pos){
                return w->_item;
            }
            w=w->_next;
            count++;
        }
        assert (!(w==nullptr));
        //???
        return  head->_item;
        //??
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending){
        if (head ==nullptr){
            head = _insert_head (head, item);
            return head;
        }
        node <ITEM_TYPE> * pos = _where_this_goes <ITEM_TYPE>(head, item, ascending);
        if(ascending){
            if (pos==nullptr){
                return _insert_head <ITEM_TYPE> (head, item);
            }
                return _insert_after <ITEM_TYPE> (head, pos, item);
        }
        else if (!ascending){
            // cout<<"Descending!\n";
            if (pos==nullptr){
                // cout << "fuck me man" << endl;
                return _insert_head <ITEM_TYPE> (head, item);
            }
            return _insert_after <ITEM_TYPE> (head, pos, item);
        }
    }
    //insert or add if a dup
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,ITEM_TYPE item,bool ascending){

        node <ITEM_TYPE>* search = _search_list (head,item);
        if (search!=nullptr){
            search->_item = search->_item + item;
            return search;
        }
        else {
            // cout << "so this ran\n";
            search= _insert_sorted (head,item, ascending);
        }
        return search;
    }
    //node after which this item goes order: 0 ascending
 template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending){
        if (head == nullptr){
            return head;
        }
        //handling beggining case
        node <ITEM_TYPE> * p = _last_node (head);
        //ascending case
        if (ascending == true){
            for (node<ITEM_TYPE> * w = head ; w!=nullptr; w=w->_next){
                node<ITEM_TYPE> * extra = w->_next;

                // if (item<=head->_item&&extra==nullptr)
                if (item<head->_item&&extra==nullptr)
                    return nullptr;
                if (item==head->_item&&extra==nullptr)
                    return nullptr;
                if (extra==nullptr)
                    return w;
                // if (item > w->_item&&item <=extra->_item){
                if (item > w->_item&&item <extra->_item){
                    return w; 
                }
                if (item > w->_item&&item ==extra->_item){
                    return w; 
                }
                if (item>p->_item)
                    return p;    
            }
            // return nullptr;
        }
        //!Descending case
        else{
            node<ITEM_TYPE> * extra = nullptr; 
            node<ITEM_TYPE>* w =head;
            // cout << "are you kidding me???\n";
            while(w!= nullptr){
                // cout << "areefpqwerwf=ds\n";
                // cout << w->_item << endl;
                // cout << item << endl;
                if (item > w->_item){
                    return extra;
                }
                // else if (extra==nullptr)
                //     return extra;
                // else if (w->_item<item){
                // // if (w->_item>=item&&extra->_item<item){
                //     return extra;
                // }
                // else if (w->_item==item){
                //     return extra;
                // }
                extra = w; 
                w=w->_next;
            }
            // for (node<ITEM_TYPE> * w = head ; w!=nullptr; w=w->_next){
                
            //     if (item>head->_item){
            //         return nullptr;
            //     }
            //     // else if (extra==nullptr)
            //     //     return extra;
            //     else if (w->_item<item){
            //     // if (w->_item>=item&&extra->_item<item){
            //         return extra;
            //     }
            //     else if (w->_item==item){
            //         return extra;
            //     }
            //     extra = w;                
            // // cout<<"Didnt break";
            // }
        return extra;
        }
    }
    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head){
        node <ITEM_TYPE> * w = head;
        node <ITEM_TYPE> * temp ;
        while (w!=nullptr){
            temp = w;
            w=w->_next;
        }
        return temp;
    }     

    template <typename ITEM_TYPE>
    bool search_ptrs (node <ITEM_TYPE>* head, node <ITEM_TYPE>* ptr){
        if (ptr==head)
            return true;
        for (node <ITEM_TYPE>* w=head; w!=nullptr; w=w->_next){
            if (w==ptr){
                return true;
            }
        }
        return false;
    }
#endif // LINKED_LIST_FUNCTIONS_H_