#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum msgtag
{				            //Tags sollten in folgendem typedef repräsentiert werden
    NoTag = 0, Important, Work, Personal, ToDo, Later
} msgtag;

typedef struct MsgID		// Zum Datenaustausch soll folgendes struct verwendet werden 
{
    char *id;
} MsgID;

typedef struct MsgDetails	// Die Daten sollen in folgendem struct gespeichert werden
{
    char *id;
    msgtag tag;
    int year;
    int month;
    int day;
} MsgDetails;

typedef struct Node		    //Der Kern soll eine Lineare Liste sein in der alle MsgDetails bis zum Programmende gespeichert werden sollen
{
    void *item;
    struct Node *next;
} Node;

                            // funktion deklarieren
Node* read(Node* readnode);
Node* reverseList (Node*);
void print (Node * head);
void tag (Node*);
void yearless (Node*);
void dategreater (Node*);
void exactdate (Node*);
void freeMsgDetails (Node *);
void freeMsgIDs (Node *);
Node* addMsgDetails (Node *, MsgDetails *);
int cmpYear(int, MsgDetails*);
int cmpDate(int, MsgDetails*);
void filterList(Node*, int(*)(int, MsgDetails*), int, int);


                            //menu
char getMenu ()
{
    char result;

    printf ("\ncmd: ");
    scanf (" %c", &result);
    if (result != 'r' && result != 'R' && result != 'p' && result != 'q'
	    && result != 't' && result != 'y' && result != 'D' && result != 'e')
    {                      //Wenn etwas Ungültiges eingegeben wurde
        printf ("\nError: unknown command!"); 
     
    }

    return result;
    
}


int main ()
{
    Node* head = NULL;

    printf ("\nMsgDB -- Testprogramm ");

                           //menu rufen
    char switchmode = 'a';
    while (switchmode != 'q')
    {
        switchmode = getMenu ();



                           //Falle
        switch (switchmode)
	    {

	        case ('r'):
	    
	        head = read(head);
	        break;

	        case ('p'):

	        print(head);
	        break;

	  
	        case('R'):

	        head = reverseList(head);
	        break;



	        case('t'):

	        tag(head);
	        break;
        
	        case('y'):

	        yearless(head);
	        break;

	        case('D'):

	        dategreater(head);
	        break;

	        case('e'):

	        exactdate(head);
	        break;
	   
	        case ('q'):
	        break;
	    }
    }

    return 0;

}
                            //einen Datensatz im passenden Format einlesen
Node* read (Node* readnode)
{

    MsgDetails *id = malloc(sizeof (id));
    char *ids = malloc(sizeof(char*) * 40);
  
    printf("\n");
    printf("enter msg metadata (tag,year,month,day,id): ");
    scanf(" %u,%4d,%2d,%2d,%s", &id->tag, &id->year, &id->month, &id->day,ids);
    id->id = ids;
    return addMsgDetails(readnode,id);

}


                            //fügt Ihrer Datenbank eine neue Nachricht hinzu
Node* addMsgDetails(Node * head, MsgDetails * item)
{
    Node* newNode = malloc(sizeof(Node));
    Node* newHead = head;
    newNode->item = item;
    newNode->next = NULL;
    if (head==NULL)
    {
        newHead=newNode;
        newHead->next = NULL;     
    }
    else
    {
        Node* current = head;
        Node* prev = NULL;
        MsgDetails* msg;
        int gr;
        while(current != NULL)
        {
            msg = current->item;            
            gr = 0;
            if(msg->year > item->year)
                {gr = 1;}
                else
                {
                    if(msg->year == item->year)
                    {
                        if(msg->month > item->month)
                        {gr = 1;}
                        else
                        if(msg->month == item->month)
                        {
                            if (msg->day > item->day)
                            {
                                gr = 1;
                            }
                        }
                    }
                }
              
              
            if(gr == 1)
            {
                newNode->next = current;
                if(prev==NULL)
                {
                    newHead = newNode;
                }
                else
                {
                    prev->next = newNode;
                }
                break;
                printf ("xx %d ", msg->year);     //!!!!!!!!!!!!!!
            }
            prev = current;
            current = current->next;
            if(current == NULL)
            {
                prev->next = newNode;
            }
        }
    }
    return newHead; 
    
}

                            // die interne Datenbank ausgeben
void print (Node* head)
{
   

    Node* current = head;
    MsgDetails* msg;
    while(current != NULL)
    {
        msg = current->item;
        printf("\nID: %s", msg->id);
        printf("\n  %04d-%02d-%02d Tag: %u", msg->year, msg->month, msg->day, msg->tag);
        current = current->next;
        
    }
    

}
                            // Liste durch den gewählten Tag ausdrücken
void tag(Node* head){
    int tagfinder;
    head = reverseList(head);
    Node* current = head;
    MsgDetails* msg;
	printf("\n");
    printf("which tag (0-5)?");
	scanf(" %d", &tagfinder);
                            //wenn current node nicht null ist
    
    while(current != NULL)
    {
        msg = current->item;
        if (tagfinder == msg->tag)
        {
            printf("\nID: %s", msg->id);
        }
        current = current->next;
    }
    head = reverseList(head);

}
                            // die eine Ergebnisliste, MsgID und die zugehörigen Node structs löscht
void freeMsgDetails(Node* head){

    struct Node* tmp;

    while(head != NULL){

        tmp = head;
        head = head->next;
        free(tmp);
        
    }
}
                            // die Liste der IDs der Nachrichten ausgeben, deren Jahr kleiner als das eingegebene ist
void yearless(Node* head){

	int yearfinder;
	head = reverseList(head);
    Node* current = head;
    MsgDetails* msg;
	
    printf("\nwhich year?  ");
	scanf(" %04d", &yearfinder);

    while(current != NULL)
    {
        msg = current->item;
        if (yearfinder > msg->year)
        {
            printf("\nID: %s", msg->id);
        }
        current = current->next;
    }
    head = reverseList(head);
}
                            //die resultierende Liste der Nachrichten deren Datum größer ist als das angegebene ausgeben
void dategreater(Node* head){

	int yearfinder;
	int monthfinder;
	int dayfinder;
	head = reverseList(head);
    Node* current = head;
    MsgDetails* msg;
	
    printf("\nwhich date (YYYYMMDD)? ");
	scanf(" %04d%02d%02d", &yearfinder, &monthfinder, &dayfinder);
    
    int gr;
    while(current != NULL)
    {
        msg = current->item;

            gr = 0;
            if (msg->year > yearfinder)
            {
                gr = 1;
            }
            else
            {
                if (msg->year == yearfinder)
                {
                    if (msg->month > monthfinder)
                    {
                        gr = 1;
                    }
                    else if (msg->month == monthfinder)
                    {
                        if (msg->day > dayfinder)
                        {
                            gr = 1;
                        }
                    }
                }
            }
              
              
        if(gr == 1)
        {
            printf("\nID: %s", msg->id);
        }
        current = current->next;
    }
    head = reverseList(head);
}
                            //die resultierende Liste der Nachrichten IDs ausgeben
void exactdate(Node* head){

	int yearfinder;
    int monthfinder;
    int dayfinder;
    Node* current = head;
    MsgDetails* msg;
    printf("\nwhich date (YYYYMMDD)? ");
	scanf(" %04d%02d%02d", &yearfinder, &monthfinder, &dayfinder);

    while(current != NULL)
    {
        msg = current->item;
        if(yearfinder == msg->year && monthfinder == msg->month && dayfinder == msg->day)
        {
            printf("\nID: %s", msg->id);
        }
        current = current->next;
    }

}

Node* reverseList(Node* head){
    Node* prev = NULL;
    if (head != NULL)
    {
    
        Node* current = head;
        Node* next;
       
        
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }
    return prev;
}

int matchTag(int filtertag, MsgDetails* msg){


    if(filtertag == msg->tag){
        return 1;
    }
    else
    {
        return 0;
    }

}

int cmpYear(int filteryear, MsgDetails* msg)
{
    int ret;
    if(filteryear == msg->year){

        ret = 0;
    
    }
    else if(filteryear > msg->year){

        ret = 1;
    
    }
    else if(filteryear < msg->year){

        ret =  -1;
    
    }
    return ret;
}

int cmpDate(int filterdate, MsgDetails* msg)
{
    int y;
    int m;
    int d;
    int buf;
    buf = filterdate;
    d  = buf - (buf/100)*100;
    buf = buf /100;
    m  = buf - (buf/100)*100;
    y = buf /100;
   

    int gr = -1;
    if (msg->year > y)
    {
        gr = 1;
    }
    else
    {
        if (msg->year == y)
        {
            if (msg->month > m)
            {
                gr = 1;
            }
            else if(msg->month == m)
            {
                if (msg->day > d)
                {
                    gr = 1;
                }
            }
        }
        else
        {
            if (msg->day == d)
            {
                gr= 0;
            }
        }
        
    }
    return gr;    

}

void filterList(Node* a, int(* f)(int b , MsgDetails* msg),int par, int res){





}
void freeMsgIDs (Node * asd){
    
}
