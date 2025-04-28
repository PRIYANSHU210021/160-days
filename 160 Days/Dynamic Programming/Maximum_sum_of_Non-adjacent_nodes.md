Problem: https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1?_gl=1*bt1231*_up*MQ..*_gs*MQ..&gclid=CjwKCAjwn6LABhBSEiwAsNJrjhbrZxhsyBlxbi7pbkO_LnsWgtga1y52tegFxak6KHEhj1qTZD1eCxoCL-IQAvD_BwE&gbraid=0AAAAAC9yBkDqLQjO9BONlOTP_a_a6SZDV

Code: 
 unordered_map<Node*,int>mp;
class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        if(root== NULL) 
        return 0;
        if(mp[root]) 
        return mp[root];
        int withroot = root->data;
        
        if(root->left){
            withroot+= getMaxSum(root->left->left);
            withroot+= getMaxSum(root->left->right);
        }
        
        if(root->right){
            withroot+= getMaxSum(root->right->left);
            withroot+= getMaxSum(root->right->right);
        }
        int withoutroot = getMaxSum(root->left) + getMaxSum(root->right);
        return mp[root] = max(withroot, withoutroot);
        
        
    }
};
