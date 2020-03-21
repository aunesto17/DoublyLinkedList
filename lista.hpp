//
//  lista.hpp
//  AED_ListaDoblementeEnlazada
//
//  Created by Alexander Arturo Baylon Ibanez on 10/10/15.
//  Copyright © 2015 aunesto17. All rights reserved.
//

#ifndef lista_hpp
#define lista_hpp

#include <stdio.h>
#include <iostream>

using namespace std;



template <class T>
struct CListTrait{
    typedef  T          U;
    typedef  less<T>    C;
    typedef  greater<T> D;
};


template <class T>
class cNode {
public:
    T m_data;
    cNode<T> *  m_next;
    cNode<T> *  m_prev;
    cNode(){};
    cNode(T x)
    {
        m_data = x;
        m_next = m_prev = nullptr;
    }
};
 

template <class Tr>
class doubleList {
    char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',};
    typedef typename Tr::U T;
    typedef typename Tr::C C;
    typedef typename Tr::D D;
    cNode<T> * m_head;
    cNode<T> * m_tail;
public:
    doubleList();
    bool insert(T);
    bool find(T,cNode<T>**&);
    bool remove(T);
    void printList();
    //~doubleList();
};

template<class Tr>
bool doubleList<Tr>::insert(T x)
{
    cNode<T> ** p;
    if (find(x,p)) return 0;
    cNode<T> * t = new cNode<T>(x);
    t->m_next = *p;
    *p = t;
    if (!*p) {
        t->m_prev           = t->m_next->m_prev;
        t->m_next->m_prev   = t;
    }
    else
        return 1;
    return 1;
}


template<class Tr>
bool doubleList<Tr>::find(T x ,cNode<T> **& p)
{
    p = &m_head;
    //if(*p)
    while (*p && x>(*p)->m_data) {
        if (*p && x==(*p)->m_data) return 1;
        p = &(*p)->m_next;
    }
    return 0;
}


template<class Tr>
void doubleList<Tr>::printList()
{
    cNode<T> * temp = m_head;
    int i = 0;
    cout << "-> ";
    while (temp!=nullptr) {
        cout << letras[i++] << "(" << temp->m_data << ")" << " -> ";
        temp = temp->m_next;
    }
    cout << "end" << endl;
}


template<class Tr>
doubleList<Tr>::doubleList()
{
    m_head = nullptr;
    m_tail = nullptr;
}


#endif /* lista_hpp */
