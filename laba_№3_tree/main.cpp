#include <bits/stdc++.h>
#define isz(x) (int)x.size()

using namespace std;

struct Node{ // структура дл€ представлени€ узлов дерева;
	int key;
	int size;
	Node* left;
	Node* right;
	Node(int k) { key = k; left = right = nullptr; size = 1;}
	~Node(){
        if (left){
            delete left;
        }
        if (right){
            delete right;
        }
	}
};
Node* find(Node* root, int key){ // поиск ключа key
    if(!root){
        std::cout << "Ёлемент не найден!\n";
        return 0; // в пустом дереве можно не искать
    }
    if( key == root->key){
        std::cout << "Ёлемент найден\n";
        return root;
    }
    if(key < root->key){
        return find(root->left,key);
    }
    else{
        return find(root->right,key);
    }
}

int getsize(Node* root){ // обертка дл€ пол€ size, работает с пустыми деревь€ми (t = NULL)
	if(!root){
        return 0;
	}
	return root->size;
}

void fixsize(Node* root){ // установление корректного размера дерева
	root->size = getsize(root->left) + getsize(root->right) + 1;
}


Node* rotateright(Node* p){ // правый поворот вокруг узла p
	Node* q = p->left;
	if(!q){
        return p;
	}
	p->left = q->right;
	q->right = p;
	q->size = p->size;
	fixsize(p);
	return q;
}

Node* rotateleft(Node* q){ // левый поворот вокруг узла q
	Node* p = q->right;
	if( !p ){
        return q;
	}
	q->right = p->left;
	p->left = q;
	p->size = q->size;
	fixsize(q);
	return p;
}

Node* insertroot(Node* root, int key){ // вставка нового узла с ключом key в корень дерева
	if(!root){
        return new Node(key);
	}
	if(key < root->key){
		root->left = insertroot(root->left,key);
		return rotateright(root);
	}
	else{
		root->right = insertroot(root->right,key);
		return rotateleft(root);
	}
}

Node* insert(Node* root, int key){ // рандомизированна€ вставка нового узла с ключом key в дерево
	if(!root){
        return new Node(key);
	}
	if(rand() % (root->size + 1) == 0){
		return insertroot(root,key);
	}
	if(root->key > key){
		root->left = insert(root->left,key);
	}
	else{
		root->right = insert(root->right,key);
    }
    fixsize(root);
	return root;
}
Node* join(Node* p, Node* q){ // объединение двух деревьев
	if(!p){
        return q;
	}
	if(!q){
        return p;
	}
	if(rand() % (p->size + q->size) < p->size){
        p->right = join(p->right,q);
        fixsize(p);
        return p;
	}
	else{
		q->left = join(p,q->left);
		fixsize(q);
		return q;
	}
}

Node* remove(Node* root, int key){ // удаление из дерева первого найденного узла с ключом key
	if(!root){
        return root;
	}
	if( root->key == key){
		Node* q = join(root->left,root->right);
		delete root;
		return q;
	}
	else if(key < root->key){
		root->left = remove(root->left,key);
	}
	else{
		root->right = remove(root->right,key);
	}
	return root;
}


void convert(Node* root){ // перевод классического двоичного дерева поиска, в левого сына правого брата
    if (root == nullptr) { // если дерево пустое, выходим
        return;
    }
    // сначала рекурсирвно преобразуем левое поддерево
    convert(root->left);
    convert(root->right);
    if (root->left == nullptr){ // если левый дочерний элемент пуст, указываем его на правый дочерний элемент и говорим, что у правого дочернего элемента теперь ничего нет
        root->left = root->right;
        root->right = nullptr;
    }
    else { // если левый потомок уже существует, то нужно создать его правого потомка: указать на правый дочерний элемент текущего узла и установить дл€ правого дочернего элемента nullptr
        root->left->right = root->right;
        root->right = nullptr;
    }
}
void pred(Node* root){ // пр€мой обход дерева
    std::cout << root->key << ' ';
    if (root->left)
        pred(root->left);
    if (root->right)
        pred(root->right);
}
void post(Node* root){ // обратный обход дерева
    if (root->left){
        post(root->left);
    }
    if (root->right){
        post(root->right);
    }
    std::cout << root->key << ' ';
}

void sym(Node *root){ // симметричный обход дерева
    if (root->left){
        sym(root->left);
    }
    std::cout << root->key << ' ';
    if (root->right){
        sym(root->right);
    }
}

void post(Node *root,set <int> vertex_in_tree_a){
    if (root->left){

    }
}
int main(){
    system("chcp 1251");
    std::cout << "¬ведите количество вершин дерева, которые будут случайно сгенерированы - ";
    int n;
    std::cin >> n;
    set <int> vertex_in_treeA;
    set <int> vertex_in_treeB;
    for (int i = 0;i < n;i++){
        int x = rand() % 30000;
        vertex_in_treeA.insert(x);
    }
    for (int i = 0;i < n;i++){
        int x = rand() % 40000;
        vertex_in_treeB.insert(x);
    }
    Node tree_a(*vertex_in_treeA.begin());
    Node tree_b(*vertex_in_treeB.begin());
    int temp_a = *vertex_in_treeA.begin();
    int temp_b = *vertex_in_treeB.begin();
    vertex_in_treeA.erase(vertex_in_treeA.begin());
    vertex_in_treeB.erase(vertex_in_treeB.begin());
    for (auto cur_vertex : vertex_in_treeA){
        insert(&tree_a,cur_vertex);
    }
    for (auto cur_vertex : vertex_in_treeB){
        insert(&tree_b,cur_vertex);
    }
    vertex_in_treeA.insert(temp_a);
    vertex_in_treeB.insert(temp_b);
    convert(&tree_a);
    convert(&tree_b);
    std::cout << "ќбратный обход дерева A:\n";
    post(&tree_a);
    std::cout << "\n—имметричный обход дерева B:\n";
    sym(&tree_b);
    std::cout << "\n";
    set <int> vertex_in_treeC;
    for (auto cur : vertex_in_treeA){
        if (!vertex_in_treeB.count(cur)){
            vertex_in_treeC.insert(cur);
        }
    }
    Node tree_c(*vertex_in_treeC.begin());
    vertex_in_treeC.erase(*vertex_in_treeC.begin());
    for (auto cur_vertex : vertex_in_treeC){
        insert(&tree_c,cur_vertex);
    }
    std::cout << "ѕр€мой обход дерева C (результат A / B):\n";
    pred(&tree_c);
}
