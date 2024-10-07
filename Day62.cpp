//Q1. Rotate DLL by K nodes counter clockwise 
//TC-O(n)
//SC-O(1)

class Solution {
public:
    Node *rotateDLL(Node *head,int p)
    {
        if(head ==nullptr || head ->next ==nullptr){
            return head;
        }
        //point the last node at the end
        Node* last = head;
        while(last->next != NULL){
            last = last->next;
        }
        // point the last node 
        Node* curr = head;
        for(int i=0;i<p;i++){
            curr = curr->next;
        }
        curr->prev->next = nullptr;
        curr->prev = nullptr;
        
        last->next = head;
        head->prev = last;
        
        return curr;
    }

//Q2. Rotate a Doubly linkedlist in group of given size. 
//TC-O(n)
//SC-O(n) // for recursion stack
Node* reverseDLLInGroups(Node* head, int k)
{	
    // Write your code here. 
	if( head == nullptr || head ->next ==nullptr){
		return head;
	}
	
	Node* curr = head;
	int count  = 0;
	Node* prev = nullptr;
	Node* next = nullptr;
	while(curr!=nullptr && count< k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if( curr !=NULL){
		head->next  = reverseDLLInGroups(curr, k);
	}

	return prev;
}