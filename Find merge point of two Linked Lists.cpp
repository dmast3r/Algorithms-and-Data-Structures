/*
  Given pointers to heads of two linked lists which may or may not merge. Find their intersection point if they merge or return -1
  otherwise.
  
  Solution- 
  Count the number of nodes in the two list and thus the difference in the number of nodes. Advance the head pointer of
  the bigger list by the absolute value of the difference in the the number of nodes of the two list. Now one by one conmpare the
  pointers scanning the lists, until either they are equal or one of them reaches NULL.
  
  If at the end neither of them is NULL then the two lists have a merge point, so return the data at this node. Return -1 otherwise.
*/

int countNodes(Node *node) {
    int nodes = 0;
    while(node) {
        ++nodes;
        node = node -> next;
    }
    
    return nodes;
}

int intersectPoint(Node* head1, Node* head2) {
    int num_nodes_1 = countNodes(head1);
    int num_nodes_2 = countNodes(head2);
    int diff_nodes = abs(num_nodes_1 - num_nodes_2);
    
    Node *&bigger_list = (num_nodes_1 > num_nodes_2 ? head1 : head2);
    
    for(int i = 0; i < diff_nodes and bigger_list; ++i)
        bigger_list = bigger_list -> next;
    
    while(head1 and head2 and head1 != head2) {
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    return (head1 and head2 ? head1 -> data : -1);
}
