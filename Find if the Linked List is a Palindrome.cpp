/*
  Given a Linked List with the nodes of the list defined as-
  {
    int data;
    Node *next;
  }
  Find if the List is a Palindrome
  
  Solution - Naive approach is to store all the elements in an array and then find if the elements of the array form a Palindrome.
  The time complexity of this solution is O(N) space and time.
  
  An efficient approach is to use recursion. The base case of recursion is when the list is empty. Under such a circumstance, the
  list is trivially a palindrome.
*/

// curr is the right pointer and head is the left
// the idea is first advance curr till the null node and return true
// then using the power of recursion compare the last node with the first node, second with the second last 
// and so on...
// If there is a match return true and advance the head pointer else return false.
// Also for the list to be a palidrome, all matches before the current match must be a success.
bool isPalindrome(Node *curr, Node *&head) {
    if(curr == nullptr)
        return true;
        
    if(isPalindrome(curr -> next, head) == false)
        return false;
    
    if(curr -> data != head -> data)
        return false;
        
    head = head -> next;
    return true;
}

bool isPalindrome(Node *head) {
    return isPalindrome(head, head);
}
