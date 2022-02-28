/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #include<queue>
    #define lli long long int
    int widthOfBinaryTree(TreeNode* root) {
        /*if(root==NULL)
            return 0;
        queue<pair<TreeNode*,int>> pendingNodes;
        pendingNodes.push(root);
        int n=1;
        int maxWidth=0;
        int childCount=0;
        
        while(!pendingNodes.empty()){
            vector<int> children;
            while(n--){
                TreeNode* front=pendingNodes.front();
                pendingNodes.pop();
                if(front->left){
                        
                        pendingNodes.push(front->left);
                        
                }   
                if(front->right){       
                        pendingNodes.push(front->right);
                }   
            }
            
        }
        
        return maxWidth;*/
        /* queue<pair<TreeNode*,int>> pendingNodes;
        if(root!=NULL)
            pendingNodes.push({root,0});
        
        int n=1;
        int maxWidth=-9999;
        int childCount=0;
        
        while(!pendingNodes.empty()){
            int lmax=0;
            int rmax=0;
            
            while(n--){
                
                pair<TreeNode*,long long int> front=pendingNodes.front();
                if(lmax==0){
                    lmax=front.second;
                }
                if(front.second>rmax)
                    rmax=front.second;
                pendingNodes.pop();
                
                if(front.first->left!=NULL){
                    long long int li=2*(front.second)+1;
                    pendingNodes.push({front.first->left,li});
                    childCount++;
                }
                if(front.first->right!=NULL){
                    long long int ri=2*(front.second)+2;
                    pendingNodes.push({front.first->right,ri});  
                    childCount++;
                }
                
                
            }    
            int n=childCount;
            childCount=0;
            int width=rmax-lmax+1;
            if(width>maxWidth)
                maxWidth=width;
        }
        
        //find position of first and last not null node and subtract
        //keep adding them to 
        
        
        
        return maxWidth;*/
        queue<pair<TreeNode*,lli>> pendingNodes;
        
        if(root!=NULL){
            pendingNodes.push({root,0});     
        }
        
        lli maxWidth=0;
        while(!pendingNodes.empty()){
            lli count=pendingNodes.size();
            lli rmax=-1;
            lli lmax=-1;
            for(lli i=0;i<count;i++){
                pair<TreeNode*,lli> front=pendingNodes.front();
                pendingNodes.pop();
                if(i==0)
                    lmax=front.second;
                rmax=front.second;
                if(front.first->left!=NULL){
                    lli li=2*(front.second-lmax)+1;
                    pendingNodes.push({front.first->left,li});
                }
                if(front.first->right!=NULL){
                    lli ri=2*(front.second-lmax)+2;
                    pendingNodes.push({front.first->right,ri});
                }
                
                
            }
            
            lli width=rmax-lmax+1;
            if(width>maxWidth)
                maxWidth=width;
            
        }
        return maxWidth;
        
        
        
        
        
    }
    
};