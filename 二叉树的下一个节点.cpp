#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
    	//д��̫�� �ع�һ�� 
    	if(pNode == nullptr) return nullptr;
        //Ѱ�������������һ���ڵ�
        TreeLinkNode * q, *p;
        p = pNode;
		q = p->next;//���ڵ� 
		if(p->right==nullptr){
			//������Ϊ�յ����нڵ� 
			 if(q){
			 	//Ҷ�ӽڵ�
				 if(q->left==p) {
		        	//��Ҷ�ӽڵ� 
		        	//��Ҷ�ӽڵ�������������һ���ڵ�Ϊ���ڵ�
					return q; 
				 }else if(q->right==p){
					while(q->next){
						if(q->next->left == q){
							return q->next;
						}else{
							q=q->next;
						}
					} 
					return nullptr;
				 }
			 } else{
			 	//���ڵ㲻���ڣ���õ�Ϊֻ��һ���ڵ�Ķ������ĸ��ڵ�
				 return nullptr; 
			 }
		}else{
			//���ڵ� 		
			p=p->right;
			 while(p->left){
			 	p=p->left;
			 } 
			 return p;			
		}

		
    }
};


//class Solution {
//public:
//    TreeLinkNode* GetNext(TreeLinkNode* pNode)        //Ѱ�������������һ���ڵ�
//    {
//    	//���д����ȫ���ս�ָoffer�ϵ�д�������� 
//    	if(pNode == nullptr) return nullptr; 
//		TreeLinkNode *pNext=nullptr; //�����������һ���ڵ�
//		
//		if(pNode->right!=nullptr){//������������ֱ���������������󣬼����������һ���ڵ� 
//			pNext=p->right;
//			 while(pNext->left){
//			 	pNext=pNext->left;
//			 } 
//			 return pNext;	
//		}else if(pNode->next!=nullptr){//û�����������и��ڵ㣬�����ϻ��� 
//			TreeLinkNode * pParent=pNode->next;//���ڵ�
//			TreeLinkNode * pCurrent=pNode;
//			 while(pParent != nullptr && pCurrent==pParent->right){
//			 	pCurrent = pParent;
//				 pParent = pParent->next;
//			 }
//			pNext=pParrent;
//			 
//		}
//		return pNext;		
//    }
//};

// �ؽ������� 
TreeLinkNode* reConstructBinaryTree(vector<int> pre,vector<int> vin,TreeLinkNode * parent) {
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
		TreeLinkNode* rootnode = new TreeLinkNode(root);
		rootnode->next = parent;
		//������
		//��������Χ pre:[1,1+root_pos} , vin: [0,root_pos)
		if(root_pos>0){
			vector<int> pre_left(pre.begin()+1,pre.begin()+1+root_pos);
			vector<int> vin_left(vin.begin(),vin.begin()+root_pos);
			rootnode->left = reConstructBinaryTree(pre_left,vin_left,rootnode);
		}
		
		//������
		//��������Χ pre:[1+root_pos,pre.size()) , vin: [root_pos+1,vin.size())
		if(1+root_pos < pre.size()){
			vector<int> pre_right(pre.begin()+1+root_pos,pre.end());
			vector<int> vin_right(vin.begin()+1+root_pos,vin.end());
			rootnode->right = reConstructBinaryTree(pre_right,vin_right,rootnode);
		}
		 		 
		return rootnode;

}
    
void preorder_tree(TreeLinkNode* root){
	if(root==NULL)return;
	printf("%d ",root->val);
	preorder_tree(root->left);
	preorder_tree(root->right);
	return; 	
} 

void inorder_tree(TreeLinkNode* root){
	if(root==NULL)return;
	inorder_tree(root->left);
	printf("%d ",root->val);
	inorder_tree(root->right);
	return; 	
} 

int main()
{
//	vector<int> preorder={1,2,4,7,3,5,6,8};
//	vector<int> inorder={4,7,2,1,5,3,8,6};
    vector<int> preorder={1,2,4,5,8,9,3,6,7};
	vector<int> inorder={4,2,8,5,9,1,6,3,7};	
//    vector<int> preorder={1};
//	vector<int> inorder={1};

	TreeLinkNode* root = reConstructBinaryTree(preorder,inorder,NULL);
	
	//������  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root);
	printf("\n");
	Solution s;
	
	TreeLinkNode*  t=root; 
	printf("search: %d\n",t->val);
	TreeLinkNode* ans = s.GetNext(t);
	if(ans == NULL){
		printf("NULL\n");
	} else{
		printf("answer: %d\n",ans->val);
	}
	printf("----------------------\n\n");
	
    t=root->left; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
	
	t=root->right; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
	
	t=root->left->left; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
		
	t=root->left->right; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
		
	t=root; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
		
	t=root->left->right->left; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
		
	t=root->left->right->right; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
		
	t=root->right->left; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	printf("answer: %d\n",ans->val);
	printf("----------------------\n\n");
		
	t=root->right->right; 
	printf("search: %d\n",t->val);
	ans = s.GetNext(t);
	if(ans == NULL){
		printf("NULL\n");
	} else{
		printf("answer: %d\n",ans->val);
	}

	printf("----------------------\n\n");	
	return 0;
 } 
