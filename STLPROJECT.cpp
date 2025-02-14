#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Liear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    int data;
    struct nodeDL<T>* prev;
    struct nodeDL<T>* next;
};

template <class T>
class DoublyLL
{
    private:
    int iCount;
    struct nodeDL<T>* First;

    public:
    DoublyLL();
    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

};

template <class T>
DoublyLL<T>::DoublyLL()
{
    iCount = 0;
    First = NULL;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T>* temp = First;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T>* newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if((First == NULL))
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T>* newn = NULL;
    struct nodeDL<T>* temp = First;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if((First == NULL))
    {
        First = newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev =temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No,int iPos)
{
    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iCount+1))
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDL<T>* newn = NULL;
        struct nodeDL<T>* temp = First;
        int i = 0;

        newn = new nodeDL<T>;

        newn->data = No;
        newn->prev = NULL;
        newn->next = NULL;

        for(i = 1; i < iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First->next== NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
    First = First->next;
    delete First->prev;
    First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T>* temp = First;
    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First->next== NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
     if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDL<T>* temp1 = First;
        struct nodeDL<T>* temp2 = NULL;
        int i = 0;

        for(i = 1; i < iPos-1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        temp1->next->prev = temp1;
        delete temp2;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeSC
{
    int data;
    struct nodeSC<T>* next;
};

template<class T>
class SinglyCL
{
   private:
   struct nodeSC<T>* First;
   struct nodeSC<T>* Last;
   int iCount;

   public:
   SinglyCL();

   void Display();
   int Count();

   void InsertFirst(T No);
   void InsertLast(T No);
   void InsertAtPos(T No,int iPos);

   void DeleteFirst();
   void DeleteLast();
   void DeleteAtPos(int iPos);
};

template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCL<T>::InsertFirst(T No)
{
   struct nodeSC<T>* newn = NULL;

   newn = new struct nodeSC<T>;

   newn->data = No;
   newn->next = NULL;

   if(First == NULL && Last == NULL)
   {
    First = newn;
    Last = newn;
   }
   else
   {
    newn->next = First;
    First = newn;
   }
   Last->next = First;
   iCount++;
}

template<class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T>* newn = NULL;

    newn= new struct nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    
   if(First == NULL&& Last == NULL)
   {
    First = newn;
    Last = newn;
   }
   else
   {
    Last->next = newn;
    Last = newn;
   }
   Last->next = First;
   iCount++;
}

template<class T>
void SinglyCL<T>::InsertAtPos(T No,int iPos)
{
    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeSC<T>* newn = NULL;

        newn = new struct nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        struct nodeSC<T>* temp = First;
        int i = 0;
        for(i = 1;i < iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next=temp->next;
        temp ->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyCL<T>::Display()
{
    struct nodeSC<T>* temp = First;
   if((First == NULL)&&(Last == NULL))
   {
     cout<<"LinkedList is empty"<<endl;
   }

   do
   {
    cout<<"|"<<temp->data<<"|<=>";
    temp = temp -> next;
   }while(temp != First);
   cout<<endl;
}

template<class T>
int SinglyCL<T>::Count()
{ 
    return iCount;
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if(First == NULL&& Last == NULL)
    {
        cout<<"The LL is emplty";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T>* temp = First;
        First = First->next;
        Last->next = First;
        delete temp;
    }
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteLast()
{
    if(First == NULL&& Last == NULL)
    {
        cout<<"The LL is emplty";
        return;
    }
    else if(First == Last)
    {
       delete First;
       First == NULL;
       Last == NULL;
    }
    else
    {
        struct nodeSC<T>* temp = First;
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
     if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount + 1)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSC<T>* temp1 = First;
        struct nodeSC<T>* temp2 = NULL;
        int i = 0;
        for(i = 1;i < iPos-1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeST
{
    T data;
    struct nodeST *next;
};

template<class T>
class Stack
{
    private:
        struct nodeST<T>* First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);  // InsertFirst()
        int Pop();   // DeleteFirst()
};

template<class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Stack <T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeST<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
int Stack <T>::Count()
{
    return iCount;
}

template<class T>
void Stack <T>::Push(T No)
{
    struct nodeST<T>* newn = NULL;

    newn = new nodeST<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
int Stack <T>::Pop()
{
    int Value = 0;
    struct nodeST<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        Value = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return Value;
}



/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeQE
{
    T data;
    struct nodeQE<T>* next;
};

template<class T>
class Queue
{
    private:
        struct nodeQE<T>* First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  // InsertLast()
        int DeQueue();   // DeleteFirst()
};

template<class T>
Queue <T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Queue <T>::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQE<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
int Queue <T>::Count()
{
    return iCount;
}

template<class T>
void Queue <T>::EnQueue(T No)
{
    struct nodeQE<T>* newn = NULL;
    struct nodeQE<T>* temp = NULL;

    newn = new nodeQE<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template<class T>
int Queue <T>::DeQueue()
{
    T Value = 0;
    struct nodeQE<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        Value = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return Value;
}

int main()
{
    
    return 0;
}