/*
  If there are even node, delete the second one

  Solution - The Solution is similar to finding the middle node of the Linked List in a Single Traversal. We use the Hare and 
  Tortoise approach for this.
*/

Node* deleteMid(Node *head) {
     if(head == nullptr)
        return nullptr;
  
    // two pointers, fast(hare) and slow(tortoise).
    // hare moves two steps at a time where as tortoise moves one step at a time
    // slow will finally be set to the middle node, if there are even number of nodes then slow will point to the first node
    // so, if there are odd nodes then we will be deleting the node pointed by slow. Else we will delete the node next to slow
    // num_nodes keeps track of total number of nodes in the list. Thus, in deciding which node to delete
    // prev keeps track of the node just previous to slow, will be helpful in deletion of middle node if total nodes are odd
    Node *slow = head, *fast = head -> next, *prev = nullptr;
    int num_nodes = 1;
    
    // move fast at twice the rate.
    // increment the number of node each time you move fast
    while(fast != nullptr) {
        ++num_nodes;
        fast = fast -> next;
        
        if(fast != nullptr) {
            ++num_nodes;
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    
    if(num_nodes % 2) {
        // if the number of nodes are odd and prev is set to null
        // it means there is only single node in the entire list
        // simply delete the head and return null
        if(prev == nullptr) {
            delete head;
            return nullptr;
        }
        
        // else perform deletion by unlinking some links.
        prev -> next = slow -> next;
        delete slow;
    }
    
    // nodes are even, so, remove the node next to slow.
    else {
        Node *temp = slow -> next -> next;
        delete slow -> next;
        slow -> next = temp;
    }
    
    
    return head;
}
