输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        int length = pre.size();
        int* preorder = pre.data();
        int* inorder = vin.data();
        if(preorder==nullptr||inorder==nullptr)
            return nullptr;
        return Construct(preorder,preorder+length-1,inorder,inorder+length-1);
    }
      
    TreeNode* Construct(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
    {
        int rootValue=startPreorder[0];
        TreeNode* root=new TreeNode(rootValue);
        int* rootInorder=startInorder;
        while(rootInorder<=endInorder&&*rootInorder!=rootValue)
            ++rootInorder;
        int leftLength=rootInorder-startInorder;
        int* leftPreorderEnd=startPreorder+leftLength;
        if(leftLength>0)
        {
            root->left=Construct(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
        }
        if(leftLength<endPreorder-startPreorder)
        {
            root->right=Construct(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
        }
        return root;
    }
};
////////////////////////////////////////////////////////////////////////下面的解法就是多了注释的抛出异常
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        int length = pre.size();
        int* preorder = pre.data();
        int* inorder = vin.data();
        if(preorder==nullptr||inorder==nullptr)
            return nullptr;
        return Construct(preorder,preorder+length-1,inorder,inorder+length-1);
    }
      
    TreeNode* Construct(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
    {
        int rootValue=startPreorder[0];
        TreeNode* root=new TreeNode(rootValue);
//        TreeNode* root=new TreeNode();
//        root->val=rootValue;
//        root->left=root->right=nullptr;
//        if(startPreorder==endPreorder)
//        {
//            if(startInorder==endInorder&&*startPreorder==*startInorder)
//                return root；
//             else
//                 throw std::exception("Invalid input.");
//         }
          
        int* rootInorder=startInorder;
        while(rootInorder<=endInorder&&*rootInorder!=rootValue)
            ++rootInorder;
//        if(rootInorder==endInorder&&*rootInorder!=rootValue)
//            throw std::exception("Invalid input.");
        int leftLength=rootInorder-startInorder;
        int* leftPreorderEnd=startPreorder+leftLength;
        if(leftLength>0)
        {
            root->left=Construct(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
        }
        if(leftLength<endPreorder-startPreorder)
        {
            root->right=Construct(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
        }
        return root;
    }
};

///////////////////////////////////////////////////////////////总结
1.方法用递归
输入前序遍历序列、中序遍历序列
前序遍历序列第一个数字就是根节点的值，然后在中序遍历序列中找到根节点位置。
前序遍历序列 （根节点，左子树，右子树）
中序遍历序列（左子树，根节点，右子树）

重新把左子树、右子树的前序遍历序列和中序遍历序列拿去递归。

输入是vector还是数组int* int[]
(vector<int> pre,vector<int> vin)或(int* preorder,int* inorder,int length)

2.
指针/数组转换成vector：

        int* preorder = pre.data();
        int* inorder = vin.data();

vector转换成指针/数组：        

        int pre_size=pre.size();
        for(int i=0;i<pre_size;i++)
        pre.push_back(preorder[i]);
        
3.
指针的方法要确定左右子树的移动情况，比较容易搞晕。
参考解析中vector递归方法比较好理解，找出根节点位置，然后循环push左右子树的前序和中序。
        

////////////////////////////////////////////////////////////////牛客网参考解析

/* 先序遍历第一个位置肯定是根节点node，
 
  中序遍历的根节点位置在中间p，在p左边的肯定是node的左子树的中序数组，p右边的肯定是node的右子树的中序数组
 
  另一方面，先序遍历的第二个位置到p，也是node左子树的先序子数组，剩下p右边的就是node的右子树的先序子数组
 
  把四个数组找出来，分左右递归调用即可
 
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  
public:
  
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
  
        int in_size = in.size();
  
        if(in_size == 0)
  
            return NULL;
  
        vector<int> pre_left, pre_right, in_left, in_right;
  
        int val = pre[0];
  
        TreeNode* node = new TreeNode(val);//root node is the first element in pre
  
        int p = 0;
  
        for(p; p < in_size; ++p){
  
            if(in[p] == val) //Find the root position in in
  
                break;
  
        }
  
        for(int i = 0; i < in_size; ++i){
  
            if(i < p){
  
                in_left.push_back(in[i]);//Construct the left pre and in
  
                pre_left.push_back(pre[i+1]);//!!!!!!!!!!!!!!!!!!!!!注意该处pre[0]是根节点的值，左子树第一个值是pre[1]，所以用pre[i+1]
  
            }
  
            else if(i > p){
  
                in_right.push_back(in[i]);//Construct the right pre and in
  
                pre_right.push_back(pre[i]);
  
            }
  
        }
  
        node->left = reConstructBinaryTree(pre_left, in_left);
  
        node->right = reConstructBinaryTree(pre_right, in_right);
  
        return node;
  
    }
  
};
