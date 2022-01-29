class WordDictionary {
public:
    
    struct Node{
        bool end = false;
        Node* children[26];
        Node(){
            end = false;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }
    };
    
    Node* root = new Node();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* pCrawl = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            if(pCrawl->children[idx]==NULL){
                pCrawl->children[idx] = new Node();
            }
            pCrawl = pCrawl->children[idx];
        }
        pCrawl->end = true;
    }
    
    bool searchUtil(string word, Node* root, int depth){
        if(!root)
            return NULL;
        if(depth == word.size()){
            if(root->end)
                return true;
            return false;
        }
        
        bool res = false;
        
        if(word[depth]=='.'){
            for(int i=0; i<26; i++){
                if(root->children[i]){
                    res = res || searchUtil(word, root->children[i], depth+1);
                }
            }
            return res;
        
        }
        
        int idx = word[depth]-'a';
        
        if(root->children[idx]){
            return searchUtil(word, root->children[idx], depth+1);
        }
        return false;
    }
    
    bool search(string word) {
        return searchUtil(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */