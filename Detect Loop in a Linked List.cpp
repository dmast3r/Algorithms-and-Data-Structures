/*
  Given a linked list, determine if the list contains a loop. If it does return true or false otherwise.
  
  Solution- Use the Hare and Tortoise approach. Use two pointers, move one pointer two steps at a time(hare) and  the other one 
  step at a time(tortoise). If there is a loop the two pointers will eventually meet, else they will reach NULL. 
*/

int detectloop(Node *head) {
    if(head == nullptr or head -> next == nullptr)
        return false;
        
    Node *fast = head -> next, *slow = head;
    while(fast != nullptr) {
        if(fast == slow)
            return true;
        fast = fast -> next;
        if(fast != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    
    return false;
}
