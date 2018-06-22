Node * inOrderSuccessor(Node *root, Node *x)
{
    Node *suc=NULL;

    while(root!=NULL){
        
        
        if(root->data==x->data){
            
            // See if it's right subtree exits
            if(root->right!=NULL){
            
                Node *temp=root->right;
            
                while(temp->left){
                  temp=temp->left;
                }
            
                // If temp->left is NULL ie. no leftmost most child in rightsubtree
                // Then temp contains root of rightsubtree
                 suc=temp;
             }
             break;
        }
        // inOrderSuccessor means just next greater element because inOrder is sorted
        // So if you find any greater element store it and move towards target node
        else if(x->data<root->data){
            suc=root;
            root=root->left;
        }
        // Move towards target node
        else{
            root=root->right;
        }
    }
    return suc;
}
