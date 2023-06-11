#include<stdio.h>
#include<stdlib.h>


struct x {
    int num;
    struct x *link;
};
struct x *head, *node;

struct x* create();
void display(struct x* display);
void traverse(struct x* traverse);
struct x* insert(struct x* insert);
struct x* delete(struct x* delete);
void search(struct x* search);
struct x* sorting(struct x* sorting);

void main()
{
    struct x* head1 = (struct x*) malloc (sizeof(struct x));
    int ch;
    do{
        print_line:
        printf("\n\nLINKED LIST: Menu");
        printf("\n--------------");
        printf("\n1 - Create");
        printf("\n2 - Display");
        printf("\n3 - Traverse");
        printf("\n4 - Searching");
        printf("\n5 - Sorting");
        printf("\n6 - Inserting Nodes");
        printf("\n7 - Deleting Nodes");
        printf("\n8 - EXIT");
        printf("\n\nenter your choice: ");
        scanf("%d",&ch);
        if (ch > 8 || ch < 1){
            printf("\nWrong choice.");
            goto print_line;
        }
        switch(ch){
            case 1:
                head1 = create();
                break;
            
            case 2:
                display(head1);
                break;
			 
            case 3:
                traverse(head1);
                break;

            case 4:
                search(head1);
                break;

        	case 5:
                head1 = sorting(head1);
                break;
            
            case 6:
                head1 = insert(head1);
                break;
            
            case 7:
                head1 = delete(head1);
                break;

            case 8:
               	exit(0);
                break;
        }
    } while(ch < 8);
}

//Function for creating the nodes
struct x* create(){
    printf("\n\nLINKED LIST: CREATING NODES\n");
    printf("--------------------------------\n");
    printf("\nEnter no of nodes you want to create: ");
    int node_num;
    scanf("%d",&node_num);
    //Creating first node
    struct x* head = (struct x*)malloc(sizeof(struct x));
    printf("\nInput value for node 1: ");
    scanf("%d",&head->num);
    head->link = NULL;    
    struct x* ptr = head;
    
    for(int i=0;i<node_num-1;i++){
        struct x* temp = (struct x*)malloc(sizeof(struct x));
        printf("\nInput value for node %d: ",i+2);
        scanf("%d",&temp->num);
        temp->link = NULL;
        ptr->link = temp;
        ptr = temp;
    }
    printf("\nNode is created.\n");
    return head;
}

//Function for displaying the nodes
void display(struct x* display){
    printf("\n\nLINKED LIST: DISPLAYING ALL THE VARIABLES & ADDRESS OF NODES\n");
    printf("----------------------------------------------------------------\n");
    int i = 0;
    if(display == NULL){
        printf("\n\nThere no linked list is avilable\n");
    }
    else{
        
        struct x* node_counter = display;
        while(node_counter != NULL){
            printf("\nAddress of node %d: %u",i+1,node_counter);
            printf("\nvalue of node %d: %u",i+1,node_counter->num);
            node_counter = node_counter->link;
            printf("\nlink in node %d: %u\n\n",i+1,node_counter);
            ++i;

        }        
    }
}

// Function for traverse the nodes
void traverse(struct x* traverse){
    printf("\n\nLINKED LIST: Traversing All The Nodes\n");
    printf("----------------------------------------\n");
    int count = 0;
    if(traverse == NULL){
        printf("\n\nThere no linked list is avilable\n");
    }
    else{
        while(traverse != NULL){
            ++count;
            traverse = traverse->link;
        }
        printf("There are %d number of nodes avilable.\n",count);
    }
}

//Function for insert element
struct x* insert(struct x* insert){
    int ch;    
    printf("\nSINGLE LINKED LIST: INSERTING NODES");
    printf("\n--------------");
    print_line:
    printf("\n\nINSERTING MENU");
    printf("\n----------------");
    printf("\n1.Inserting Node At First");
    printf("\n2.Inserting Node(Before/After)");
    printf("\n3.Inserting Node At Last");
    printf("\n4.Exit");
    printf("\nenter your choice: ");
    scanf("%d",&ch);

    if(ch == 1){
        printf("\nEnter no of nodes you want to INSERT: ");
        int node_num;
        scanf("%d",&node_num); 
        struct x* head = (struct x*)malloc(sizeof(struct x));
        printf("\nInput value for node 1: ");
        scanf("%d",&head->num);
        head->link = NULL;    
        struct x* ptr = head;
        
        for(int i=0;i<node_num-1;i++){
            struct x* temp = (struct x*)malloc(sizeof(struct x));
            printf("\nInput value for node %d: ",i+2);
            scanf("%d",&temp->num);
            temp->link = NULL;
            ptr->link = temp;
            ptr = temp;
        }
        //Nodes are created 
        //Initial address is carried in "ptr"  
        ptr->link = insert;
        insert = ptr;
        printf("\nNodes are inserted at beginning.\n");
        return head;
    }
    else if(ch == 2){
        printf("\nEnter no of nodes you want to INSERT: ");
        int node_num;
        scanf("%d",&node_num); 
        struct x* head = (struct x*)malloc(sizeof(struct x));
        printf("\nInput value for node 1: ");
        scanf("%d",&head->num);
        head->link = NULL; 
        struct x* ptr = head;
        for(int i=0;i<node_num-1;i++){
            struct x* temp = (struct x*)malloc(sizeof(struct x));
            printf("\nInput value for node %d: ",i+2);
            scanf("%d",&temp->num);
            temp->link = NULL;
            ptr->link = temp;
            ptr = temp;
        }
        //Nodes are created 
        //Initial address is carried in "head"
        struct x* head1 = insert; 
        print_line1:
        printf("\n1.Inserting Node Before Place");
        printf("\n2.Inserting Node After Place\n");
        printf("\n3.Exit");
        printf("\nEnter Your choice: ");
        scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the place: ");
            int node_place;
            scanf("%d", &node_place);
            for(int i=1;i<node_place-1;i++){
                head1 = head1->link;
            }
            ptr->link = head1->link;
            head1->link = head;
        }        
        else if(ch == 2){
            printf("Enter the place: ");
            int node_place;
            scanf("%d", &node_place);
            for(int i=1;i<=node_place-1;i++){
                head1 = head1->link;
            }
            ptr->link = head1->link;
            head1->link = head;
        }
        else if(ch == 3){
            printf("\n");
        }
        else{
            printf("\nWrong Choice.");
            goto print_line1;   
        }
        return insert;
    }
    else if(ch == 3){
        printf("\nEnter no of nodes you want to INSERT: ");
    int node_num;
    scanf("%d",&node_num); 
    struct x* head = (struct x*)malloc(sizeof(struct x));
    printf("\nInput value for node 1: ");
    scanf("%d",&head->num);
    head->link = NULL;    
    struct x* ptr = head;
    
    for(int i=0;i<node_num-1;i++){
        struct x* temp = (struct x*)malloc(sizeof(struct x));
        printf("\nInput value for node %d: ",i+2);
        scanf("%d",&temp->num);
        temp->link = NULL;
        ptr->link = temp;
        ptr = temp;
    }
    //Nodes are created 
    //Initial address is carried in "head" 
    struct x* head1 = insert; 
    while(head1->link != NULL){
        head1 = head1->link;
    }
    head1->link = head;
    printf("\nNodes are inserted at the end.\n");
    return insert;
    }
    else if(ch == 4){
        printf("\n");
    }
    else{
        printf("\nWrong Choice.");
        goto print_line;
    }
}

//Function for deleting nodes
struct x* delete(struct x* delete){
    printf("\n\nSINGLE LINKED LIST: DELETING NODES\n");
    int ch;
    printf("\n--------------------------------");
    printf("\n\nDELETING MENU");
    printf("\n--------------");
    printf("\n1.Deleting First Node");
    printf("\n2.Deleting Node(Before/After)");
    printf("\n3.Deleting Last Node");
    printf("\n4.Deleting All nodes");
    printf("\n5.Exit");
    print_line:
    printf("\n\nEnter your choice: ");
    scanf("%d",&ch);
    if (ch == 1){
        struct x* current = delete;
        current = current->link;
        free(delete);
        delete = current;
    }
    else if(ch == 2){
        int cho;
        f1:
        printf("\n\n1.Delete Node Before Place");
        printf("\n2.Delete Node After Place");
        printf("\n\nEnter your Choice: ");
        scanf("%d",&cho);
        if(cho == 1){
            printf("\nEnter your place: ");
            int pla;
            scanf("%d",&pla);
            struct x* current = delete;
            for(int i=1; i<pla; i++){
                current = current->link;
                free(delete);
                delete = current;
            }
            return delete;
        } 
        else if(cho == 2){
            printf("\nEnter your place: ");
            int pla,count=1;
            scanf("%d",&pla);
            struct x* current = delete;
            while(count != pla){
                current = current->link;
                count++;
            }
            current->link = NULL;
            return delete;
        } 
        else{
            printf("\nWrong Choice.");
            goto f1;
        }

    }
    else if(ch == 3){
        struct x* ptr = delete; 
        int count = 0;
        while(ptr != NULL){
            ptr = ptr->link;
            count++;
        }
        struct x* current2 = delete;
        for(int i=1;i<count-1;i++){
            current2 = current2->link;
        }
        current2->link = NULL;
    }
    else if(ch == 4){
        struct x* ptr1 = delete;
        while(ptr1 != NULL){
            ptr1 = ptr1->link;
            free(delete);
            delete = ptr1;
        }
    }
    else if(ch == 5){
        printf("\n");
    }
    else{
        printf("\nWrong Choice.");
        goto print_line;
    }
    return delete;
}

//Function for searching elements
void search(struct x* search){
    printf("\n\nSINGLE LINKED LIST: SEARCHING THE ELEMENT");
    printf("\n-----------------");
    printf("\n\nEnter the element: ");
    int element,k = 0,count = 0;
    scanf("%d",&element);
    while(search->link != NULL){
        if(element == search->num){
            k=1;
            break;
        }
        search = search->link;
        count++;
    }
    if(k == 0){
        printf("\n%d is not avilable.",element);
    }
    else if(k == 1){
       printf("\n%d is avilable.",element); 
       printf("\nIt is avilable at %d place.",count);
    }
}

//Function for sorting the elements
struct x* sorting(struct x* sorting){
    printf("\n\nSINGLE LINKED LIST: SEARCHING THE ELEMENT");
    printf("\n-----------------");
    printf("\n\nSORTING MENU");
    printf("\n--------------");
    f2:
    printf("\n1.Sorting In Ascending Order");
    printf("\n2.Sorting In Descending Order");
    printf("\n3.Exit");
    printf("\n\nEnter your choice: ");
    int ch;
    scanf("%d",&ch);
    struct x* i;
    struct x* j;
    int temp;
    if(ch == 1){
        for(i = sorting; i != NULL; i=i->link){
            for(j = i->link; j != NULL; j=j->link){
                if(i->num > j->num){
                    temp = i->num;
                    i->num = j->num;
                    j->num = temp;
                }
            }
        }
        return sorting;
    }
    else if(ch == 2){
        for(i = sorting; i != NULL; i=i->link){
            for(j = i->link; j != NULL; j=j->link){
                if(i->num < j->num){
                    temp = i->num;
                    i->num = j->num;
                    j->num = temp;
                }
            }
        }
        return sorting;
    }
    else if(ch == 3){
        printf("\n");
    }
    else{
        printf("\nWrong Choice.");
        goto f2;
    }
}