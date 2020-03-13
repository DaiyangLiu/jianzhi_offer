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

//���һ���������Ƿ��ǶԳƶ���������������ȷ���Գ�λ����ȼ��� 
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(pRoot == nullptr) return true;//������ط����˴� 
    	return SubtreeSymetrical(pRoot->left,pRoot->right);
    }
    
    bool SubtreeSymetrical(TreeNode* pleft,TreeNode* pright){
    	if(pleft == nullptr && pright == nullptr) return true;
    	else if(pleft != nullptr && pright == nullptr) return false;
    	else if(pleft == nullptr && pright != nullptr) return false;
    	
    	//pleft != nullptr && pright != nullptr
    	if(pleft->val != pright->val)  return false;
    	else{
    		return SubtreeSymetrical(pleft->left,pright->right) && SubtreeSymetrical(pleft->right,pright->left);
		}
	}

};

int main(){
	//����һ��������
	vector<int> preorder={8,6,5,7,6,7,5};
	vector<int> inorder={5,6,7,8,7,6,5};
//	vector<int> preorder={8};
//	vector<int> inorder={8};
	
	Solution_buildtree sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//������  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	printf("\n");
	//printf("%d ",root->left->val);
	//printf("%d ",root->right->val);
	
	//�ö������ĶԳ���� 
	Solution s;
	
	cout<<"�Գ������"<<s.isSymmetrical(root)<<endl;
	

	
		
	
	return 0;
}


