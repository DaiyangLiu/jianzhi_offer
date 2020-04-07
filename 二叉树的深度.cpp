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
class Solution_jianzhi { //这个是剑指offer上的示范代码 
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot == nullptr) return 0;
    	int nLeft = TreeDepth(pRoot->left);
		int nRight = TreeDepth(pRoot->right);
        return (nLeft<nRight)? (nRight+1):(nLeft+1);
    }
};
class Solution {//这个是自己第一次做的 
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot == nullptr) return 0;
    	int result = FindTreeDepth(pRoot,1);
        return result;
    }
    
    int FindTreeDepth(TreeNode* pRoot,int n){
    	int result_root = n,result_l=n,result_r=n;
		if(pRoot->left!= nullptr){
    		result_l = FindTreeDepth(pRoot->left,n+1);
		}
		
		if(pRoot->right!=nullptr){
			result_r = FindTreeDepth(pRoot->right,n+1);
		}
        int result = max3(result_root,result_l,result_r);
		return result;
	}
	
	int max3(int a,int b,int c){
		int max;
		if(a<=b) max = b;
		if(max<=c) max = c;
		return max;
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
    vector<int> preorder={1,2,4,5,7,3,6};
	vector<int> inorder={4,2,7,5,1,3,6};	
//    vector<int> preorder={1};
//	vector<int> inorder={1};
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//遍历树  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	printf("\n");
	//printf("%d ",root->left->val);
	//printf("%d ",root->right->val);
	
	Solution_jianzhi s;
	cout<<s.TreeDepth(root)<<endl;	
	
	return 0;
}
