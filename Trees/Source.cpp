#include<iostream>
#include<string>
#include<queue>
using namespace std;
template<typename T>
class tnode {
public:
	T data;
	tnode<T>*llink;
	tnode<T>*rlink;
	tnode()
	{}
	tnode(const T &item, tnode<T>*lptr = NULL, tnode<T>*rptr = NULL) {}//:data(item),left(lptr),right(rptr){}
};
template<typename T>
void inorder(tnode<T>*t, const string&sprtr = " ") {
	if (t != NULL) {
		inorder(t->llink, sprtr);
		cout << t->data <<  sprtr;
		inorder(t->rlink, sprtr);
	}
}
template<typename T>
void preorder(tnode<T>*t, const string&sprtr = " ") {
	if (t != NULL) {
		cout << t->data << sprtr;
		preorder(t->llink, sprtr);
		preorder(t->rlink, sprtr);
	}
}
template<typename T>
void postorder(tnode<T>*t, const string&sprtr = " ") {
	if (t != NULL) {
		postorder(t->llink, sprtr);
		postorder(t->rlink, sprtr);
		cout << t->data << sprtr;
	}
}
template<typename T>
void levelorder(tnode<T>*t, const string&sprtr = " ") {
	queue<tnode<T>*>q;
	tnode <T>*p;
	q.push(t);
	while (!q.empty()) {
		p = q.front();
		q.pop();
		cout << p->data << sprtr;
		if (p->llink != NULL)
			q.push(p->llink);
		if (p->rlink != NULL)
			q.push(p->rlink);
	}
}
template<typename T>
void countleaf(tnode<T>*t, int &count) {
	if (t != NULL) {
		if (t->llink == NULL && t->rlink == NULL)
			count++;
		countleaf(t->llink, count);
		countleaf(t->rlink, count);
	}
}
template<typename T>
int depth(tnode<T>*t) {
	int depthleft, depthright, depthval;
	if (t == NULL)
		depthval = -1;
	else {
		depthleft = depth(t->llink);
		depthright = depth(t->rlink);
		depthval = 1 + (depthleft > depthright ? depthleft : depthright);
	}
	return depthval;
}
template<typename T>
void deletetree(tnode<T>*t) {
	if (t != NULL) {
		deletetree(t->llink);
		deletetree(t->rlink);
		delete t;
	}
}
template<typename T>
void cleartree(tnode<T>*&t) {
	deletetree(t);
	t = NULL;
}
template<typename T>
void buildtree(tnode<T>*&t) {
	T elem,elem2;
	int size;
	cout << "Enter the size of the tree : ";
	cin >> size;
	cout << "Enter your element : ";
	cin >> elem;
	t = new tnode<T>(d);
	while (size != 0) {
		cout << "Enter your element : ";
		cin >> elem2;
		if(elem2>elem)
			t = new tnode<T>(elem2,NULL,q);
		else
			t = new tnode<T>(elem2, NULL, q);



	}




}
int main() {
	
	typename tnode<int>*root;
	buildtree(root);
	preorder(root, " ");

}