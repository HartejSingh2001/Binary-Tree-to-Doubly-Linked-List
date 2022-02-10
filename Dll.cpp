class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void inorder(Node *root,vector<int>&v)
    {
        if(root!=NULL)
        {
            inorder(root->left,v);
            v.push_back(root->data);
            inorder(root->right,v); 
        }
       
    }
    Node * bToDLL(Node *root)
    {
        vector<int>v;
        inorder(root,v);
        Node *head=NULL,*temp;
        vector<int>::iterator it;
        for(it=v.begin();it!=v.end();it++)
        {
            struct Node *newnode=newNode(*it);
           
            if(head==NULL)
            {
                head=newnode;
                temp=newnode;
            }
            else
            {
                temp->right=newnode;
                newnode->left=temp;
                temp=newnode;
            }
        }
        return head;
    }
    
};
