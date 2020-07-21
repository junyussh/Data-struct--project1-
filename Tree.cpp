#include"Tree.h"

Bitree::Bitree()
{
  head= nullptr;
}

void Bitree::Preorder_traversal()
{
    if(!Preorder.empty())
    {
        for(int i=0;i<Preorder.size();++i)
        {
            cout<<Preorder.at(i)->key<<" ";
            cout<<endl;
        }
    }

    Node* cur=head;
    if(cur!=nullptr)
    {
        preorder_traversal(cur);
    }
}
void Bitree::preorder_traversal(Node * node)
{
    if(node!=nullptr)
    {
        cout << node->key<<"("<<node->color<<")"<<" ";
        Preorder.push_back(node);
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

void Bitree::Inorder_traversal()
{
    if(!Inorder.empty())
    {
        for(int i=0;i<Inorder.size();++i)
        {
            cout<<Inorder.at(i)->key<<" ";
        }
        cout<<endl;
    }

    Node* cur=head;
    if(cur!=nullptr)
    {
        inorder_traversal(cur);
        cout<<endl;
    }
}

void Bitree::inorder_traversal(Node * node)
{
    if(node!=nullptr)
    {
        inorder_traversal(node->left);
        cout << node->key<<"("<<node->color<<")"<<" ";
        Inorder.push_back(node);
        inorder_traversal(node->right);
    }
}

void Bitree::Postorder_traversal()
{
    if(!Postorder.empty())
    {
        for(int i=0;i<Postorder.size();++i)
        {
            cout<<Postorder.at(i)->key<<"("<<Postorder.at(i)->color<<")"<<" ";
            cout<<endl;
        }
    }

    Node* cur=head;
    if(cur!=nullptr)
    {
        postorder_traversal(cur);
        cout<<endl;
    }
}

void  Bitree::postorder_traversal(Node * node)
{
    if(node!=nullptr)
    {
        inorder_traversal(node->left);
        inorder_traversal(node->right);
        cout << node->key<<"("<<node->color<<")"<<" ";
        Postorder.push_back(node);
    }
}


Node* Bitree::successor(Node * node)
{
    for(int i=0;i<Inorder.size();++i)
    {
        if(Inorder.at(i)==node)
        {
            return Inorder.at(i+1);
        }
    }
    return nullptr;
}

Node* Bitree::predecessor(Node * node)
{
    for(int i=0;i<Inorder.size();++i)
    {
        if(Inorder.at(i)==node)
        {
            return Inorder.at(i-1);
        }
    }
    return nullptr;
}


void Bitree::LevelOrder_traversal()
{
    deque<Node* > q;
    q.push_back(head);

    Node* cur;
    while (!q.empty())
    {
        cur=q.front();
        if(cur->left!= nullptr)
            q.push_back(cur->left);
        if(cur->right!= nullptr)
            q.push_back(cur->right);
        cout << cur->key<<"("<<cur->color<<")"<<" ";
        q.pop_front();
    }
    cout<<endl;
}

Node* Bitree::search(Node* node)
{
    deque<Node* > q;
    q.push_back(head);

    Node* cur;
    while (!q.empty())
    {
        cur=q.front();
        if(cur->key==node->key)
        {
            return cur;
        }
        if(cur->left!= nullptr)
            q.push_back(cur->left);
        if(cur->right!= nullptr)
            q.push_back(cur->right);
        q.pop_front();
    }
   return nullptr;
}

void Bitree::Insert(Node* node)
{
    deque<Node* > q;
    q.push_back(head);

    Node* cur;
    while (!q.empty())
    {
        cur=q.front();
        if(cur->left!= nullptr)
        {
            q.push_back(cur->left);
        }
        else
        {
            cur->left=node;
            node->parent=cur;
        }
        if(cur->right!= nullptr)
        {
            q.push_back(cur->right);
        }
        else
        {
            cur->right=node;
            node->parent=cur;
        }
        q.push_back(cur->right);
    }
}
void Bitree::Delete(Node* node)
{
    node=search(node);
    if(node== nullptr)
    {
        return;
    }
    else
    {
        if(node->right== nullptr&&node->left== nullptr)
        {
            //--case 1 :no child
            (node==node->parent->left)?
                    node->parent->left= nullptr: node->parent->right= nullptr;
            delete node;
            return;
        }
        else if(node->right== nullptr^node->left== nullptr)
        {
            //--case 2 : one child

            if (node->right == nullptr)
            {
                node->left->parent=node->parent;
                (node==node->parent->left)?
                        node->parent->left= node->left: node->parent->right= node->right;
                delete node;
                return;
            }
            else
            {
                node->right->parent=node->parent;
                (node==node->parent->left)?
                        node->parent->left= node->left: node->parent->right= node->right;
                delete node;
                return;
            }
        }
        else
        {
            //case 3 : two child
            Node* sur=successor(node);
            //node->color=sur->color;
            int temp=sur->key;
            Delete(sur);
            node->key=temp;
        }
    }
}

void Bitree::reset_data()
{

    Preorder.clear();
    Inorder.clear();
    Postorder.clear();

    Preorder_traversal();
    Inorder_traversal();
    Postorder_traversal();

}



Bistree::Bistree():Bitree()
{
    
}


Node* Bistree::max()
{
    Node* cur=head;
    if(cur==nullptr)
    {
        return cur;
    }
    while(cur->right!=nullptr)
    {
        cur=cur->right;
    }
    return cur;
}

Node* Bistree::min()
{
    Node* cur=head;
    if(cur==nullptr)
    {
        return cur;
    }
    while(cur->left!=nullptr)
    {
        cur=cur->left;
    }
    return cur;
}

Node* Bistree::search(Node* node)
{
    Node* cur=head;
    while (cur!=nullptr)
    {
        if(cur->key==node->key)
            return cur;
        else if(cur->key>node->key)
            cur=cur->left;
        else
            cur=cur->right;
    }
    return cur;
}
Node* Bistree::search(int node)
{
    Node* cur=head;
    while (cur!=nullptr)
    {
        if(cur->key==node)
            return cur;
        else if(cur->key>node)
            cur=cur->left;
        else
            cur=cur->right;
    }
    return cur;
}

void Bistree::Insert(Node* node)
{
   if(search(node)==node)
   {
       return;
   }
   Node* pre=nullptr,* cur=head;
   if(cur==nullptr)
   {
       head=node;
       return;
   }
   while (cur!=nullptr)
   {
       if(cur->key > node->key)
       {
           pre=cur;
           cur=cur->left;

       }
       else
       {
           pre=cur;
           cur=cur->right;
       }
   }

   node->parent=pre;
   node->right=nullptr;
   node->left=nullptr;
   if(node->parent->key>node->key)
       node->parent->left=node;
   else
       node->parent->right=node;
    //reset_data();
}

void Bistree::Delete(Node * node)
{
    node=search(node);
    if(node== nullptr)
    {
        return;
    }
    else
    {
        if(node->right== nullptr&&node->left== nullptr)
        {
            //--case 1 :no child
            (node==node->parent->left)?
            node->parent->left= nullptr: node->parent->right= nullptr;
            delete node;
            return;
        }
        else if(node->right== nullptr^node->left== nullptr)
        {
            //--case 2 : one child

            if (node->right == nullptr)
            {
                node->left->parent=node->parent;
                (node==node->parent->left)?
                node->parent->left= node->left: node->parent->right= node->left;
                delete node;
                return;
            }
            else
            {
                node->right->parent=node->parent;
                (node==node->parent->left)?
                node->parent->left= node->right: node->parent->right= node->right;
                delete node;
                return;
            }
        }
        else
        {
            //case 3 : two child
            Node* sur=successor(node);
            //node->color=sur->color;
            int temp=sur->key;
            Delete(sur);
            node->key=temp;
        }
    }
}



Birbtree::Birbtree()
{

}

void Birbtree::LeftRotation(Node* node)
{
    if(node->right== nullptr)
    {
        return ;
    }
    else{
        //--- initialize
       Node* child=node->right;

       //---step 1 : exchange child
       node->right=child->left;
       if(child->left!= nullptr)
       {
           child->left->parent=node;
       }

       //---step 2 : parent and child
       child->parent=node->parent;
       if(node->parent!= nullptr)
       {
           if(node==node->parent->left)
               node->parent->left=child;
           else
               node->parent->right=child;
       }
       else
       {
           head=child;
       }

       //---step 3 : self and child

       node->parent=child;
       child->left=node;

        return;
    }
}

void Birbtree::RightRotation(Node * node)
{
    if(node->left== nullptr)
    {
        return;
    }
    else
    {
        //--initialize
        Node* child=node->left;

        //--step 1 : exchange child
        node->left=child->right;
        if(child->right!= nullptr)
        {
            child->right->parent=node;
        }

        //--step 2 : parent and child
        child->parent=node->parent;
        if(node->parent== nullptr)
        {
            head=child;
        }
        else
        {
            if(node==node->parent->left)
                node->parent->left=child;
            else
                node->parent->right=child;
        }

        //step 3 : self and child

        node->parent=child;
        child->right=node;
        return ;
    }
}

void Birbtree::Insert(Node* node)
{
    Bistree::Insert(node);
    InsertFix(node);
}

void Birbtree::InsertFix(Node * node)
{
    if(node->parent== nullptr)
    {
        head->color=black;
        return;
    }
    while (node->parent->color==red)
    {
        if(node->parent==node->parent->parent->left)
        {
            //----set uncle pointer
            Node* uncle;
            if(node->parent->parent->right== nullptr)
            {
                uncle=new Node;
                uncle->color=black;
            }
            else
            {
                uncle=node->parent->parent->right;
            }

            //----judge case
            if(uncle->color==red)
            {
                //--case 1
                node->parent->color=black;
                uncle->color=black;
                node->parent->parent->color=red;
                if(node->parent->parent== head)
                {
                    head->color=black;
                    return;
                }
                else
                {
                    node=node->parent->parent;
                }
            }
            else
            {
                if(node==node->parent->right)
                {
                   //--case 2
                   node=node->parent;
                   LeftRotation(node);
                }
                //--case 3
                node->parent->color=black;
                node->parent->parent->color=red;
                RightRotation(node->parent->parent);
            }
        }
        else
        {
            Node* uncle;
            if(node->parent->parent->left== nullptr)
            {
                uncle=new Node;
                uncle->color=black;
            }
            else
            {
                uncle=node->parent->parent->left;
            }

            if(uncle->color==red)
            {
                //---case 1
                node->parent->color=black;
                uncle->color=black;
                node->parent->parent->color=red;
                if(node->parent->parent== head)
                {
                    head->color=black;
                    return ;
                }
                else
                {
                    //node->parent->parent->color=red;
                    node = node->parent->parent;
                }
            }
            else
            {
                if(node==node->parent->left)
                {

                    //---case 2
                    node=node->parent;
                    RightRotation(node);
                }
                //---case 3
                node->parent->color=black;
                node->parent->parent->color=red;
                LeftRotation(node->parent->parent);

            }
        }
    }
    head->color=black;
}

void Birbtree::Delete(Node* delete_node)
{
    
    delete_node=search(delete_node);
    if(delete_node== nullptr)
    {
        return;
    }
    else
    {
        //--- adjust to case 1 or 2 in BST
        Node* father;
        int temp;
        if(delete_node->right!= nullptr&&delete_node->left!= nullptr)
        {
            Node* child=successor(delete_node);
            father=delete_node;
            temp=child->key;
            delete_node=child;
            delete child;
        }
        //---
        if(delete_node==head)
        {
            Bistree::Delete(delete_node);
            if (head != nullptr)
            {
                head->color = black;
                return;
            }
            return;
        }
        else
        {
            if(delete_node->color==red)
            {
                Bistree::Delete(delete_node);
                return;
            }
            else
            {
                if(delete_node->right!= nullptr^delete_node->left!= nullptr)
                {
                    if(delete_node->right!= nullptr)
                    {
                        delete_node->right->color=black;
                        Bistree::Delete(delete_node);
                        return;
                    }
                    else
                    {
                        delete_node->left->color=black;
                        Bistree::Delete(delete_node);
                        return;
                    }
                }
                else
                {
                    //cout<<"fix"<<endl;
                    //-- need fix
                    Node* child=new Node;
                    child->color=black;
                    child->parent=delete_node;
                    delete_node->right=child;
                    Bistree::Delete(delete_node);
                    DeleteFix(child);
                    father->key=temp;
                }
            }
        }
    }
}

void Birbtree::DeleteFix(Node * node)
{
  while (node->color==black&&node!=head) {
      if (node == node->parent->left) {   //-- current is left
          Node *sibling = node->parent->right;
          if (sibling->color == red) {
              //--case 1
              sibling->color = black;
              node->parent->color = red;
              LeftRotation(node->parent);
              if (node == node->parent->right)
                  sibling = node->parent->left;
              else
                  sibling = node->parent->right;
          }
          if (sibling->color == black && sibling->right == nullptr && sibling->left == nullptr) {
              //--case 2
              sibling->color = red;
              node = node->parent;
          } else {
              if (sibling->right== nullptr) {
                  //--case 3
                  sibling->left->color = black;
                  sibling->color = red;
                  RightRotation(sibling);
                  if (node == node->parent->right)
                      sibling = node->parent->left;
                  else
                      sibling = node->parent->right;
              }
              //--case 4
              sibling->color = node->parent->color;
              node->parent->color = black;
              sibling->right->color = black;
              LeftRotation(node->parent);
              if (node == node->parent->right)
                  node->parent->right = nullptr;
              else
                  node->parent->left = nullptr;
              delete node;
              return;
          }
      } else {
          Node *sibling = node->parent->left;
          if (sibling->color == red) {
              //--case 1
              sibling->color = black;
              node->parent->color = red;
              RightRotation(node->parent);
              if (node == node->parent->right)
                  sibling = node->parent->left;
              else
                  sibling = node->parent->right;
          }
          if (sibling->color == black && sibling->right == nullptr && sibling->left == nullptr) {
              //--case 2
              sibling->color = red;
              Node *child = node;
              node = node->parent;
              if (child == child->parent->right)
                  child->parent->right = nullptr;
              else
                  child->parent->left = nullptr;
              delete child;
          } else {
              if (sibling->right== nullptr) {
                  //--case 3
                  sibling->left->color = black;
                  sibling->color = red;
                  LeftRotation(sibling);
                  if (node == node->parent->right)
                      sibling = node->parent->left;
                  else
                      sibling = node->parent->right;
              }
              //--case 4
              sibling->color = node->parent->color;
              node->parent->color = black;
              sibling->left->color = black;
              RightRotation(node->parent);
              if (node == node->parent->right)
                  node->parent->right = nullptr;
              else
                  node->parent->left = nullptr;
              delete node;
              return;
          }
      }
      node->color = black;
  }
}