class MyLinkedList {
public:
    int data;
    MyLinkedList *next,*head;
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        next=NULL;
        head=NULL;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        int count=0;
        MyLinkedList *tmp=head;
        while(tmp)
        {
            if(count==index)
            {
                return tmp->data;
            }
            tmp=tmp->next;
            count++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        MyLinkedList *new_node=new MyLinkedList;
        new_node->data=val;
        new_node->next=head;
        head=new_node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        MyLinkedList *new_node=new MyLinkedList;
        new_node->data=val;
        if(!head)
        {
            head=new_node;
        }
        else
        {
            MyLinkedList *tmp=head;
            while(tmp->next)
            {
                tmp=tmp->next;
            }
            tmp->next=new_node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        int len=0,count=0;
        MyLinkedList *tmp=head;
        while(tmp)
        {
            tmp=tmp->next;
            len++;
        }
        if(index>len)
        {
            return;
        }
        /*if(index==len-1)
        {
            addAtTail(val);
            return;
        }*/
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        tmp=head;
        while(tmp && count<index-1)
        {
            tmp=tmp->next;
            count++;
        }
        MyLinkedList *new_node=new MyLinkedList;
        new_node->data=val;
        MyLinkedList *end=tmp->next;
        tmp->next=new_node;
        new_node->next=end;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        int len=0,count=0;
        MyLinkedList *tmp=head;
        while(tmp)
        {
            len++;
            tmp=tmp->next;
        }
        if(index>=len)
        {
            return;
        }
        if(index==0)
        {
            if(head)
            {
                head=head->next;
            }
            return;
        }
        tmp=head;
        while(tmp && count<index-1)
        {
            tmp=tmp->next;
            count++;
        }
        tmp->next=tmp->next->next;
    }
};