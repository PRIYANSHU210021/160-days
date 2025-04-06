# Problem: Topological sort
## **For a better understanding, the prerequisite is that you should know DFS very well.**
# Code: 

```c++
class Solution {
  public:
    void dfsTOPO(int node,vector<vector<int>>&Adj,stack<int>&st,vector<int>&visited)
    {
        visited[node] = 1;   
        for(int i=0; i<Adj[node].size(); i++)
        {
            if(visited[Adj[node][i]]==0)
                dfsTOPO(Adj[node][i],Adj,st,visited);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges){
        vector<vector<int>>Adj(V);
        vector<int>visited(V,0);
        stack<int>st;
        for(auto x:edges)
            Adj[x[0]].push_back(x[1]);
        
        for(int i=0; i<V; i++)
        {
            if(visited[i]==0)
                dfsTOPO(i,Adj,st,visited);
        }
        vector<int>res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```



You're managing a **course schedule** for a college.

- Each course is a **node**.
- If course A is a prerequisite for course B, you draw a **directed edge** from A → B.

Now, your job is to **find an order to take the courses** so that you **never take a course before its prerequisite**.

This is exactly what **topological sorting** does!

---

###  DFS Intuition:

Let’s say you start from a random course (node) and go as deep as you can into its prerequisites.

Here's how you **think like DFS**:

1. "Can I go deeper from this course? Yes? Okay, I’ll go."
2. Keep doing that until you hit a course with **no further prerequisites**.
3. That course is **ready** to be taken — put it into the **stack**.
4. Then go back up one level and ask: “Okay, are **all** my dependencies done?” If yes — push that one too.
5. Keep doing this for all courses.

So, the **last course you finish**, goes to the **bottom of the stack**, and the **first one you finish** goes to the **top**.

---

###  Why use a Stack?

Because:
- Courses (nodes) are completed in **reverse order** of how you finish them.
- That’s why you **push after exploring all children**, and then later **pop** to get the final order.

---

###  One-liner Intuition:

> "**Do all the hard stuff first (children), then do yourself (push node).** That’s the DFS way of topological sort."

---

###  Final Result

When you're done:
- Pop from the stack.
- You’ll get an order where **every course appears only after all its prerequisites** — exactly what you wanted!
