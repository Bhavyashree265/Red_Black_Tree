#include "main.h"

int main()
{
    tree_t *root = NULL;
    int choice;
    data_t item;
    data_t min, max;

    while (1)
    {
        printf("\n-----------------------------------------\n");
        printf("          RED BLACK TREE MENU\n");
        printf("-----------------------------------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Delete Minimum\n");
        printf("6. Delete Maximum\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("-----------------------------------------\n");
        
        printf("Enter your choice: ");
        if (read_integer(&choice) == FAILURE)
        {
            printf("Invalid choice! Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                if (read_integer(&item) == FAILURE)
                {
                    printf("Invalid input! Please enter digits only.\n");
                    break;
                }

                if (insert(&root, item) == SUCCESS)
                {
                    printf("Insertion Successful\n");
                    inorder(root);
                    printf("\n");
                }
                else
                {
                    printf("Duplicate element not allowed\n");
                }
                break;

            case 2:
                if (root == NULL)
                {
                    printf("Tree is Empty\n");
                    break;
                }
                printf("Enter the element to delete: ");
                if (read_integer(&item) == FAILURE)
                {
                    printf("Invalid input! Please enter digits only.\n");
                    break;
                }
                if (delete(&root, item) == SUCCESS)
                {
                    printf("Deletion Successful\n");
                    inorder(root);
                    printf("\n");
                }
                else
                {
                    printf("Element not found\n");
                }
                break;

            case 3:
                if (find_minimum(&root, &min) == SUCCESS)
                {
                    printf("Minimum element = %d\n", min);
                }
                else
                {
                    printf("Tree is Empty\n");
                }
                break;

            case 4:
                if (find_maximum(&root, &max) == SUCCESS)
                {
                    printf("Maximum element = %d\n", max);
                }
                else
                {
                    printf("Tree is Empty\n");
                }
                break;

            case 5:
                if (delete_minimum(&root) == SUCCESS)
                {
                    printf("Minimum node deleted successfully\n");
                    inorder(root);
                    printf("\n");
                }
                else
                {
                    printf("Tree is Empty\n");
                }
                break;

            case 6:
                if (delete_maximum(&root) == SUCCESS)
                {
                    printf("Maximum node deleted successfully\n");
                    inorder(root);
                    printf("\n");
                }
                else
                {
                    printf("Tree is Empty\n");
                }
                break;

            case 7:
                if (root == NULL)
                {
                    printf("Tree is Empty\n");
                }
                else
                {
                    printf("Inorder Traversal:\n");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 8:
                printf("Enter the element to search: ");

                if (read_integer(&item) == FAILURE)
                {
                    printf("Invalid input! Please enter digits only.\n");
                    break;
                }

                if (search(root, item) == SUCCESS)
                {
                    printf("Search Node is found\n");
                }
                else
                {
                    printf("Search Node is not found\n");
                }
                break;

            case 9:
                printf("Exiting...\n");
                printf("--------------------------------------\n");
                printf("Thankyou for using this application\n");
                printf("--------------------------------------\n");
                return SUCCESS;

            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }
    return SUCCESS;
}