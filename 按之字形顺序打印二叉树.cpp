#include <cstdio>
#include <iostream>
#include <vector>
#include <stack> 
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
        vector<vector<int> > Print(TreeNode* pRoot) {
        	vector<vector<int> > printmultiline;
        	if(pRoot==nullptr) return printmultiline;
        	
        	stack<TreeNode*> snode[2];//snode[0] snode[1] 方向不同 	
        	snode[0].push(pRoot);
        	int tobeprint = 1;
        	int nextline = 0;
        	bool lefttoright = true;//true 弹出栈0  false 弹出栈1 
        	int pop_stack = 0,push_stack = 1; 
			vector<int> oneline;
        	
        	while(!snode[0].empty()||!snode[1].empty()){
        		if(lefttoright == true){
        			pop_stack = 0;
        			push_stack = 1;
				}else{
					pop_stack = 1;
					push_stack = 0;
				}
				
				TreeNode * node = snode[pop_stack].top();
				
				oneline.push_back(node->val);
				--tobeprint;
				snode[pop_stack].pop();
				//弹出栈0，压入栈1 时，子节点从左到右
				//弹出栈1，压入栈0 时，子节点从右到左 
				if(!pop_stack && node->left!=nullptr){
					snode[push_stack].push(node->left);
					++nextline;
				} 
				if(node->right!=nullptr){
					snode[push_stack].push(node->right);
					++nextline;
				}
				if(pop_stack && node->left!=nullptr){
					snode[push_stack].push(node->left); 
					++nextline;
				}
				
				if(tobeprint==0){
					printmultiline.push_back(oneline);
					oneline.clear();
					tobeprint=nextline;
					nextline=0;
					lefttoright = !lefttoright;
				}
				
			}
			return printmultiline;
        
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
    
    vector<vector<int> > printtree = s.Print(root);

    vector<vector<int> >::iterator iter;
    for(iter=printtree.begin();iter!=printtree.end();iter++){
    	vector<int>::iterator iter_in;
		for(iter_in = (*iter).begin();iter_in!=(*iter).end();iter_in++){
			cout<<*iter_in<<" ";
		}
    	
    	cout<<endl;
	}
	
	return 0;
}
