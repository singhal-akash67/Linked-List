#include<tgmath.h>
#ifndef linked_list
#define linked_list
class node
{
    int data;
    node *next;
public:
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
    friend node* makinglinkedlist();
    friend node* addatbeginning(node*);
    friend node* addatbeginning(node*,int);
    friend node* addatlast(node*);
    friend node* addatlast(node*,int);
    friend node* addatithposition(node*,int);
    friend node* addatithposition(node*,int,int);
    friend node* deleteatbeginning(node*);
    friend node* deleteatend(node*);
    friend node* deleteatithposition(node*,int);
    friend void  printinglinkedlist(node*);
    friend node* reversalrecursively(node*);
    friend node* reversaliteratively(node*);
    friend node* sorting(node*);
    friend node* eliminatingdupliacatesfromsortedlinkedlist(node*);
    friend node* mergetwosortedlinkedlist(node*,node*);
    friend void midpoint(node*);
    friend bool ispalindrome(node* head);
    friend node* appendlastNelementsinfront(node*,int);
};
node * makinglinkedlist()
{
    cout<<"how many nodes you want to make"<<endl;
    int n;
    cin>>n;
    node* head=NULL;
    node* prev=NULL;
    for(int i=0;i<n;i++)
    {
        int data;
        cout<<"enter the data for node "<<i<<endl;
        cin>>data;
        node *newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            prev=newnode;
        }
        else
        {
            prev->next=newnode;
            prev=newnode;
        }
    }
    return head;
}
node* addatbeginning(node *head)
{
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    node* newnode=new node(data);
    newnode->next=head;
    head=newnode;
    return head;
}
node *addatbeginning(node *head,int data)
{
    node *newnode=new node(data);
    newnode->next=head;
    head=newnode;
    return head;
}
node *addatlast(node *head)
{

    node *temp=head;
    if(temp!=NULL)
    {
        cout<<"enter data"<<endl;
    int data;
    cin>>data;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *newnode=new node(data);
    temp->next=newnode;
    return head;
    }
    else
    {
        cout<<"linked list does not exist"<<endl;
        return head;
    }
}
node *addatlast(node *head,int data)
{
   node *temp=head;
    if(temp!=NULL)
    {
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *newnode=new node(data);
    temp->next=newnode;
    return head;
    }
    else
    {
        cout<<"linked list does not exist"<<endl;
        return head;
    }

}
node *addatithposition(node *head,int pos)
{
    if(pos==1)
    {
        head=addatbeginning(head);
    }
    else
    {
        int i=1;
        node *temp=head;
        while(i<pos-1&&temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp==NULL)
        {
            cout<<"linked list is not that long"<<endl;
        }
        else
        {
            int data;
            cout<<"enter data"<<endl;
            cin>>data;
            node* newnode=new node(data);
            newnode->next=temp->next;
            temp->next=newnode;

        }
    }
    return head;
}
node* addatithposition(node *head,int pos,int data)
{
    if(pos==1)
    {
        head=addatbeginning(head);
    }
    else
    {
        int i=1;
        node *temp=head;
        while(i<pos-1&&temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp==NULL)
        {
            cout<<"linked list is not that long"<<endl;
        }
        else
        {
            node* newnode=new node(data);
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}
node *deleteatbeginning(node *head)
{
    if(head!=NULL)
    {
    node *temp=head;
    head=head->next;
    delete temp;
    return head;
    }
    else
    {
        cout<<"sorry your head points to NULL"<<endl;
        return NULL;
    }

}
node *deleteatend(node *head)
{
    node *temp=head;
    while(temp!=NULL&&temp->next!=NULL&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout<<"your head points to NULL, sorry"<<endl;
        return head;
    }
    else if(temp->next==NULL)
    {
        delete temp;
        cout<<"now your linked list does not have anything"<<endl;
        return NULL;
    }
    else
    {
        delete temp->next;
        temp->next=NULL;
        return head;
    }
}
node *deleteatithposition(node *head,int pos)
{
    if(pos==1)
    {
        return deleteatbeginning(head);
    }
    else
    {
        node *temp=head;
        int i=1;
        while(i<pos-1&&temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp==NULL||(temp->next==NULL&&pos-1==i))
        {
            cout<<"you are trying to delete at wrong position"<<endl;
            return head;
        }
        else
        {
            node *k=temp->next;
            temp->next=temp->next->next;
            delete k;
            return head;
        }
    }
}
void printinglinkedlist(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}
node *reversalrecursively(node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node *k=reversalrecursively(head->next);
    head->next->next=head;
    head->next=NULL;
    return k;
}
node *reversaliteratively(node *head)
{
    node *prev=NULL;
    node *temp=head;
    while(temp!=NULL)
    {


        node *k=temp->next;
        temp->next=prev;
        prev=temp;
        temp=k;
        if(temp!=NULL)
        {
            head=temp;
        }
    }
    return head;
}
node *sorting(node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node *temp=sorting(head->next);
    head->next=NULL;
    if(head->data<=temp->data)
    {
        head->next=temp;
        return head;
    }
    else
    {
        node *p=temp;

        while(p->next!=NULL&&head->data>p->next->data)
        {
            p=p->next;
        }

        if(p->next!=NULL)
        {
            head->next=p->next;
            p->next=head;
            return temp;
        }
        else
        {
            p->next=head;
            return temp;
        }
    }
}
node* eliminatingdupliacatesfromsortedlinkedlist(node *head)
{
    node *temp=sorting(head);
    head=temp;
    while(temp!=NULL)
    {
        if(temp->next!=NULL&&temp->data==temp->next->data)
        {
            node *k=temp->next;
            temp->next=temp->next->next;
            delete k;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}
node* mergetwosortedlinkedlist(node* first,node *second)
{
    node* head;
    node *prev=NULL;
    while(first!=NULL||second!=NULL)
    {
        if(first!=NULL&&second!=NULL)
        {
            if(first->data<second->data)
            {
                node *newnode=new node(first->data);
                node *k=first;
                first=first->next;
                delete k;
                if(prev==NULL)
                {
                    head=newnode;
                    prev=newnode;
                }
                else
                {
                    prev->next=newnode;
                    prev=newnode;
                }
            }
            else
            {
                 node *newnode=new node(second->data);
                node *k=second;
                second=second->next;
                delete k;
                if(prev==NULL)
                {
                    head=newnode;
                    prev=newnode;
                }
                else
                {
                    prev->next=newnode;
                    prev=newnode;
                }
            }
        }
        else
        {
            if(first==NULL)
            {
                node* newnode=new node(second->data);
                node *k=second;
                second=second->next;
                delete k;
                prev->next=newnode;
                prev=newnode;
            }
            else
            {
                node* newnode=new node(first->data);
                node *k=first;
                first=first->next;
                delete k;
                prev->next=newnode;
                prev=newnode;
            }
        }
    }
    return head;
}
void midpoint(node* head)
{
    if(head==NULL)
    {
        return;
    }
    node* mid=head;
    node* last=head->next;
    while(last!=NULL)
    {

        last=last->next;
        if(last!=NULL)
        {
            mid=mid->next;
            last=last->next;
        }
    }
    cout<<mid->data<<endl;

}
bool ispalindrome(node *head)
{
    if(head==NULL)
    {
        return false;
    }
    int i=0;
    node* temp=head;
    while(temp->next!=NULL)
    {
        i++;
        temp=temp->next;
    }
    i=ceil((i+1)/2);
    node* start=head;
    node* end=temp;
    while(i!=0)
    {
        temp=start;
        while(temp->next!=end)
        {
            temp=temp->next;
        }
        if(temp->next->data!=start->data)
        {
            return false;
        }
        end=temp;
        start=start->next;
        i--;
    }
    return true;


}
node* appendlastNelementsinfront(node* head,int n)
{
    if(head==NULL)
    {

        return head;
    }

    node* temp=head;
    int i=0;
    while(temp->next!=NULL)
    {
        i++;
        temp=temp->next;
    }
    i++;
    node* k=temp;
    temp=head;

    while(i-n>1)
    {
        temp=temp->next;
        n++;
    }
        k->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;


}

#endif // linked_list
