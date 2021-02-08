//Find the kth largest element
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int> , greater<int>>minh;
    vector<int>v;
    int k=2;
    v.push_back(10);
    v.push_back(3);
    v.push_back(50);
    v.push_back(12);
    v.push_back(25);
    v.push_back(100);
    v.push_back(70);
    for(auto x:v){
        minh.push(x);
        if(minh.size()>k){
            minh.pop();
        }
    }
    cout<<minh.top();
    return 0;
}*/

//Find the kth smallest element
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int>maxh;
    vector<int>v;
    int k=2;
    v.push_back(10);
    v.push_back(3);
    v.push_back(50);
    v.push_back(12);
    v.push_back(25);
    v.push_back(100);
    v.push_back(70);
    for(auto x:v){
        maxh.push(x);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    cout<<maxh.top();
    return 0;
}*/

//Sort a k sorted array
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
    priority_queue<int,vector<int>,greater<int>>minh;
    v.push_back(6);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(8);
    v.push_back(10);
    v.push_back(9);
    int k=3;
    for(auto x:v){
        minh.push(x);
        if(minh.size()>k){
            cout<<minh.top()<<" ";
            minh.pop();
        }
    }
    while(!minh.empty()){
        cout<<minh.top()<<" ";
        minh.pop();
    }
    return 0;
}*/

//Find k closest number
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<pair<int,int>>maxh;
    vector<int>v;
    int ele=7,k=3;
    v.push_back(14);
    v.push_back(50);
    v.push_back(7);
    v.push_back(10);
    v.push_back(90);
    for(auto x:v){
        maxh.push({abs(x-7) , x});
        if(maxh.size()>3){
            maxh.pop();
        }
    }
    while(maxh.size()!=0){
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
    return 0;
}*/

//Top k frequent number
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
    int k=2;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(4);
    unordered_map<int , int>um;
    for(auto it=v.begin();it!=v.end();it++){
        um[*it]++;
    }
    priority_queue<pair<int,int> , vector<pair<int , int>> , greater<pair<int , int>>>minh;
    for(auto i=um.begin();i!=um.end();i++){
        minh.push({i->second , i->first});
        if(minh.size()>k){
            minh.pop();
        }
    }
    while(minh.size()>0){
        cout<<minh.top().second<<" ";
        minh.pop();
    }
    return 0;
}*/

//sum of elements between k1th smallest & k2nd smallest element
/*a[]=1 3 12 5 15 11
k1=2
k2=5
1 3 5 11 12 15
Ans. 11+5=16 */

//Connect ropes to minimize the cost

//Closest point to the origin
/*#include<bits/stdc++.h>
#define pi pair<int , pair<int , int>>
using namespace std;
int main(){
    int n=4,k=2;
    int a[n][2]={{1,3} , {1 , 0} , {5 , 8} , {0 , 1}};
    priority_queue<pi>maxh;
    for(int i=0;i<n;i++){
        maxh.push({(a[i][0]*a[i][0])+(a[i][1]*a[i][1]) , {a[i][0] , a[i][1]}});
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    while(maxh.size()>0){
        cout<<maxh.top().second.first<<" "<<maxh.top().second.second<<endl;
        maxh.pop();
    }
    return 0;
}*/

//Maximum of all subarrays with size k 
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=3;
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    int n=v.size();
    priority_queue<int>maxh;
    maxh.push(v[0]);
    maxh.push(v[1]);
    for(int i=2;i<n;i++){
        maxh.push(v[i]);
        cout<<maxh.top()<<" ";
    }
    return 0;
}*/

//Reorganizing the string (LeetCode)
/*#include<bits/stdc++.h>
using namespace  std;
int main(){
    string a="aabbcd";
    unordered_map<int , int> um;
    for(auto x:a){
        um[x]++;
    }
    priority_queue<pair<int , int>>maxh;
    for(auto it:um){
        maxh.push({it.second , it.first});
    }       
    pair<int, int>temp1,temp2;
    string s;
    while(maxh.size()!=0){
        temp1=maxh.top();
        maxh.pop();
        s+=temp1.second;
        //cout<<s<<" "<<endl;
        while(maxh.size()!=0){
            temp2=maxh.top();
            maxh.pop();
            s+=temp2.second;
            if(temp2.first>1){
                maxh.push({temp2.first-1  , temp2.second});
            }
        }
        if(temp1.first>1){
            maxh.push({temp1.first-1  , temp1.second});
        }
    }
    bool flag=true;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            cout<<"NO";
            flag=false;
        }
    }
    if(flag){
        cout<<s<<endl;
    }
    return 0;
}*/

//Convert a BST to minheap
/*#include<bits/stdc++.h>
using namespace std;
int i=0,k=0;
int a[6];
class node{
    public:
        int data;
        node *left;
        node *right;
        node(int n){
            data=n;
            left=right=NULL;
        }
};

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        //cout<<root->data<<" ";
        a[i]=root->data;
        i++;
        inorder(root->right);
    }
    
}

void preorder(node *root){
    if(root!=NULL){
        root->data=a[k];
        k++;
        preorder(root->left);
        preorder(root->right);
    }
}

void inordervisit(node *root){
    if(root!=NULL){
        inordervisit(root->left);
        cout<<root->data<<" ";
        inordervisit(root->right);
    }
}


int main(){
    node *root=new node(4);
    root->left=new node(2);
    root->right=new node(6);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->left=new node(5);
    root->right->right=new node(7);
    inordervisit(root);
    cout<<endl;
    inorder(root);
    preorder(root);
    inordervisit(root);
    cout<<endl;
    return 0;
}*/

//Minimum sum of two numbers formed from digits of an array
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
    priority_queue<int , vector<int> , greater<int>> minh;
    //int sum1=0,sum2=0;
    v.push_back(5);
    v.push_back(3);
    v.push_back(0);
    v.push_back(7);
    v.push_back(4);
    //v.push_back(3);
    int sum1=0,sum2=0;
    for(auto x:v){
        minh.push(x);
    }
    while(minh.size()>0){
        cout<<minh.top();
        //cout<<minh.top()<<" ";
       // sum1=(sum1*10)+minh.top();
        //cout<<sum1<<" ";
        //cout<<minh.top()<<" ";
        minh.pop();
        cout<<minh.top();
        //cout<<minh.top()<<" ";
        //sum2=(sum2*10)+minh.top();
        //cout<<minh.top()<<endl;
        //cout<<sum2<<endl;
        minh.pop();
    }
    cout<<sum1+sum2;
    return 0;
}
