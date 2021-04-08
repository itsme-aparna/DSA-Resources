#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}

void sumUtil(Node* root, int len, int sum, int& max_sum, int &max_len){
    if(!root){
        if(max_len<len){
            max_len=len;
            max_sum=sum;
        }
        else if(max_len==len && max_sum<sum){
            max_sum = sum;
        }
        return;
    }
    
    sumUtil(root->left, len+1, sum+root->data, max_sum, max_len);
    sumUtil(root->right, len+1, sum+root->data, max_sum, max_len);
}
int sumOfLongRootToLeafPath(Node* root)
{
	if(!root)
	   return 0;
	int max_sum = INT_MIN, max_len = 0;
	sumUtil(root,0,0, max_sum, max_len);
	return max_sum;
}

