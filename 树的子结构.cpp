#include <cstdio>
#include <iostream>
#include <vector> 
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):
		val(x),left(NULL),right(NULL){
		}
}; 

class Solution_buildtree{
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	//tree1 和 tree2 中，任何一个树为空，都没有再比对的意义，所以返回false 
    	if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
		//先在tree1 中寻找 与tree2 的根节点相等的节点
		if(pRoot1->val == pRoot2->val){
			if(HasSubtree2(pRoot1->left,pRoot2->left) && HasSubtree2(pRoot1->right,pRoot2->right)){
				return true;
			}
		}
		return 	HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }
    
    bool HasSubtree2(TreeNode* pRoot1, TreeNode* pRoot2){
    	//写这个函数的时候，思维还存在一定的混乱
		//对输入树节点的判断可以统一放到函数的开头
		//写判断时想清楚
		//在root2为空的时候，root1可以不为空，也可以为空
		//在root2不为空时，root1绝对不能为空 
    	if(pRoot2 == nullptr) return true;
    	if(pRoot1 == nullptr && pRoot2!=nullptr) return false;
    	
    	if(pRoot1->val != pRoot2->val ) return false;
    	else{
    		return HasSubtree2(pRoot1->left,pRoot2->left) && HasSubtree2(pRoot1->right,pRoot2->right);
		}
	}
};


int main(){
	//创建一个二叉树
	vector<int> preorder1={8,8,9,2,4,7,7};
	vector<int> inorder1={9,8,4,2,7,8,7};

	Solution_buildtree sb;
	TreeNode* root1 = sb.reConstructBinaryTree(preorder1,inorder1);
	
	vector<int> preorder2={8,9,2};
	vector<int> inorder2={9,8,2};

	TreeNode* root2 = sb.reConstructBinaryTree(preorder2,inorder2);
	
	//遍历树 
	cout<<"tree1:"<<endl; 
	preorder_tree(root1);
	printf("\n");
	inorder_tree(root1);
	printf("\n");
	
	cout<<"tree2:"<<endl; 
	preorder_tree(root2);
	printf("\n");
	inorder_tree(root2);
	printf("\n");
	
	//printf("%d ",root->left->val);
	//printf("%d ",root->right->val);
	Solution s;
	cout<<"tree1 是否含有 tree2："<<s.HasSubtree(root1,root2)<<endl;

	
		
	
	return 0;
}
