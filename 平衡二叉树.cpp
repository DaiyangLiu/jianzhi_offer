#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
	    if(pRoot == nullptr) return true;
	    int nroot;

	    return IsBalanced(pRoot,&nroot);
    }
    
    bool IsBalanced(TreeNode* pRoot,int *n){
    	if(pRoot==nullptr){
    		*n = 0;
    		return true;
		} 
    	
    	int left,right;
    	if(IsBalanced(pRoot->left,&left) && IsBalanced(pRoot->right,&right)){
    		int diff = left -right;
			if(diff<=1 &&diff >=-1){
				*n = (left<right)? (right+1):(left+1);
				return true;
			}
		}	
		return false;//注意这里的return false 和 return true的位置。	
	}
};

class Solution_build {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	if(pre.size()==0 || vin.size()==0){
    		return NULL;
		} 
		int root = pre[0];
		int root_pos;
		for(int i=0;i<vin.size();i++){
			if(root == vin[i]){
				root_pos = i;
			}
		}
		TreeNode* rootnode = new TreeNode(root);
		//左子树
		//左子树范围 pre:[1,1+root_pos} , vin: [0,root_pos)
		if(root_pos>0){
			vector<int> pre_left(pre.begin()+1,pre.begin()+1+root_pos);
			vector<int> vin_left(vin.begin(),vin.begin()+root_pos);
			rootnode->left = reConstructBinaryTree(pre_left,vin_left);
		}
		
		//右子树
		//右子树范围 pre:[1+root_pos,pre.size()) , vin: [root_pos+1,vin.size())
		if(1+root_pos < pre.size()){
			vector<int> pre_right(pre.begin()+1+root_pos,pre.end());
			vector<int> vin_right(vin.begin()+1+root_pos,vin.end());
			rootnode->right = reConstructBinaryTree(pre_right,vin_right);
		}
		 
		 
		return rootnode;

    }
};

void preorder_tree(TreeNode* root){
	if(root==NULL)return;
	printf("%d ",root->val);
	preorder_tree(root->left);
	preorder_tree(root->right);
	return; 	
} 

void inorder_tree(TreeNode* root){
	if(root==NULL)return;
	inorder_tree(root->left);
	printf("%d ",root->val);
	inorder_tree(root->right);
	return; 	
} 

void afterorder_tree(TreeNode* root){
	if(root==NULL)return;
	afterorder_tree(root->left);
	afterorder_tree(root->right);
	printf("%d ",root->val);
	return; 	
} 

int main(){
//	vector<int> preorder={1,2,4,7,3,5,6,8};
//	vector<int> inorder={4,7,2,1,5,3,8,6};
//    vector<int> preorder={1,2,4,5,7,3,6};
//	vector<int> inorder={4,2,7,5,1,3,6};	
//    vector<int> preorder={1};
//	vector<int> inorder={1};
    vector<int> preorder={1,2,3,4,5};
	vector<int> inorder={2,1,3,4,5};	
	
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//遍历树  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	printf("\n");
	//printf("%d ",root->left->val);
	//printf("%d ",root->right->val);
	
	Solution s;
	cout<<s.IsBalanced_Solution(root)<<endl;	
	
	return 0;
}
