#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int n;
string style;
int num;

struct Tree {
    int id;
    Tree *l;
    Tree *r;
};

stack<int> s;
vector<int> pre, in, post;

Tree *create(int preL, int preR, int inL, int inR) {
    //边界条件
    if (preL > preR) return NULL;

    //root 初始化
    Tree *root = new Tree;
    root->id = pre[preL];

    //找左子树root
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL]) break;

    }

    //左子树结点个数
    int numLeft = k - inL;

    //返回左子树根节点，递归
    root->l = create(preL + 1, preL + numLeft, inL, k - 1);
    //返回右子树根节点，递归
    root->r = create(preL + numLeft + 1, preR, k + 1, inR);

    return root;


}

int cnt = 0;

void postOrder(Tree *root) {
    if (root == NULL) return;
    postOrder(root->l);
    postOrder(root->r);
    printf("%d", root->id);
    cnt++;
    if (cnt < n) printf(" ");

}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> style;
        if (style == "Push") {
            cin >> num;
            pre.push_back(num);
            s.push(num);
        }
        else if (style == "Pop") {
            in.push_back(s.top());
            s.pop();
        }
    }
    Tree *t = create(0, n - 1, 0, n - 1);
    postOrder(t);
    return 0;
}
