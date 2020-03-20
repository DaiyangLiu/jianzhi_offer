#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;



//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
    	if(pRootOfTree == nullptr) return nullptr;
        TreeNode* lastnode = nullptr;
        InorderCreateList(pRootOfTree,&lastnode);
        //倒
		while(lastnode!=nullptr && lastnode->left!=nullptr){
			lastnode=lastnode->left;
		} 
        TreeNode* listnode = lastnode;
        return listnode;
    }
    //这里遇到了一个不太常见的情况 
    //平时顶多在递归中传递一个数，众所周知使用该变量的引用即可
	//而这里遇到了想要在递归中传递一个treenode的指针的情况
	//使用treenode * 的变量类型依不足以让这个变量在递归中传递
	//必须使用该变量的指针，即 treenode **	 
     void InorderCreateList(TreeNode* root, TreeNode** lastnode){
    	if(root == nullptr) return;
    	InorderCreateList(root->left,lastnode);

		if(*lastnode != nullptr){
			cout<<"root: "<<root->val<<endl;
			cout<<"lastnode: "<<(*lastnode)->val<<endl;
			root->left = *lastnode;
			(*lastnode)->right = root;

		}
		*lastnode = root;
    	InorderCreateList(root->right,lastnode);
	}		
//    void InorderCreateList(TreeNode* root, TreeNode** lastnode){
//    	if(root == nullptr) return;
//    	InorderCreateList(root->left,lastnode);
//
//    	if(*lastnode == nullptr){
//    		//表示才开始创建这个链表
//			*lastnode = root;
//			cout<<"root(lastnode==nullptr): " <<(*lastnode)->val<<endl;
//		else if(*lastnode != nullptr){
//			cout<<"root: "<<root->val<<endl;
//			cout<<"lastnode: "<<(*lastnode)->val<<endl;
//			root->left = *lastnode;
//			(*lastnode)->right = root;
//			*lastnode = root;
//		}
//    	InorderCreateList(root->right,lastnode);
//	}		
};

int main(){
	vector<int> preorder={10,6,4,8,14,12,16};
	vector<int> inorder={4,6,8,10,12,14,16};
	
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//遍历树  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	printf("\n");
	
	Solution s;
	TreeNode* treelist = s.Convert(root);
	TreeNode* p = treelist;
	cout<<"list:"<<endl;
	while(p!=nullptr){
		cout<<p->val<<" ";
		p=p->right;
	}
	
	
	
	return 0;
}
