#include <cstdio>
#include <iostream>
#include <vector>
#include <deque> 
using namespace std;
 
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
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


class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	//用队列来实现对所有节点的依次输出
    	vector<int> output;
    	if(root==nullptr) return output;
    	
		deque<TreeNode*> node_deque;
		node_deque.push_back(root);
		
		while(!node_deque.empty()){
			TreeNode * node = node_deque.front();
			output.push_back(node->val);
			
			if(node->left!=nullptr){
				node_deque.push_back(node->left);
			}
			if(node->right!=nullptr){
				node_deque.push_back(node->right);
			}
			node_deque.pop_front();
		}
		 
		return output;
    }
};

int main(){
	vector<int> preorder={8,6,5,7,10,9,11};
	vector<int> inorder={5,6,7,8,9,10,11};
	
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//遍历树  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	cout<<endl;

    Solution s;
    
    vector<int> printtree = s.PrintFromTopToBottom(root);
    
    vector<int>::iterator iter;
    for(iter=printtree.begin();iter!=printtree.end();iter++){
    	cout<<*iter<<" "; 
	}
	
	return 0;
}
