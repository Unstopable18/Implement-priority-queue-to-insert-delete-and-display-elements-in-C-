#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct n 
{
   int p;
   int info;
   struct n *l;
};
class priqueue 
{
    private:
    n *f;
    public:
    priqueue()
        {
            f = NULL;
        }
    void insert(int i, int p) 
    {
        n *t, *q;
        t = new n;
        t->info = i;
        t->p = p;
        if (f == NULL || p < f->p) 
        {
            t->l= f;
            f = t;
        } else 
        {
            q = f;
            while (q->l != NULL && q->l->p <= p)
            q = q->l;
            t->l = q->l;
            q->l = t;
        }
    }
    void remove() 
    {
        n *t;
        if(f == NULL)
        cout<<"Queue Underflow\n";
        else 
        {
            t = f;
            f = f->l;
            free(t);
        }
    }
    void display() 
    {
        n *ptr;
        ptr = f;
        if (f == NULL)
        cout<<"\n\t***Queue is empty***\n";
        else 
        {
            cout<<"\n\t\tP\tI\n";
            while(ptr != NULL) 
            {
                cout<<"\t\t"<<ptr->p<<"\t"<<ptr->info<<endl;
                ptr = ptr->l;
            }
        }
    }
};
int main() 
{
    int ch, i, p;
    priqueue pq;
    cout<<"\n*******************************************\n";
    cout<<"1. Insert\n2. Delete\n3. Exit";
    cout<<"\n*******************************************\n";
    do
   {
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<"*******************************************\n";
        switch(ch) 
        {
            case 1:
            cout << "  ***Priority Queue Before Insertion***"; 
            pq.display();
            cout<<"\nEnter to insert in Priority Queue : ";
            cin>>i;
            cout<<"\nEnter Priority of the Element in Queue : ";
            cin>>p;
            pq.insert(i, p);
            cout << "\n  ***Priority Queue After Insertion*** "; 
            pq.display();
            break;
            case 2:
            cout << "  ***Priority Queue Before Deletion*** "; 
            pq.display();
            pq.remove();
            cout << "\n  ***Priority Queue After Deletion*** "; 
            pq.display();
            break;
            case 3:cout<<"\t*** Exit ***"<<endl;
            break;
            default: cout<<"Invalid choice"<<endl;
        }
        cout<<"*******************************************\n"; 
    }
    while(ch != 3);
    return 0;
}