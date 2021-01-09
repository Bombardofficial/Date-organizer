#include <stdio.h>
#include <stdlib.h>

typedef enum msgtag { //tags
  NoTag = 0, Important, Work, Personal, ToDo, Later
} msgtag;

typedef struct MsgID // ID Speicherung 
{
  char* id;
} MsgID;

typedef struct MsgDetails // Speicherung der Daten
{
  char* id;
  msgtag tag;
  int year;
  int month;
  int day;
} MsgDetails;

typedef struct Node //verkettete Liste
{
  void* item;
  struct Node* next;
} Node;


Node* getAt(int position, Node* head) {
    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current;
}

void swap(Node* a, Node* b) { //Tauscht die values der beiden Nodes
    int t = a->value;
    a->item = b->item;
    b->item = t;
}

int partition (Node* head, int low, int high) 
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
{ 
    Node* pivot = getAt(high, head);    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (getAt(j, head)->item < pivot->item) 
        { 
            i++;    // increment index of smaller element 
            swap(getAt(i, head), getAt(j, head)); 
        }
    } 
    swap(getAt(i + 1, head), getAt(high, head));
    return (i + 1);
}

void quickSort(Node* head, int low, int high) 
/* The main function that implements QuickSort 
 head --> verkettete Liste, 
  low  --> Starting index, 
  high  --> Ending index */
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(head, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(head, low, pi - 1); 
        quickSort(head, pi + 1, high); 
    } 
}

Node* insertFirst(void* item, Node* head) {
    Node* newHead = malloc(sizeof(Node));
    newHead->item = item;
    newHead->next = head;
    return newHead;
}
  


//menu
char getMenu(){
    char result;
    printf("cmd: ");
    scanf(" %c", &result);
    while(result != 'r' && result != 'R' && result != 'p' && result != 'q' && result != 't' 
	&& result != 'y' && result != 'D' && result != 'e'){
        printf("\nInvalid selection\n");
        return result;
    }
}

{}
// funktion deklarieren
void read(MsgDetails *details);
void reverseList(MsgDetails *details);
void print(Node* head);
void tag(MsgDetails *details);
void yearless(MsgDetails *details);
void dategreater(MsgDetails *details);
void exactdate(MsgDetails *details);
void freeMsgIDs(Node*);


void read(MsgDetails *details){

	printf("\n\n");
	printf("enter msg metadata (tag,year,month,day,id): ");
	scanf(" %d,%d,%d,%d,%s", &Msgdetails->tag,&Msgdetails->year,&Msgdetails->month,&Msgdetails->day,&Msgdetails->id);

    head = insertFirst(5, head);
    
 // quicksortnál 2. low, 3. high
    quickSort(head, 0, 5);


}

void reverseList(MsgDetails *details){

    printf("\n\n");

}

void print(Node* head){
/* Function to print an array */
    printf("\n\n");

    Node* current = head;
    while(current != NULL) {
        printf(" %d ", current->value);
        current = current->next;
    }



}




    freeMsgIDs();


}
// 
void tag(MsgDetails *details){

	printf("\n\n");
    printf("which tag (0-5)? ");
	scanf(" %d", &tagfinder);

}

void yearless(MsgDetails *details){

	printf("\n\n");
    printf("which year? ");
	scanf(" %d", &yearfinder);

}

void dategreater(MsgDetails*details){

	printf("\n\n");
    printf("which date (YYYYMMDD)? ");
	scanf(" %d", &yearfinder);

}

void exactdate(MsgDetails *details){

	printf("\n\n");
    printf("which date (YYYYMMDD)? ");
	scanf(" %d", &yearfinder);


}

void freeMsgIDs(Node*){

    struct Node* tmp;

    while(head != NULL){

        tmp = head;
        head = head->next;
        free(tmp);

    }
}



// Driver program to test above functions 
int main(){

	int tagfinder;
	int yearfinder;
    int id_org;

    Node* head = NULL;
    
    struct MsgDetails ID1;
    struct MsgDetails ID2;
    struct MsgDetails ID3;
    struct MsgDetails ID4;
    struct MsgDetails ID5;


    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

// ||| MsgDetails 'például details1' ||| így tudom majd szegmensekre bontani pl. details1.year

	printf("MsgDB -- Testprogramm");
	//menu rufen
    char switchmode = 'a';
    while(switchmode != 'q'){
        switchmode = getMenu();
	}

	//Falle
    switch(switchmode){

    case('r'):
        read();
        break;

	case('R'):
        
        reverseList();
        break;

	case('p'):
        
        print();
        break;

	case('t'):
        
		tag();
        break;

	case('y'):
        
        yearless();
        break;

	case('D'):
        
		dategreater();
        break;

	case('e'):
        
		exactdate();
        break;

	case('q'):
        exit;
	}
	return 0;
}

