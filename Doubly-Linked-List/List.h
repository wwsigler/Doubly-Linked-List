
#ifndef LIST_H
#define LIST_H
#include<iostream>

using namespace std;

template<typename T>
class List {
    
public:
    struct ListNode 
    {
        T value;
        ListNode* prev;
        ListNode* next;
    };

    ListNode* head;
    ListNode* tail;


    //constructor for List class
    List() : head(nullptr), tail(nullptr) {}


    //destructor for List class
    ~List() 
    {
        while (head != nullptr) 
        {
            ListNode* node = head;
            head = head->next;
            delete node;
        }
    }


    //print function that calls other print function
    void print()
    {
        print(head);
        cout << endl;
        
    }


    //append function that dynamically allocates new node w/ paramete
    void append(T value)
    {
        ListNode* newNode = new ListNode;
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }


    //this function calls to begin sorting the list in descending order.
    void mergesort()
    {
        head = mergesort(head, tail);

        //looks through list for new tail
        ListNode* node = head;

        while (node->next != nullptr)
        {
            node = node->next;
        }

        tail = node;
    }



private:
    //this will print every value in the  list after the parameter node
    void print(ListNode* node) 
    {
        while (node != nullptr)
        {
            cout << node->value << " ";
            node = node->next;
        }
    cout << endl;
    }


    //This function manages the recursive calls that mergesort needs to make
    ListNode* mergesort(ListNode* first, ListNode* last)
    {
        if (first == nullptr || first == last)
        {
            return first;
        }

        ListNode* midpoint = split(first, last);
        cout << "midpoint: " << midpoint->value << endl; // remove
        ListNode* left = first;
        ListNode* right = midpoint;

        left = merge(left, midpoint);
        right = merge(right, last);

        return merge(left, right);
        cout << "After merging: "; //remove
        print(left); //remove
        print(right); //remove

        

    };
    

    //merges two list partitions together
    ListNode* merge(ListNode* first, ListNode* second)
    {
        if (first == nullptr)
        {
            return second;
        }
        if (second == nullptr)
        {
            return first;
        }
        ListNode* result;
        if (first->value <= second->value)
        {
            result = first;
            result->next = merge(first->next, second);
        }
        else
        {
            result = second;
            result->next = merge(first, second->next);
        }
        return result;
    }


    //subdivides a list partition into two more partitions
    ListNode* split(ListNode* first, ListNode* last)
    {
        cout << "Splitting: "; //remove
        print(first); //remove
        ListNode* slow = first;
        ListNode* fast = first->next;

        while (fast != last && fast->next != last)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Left: "; //remove
        print(first); //remove
        cout << "Right: "; //remove
        print(slow->next); //remove

        return slow; 
    }
    
};

#endif