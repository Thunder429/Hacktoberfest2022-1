#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* pre;
    Node(int d)
    {
        this->data=d;
        this->pre=NULL;
    }
};

class Stack{
public:
    Node* top;
    Stack()
    {
        this->top=NULL;
    }
    void push(int d)
    {
        Node* temp=new Node(d);
        temp->pre=top;
        top=temp;
    }
    void pop()
    {
        if(top!=NULL)
        {
            Node* temp=top;
            top=top->pre;
            delete(temp);
        }
    }
    int Top()
    {
        if(this->top!=NULL)
        return this->top->data;
        else
            return -1;
    }

    bool Empty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }
    void disp(Stack s)
    {
        while(!s.Empty())
        {
            cout<<s.Top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    void push_bottom(Stack& S,int ele)
    {
       if(S.Empty())
       {
            S.push(ele);
            return;
       }

       int temp=S.Top();
       S.pop();
       push_bottom(S,ele);
       S.push(temp);
    }
    void Reverse(Stack& S)
    {
        if(S.Empty())
            return;

        int temp=S.Top();
        S.pop();
        Reverse(S);
        push_bottom(S,temp);
    }
};


int main()
{
    Stack current;
    int i;
    for(i=0;i<5;i++)
        current.push(i);
    current.disp(current);
    current.Reverse(current);
    current.disp(current);
}
