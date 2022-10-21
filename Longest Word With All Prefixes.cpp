// Q. Longest Word With All Prefixes
//LINK : https://leetcode.com/problems/longest-word-with-all-prefixes/description/
//Given an array of strings words, find the longest string in words such that every prefix of it is also in words.
// For example, let words = ["a", "app", "ap"]. The string "app" has prefixes "ap" and "a", all of which are in words.
// Return the string described above. If there is more than one string with the same length, return the lexicographically smallest one, and if no string exists, return "".
// Example 1:
// Input: words = ["k","ki","kir","kira", "kiran"]
// Output: "kiran"
// Explanation: "kiran" has prefixes "kira", "kir", "ki", and "k", and all of them appear in words.
// Example 2:
// Input: words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// Output: "apple"
// Explanation: Both "apple" and "apply" have all their prefixes in words.
// However, "apple" is lexicographically smaller, so we return that.
// Example 3:
// Input: words = ["abc", "bc", "ab", "qwe"]
// Output: ""

//SOLUTION  :
struct Node{
    Node* links[26];
    bool flag=false;

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
class Trie{
private: 
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(auto &c:word){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    bool checkPrefixExists(string word){
        Node* node = root;
        bool flag = true;
        for(auto &c:word){
            if(node->containsKey(c)){
                node=node->get(c);
                if(!node->isEnd())
                    return false;
            }
            return false;
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto &w:words){
            trie.insert(w);
        }
        string res;
        for(auto &w:words){
            if(trie.checkPrefixExists(w)){
                if(w.size()>res.size())
                    res = w;
                else if(w.size()==res.size() && w<res){
                    res = w;
                }
            }
        }
        return res;
    }
};