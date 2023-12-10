#include<bits/stdc++.h>
using namespace std;

struct vertex{
  int value;
  vector<vertex*> child;
  vector<int> weight;
};

void insert(vertex* root, vector<int> v){
  if(size(v)==0){
    return;
  }

  for(int i=0; i<size(root->child); ++i){
    if(root->child[i]->value == v.front()){
      insert(root->child[i], vector<int>{v.begin()+1,v.end()});
      ++(root->weight[i]);
      return;
    }
  }

  root->child.push_back(new vertex{v.front()});
  root->weight.push_back(0);
  insert(root->child.back(), vector<int>{v.begin()+1,v.end()});
}

void delete_prefix_tree(vertex* root){
  if(!root){
    return;
  }
  
  for(int i=0; i<size(root->child); ++i){
    delete_prefix_tree(root->child[i]);
  }

  delete root;
}

int closeness(vertex* root, int level=1){
  if(!root){
    return 0;
  }

  bool z=1;
  for(int i=0; i<size(root->child); ++i){
    if(root->weight[i]!=0){
      z=0;
      break;
    }
  }

  if(z){
    return level-1;
  }

  int c=0;
  for(int i=0; i<size(root->child); ++i){
    c+=root->weight[i]*closeness(root->child[i],level+1);
  }

  return c;
}

int main(void){
  int n;
  cin>>n;

  vector<vector<int>> A;
  for(int i=0; i<n; ++i){
    int k;
    cin>>k;
    A.emplace_back(k);
    for(int j=0; j<k; ++j){
      cin>>A[i][j];
    }
  }

  auto root=new vertex{numeric_limits<int>::min()};
  for(int i=0; i<n; ++i){
    insert(root, A[i]);
  }

  cout<<closeness(root);
  delete_prefix_tree(root);
}
