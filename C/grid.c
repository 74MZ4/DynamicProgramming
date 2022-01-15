#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int w;
    int h;
    double res;
} Node;

typedef struct b_tree {
    struct b_tree * l;
    struct b_tree * r;
    Node grid; 
} bTree;

bTree * create_tree_node(int w, int h, double res) {
    bTree * new = (bTree*)malloc(sizeof(bTree));
    if (new == NULL) printf("\nERROR BY ALLOCATIN MEM\n");
    new->l = NULL;
    new->r = NULL;
    new->grid.w = w;
    new->grid.h = h;
    new->grid.res = res;
    return new;
}

void insert_bTree(bTree ** root, int w, int h, double res) {

    if (*root == NULL) {
        *root = create_tree_node(w, h, res);
    }
    else if ((*root)->grid.w > w) insert_bTree(&(*root)->l, w, h, res);
    else insert_bTree(&(*root)->r, w, h, res);
}

double get_value_bTree(bTree *root, int w, int h) {

    if (root == NULL) return 0;
    if (w == root->grid.w && h == root->grid.h ) return root->grid.res;
    if (w < root->grid.w) return get_value_bTree(root->l, w, h);
    return get_value_bTree(root->r, w, h);
}

double dGrid(int w, int h, bTree* memo) {
    if (w == 1 || h == 1) return 1;
    double res = get_value_bTree(memo, w, h);
    if (res == 0) insert_bTree(&memo, w, h, dGrid(w-1, h, memo) + dGrid(w, h-1, memo));
    return get_value_bTree(memo, w, h);
}

void print_bTree(bTree *root) {

    if (root != NULL) {
        print_bTree(root->l);
        printf("\n (%d, %d, res: %f ) \n", root->grid.w, root->grid.h, root->grid.res);
        print_bTree(root->r);
    }
}


double grid(int w, int h) {

    if (w == 1 || h == 1) return 1;
    return grid(w-1, h) + grid(w, h-1);
}


double fctrl(int n) {
    if (n == 1 || n == 0) return 1;
    return n * fctrl(n-1);
}

double fctrl_grid(int w, int h) {
    return (fctrl(w + h - 2)) / (fctrl(w - 1) * fctrl(h - 1));
}

int main(int argc, char **argv) {

    // with N E func
    printf("fctrl_grid(18, 18) = %.f\n", fctrl_grid(18, 18));

    // with memorization
    bTree *memo = NULL;
    printf("dGrid(1,2) = %.f\n", dGrid(1, 2, memo));   // 1
	printf("dGrid(3,2) = %.f\n", dGrid(3, 2, memo));   // 3
	printf("dGrid(2,3) = %.f\n", dGrid(2, 3, memo));   // 3
	printf("dGrid(3,3) = %.f\n", dGrid(3, 3, memo));   // 6
	printf("dGrid(18,18) = %.f\n", dGrid(18, 18, memo)); // 2333606220

    // without memorization
    printf("grid(1,2) = %.f\n", grid(1, 2));   // 3
	printf("grid(3,2) = %.f\n", grid(3, 2));   // 3
	printf("grid(2,3) = %.f\n", grid(2, 3));   // 3
	printf("grid(3,3) = %.f\n", grid(3, 3));   // 6
	//printf("grid(18,18) = %.f\n", grid(18, 18)); // 2333606220

    return 0;
}