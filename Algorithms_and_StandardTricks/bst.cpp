 

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree * right;
    struct tree * left;
    struct tree * parent;
}tree;

tree * root = NULL;

void insert() {
    tree * temp = (tree*)malloc(sizeof(tree));
    scanf ("%d", &temp->data);
    temp->right = NULL;
    temp->left = NULL;
    if (root == NULL){
        root=temp;
        root->parent=NULL;
    }
    else {
        tree * i = root;
        while (i != NULL){
            if (temp->data < i->data){
                if (i->left != NULL){
                    i= i->left;
                }
                else {
                    i->left = temp;
                    break;
                }
            }
            else {
                if (i->right != NULL){
                    i=i->right;
                }
                else {
                    i->right = temp;
                    break;
                }
            }
        }
        temp->parent=i;
    }
    return;
}

void inorder(tree * root) {
    if (root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return;
}

void preorder(tree * root) {
    if (root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void postorder ( tree * root) {
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
    return;
}

tree * successor (tree * temp){
    int val = temp->data;
    if (temp->right != NULL){
        temp=temp->right;
        while(temp->left != NULL){
            temp=temp->left;
        }
    }
    else {
        while (temp->data <= val){
            if (temp->parent == NULL){
                printf("No Successor\n");
                return NULL;
            }
            else {
                temp=temp->parent;
            }
        }
    }
    return temp;
}

tree * predecessor(tree * temp){
    int val = temp->data;
    if (temp->left != NULL){
        temp= temp->left;
        while(temp->right != NULL){
            temp=temp->right;
        }
    }
    else{
        while(temp->data >= val){
            if (temp->parent == NULL){
                printf("No predecessor\n");
                return NULL;
            }
            else {
                temp = temp->parent;
            }
        }
    }
    return temp;
}

tree * search (int val){
    tree * temp = root;
    while (temp->data != val) {
        if ((temp->right==NULL)&&(temp->left==NULL)){
            return NULL;
        }
        if (val < temp->data){
            temp=temp->left;
        }
        else {
            temp=temp->right;
        }
    }
    return temp;
}

void transplant(tree *u, tree *v){
    if (u->parent == NULL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
    return;
}

void delete (tree * node){
    if (node == NULL)
        return;
    if (node->left == NULL)
        transplant(node, node->right);
    else if (node->right == NULL)
        transplant(node, node->left);
    else{
        tree * temp = search(node->data);
        tree * suc = successor(node);
        if (suc->parent != node){
            transplant(suc, suc->right);
            suc->right = node->right;
            suc->right->parent = suc;
        }
        transplant(node, suc);
        suc->left = node->left;
        suc->left->parent = suc;
    }
    free(node);
    return;
}

int main(){
    int flag;
    int val;
    printf("0)Exit 1)Insert 2)Inorder 3)Preorder 4)Postorder 5)Search 6)Successor 7)Predecessor 8)Delete\n");
    scanf("%d", &flag);
    while (flag!=0){
        if (flag==1){
            insert();
        }
        else if (flag==2){
            inorder(root);
            printf("\n");
        }
        else if (flag==3){
            preorder(root);
            printf("\n");
        }
        else if (flag==4){
            postorder(root);
            printf("\n");
        }
        else if (flag == 5){
            printf("What to search? ");
            scanf("%d", &val);
            tree *node = search(val);
            if (node == NULL){
                printf("Does not exist\n");
            }
            else{
                printf("Exists\n");
            }
        }
        else if (flag==6){
            printf("Whose successor? ");
            scanf ("%d", &val);
            tree * node = search(val);
            tree * suc = successor(node);
            if (suc != NULL){
                printf("Successor: %d\n", suc->data);
            }
        }
        else if (flag==7){
            printf("Whose predecessor? ");
            scanf("%d", &val);
            tree * node = search(val);
            tree * pre = predecessor(node);
            if (pre != NULL){
                printf("Predecessor: %d\n", pre->data);
            }
        }
        else if (flag==8){
            printf("Value to be deleted: ");
            scanf ("%d", &val); 
            tree * node = search(val);
            delete (node);
        }
        printf("0)Exit 1)Insert 2)Inorder 3)Preorder 4)Postorder 5)Search 6)Successor 7)Predecessor 8)Delete\n");
        scanf("%d", &flag);
    }
}
