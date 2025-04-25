class MyLinkedList {
public:
    class node
    {
        public:
        int val;
        node *next;
        node(int val)
        {
            this->val = val;
            next = nullptr;
        }
    };
    node *head;
    int size;
    MyLinkedList() 
    {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) 
    {
        if(index <0 || index>=size)
            return -1;
        node *temp = head;
        for(int i=0;i<index;i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) 
    {
        node *temp = new node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    
    void addAtTail(int val) 
    {
        if(size==0)
        {
            head = new node(val);
            size++;
            return;
        }
        node *temp = head;
        while(temp->next)
            temp = temp->next;
        temp ->next = new node(val); 
        size++;       
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index<0 || index>size)
            return;
        if(index == 0)
        {
            addAtHead(val);
            return ;
        }
        node *temp = head;
        for(int i=0;i<index-1;i++)
            temp = temp->next;

        node *rand = new node(val);
        rand->next = temp->next;
        temp->next = rand;
        size++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index<0 || index>=size)
            return;
        if(index == 0)
        {
            head = head ->next;
            size--;
            return;
        }
        node *temp = head;
        for(int i=0;i<index-1;i++)
        {
            temp = temp->next;
        }
        temp ->next =temp->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */