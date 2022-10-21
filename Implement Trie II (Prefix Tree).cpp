// Q.Implement Trie II (Prefix Tree)
//LINK: https://leetcode.com/problems/implement-trie-ii-prefix-tree/description/
//A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
// Implement the Trie class:
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
// int countWordsStartingWith(String prefix) Returns the number of strings in the trie that have the string prefix as a prefix.
// void erase(String word) Erases the string word from the trie.
 // Example 1:
// Input
// ["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsStartingWith"]
// [[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]
// Output
// [null, null, null, 2, 2, null, 1, 1, null, 0]

//SOLUTION : 
struct Node{
    Node* links[26];
    int prefix=0;
    int endsWith=0;

    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void increasePrefix(){
        prefix++;
    }
    void increaseEndsWith(){
        endsWith++;
    }
    void reducePrefix(){
        prefix--;
    }
    void deleteEnd(){
        endsWith--;
    }
    int getEndsWith(){
        return endsWith;
    }
    int getPrefix(){
        return prefix;
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
        for(auto &c:word){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }
            node = node->get(c);
            node->increasePrefix();
        }
        node->increaseEndsWith();
    }
    
    int countWordsEqualTo(string word) {
        Node* node = root;
        for(auto &c:word){
            if(node->containsKey(c)){
                node = node->get(c);
            }
            else{
                return 0;
            }
        }
        return node->getEndsWith();
    }
    
    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for(auto &c:prefix){
            if(node->containsKey(c)){
                node = node->get(c);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }
    
    void erase(string word) {
        Node* node = root;
        for(auto &c:word){
            if(node->containsKey(c)){
                node = node->get(c);
                node->reducePrefix();
            }
            else
                return;
        }
        node->deleteEnd();
    }
};