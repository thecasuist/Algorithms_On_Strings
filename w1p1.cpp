#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
  int idx;
  Node *next[256];
  Node(){
    idx = -1;
    for(int i = 0; i < 256; i++){
      next[i] = NULL;
    }
  }
} Node;

class Trie{
  Node *root;
  int size;
  public:
  Trie();
  Node *getRoot();
  void addString(string &s);
  void display();
};

Trie::Trie(){
  root = new Node;
  root->idx = 0;
  size = 1;
}

Node *Trie::getRoot(){
  return root;
}

void Trie::addString(string &s){
  int curr_idx = 0;
  Node *curr_node = root, *temp_node = NULL;
  while(curr_idx < s.size() && curr_node->next[(int)s[curr_idx]] != NULL){
    curr_node = curr_node->next[(int)s[curr_idx]]; 
    curr_idx++;
  }
  while(curr_idx < s.size()){
    temp_node = new Node;
    temp_node->idx = size++;
    curr_node->next[(int)s[curr_idx]] = temp_node;
    curr_node = curr_node->next[(int)s[curr_idx]];
    curr_idx++;
  }
}

void Trie::display(){
  stack<Node*> s;
  s.push(root);
  while(!s.empty()){
    Node *curr_node = s.top();
    s.pop();
    for(int i = 0; i < 256; i++){
      if(curr_node->next[i] != NULL){
        cout << curr_node->idx << "->" << curr_node->next[i]->idx << ":" << (char)i;
        cout << endl;
        s.push(curr_node->next[i]);
      }
    }
  }
}

void solve(vector<string> &p){
  Trie t;
  for(int i = 0; i < p.size(); i++){
    t.addString(p[i]);
  }
  t.display();
}

int main(){
  int n;
  cin >> n;
  vector<string> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  solve(p);
  return 0;
}
