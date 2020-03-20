#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

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

//序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。 
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        string *str = new string();
        string **pstr = &str; //*pstr --> str(一个string的指针)
        SerializeRecurse(root, pstr);
        cout<<"序列化： "<<endl; 
        cout<<*str<<endl;
        
        //string --->  const char*
        cout<<"string 转 const char*"<<endl;
		const char * cstr = str->c_str();
		cout<<cstr<<endl;
		
		//const char * ---> char *
		cout<<"const char * 转 char*"<<endl;
		char *noconst_cstr = new char[str->length()+1];
		strcpy(noconst_cstr,cstr);
		cout<<noconst_cstr<<endl;
        return noconst_cstr;
    }
    
    void SerializeRecurse(TreeNode *root, string ** pstr){
    	if(root == nullptr){
    		**pstr+="#";
    		return;
		} 
		**pstr+= to_string(root->val);
		**pstr+= "!";
		SerializeRecurse(root->left,pstr);
		SerializeRecurse(root->right,pstr);
	}
    
    
    
    TreeNode* Deserialize(char *str) {
    	if(*str == '\0' || *str =='!' || *str=='#'){
    		return nullptr;
		}
    	//TreeNode * root = new TreeNode(int(*str));
    	//str++;
    	TreeNode * root = nullptr;
    	TreeNode ** proot = &root;	
    	cout<<"传进 DeserializeRecurse(proot,str) 的 str "<<endl; 
    	char ** pstr = &str;
    	cout<<str<<endl;
    	DeserializeRecurse(proot,pstr);
    	return *proot;
    }
    
    void DeserializeRecurse(TreeNode** root, char ** str) {
    	cout<<"**str: "<<**str<<endl;
		if(**str == '\0') return;
    	if(**str == '#'){
    		root = nullptr;
    		(*str)++;
    		return;
		} 
		int value=0;
		while(**str!='!'){
			value = value*10 + **str-48;
			(*str)++;
		}
		cout<<"value: "<<value<<endl;
		(*str)++;

		TreeNode *node = new TreeNode(value);
		cout<<"create node sucess"<<endl;
		*root = node;
		cout<<"create root sucess"<<endl;
		DeserializeRecurse(&(*root)->left,str);
		DeserializeRecurse(&(*root)->right,str);
		return; 	
    }
    
    
};

int main(){
	vector<int> preorder={1,2,4,3,5,6};
	vector<int> inorder={4,2,1,5,3,6};
	
	Solution_build sb;
	TreeNode* root = sb.reConstructBinaryTree(preorder,inorder);
	
	//遍历树  
	preorder_tree(root);
	printf("\n");
	inorder_tree(root); 
	cout<<endl;
	
	string str("abc"); 
	cout<<str<<endl;
	cout<<str.length()<<endl;
	//string --->  const char*
	const char * cstr = str.c_str();
	cout<<cstr<<endl;
	
	//const char * ---> char *
	char noconst_cstr[str.length()+1];
	strcpy(noconst_cstr,cstr);
	cout<<noconst_cstr<<endl;
	
	string *ss = new string();
	string **pss = &ss;
	**pss+="a";
	**pss+=to_string(1);
	cout<<*ss<<endl;

	Solution s;
	char * rootser = s.Serialize(root);
	cout<<rootser<<endl;
	
	string chartostring = rootser;
	cout<<"char* to string "<<endl;
	cout<<chartostring<<endl;
	
	for(int i=0;i<chartostring.length();i++){
		if(chartostring[i] == '\0'){
			cout<<"find \0" <<endl;
		}
	}
	cout<<"============================"<<endl;
    TreeNode * droot = s.Deserialize(rootser);
    	//遍历树  
    cout<<"遍历反序列化后的树 "<<endl;	
	preorder_tree(droot);
	printf("\n");
	inorder_tree(droot); 
	cout<<endl;
	return 0;
} 
