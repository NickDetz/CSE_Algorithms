// Collaborated with Tristan Fong
#include <iostream>
#include <vector>
#include <queue>
#include <string>
//#includes array

using namespace std;
//int Sentinal 289674565;

class Node {
public:
    //making class Variables for the
    //int arr[]
    char key;
    //int size
    int freq;
    string freqcd;
    Node* right;
    Node* left;
    
    

    Node () {
      right = NULL;
      left = NULL;
    }
    //node of the Frequncey
    Node(char k, int f) {
      this->key = k;
      this->freq = f;
      right = NULL;
      left = NULL;
    }
    //Node of the Value
    Node (const Node &n) {
      key = n.key;
      freq = n.freq;
      freqcd = n.freqcd;
      right = n.right;
      left = n.left;
    }

    virtual ~Node() {}
};

class compare {
public:
    int operator () (const Node& n, const Node& node2){
      return n.freq > node2.freq;
    }};
// Huffman check algorith to use Greedy algorithm in the theifknapsack problem foun on page 425
void setCodes(Node *root, string freqcd, vector<Node>& v) {
    string str1 = freqcd;
    string str2 = freqcd;
    if (!root)
      return;
    if (!root->left && !root->right) {
      int temp = int(root->key - 'A');
      v[temp].freqcd = freqcd;
    } else {
      str1.append("0");
      root->left->freqcd = str1;
      setCodes(root->left, str1, v);

      str2.append("1");
      root->right->freqcd = str2;
      setCodes(root->right, str2, v);
    }
}
// Huffman algorithm found on page 431
void Huffman (vector<Node>& v, int size) {
    priority_queue <Node, vector<Node>, compare> Q;

    for (int i = 0; i < size; i++) {
        Q.push(v[i]);
    }
    for (int i = 1; i <= size - 1; i++) {
        Node newNode;
        newNode.left = new Node(Q.top());
        Q.pop();
        newNode.right = new Node(Q.top());
        Q.pop();
        newNode.freq = newNode.right->freq + newNode.left->freq;
        Q.push(newNode);
    }
    setCodes(new Node(Q.top()), "", v);
}
// Code starts here
int main() {
    // cin >> length
    // char[] {"A" , "B" , "C" , "D", "E" , "F", }
    // Array size = [6]
    // Note to self C++ 11 sucks and doesn't use convertions so fuck this
    int n = 6;
    vector <Node> v;

    for (int i = 0; i < n; i++) {
      int frequency;
      cin >> frequency;
      Node newNode (char ('A' + i), frequency);
      v.push_back(newNode);
    }
    Huffman (v, n);

    for (int i = 0; i < n; i++)
      cout << v[i].key << ":" << v[i].freqcd << endl;
}
