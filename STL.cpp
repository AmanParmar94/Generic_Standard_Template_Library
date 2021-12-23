#include<iostream>
using namespace std;

template <typename T>
struct node1
{
    T data;
    struct node1 *next;
};

template <typename T>
struct node2
{
    T data;
    struct node2 *next;
    struct node2 *prev;
};

template <typename T>
struct node3
{
    T data;
    struct node3 *lchild;
    struct node3 *rchild;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////Singly Linear Linked List Start///////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
private:
    node1 <T>* first;
    int size;

public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    first = NULL;
    size = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Description :           It is used to insert the node in Singly Linear Linked List at first position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: InsertFirst(T no)
{
    node1 <T>* newn = new node1<T>;
    newn->data = no;
    newn->next = NULL;

    if(size == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Description :           It is used to insert the node in Singly Linear Linked List at last position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: InsertLast(T no)
{
    node1 <T>* newn = new node1<T>;
    newn->data = no;
    newn->next = NULL;

    if(size == 0)
    {
        first = newn;
    }
    else
    {
        node1 <T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    size++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Description :           It is used to insert the node in Singly Linear Linked List at given position.
//  Input Arguments :       Integer, Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: InsertAtPos(T no, int pos)
{
    node1 <T>* newn = new node1<T>;
    newn->data = no;
    newn->next = NULL;
    
    if((pos<1)||(pos>size+1))
    {
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        node1 <T>* temp = first;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    size++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Description :           It is used to delete the node in Singly Linear Linked List at first position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: DeleteFirst()
{
    if(size == 0)
    {
        return;
    }
    else if(size == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        node1 <T>* temp = first;
        first = temp->next;
        delete temp;
    }
    size--;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Description :           It is used to delete the node in Singly Linear Linked List at last position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL <T> :: DeleteLast()
{
      if(size == 0)
    {
        return;
    }
    else if(size == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        node1 <T>* temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    size--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Description :           It is used to delete the node in Singly Linear Linked List at given position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: DeleteAtPos(int pos)
{
    if((pos<1)||(pos>size+1))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == size+1)
    {
        DeleteLast();
    }
    else
    {
        node1 <T>* temp = first;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        node1 <T>* targeted = temp->next;
        temp->next = temp->next->next;
        delete targeted;
    }
    size--;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Description :           It is used to display the all nodes of Singly Linear Linked List.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL <T> :: Display()
{
    node1 <T>* temp = first;

    while(temp!= NULL)
       {
           cout<<"|"<<temp->data<<"|->";
           temp = temp->next;
       }
       cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Description :           It is used to count the nodes of Singly Linear Linked List.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL <T> :: Count()
{
    return size;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////Doubly Linear Linked List Start///////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
class DoublyLL
{
private:
    node2 <T>* first;
    int size;

public:
    DoublyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    first = NULL;
    size = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Description :           It is used to insert the node in Doubly Linear Linked List at first position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T> :: InsertFirst(T no)
{
    node2 <T>* newn = new node2<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(size == 0)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
    size++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Description :           It is used to insert the node in Doubly Linear Linked List at last position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T> :: InsertLast(T no)
{
    node2 <T>* newn = new node2<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(size == 0)
    {
        first = newn;
    }
    else
    {
        node2 <T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    size++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Description :           It is used to insert the node in Doubly Linear Linked List at given position.
//  Input Arguments :       Integer, Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T> :: InsertAtPos(T no, int pos)
{
    node2 <T>* newn = new node2<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((pos<1)||(pos>size+1))
    {
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        node2 <T>* temp = first;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    size++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Description :           It is used to delete the node in Doubly Linear Linked List at first position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T> :: DeleteFirst()
{
    if(size == 0)
    {
        return;
    }
    else if(size == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        node2 <T>* temp = first;
        first = temp->next;
        delete temp;
        first->prev = NULL;
    }
    size--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Description :           It is used to delete the node in Doubly Linear Linked List at last position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T> :: DeleteLast()
{
    if(size == 0)
    {
        return;
    }
    else if(size == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        node2 <T>* temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL; 
    }
    size--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Description :           It is used to delete the node in Doubly Linear Linked List at given position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T> :: DeleteAtPos(int pos)
{
    if((pos<1)||(pos>size+1))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == size+1)
    {
        DeleteLast();
    }
    else
    {
        node2 <T>* temp = first;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        node2 <T> * targated = temp->next;
        temp->next = targated->next;
        temp->next->prev = temp;
        delete targated;
    }
    size--;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Description :           It is used to display the all nodes of Doubly Linear Linked List.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL <T> :: Display()
{
    node2 <T>* temp = first;

    while(temp!= NULL)
       {
           cout<<"|"<<temp->data<<"|->";
           temp = temp->next;
       }
       cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Description :           It is used to count the nodes of doubly Linear Linked List.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL <T> :: Count()
{
    return size;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////Singly Circular Linked List Start/////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
private:
    node1 <T>* first;
    node1 <T>* last;
    int size;
    
public:
    SinglyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

    template <class T>
    SinglyCL<T>::SinglyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Description :           It is used to display the all nodes of Singly Circular Linked List.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void SinglyCL<T>::Display()
    {
        node1 <T> * temp  = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        
        do
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }while(temp != last->next);
        
        cout<<"\n";
    }

/////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Description :           It is used to count the nodes of Singly Circular Linked List.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int SinglyCL<T>::Count()
    {
        return size;
    }
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Description :           It is used to insert the node in Singly Circular Linked List at first position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void SinglyCL<T>::InsertFirst(T no)
    {
        node1 <T> * newn = new node1<T>;
        
        newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        
        last->next = first;
        size++;
    }
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Description :           It is used to insert the node in Singly Circular Linked List at last position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void SinglyCL<T>::InsertLast(T no)
   {
        node1 <T> * newn = new node1<T>;
        
        newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }
        
        last->next = first;
        size++;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Description :           It is used to insert the node in Singly Circular Linked List at given position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void SinglyCL<T>::InsertAtPos(T no, int ipos)
    {
        if((ipos < 1) || (ipos > (size+1)))
        {
            return;
        }
        
        if(ipos ==1)
        {
            InsertFirst(no);
        }
        else if(ipos == size+1)
        {
            InsertLast(no);
        }
        else
        {
            node1 <T> * newn = new node1<T>;
            
            newn->data = no;
            newn->next = NULL;
            
            node1 <T>* temp = first;
            
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
            newn->next = temp->next;
            temp->next = newn;
            
            size++;
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Description :           It is used to delete the node in Singly Circular Linked List at first position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void SinglyCL<T>::DeleteFirst()
    {
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
        }
        size--;
    }

 
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Description :           It is used to delete the node in Singly Circular Linked List at last position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////


    template <class T>
    void SinglyCL<T>::DeleteLast()
    {
        node1 <T>* temp = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            while(temp->next != last)
            {
                temp = temp -> next;
            }
            
            delete last;
            last = temp;
                
            last->next = first;
        }
        size--;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Description :           It is used to delete the node in Singly Circular Linked List at given position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////// 

    template <class T>
    void SinglyCL<T>::DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos > size))
        {
            return;
        }
        
        if(ipos ==1)
        {
            DeleteFirst();
        }
        else if(ipos == size)
        {
            DeleteLast();
        }
        else
        {
            node1 <T> * temp = first;
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
            node1 <T> * targated = temp->next;
            
            temp->next = targated->next;    
            delete targated;
            
            size--;
        }
        
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////Doubly Circular Linked List Start/////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



template <class T>
class DoublyCL
{
private:
    node2 <T>* first;
    node2 <T>* last;
    int size;
    
public:
    DoublyCL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL<T>::DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Description :           It is used to insert the node in Doubly Circular Linked List at first position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    node2 <T> * newn = new node2<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Description :           It is used to insert the node in Doubly Circular Linked List at last position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    node2 <T> * newn = new node2<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Description :           It is used to display the all nodes of Doubly Circular Linked List.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: Display()
{
    node2 <T> * temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Description :           It is used to count the nodes of Doubly Circular Linked List.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
/////////////////////////////////////////////////////////////////////////////////////////


template <class T>
int DoublyCL<T> :: Count()
{
    return size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Description :           It is used to delete the node in Doubly Circular Linked List at first position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Description :           It is used to delete the node in Doubly Circular Linked List at last position.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Description :           It is used to insert the node in Doubly Circular Linked List at given position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        node2 <T> * newn = new node2<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        node2 <T>* temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Description :           It is used to delete the node in Doubly Circular Linked List at given position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        node2 <T> * temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////Stack Start////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
private:
    node1 <T>* first;
    int size;
    
public:
    Stack();
    void push(T);
    int pop();
    void Display();
    int Count();
};

    template <class T>
    Stack<T>::Stack()
    {
        first = NULL;
        size = 0;
    }

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         push
//  Description :           It is used to insert the node in Stack at first position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void Stack<T> :: push(T no)
    {
        node1 <T> * newn = new node1<T>;
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         pop
//  Description :           It is used to delete the node in Stack at first position.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int Stack<T> :: pop()
    {
        T no = 0;
        node1 <T>* temp = first;
        
        if(size == 0)
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        
        if(size == 1)
        {
            no = first->data;
            delete first;
            first = NULL;
        }
        else
        {
            no = first->data;
            first = first -> next;
            delete temp;
        }
        
        size--;
        return no;
    }

//////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Description :           It is used to display the all nodes of Stack.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////

    template <class T>
    void Stack<T> :: Display()
    {
        node1 <T>* temp = first;
        
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp = temp->next;
        }
    }

//////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Description :           It is used to count the all nodes of Stack.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////

    template <class T>
    int Stack<T> :: Count()
    {
        return size;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////Queue Start////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue     
{
private:
    node1 <T>* first;
    int size;
    
public:
    Queue();
    void Enqueue(T);
    int Dequeue();
    void Display();
    int Count();
};
    
    template <class T>
    Queue<T> :: Queue()
    {
        first = NULL;
        size = 0;
    }

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Enqueue
//  Description :           It is used to insert the node in Queue at last position.
//  Input Arguments :       Integer
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void Queue<T> :: Enqueue(T no)   
    {
        node1 <T> * newn = new node1<T>;
        newn->data = no;
        newn -> next = NULL;
        
        if(size == 0)   
        {
            first = newn;
        }
        else
        {
            node1<T>* temp = first;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = newn;
        }
        size++;
    }

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Dequeue
//  Description :           It is used to delete the node in Queue at first position.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int Queue<T> :: Dequeue()   
    {
        T no = 0;
               node1 <T>* temp = first;
               
               if(size == 0)
               {
                   cout<<"Queue is empty\n";
                   return -1;
               }
               
               if(size == 1)
               {
                   no = first->data;
                   delete first;
                   first = NULL;
               }
               else
               {
                   no = first->data;
                   first = first -> next;
                   delete temp;
               }
               
               size--;
               return no;
    }

//////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Description :           It is used to display the all nodes of Queue.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////

    template <class T>
    void Queue<T> :: Display()
    {
        node1<T>* temp = first;

        for(int i = 1 ; i <= size; i++, temp = temp->next)
        {
            cout<<"|"<<temp->data<<"|-> ";
        }
        cout<<"\n";
    }

//////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Description :           It is used to count the all nodes of Queue.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
//////////////////////////////////////////////////////////////////////////

    template <class T>
    int Queue<T> :: Count()
    {
        return size;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////Binary Search Tree Start/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class BST
{
private:
    node3 <T>* first;
    int size;
    
public:
    BST();
    void Insert(T);
    bool Search(T);
    int Count();
};

template <class T>
BST<T> :: BST()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Insert
//  Description :           It is used to insert the node in Tree.
//  Input Arguments :       
//  Output :                
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST <T> :: Insert(T no)
{
    node3 <T>* temp = first;
    node3 <T>* newn = new node3<T>;
    
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;
    
    if(first == NULL)
    {
        first = newn;
        size++;
    }
    else
    {
            while(1)    
            {
                if(temp->data == no)
                {
                    cout<<"Duplicate node\n";
                    
                    delete newn;
                    break;
                }
                else if(no < (temp->data))    
                {
                    if(temp -> lchild == NULL)
                    {
                        temp->lchild = newn;
                        size++;
                        break;
                    }
                    temp = temp -> lchild;
                }
                else if(no > (temp->data))    
                {
                    if(temp -> rchild == NULL)
                    {
                        temp->rchild = newn;
                        size++;
                        break;
                    }
                    temp = temp->rchild;
                }
            }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Search
//  Description :           It is used to search the node in Tree.
//  Input Arguments :       Integer
//  Output :                bool
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool BST <T> :: Search(T no)
{
    if(first == NULL)    
    {
        return false;
    }
    else    
    {
        node3 <T>* temp = first;
        while(temp != NULL)
        {
            if(temp -> data == no)  
            {
                break;
            }
            else if(no > (temp -> data))
            {
                temp = temp->rchild;
            }
            else if(no < (temp -> data))
            {
                temp = temp -> lchild;
            }
        }
        if(temp == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Description :           It is used to count the nodes in Tree.
//  Input Arguments :       
//  Output :                Integer
//  Author :                Aman Liladhar Parmar
//  Date :                  20/11/2021
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST <T> :: Count()
{
    return size;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////Main Function Start////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////For INTEGER as a Input/////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
    cout<<"/////////////////////////////////Below Output is, When Integer as a Input////////////////////////////////////////////////////\n";
    cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
    cout<<"\n";
    
    SinglyLL <int>slobj;
    DoublyLL <int>dlobj;
    SinglyCL <int>scobj;
    DoublyCL <int>dcobj;
    Stack <int>sobj;
    Queue <int>qobj;
    BST <int>bobj;

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Singly Linear....\n";
    cout<<"------------------------------------------\n";

    slobj.InsertFirst(40);
    slobj.InsertFirst(30);
    slobj.InsertFirst(20);
    slobj.InsertFirst(10);

    slobj.Display();
    int iret = slobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slobj.InsertLast(45);

    slobj.Display();
    iret = slobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slobj.DeleteFirst();

    slobj.Display();
    iret = slobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slobj.DeleteLast();

    slobj.Display();
    iret = slobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slobj.InsertAtPos(15,2);

    slobj.Display();
    iret = slobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slobj.DeleteAtPos(2);

    slobj.Display();
    iret = slobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Doubly Linear....\n";
    cout<<"------------------------------------------\n";
    
    dlobj.InsertFirst(40);
    dlobj.InsertFirst(30);
    dlobj.InsertFirst(20);
    dlobj.InsertFirst(10);

    dlobj.Display();
    iret = dlobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlobj.InsertLast(45);

    dlobj.Display();
    iret = dlobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlobj.DeleteFirst();

    dlobj.Display();
    iret = dlobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlobj.DeleteLast();

    dlobj.Display();
    iret = dlobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlobj.InsertAtPos(15,2);

    dlobj.Display();
    iret = dlobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlobj.DeleteAtPos(2);

    dlobj.Display();
    iret = dlobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Singly Circular....\n";
    cout<<"------------------------------------------\n";
    
    scobj.InsertFirst(40);
    scobj.InsertFirst(30);
    scobj.InsertFirst(20);
    scobj.InsertFirst(10);

    scobj.Display();
    iret = scobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    scobj.InsertLast(45);

    scobj.Display();
    iret = scobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    scobj.DeleteFirst();

    scobj.Display();
    iret = scobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    scobj.DeleteLast();

    scobj.Display();
    iret = scobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    scobj.InsertAtPos(15,2);

    scobj.Display();
    iret = scobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    scobj.DeleteAtPos(2);

    scobj.Display();
    iret = scobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Doubly Circular....\n";
    cout<<"------------------------------------------\n";
    dcobj.InsertFirst(40);
    dcobj.InsertFirst(30);
    dcobj.InsertFirst(20);
    dcobj.InsertFirst(10);

    dcobj.Display();
    iret = dcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dcobj.InsertLast(45);

    dcobj.Display();
    iret = dcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dcobj.DeleteFirst();

    dcobj.Display();
    iret = dcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dcobj.DeleteLast();

    dcobj.Display();
    iret = dcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dcobj.InsertAtPos(15,2);

    dcobj.Display();
    iret = dcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dcobj.DeleteAtPos(2);

    dcobj.Display();
    iret = dcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below is Stack....\n";
    cout<<"------------------------------------------\n";
    sobj.push(40);
    sobj.push(30);
    sobj.push(20);
    sobj.push(10);

    cout<<"Elements of stack\n";
    sobj.Display();
    
    iret = sobj.pop();       
    cout<<"Poped element is : "<<iret<<"\n";                   
    
    cout<<"Elements of stack\n";
    sobj.Display();          
    iret = sobj.Count();
    
    cout<<"Size of stack is : "<<iret<<"\n"; 
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below is Queue....\n";
    cout<<"------------------------------------------\n";
    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);
    
    cout<<"Elements of Queue :\n";
    
    qobj.Display();
    iret = qobj.Dequeue();      
    cout<<"Removed element from queue is : "<<iret<<"\n";                    
    
    cout<<"Elements from queue : \n";
    qobj.Display();          
    iret = qobj.Count();     
    
    cout<<"Size of queue is : "<<iret<<"\n";
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below is Binary Search Tree....\n";
    cout<<"------------------------------------------\n";

    int value = 0;
    bool bret = false;
    
    bobj.Insert(51);
    bobj.Insert(21);
    bobj.Insert(101);
   
    cout<<"Enter number to search\n";
    cin>>value;
    
    bret = bobj.Search(value);
    if(bret == true)
    {
        cout<<"Data is there\n";
    }
    else
    {
        cout<<"Data is not there\n";
    }
    
    iret = bobj.Count();
    cout<<"Number of nodes are "<<iret<<"\n";
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////For CHARACTER as a Input//////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
    cout<<"/////////////////////////////////Below Output is, When Character as a Input//////////////////////////////////////////////////\n";
    cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
    cout<<"\n";
    SinglyLL <char>slcobj;
    DoublyLL <char>dlcobj;
    SinglyCL <char>sccobj;
    DoublyCL <char>dccobj;
    Stack <char>sscobj;
    Queue <char>qcobj;
    BST <char>bcobj;

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Singly Linear....\n";
    cout<<"------------------------------------------\n";

    slcobj.InsertFirst('D');
    slcobj.InsertFirst('C');
    slcobj.InsertFirst('B');
    slcobj.InsertFirst('A');

    slcobj.Display();
    iret = slcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slcobj.InsertLast('E');

    slcobj.Display();
    iret = slcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slcobj.DeleteFirst();

    slcobj.Display();
    iret = slcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slcobj.DeleteLast();

    slcobj.Display();
    iret = slcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slcobj.InsertAtPos('Z',2);

    slcobj.Display();
    iret = slcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    slcobj.DeleteAtPos(2);

    slcobj.Display();
    iret = slcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Doubly Linear....\n";
    cout<<"------------------------------------------\n";
    
    dlcobj.InsertFirst('D');
    dlcobj.InsertFirst('C');
    dlcobj.InsertFirst('B');
    dlcobj.InsertFirst('A');

    dlcobj.Display();
    iret = dlcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlcobj.InsertLast('E');

    dlcobj.Display();
    iret = dlcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlcobj.DeleteFirst();

    dlcobj.Display();
    iret = dlcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlcobj.DeleteLast();

    dlcobj.Display();
    iret = dlcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlcobj.InsertAtPos('Z',2);

    dlcobj.Display();
    iret = dlcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dlcobj.DeleteAtPos(2);

    dlcobj.Display();
    iret = dlcobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Singly Circular....\n";
    cout<<"------------------------------------------\n";
    
    sccobj.InsertFirst('D');
    sccobj.InsertFirst('C');
    sccobj.InsertFirst('B');
    sccobj.InsertFirst('A');

    sccobj.Display();
    iret = sccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    sccobj.InsertLast('E');

    sccobj.Display();
    iret = sccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    sccobj.DeleteFirst();

    sccobj.Display();
    iret = sccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    sccobj.DeleteLast();

    sccobj.Display();
    iret = sccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    sccobj.InsertAtPos('Z',2);

    sccobj.Display();
    iret = sccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    sccobj.DeleteAtPos(2);

    sccobj.Display();
    iret = sccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below Linked List is of Doubly Circular....\n";
    cout<<"------------------------------------------\n";
    dccobj.InsertFirst('D');
    dccobj.InsertFirst('C');
    dccobj.InsertFirst('B');
    dccobj.InsertFirst('A');

    dccobj.Display();
    iret = dccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dccobj.InsertLast('E');

    dccobj.Display();
    iret = dccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dccobj.DeleteFirst();

    dccobj.Display();
    iret = dccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dccobj.DeleteLast();

    dccobj.Display();
    iret = dccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dccobj.InsertAtPos('Z',2);

    dccobj.Display();
    iret = dccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";

    dccobj.DeleteAtPos(2);

    dccobj.Display();
    iret = dccobj.Count();
    cout<<"Elements of linked list are:"<<iret<<"\n";
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below is Stack....\n";
    cout<<"------------------------------------------\n";
    sscobj.push('D');
    sscobj.push('C');
    sscobj.push('B');
    sscobj.push('A');

    cout<<"Elements of stack\n";
    sscobj.Display();
    
    char cret = sscobj.pop();       
    cout<<"Poped element is : "<<cret<<"\n";                   
    
    cout<<"Elements of stack\n";
    sscobj.Display();          
    iret = sscobj.Count();
    
    cout<<"Size of stack is : "<<iret<<"\n"; 
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below is Queue....\n";
    cout<<"------------------------------------------\n";
    qcobj.Enqueue('D');
    qcobj.Enqueue('C');
    qcobj.Enqueue('B');
    qcobj.Enqueue('A');
    
    cout<<"Elements of Queue :\n";
    
    qcobj.Display();
    cret = qcobj.Dequeue();      
    cout<<"Removed element from queue is : "<<cret<<"\n";                    
    
    cout<<"Elements from queue : \n";
    qcobj.Display();          
    iret = qcobj.Count();     
    
    cout<<"Size of queue is : "<<iret<<"\n";
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"------------------------------------------\n";
    cout<<"Below is Binary Search Tree....\n";
    cout<<"------------------------------------------\n";

    char cvalue = '\0';
    bret = false;
    
    bcobj.Insert('A');
    bcobj.Insert('B');
    bcobj.Insert('C');
   
    cout<<"Enter alphabet to search\n";
    cin>>cvalue;
    
    bret = bcobj.Search(cvalue);
    if(bret == true)
    {
        cout<<"Data is there\n";
    }
    else
    {
        cout<<"Data is not there\n";
    }
    
    iret = bcobj.Count();
    cout<<"Number of nodes are "<<iret<<"\n";

    return 0;
}







