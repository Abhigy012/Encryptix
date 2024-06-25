#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void choices()
{
    cout << "***** TO-DO LIST *****\n\n";
    cout << "1. Display the list \n";
    cout << "2. Add task \n";
    cout << "3. Remove a task \n";
    cout << "4. Mark a task as complete\n";
    cout << "5. Exit and delete the list \n";
}
struct node
{
    string data;
    int status;
    struct node *next;
};
class todolist
{
private:
    node *head = NULL;
    node *last = head;
public:
    void display()
    {
        int i = 1;
        node *p = head;
        if (p == NULL)
        {
            cout << "The list is empty\n";
        }
        else
        {
            while (p)
            {
                cout << i++ << ". " << p->data << " | Status : " << (p->status ? "Completed" : "Incomplete") << endl;
                p = p->next;
            }
        }
    }
    void addtask(string x)
    {
        node *t = new node;
        t->data = x;
        t->status = 0;
        t->next = NULL;
        if (head == NULL)
        {
            head = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
        cout << "Task added successfully \n";
    }
    void taskcomplete()
    {
        display();
        node *p = head;
        if (p)
        {
            int pos;
            cout << "Enter the task number to mark as complete: ";
            cin >> pos;
            for (int i = 0; i < pos - 1; i++)
            {
                p = p->next;
            }
            p->status = 1;
            cout << "Task marked as completed successfully \n";
        }
    }
    void removetask()
    {
        node *p = NULL;
        node *q = head;
        display();
        if (q)
        {
            int pos;
            cout << "Enter the task number to be removed: ";
            cin >> pos;
            if (pos > 0 && pos <= count())
            {
                if (pos == 1)
                {
                    head = head->next;
                    free(q);
                }
                else
                {
                    for (int i = 0; i < pos - 1; i++)
                    {
                        p = q;
                        q = q->next;
                    }
                    p->next = q->next;
                    free(q);
                }
                cout << "Task removed successfully \n";
            }
            else
            {
                cout << "Invalid Position Given\n";
            }
        }
    }
    int count()
    {
        node *p = head;
        int i = 0;
        while (p)
        {
            i++;
            p = p->next;
        }
        return i;
    }
};
int main()
{
    todolist *newlist = new todolist;
    int choice;
    string x;
    while (true)
    {
        choices();
        cout << "Enter your choice : ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 5)
            break;

        switch (choice)
        {
        case 1:
            newlist->display();
            break;
        case 2:
            cout << "Enter task to be added: ";
            getline(cin, x);
            newlist->addtask(x);
            break;
        case 3:
            newlist->removetask();
            break;
        case 4:
            newlist->taskcomplete();
            break;
        default:
            cout << "Invalid Choice, Try Again \n";
        }
    }
    cout << "Hoping to see you again, Goodbye!\n";
    delete newlist;
    return 0;
}