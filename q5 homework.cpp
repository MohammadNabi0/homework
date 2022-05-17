#include <bits/stdc++.h>
using namespace std;
  

struct Node {
    int data;
    struct Node* next;
};
  

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node;

    new_node->data = new_data;
  
  
    new_node->next = (*head_ref);
  
   
    (*head_ref) = new_node;
}
  

void sumOfNodes(struct Node* head, int* sum)
{
  
    if (!head)
        return;
  
   
    sumOfNodes(head->next, sum);
  
    
    *sum = *sum + head->data;
}
  

int sumOfNodesUtil(struct Node* head)
{
  
    int sum = 0;
  
    
    sumOfNodes(head, &sum);
  
   
    return sum;
}
  
// deney 
int main()
{
    struct Node* head = NULL;
  
 
    push(&head, 7);
    push(&head, 6);
    push(&head, 8);
    push(&head, 4);
    push(&head, 1);
  
    cout << "Sum of nodes = "
         << sumOfNodesUtil(head);
    return 0;
}