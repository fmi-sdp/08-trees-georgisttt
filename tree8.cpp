// tree8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

struct nodem {
    int data;
    vector<nodem*> children;
    nodem(int _data , vector<nodem * > _children={}) : data(_data), children(_children) {}
};

struct node {
    int  val;
    node* left;
    node* right;
    node(int _val = 0, node* _left = nullptr, node* _right = nullptr) : val(_val), left(_left), right(_right) {}

};
/*in-order (left, root, right)
pre-order (root, left, right)
post-order (left, right, root)*/

void outinorder(node* root) {
    if (!root) return;

    outinorder(root->left);
    cout << root->val << endl;
    outinorder(root->right);
    return;


}
void outpreorder(node* root) {
    if (!root) return;

    cout << root->val << endl;
    outpreorder(root->left);
    outpreorder(root->right);
    return;


}

void outpostorder(node* root) {
    if (!root) return;

    
    outpostorder(root->left);
    outpostorder(root->right);
    cout << root->val << endl;

    return;


}
bool isleaf(node* root) {

    if (root->left == nullptr && root->right == nullptr) return true;
    else return false;

}
void trim(node* root) {

    if (root == nullptr) return;
    if (isleaf(root->left)) {delete root->left;  root->left = nullptr;
}
    if (isleaf(root->right)) {
        delete root->right; root->right = nullptr;
    }

    trim(root->left);
    trim(root->right);
    return;




}

void bloom(node* root) {
    if (root== nullptr) return;
    if (isleaf(root)) { root->left = new node{ root->val };root->right= new node{ root->val } ; return;}

    bloom(root->left);
    bloom(root->right);

}

void out(nodem* root) {
    if (root == nullptr) return;

    std::cout << root->data << endl;
    for (int i = 0; i < root->children.size(); ++i) {

        out(root->children[i]);


    }
    return;
}


int rask(nodem * root) {
    if (root == nullptr) return 0;
    int size = root->children.size();
    int temp = size;
    for (int i = 0; i < size; ++i) {
        temp = max(temp, rask(root->children[i]));
    }
    return temp;


}


void printlevel(nodem* root, int h) {

    if (root == nullptr) return;
    if (h == 0) {
        std::cout << root->data; 
        return;
    }
    for (int i = 0; i < root->children.size(); ++i) {

        printlevel(root->children[i], h - 1);



    }
    return;

}


int numberlief(nodem* root) {
    if (root == nullptr) return 0;
    if (root->children.empty())return 1;
    int temp = 0;
    for (int i = 0; i < root->children.size(); ++i) {

       temp+= numberlief(root->children[i]);


    }
    return temp;



}









int main(){
    /*
    node* s1 = new node{ 3 , new node {4 } , new node{1 , new node {2} , new node{0}} };
    cout << "out" << endl;
    outinorder(s1);

    cout << "tirm" << endl;
    trim(s1);
    outinorder(s1);
    cout << "bloom" << endl;
    bloom(s1);
    outinorder(s1);
    */

    nodem* s1 = new nodem{ 0 , {new nodem {3} , new nodem {4} , new nodem {7, {new nodem {2} , new nodem {10}  } } } };
   // out(s1);

    //std::cout << rask(s1);
   // printlevel(s1, 5);
    cout<<numberlief(s1);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
