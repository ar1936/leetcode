class Node {
public:
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
public:
    Trie() {
        
    }
    Node* root=new Node();
    void insert(string word) {
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])==false){
                node->put(word[i], new Node());
            }
            node = node -> get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])==false){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->containKey(prefix[i])==false)
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */