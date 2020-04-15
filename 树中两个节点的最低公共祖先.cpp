#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
using namespace std;



//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
		TreeNode *TheLowestAncestorNode(TreeNode *pRoot, TreeNode *pNode1, TreeNode *pNode2){
			if(pRoot==nullptr || pNode1==nullptr || pNode2==nullptr) return nullptr;
			
			list<TreeNode*> path1;
			list<TreeNode*> path2;
			
			bool found1 = GetNodePath(pRoot,pNode1,path1);
			bool found2 = GetNodePath(pRoot,pNode2,path2);
			if(!found1 || !found2) return nullptr;
			for(list<TreeNode*>::iterator iter=path1.begin();iter!=path1.end();iter++){
				cout<<(*iter)->val<<" ";
			}		
			cout<<endl;
			for(list<TreeNode*>::iterator iter=path2.begin();iter!=path2.end();iter++){
				cout<<(*iter)->val<<" ";
			}
			cout<<endl;
			
			TreeNode* common = GetLastCommonNode(pRoot,path1,path2);
			return common;
		}
		
		bool GetNodePath(TreeNode *pRoot, TreeNode *pNode,list<TreeNode*> &li){	
			TreeNode * p = pRoot;
			if(p == pNode){
				return true;
			}else{
				li.push_back(p);
			}
            bool found = false;
			for(int i=0;i<2&&!found;i++){
				if(i==0&&!found&&p->left!=nullptr)
				    found = GetNodePath(p->left,pNode,li);
			    if(i==1&&!found&&p->right!=nullptr){
			    	found = GetNodePath(p->right,pNode,li);
				}
			}
			if(!found){
				li.pop_back();
			}
			return found;						
		}
		
		TreeNode *GetLastCommonNode(TreeNode *pRoot, const list<TreeNode*> &li1,const list<TreeNode*> &li2){
			list<TreeNode*>::const_iterator iter1=li1.cbegin();
			list<TreeNode*>::const_iterator iter2=li2.cbegin();
			TreeNode* p=nullptr;
			for(;iter1!=li1.cend()&&iter2!=li2.cend();iter1++,iter2++){
				if((*iter1)==(*iter2)){
					p=*iter1;
				}else{
					break;
				}
			}
			return p;
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
		//×ó×ÓÊ÷
		//×ó×ÓÊ÷·¶Î§ pre:[1,1+root_pos} , vin: [0,root_pos)
		if(root_pos>0){
			vector<int> pre_left(pre.begin()+1,pre.begin()+1+root_pos);
			vector<int> vin_left(vin.begin(),vin.begin()+root_pos);
			rootnode->left = reConstructBinaryTree(pre_left,vin_left);
		}
		
		//ÓÒ×ÓÊ÷
		//ÓÒ×ÓÊ÷·¶Î§ pre:[1+root_pos,pre.size()) , vin: [root_pos+1,vin.size())
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
	vector<int> preorder={1,2,4,6,7,5,8,9,3};
	vector<int> inorder={6,4,7,2,8,5,9,1,3};
	
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//±éÀúÊ÷  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	printf("\n");
	TreeNode *p = root;
	TreeNode * pnode1 = p->left->left->left;
	cout<<"pnode1 "<<pnode1->val<<endl;
	TreeNode * pnode2 = p->left->right->left;
	cout<<"pnode2 "<<pnode2->val<<endl;
	
	
	Solution s;
	TreeNode* common = s.TheLowestAncestorNode(root,pnode1,pnode2);
    cout<<"ans="<<common->val<<endl;



	
	return 0;
}
