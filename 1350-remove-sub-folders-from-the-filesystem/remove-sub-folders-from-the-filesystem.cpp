class Solution {
public:

    class trienode
    {
        public:
        trienode *child[27];
        bool check;
        trienode()
        {
            for(int i=0;i<27;i++)
                child[i] = nullptr;
            check = false;
        }
    };
    class trie
    {
        public:
        trienode *root;
        trie()
        {
            root = new trienode();
        }
        void insert(string s)
        {
            trienode *node = root;
            int n = s.size();
            for(int i=0;i<n;i++)
            {
                int bit = s[i] - 'a';
                if(bit == -50)
                    bit = 26;
                if(node->child[bit] == nullptr)
                        node->child[bit] = new trienode();
                node = node->child[bit];
            }
            node->check = true;
        }
        int search(string s)
        {
            trienode *node = root;
            int n = s.size();
            int i=0;
            for(    ;i<n;i++)
            {
                int bit = s[i] - 'a';
                if(bit == -50)
                    bit = 26;
                if(node->child[bit])
                    node = node->child[bit];
                else
                    return i;
                if(node->check)
                {
                    if(i==n-1){return i;}

                    if(i<n-1 && s[i+1] == '/')
                        return i;
                }
            }
            return i;
        }
    };
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        int n = folder.size();
        vector<string> vec;
        trie node;
        for(string &s:folder)
            node.insert(s);
        for(string &s:folder)
            if(node.search(s) + 1 == s.size())
                vec.push_back(s);
        return vec;
    }
};