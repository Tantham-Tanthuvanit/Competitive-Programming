#include<bits/stdc++.h>
#define ULTRA ios_base::sync_with_stdio(false);cin.tie(NULL);
#define str string
using namespace std;

struct node{
    int data;
    node *left,*right;
};

int n;


unordered_map<int,int> pos; // keep idx from inorder

node* build(int pl,int pr,int il, int ir,vector<int>& pre,vector<int>& in){
    if(pl>pr || il>ir) return nullptr;
	
    int rVal = pre[pl];
    node* root = new node{rVal,nullptr,nullptr};

    int k=pos[rVal]; //pos in inorder
    int lsize = k-il;


    root->left = build(pl+1,pl+lsize,il,k-1,pre,in);
    root->right = build(pl+lsize+1,pr,k+1,ir,pre,in);

    return root;
     
}
void postorder(node *cur){
    if (cur==nullptr) return;
    postorder(cur->left);
    postorder(cur->right);
    cout << cur->data << ' ';
}

int main(){
    
    vector<int> in,pr;
    cin >> n;
    for(int i=0;i<n;i++){
        int k; cin >> k;
        pr.push_back(k);
    }
    for(int i=0;i<n;i++){
        int k; cin >> k;
        in.push_back(k);
    }

    for(int i=0;i<n;i++){
        pos[in[i]]=i;
    }

    node *root = build(0,n-1,0,n-1,pr,in);
    postorder(root);
}
