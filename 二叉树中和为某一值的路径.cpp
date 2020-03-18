#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int> > path;
		if(root==nullptr) return path;
		deque<TreeNode*> deque_node; 
		int sum = 0;
		everypath(root,path,deque_node,expectNumber,sum);
		return path;//返回的数组，长度大的靠前 
    }
    
    
    void everypath(TreeNode * root, vector<vector<int> > &ep, deque<TreeNode*> &deque_node,int expectNumber,int sum){
    	sum += root->val;
		deque_node.push_back(root);
		//这里要求的是一条完整的路径
		//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
		//所以条件有下面三个 
		if(sum == expectNumber && root->left == nullptr  && root->right == nullptr){
			vector<int> onepath;
			deque<TreeNode*>::iterator iter;
			for(iter=deque_node.begin();iter!=deque_node.end();iter++){
				onepath.push_back((*iter)->val);
				cout<<(*iter)->val<<" ";
			}
			cout<<endl;
			ep.push_back(onepath);
			deque_node.pop_back();
			return ;
		}
		 
		if(root->left == nullptr  && root->right == nullptr){
			deque_node.pop_back();
			return ;
		}
    	
    	if(root->left){
    		cout<<root->val<<"  root->left"<<endl;
    		everypath(root->left,ep,deque_node,expectNumber,sum);
		}
		if(root->right){
			cout<<root->val<<"  root->right"<<endl;
			everypath(root->right,ep,deque_node,expectNumber,sum);
		}
		cout<<root->val<<" pop_back"<<endl;
		deque_node.pop_back();
		return ;

	} 
};

class Solution_deep {
public:
    vector<vector<int> > FindDeepPath(TreeNode* root,int expectNumber) {
    	//这里实现了一个深度遍历
    	vector<vector<int> > path;
		if(root==nullptr) return path;
		deque<TreeNode*> deque_node; 
		
		path = everypath(root,path,deque_node);
		return path;
    } 
    
    vector<vector<int> > everypath(TreeNode * root, vector<vector<int> > &ep, deque<TreeNode*> &deque_node){
    	
		deque_node.push_back(root);
		 
		if(root->left == nullptr  && root->right == nullptr){
			vector<int> onepath;
			deque<TreeNode*>::iterator iter;
			for(iter=deque_node.begin();iter!=deque_node.end();iter++){
				onepath.push_back((*iter)->val);
				cout<<(*iter)->val<<" ";
			}
			cout<<endl;
			ep.push_back(onepath);
			deque_node.pop_back();
			return ep;
		}
    	
    	if(root->left){
    		cout<<root->val<<"  root->left"<<endl;
    		everypath(root->left,ep,deque_node);
		}
		if(root->right){
			cout<<root->val<<"  root->right"<<endl;
			everypath(root->right,ep,deque_node);
		}
		cout<<root->val<<" pop_back"<<endl;
		deque_node.pop_back();
		return ep;

	} 
};

int main(){
//	vector<int> preorder={8,6,5,7,10,9,11};
//	vector<int> inorder={5,6,7,8,9,10,11};
	vector<int> preorder={10,5,4,7,12};
	vector<int> inorder={4,5,7,10,12};
	
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//遍历树  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	cout<<endl;
	
	Solution s;
	vector<vector<int> >  path= s.FindPath(root,22);
    vector<vector<int> >::iterator iter;
    vector<int>::iterator iiter;
    for(iter= path.begin();iter!=path.end();iter++){
    	//*iter   vector<int>
    	
    	for(iiter= (*iter).begin();iiter!=(*iter).end();iiter++){
    		cout<<*iiter<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
