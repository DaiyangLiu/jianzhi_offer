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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==nullptr) return nullptr;
        
        int & n = k;
        TreeNode* knode = InOrderFindK(pRoot,n); 
        return knode;
    }

    TreeNode* InOrderFindK(TreeNode* pRoot,int &k){
    	TreeNode* target =nullptr;

    	if(target == nullptr && pRoot->left!=nullptr){
    		target = InOrderFindK(pRoot->left,k);
		}
		
		if(target ==nullptr){
			if(k== 1 ){
				target = pRoot;
			}
			k--;
		}
		
		if(target==nullptr && pRoot->right!=nullptr){
    		target=InOrderFindK(pRoot->right,k);
		}
		return target;
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
		//������
		//��������Χ pre:[1,1+root_pos} , vin: [0,root_pos)
		if(root_pos>0){
			vector<int> pre_left(pre.begin()+1,pre.begin()+1+root_pos);
			vector<int> vin_left(vin.begin(),vin.begin()+root_pos);
			rootnode->left = reConstructBinaryTree(pre_left,vin_left);
		}
		
		//������
		//��������Χ pre:[1+root_pos,pre.size()) , vin: [root_pos+1,vin.size())
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
	vector<int> preorder={5,3,2,4,7,6,8};
	vector<int> inorder={2,3,4,5,6,7,8};
	
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//������  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	printf("\n");
	
	Solution s;
	TreeNode* p= nullptr;
	p=s.KthNode(root,3);
	if(p==nullptr) cout<<"nullptr"<<endl;
	if(p!=nullptr){
		cout<<"ans: "<<p->val<<endl;
	}
    	
	
	return 0;
}
