#include "list.h"


using namespace std;

void createlist (list *l)
{
    first(*l) = nil;
}

void dealokasi (address p)
{
    free(p);
}

address alokasi (infotype x)
{
    address p;
    p = (address) malloc (sizeof(elmlist));
    info(p) = x;
    next(p) = nil;
    return p;
}

void insertfirst (list *l, address p)
{
    if (first(*l) == nil)
    {
        first(*l) = p;
    }
    else
    {
        next(p) = first(*l);
        first(*l) = p;
    }
}

void insertlast (list *l, address p)
{
    address q;

    if (first(*l) == nil)
    {
        first(*l) = p;
    }
    else
    {
        q = first(*l);
        while (next(q) != nil)
        {
            q = next(q);
        }
        next(q) = p;
    }
}
void insertafter (list *l, address p, address prec)
{
    next(p) = next(prec);
    next(prec) = p;
}

void deletefirst (list *l, address *p)
{
    if (first(*l) == nil)
    {
        cout<<"List Kosong";
    }
    else if (next(first(*l)) == nil)
    {
        *p=first(*l);
        first(*l) = nil;
        dealokasi(*p);
    }
    else
    {
        *p = first(*l);
        first(*l) = next(first(*l));
        next(*p) = nil;
        dealokasi(*p);
    }
}

void deletelast (list *l, address *p)
{
    address q;

    if (first(*l) == nil)
    {
        cout<<"List Kosong";
    }
    else if (next(first(*l)) == nil)
    {
        *p=first(*l);
        first(*l) = nil;
        dealokasi(*p);
    }
    else
    {
        q=first(*l);
        while (next(next(q)) != nil)
        {
            q=next(q);
        }
        *p = next(q);
        next(q) = nil;
        dealokasi(*p);
    }
}
void deleteafter (list *l, address *p, address prec)
{
    *p = next(prec);
    next(prec) = next(*p);
    next(*p) = nil;
    dealokasi(*p);
}

address searchelement(list l, infotype x)
{
    address p;
    int a=0;

    p=first(l);
    while ( p != nil)
    {
        if (strcmp(info(p).id,x.id) == 0)
        {
            a = 1;
            break;
        }
        else
        {
            p = next(p);
        }
    }
    if (a != 1)
    {
        p = nil;
    }
    return p;
}

void viewlist (list l)
{
    address p;

    p = first(l);
    if (p == nil)
    {
        cout<<"List masih kosong";
    }
    else
    {
        while (p != nil)
        {
            cout<<"\nID : "<<info(p).id<<endl;
            cout<<"Nama : "<<info(p).nama<<endl;
            cout<<"Alamat : "<<info(p).alamat<<endl;
            cout<<"Jabatan : "<<info(p).jab<<endl;
            cout<<"Hobi : "<<info(p).hobi<<endl;
            p = next(p);
        }
    }


}

