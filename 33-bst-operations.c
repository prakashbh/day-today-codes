#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree TREE;

TREE * insert_into_bst(TREE *, int);
void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);
TREE * delete_from_bst(TREE *, int);


/*
Function Name: insert_into_bst
Input Params:  Root of the tree and data item to be inserted
Return Type:   Updated root of the tree
Description:   Inserts a node into a binary search tree at
               appropriate position
*/
TREE * insert_into_bst(TREE * root, int data)
{
	TREE *newnode,*currnode,*parent;

	// Dynamically allocate the memory using malloc
	newnode=(TREE*)malloc(sizeof(TREE));

	// Check if the memory allocation was successful
	if(newnode==NULL)
	{
        printf("Memory allocation failed\n");
        return NULL;
	}

	// Initialize the tree node elements
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	// When the first insertion happens which is the root node
	if(root == NULL)
	{
		root = newnode;
		printf("Root node inserted into tree\n");
		return root;
	}

	// Traverse through the desired part of the tree using
	// currnode and parent pointers
	currnode = root;
	parent = NULL;
	while(currnode != NULL)
	{
		parent = currnode;
		if(newnode->data < currnode->data)
			currnode = currnode->left;
		else
			currnode = currnode->right;
	}

    // Attach the node at appropriate place using parent
	if(newnode->data < parent->data)
		parent->left = newnode;
	else
		parent->right = newnode;

    // print the successful insertion and return root
    printf("Node inserted successfully into the tree\n");
    return root;
}

/*
Function Name: inorder
Input Params:  Root of the tree
Return Type:   void
Description:   Recursively visits the tree in the order of
               Left, Root, Right
*/
void inorder(TREE *troot)
{
	if(troot != NULL)
    	{
        	inorder(troot->left);
        	printf("%d\t",troot->data);
        	inorder(troot->right);
	}
}

/*
Function Name: preorder
Input Params:  Root of the tree
Return Type:   void
Description:   Recursively visits the tree in the order of
               Root, Left, Right
*/
void preorder(TREE *troot)
{
	if(troot != NULL)
	{
        	printf("%d\t",troot->data);
        	preorder(troot->left);
        	preorder(troot->right);
	}
}


/*
Function Name: postorder
Input Params:  Root of the tree
Return Type:   void
Description:   Recursively visits the tree in the order of
               Left, Right, Root
*/
void postorder(TREE *troot)
{
	if(troot != NULL)
	{
        	postorder(troot->left);
        	postorder(troot->right);
        	printf("%d\t",troot->data);
	}
}


/*
Function Name: delete_from_bst
Input Params:  Root of the tree, item data to be deleted
Return Type:   Updated root of the tree
Description:   Deletes the specified data and re-adjusts the
               tree structure according to bst tree constraints
*/

TREE * delete_from_bst(TREE * root, int data)
{
    TREE * currnode, *parent, *successor, *p;

    // Check if the tree is empty
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    // Traverse and reach the appropriate part of the tree
    parent = NULL;
    currnode = root;
    while (currnode != NULL && data != currnode->data)
    {
        parent = currnode;
        if(data < currnode->data)
            currnode  = currnode->left;
        else
            currnode = currnode->right;
    }

    // If the data is not present in the tree
    if(currnode == NULL)  {
        printf("Item not found\n");
        return root;
    }

    // Check and manipulate if either left subtree is absent,
    // or right subtree is absent
    // or both are present
    if(currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else
    {
	 // Process of finding the inorder successor
        successor = currnode->right;
        while(successor->left != NULL)
            successor = successor->left;

        successor->left = currnode->left;
        p = currnode->right;
    }

    // The case of root deletion
    if (parent == NULL) {
        free(currnode);
        return p;
    }

    if(currnode == parent ->left)
        parent->left = p;
    else
        parent->right = p;

    free(currnode);
    return root;
}

int main()
{
	TREE * root;
	root = NULL;
	int choice = 0;
	int data = 0;
	int count = 0;

	while(1)
	{
        printf("\n******** Menu *************\n");
        printf("1-Insert into BST\n");
        printf("2-Inorder Traversal\n");
        printf("3-Preorder Traversal\n");
        printf("4-Postorder Traversal\n");
        printf("5-Delete from BST\n");
        printf("Any other option to exit\n");
        printf("*****************************\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

	 switch(choice)
	 {
            case 1: printf("Enter the item to insert\n");
                    scanf("%d", &data);
                    root = insert_into_bst(root, data);
                    break;

            case 2: if(root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        printf("Inorder Traversal is...\n");
                        inorder(root);
                    }
                    break;

            case 3: if(root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        printf("Preorder Traversal is...\n");
                        preorder(root);
                    }
                    break;

            case 4: if(root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        printf("Postorder Traversal is...\n");
                        postorder(root);
                    }
                    break;

            case 5: printf("Enter the item to be deleted\n");
                    scanf("%d", &data);
                    root = delete_from_bst(root, data);
                    break;

            default: printf("Exciting Code.\n");
                     exit(0);
        }
    }
    return 0;
}
