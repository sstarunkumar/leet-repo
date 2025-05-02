class MyLinkedList {
public:
    class node 
    {
        public:
        int val;
        node *left,*right;
        node(int val)
        {
            this->val = val;
            left = right =nullptr;
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
        node *temp = head;
        if(index >= size)   
            return -1;
        while(index--)
            temp = temp ->right;
        return temp->val;
    }
    
    void addAtHead(int val) 
    {
        if(!head)
        {
            head = new node(val);
            size++;
            return ;
        }
        node *temp = new node(val);
        temp->right = head;
        head->left = temp;
        head = temp;
        size++;
    }
    
    void addAtTail(int val) 
    {
        if(size == 0)
        {
            head = new node(val);
            size++;
            return;
        }
        node *temp = head;
        while(temp->right)
            temp = temp->right;
        temp->right = new node(val);
        temp->right->left = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index > size)
            return ;
        if(index == size)
        {
            addAtTail(val);
            return ;
        }
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        size++;
        node *temp = head;
        while(--index)
        {
            temp = temp->right;
        }
        node *bot = new node(val);
        bot->left = temp;
        bot->right = temp->right;
        bot->right->left = bot;
        temp->right =bot;
    }
    void deleteAthead()
    {
        if(!head)
            return;
        if(!head->right)
        {
            head = nullptr;
            size--;
            return;
        }
        size--;
        head = head->right;
        head->left = nullptr;
    }
    void deleteAtIndex(int index) 
    {
        if(index >= size)
            return ;
        if(index == 0)
        {
            deleteAthead();
            return;
        }
        node *temp = head;
        size--;
        while(index --)
        {
            temp = temp->right;
        }
        if(!temp->right)
        {
            temp->left->right = nullptr;
            return;
        }
        temp->left->right = temp->right;
        temp->right->left = temp->left;
        delete temp;
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