// Q. Implement Trie (Prefix Tree)
// LINK : https://leetcode.com/problems/implement-trie-prefix-tree/description/
//A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
// Implement the Trie class:
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
// Example 1:
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

//SOLUTION 
struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto &c : word){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto &c:word){
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto &c:prefix){
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return true;
    }
};