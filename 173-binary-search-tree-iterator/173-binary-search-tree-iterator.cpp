
class BSTIterator {
    vector<int> v;
    int i;
    void inorder(TreeNode* root){
        if(root==NULL)
            return ;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return ;
    }
public:
    BSTIterator(TreeNode* root) {
        i=-1;
        inorder(root);
    }
    
    int next() {
        //if(hasNext())
        return v[++i];
        //return v[i];
    }
    
    bool hasNext() {
        cout<<i<<' ';
        if(v.size()-1==i)
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */