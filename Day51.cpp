//Q1. Minimum Cost of Ropes
//TC-O(nlogn)
//SC-O(n)
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long, vector<long long >, greater<long long>>pq;
        
        for(long long it: arr){
            pq.push(it);
        }
        
        long long ans =0;
        while(pq.size()>1){
            long long num1= pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            long long sum = num1+num2;
            
            ans+=sum;
            pq.push(sum);
        }
        
         return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends


//Q2.  BST to Min Heap

#include <bits/stdc++.h>
using namespace std;

// Structure of a node of BST
struct Node {

	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct Node* getNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// function prototype for preorder traversal
// of the given tree
void preorderTraversal(Node*);

// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node* root, vector<int>& arr)
{
	if (root == NULL)
		return;

	// first recur on left subtree
	inorderTraversal(root->left, arr);

	// then copy the data of the node
	arr.push_back(root->data);

	// now recur for right subtree
	inorderTraversal(root->right, arr);
}

// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
	if (root == NULL)
		return;

	// first copy data at index 'i' of 'arr' to
	// the node
	root->data = arr[++*i];

	// then recur on left subtree
	BSTToMinHeap(root->left, arr, i);

	// now recur on right subtree
	BSTToMinHeap(root->right, arr, i);
}

// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node* root)
{
	// vector to store the data of all the
	// nodes of the BST
	vector<int> arr;
	int i = -1;

	// inorder traversal to populate 'arr'
	inorderTraversal(root, arr);

	// BST to MIN HEAP conversion
	BSTToMinHeap(root, arr, &i);
}

// function for the preorder traversal of the tree
void preorderTraversal(Node* root)
{
	if (!root)
		return;

	// first print the root's data
	cout << root->data << " ";

	// then recur on left subtree
	preorderTraversal(root->left);

	// now recur on right subtree
	preorderTraversal(root->right);
}

// Driver program to test above
int main()
{
	// BST formation
	struct Node* root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

	// Function call
	convertToMinHeapUtil(root);
	cout << "Preorder Traversal:" << endl;
	preorderTraversal(root);

	return 0;
}


//Q3. Find the kth maximum subarray sum   -- Brute Force    
//TC-O(n*n*logk)
//SC-O(k)

#include<bits/stdc++.h>
using namespace std;


int maxiSum(int arr[], int n, int k)
{
    priority_queue<int,vector<int>, greater<int>>maxiHeap;
    int ans =0;
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(maxiHeap.size()<k)
            maxiHeap.push(sum);
            else{
                if(sum>maxiHeap.top()){
                    maxiHeap.pop();
                    maxiHeap.push(sum);
                }
            }
        }
    }
    return maxiHeap.top();
}
int main()
{
    int arr[5]={1,2,6,4,3};
    
    cout<<maxiSum(arr,5,1)<<endl;
}