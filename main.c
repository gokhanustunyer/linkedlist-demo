#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    float      data;
    node     * next;
};


node* allocate();
node* generate_node();

void add_node(node *head, float value);
void add_node_first(node *head, float value);
void remove_node(node *head, int index);
void print_node(node *head);

int main(){
    int         i;
    node    *head;
    head = allocate();
    head -> next = NULL;
    
    // 10'dan 20'ye degerlerin listenin sonuna eklenmesi
    for (i=10;i<=20;i++){
        add_node(head, i);
    }

    // 9'dan 0'a degerlerin listenin basina eklenmesi
    for (i=9;i>=0;i--){
        add_node_first(head, i);
    }

    // Beklenen cikti 0-20 arasi degerler
    print_node(head);

    printf("\n");

    // Listenin temizlenmesi
    for (i=0;i<21;i++){
        remove_node(head, 0);
    }
    print_node(head);

    return 0;
}

void add_node(node *head, float value){
	/*
		@brief -> Verilen node'un sonuna
                  verilen degeri ekler
		@param -> node *head, float value
		@return -> empty
	*/

    node *new_node, *temp;              // Eklenecek node, gezecek temp
    new_node = generate_node();         // yeni node'a default degerlerin atanmasi
    new_node -> data = value;

    temp = head;                        // temp'in head ile baslatilmasi
    while (temp -> next != NULL){       // Onundeki deger NULL olana kadar (sona) gidilmesi
        temp = temp -> next;
    }
    temp -> next = new_node;            // Next degeri NULL olan temp'in yeni node ile guncellenmesi
}

void add_node_first(node *head, float value){
	/*
		@brief -> Verilen node'un basina 
                  verilen degeri ekler
		@param -> node *head, float value
		@return -> empty
	*/

    node    * new_node;                 // Basa eklenecek node
    new_node = allocate();
    new_node->data = value;
    new_node -> next = head -> next;    // Yeni node'un head'a baglanmasi
    head -> next = new_node;            // Head'in donerek yeni node'a baglanmasi
}

void remove_node(node *head, int index){
	/*
		@brief -> Verilen node'un verilen index'ine kadar
                  gider ve oradaki degeri siler
		@param -> node *head, int index
		@return -> empty
	*/

    node *temp, *delete;            // Elemanlari gezecek pointer,
    int      i;                     // bellekten silinecek yer, sayac

    temp = head;
    for (i=0;i<index;i++){          // Sayacin index'e ulastirilmasi
        temp = temp -> next;
        if (temp == NULL){          // Gecersiz index girisi kontrolu
            printf("Invalid Index '%d'\n", index);
            return;
        }
    }
    delete = temp -> next;
    temp -> next = temp -> next -> next;
    free(delete);                   // Bellekte bosa dusen degerin silinmesi
}

void print_node(node *head){
	/*
		@brief -> Verilen Node'un elemanlarını yazdirir
		@param -> node *q,
		@return -> empty
	*/

    int     i = 0;                                                    // Index sayaci
    node    *temp;                                      // Elemanlari gezecek pointer
    temp = head -> next;
    while (temp != NULL){                               // Temp'in ucu NULL'a cikana
        printf("Element %d: %f\n", i++, temp -> data);  // kadar donen while loop
        temp = temp -> next;
    }
    if (i==0)
        printf("List Empty!");
}


node* generate_node(){
	/*
		@brief -> node pointer olusturur bellekte
                  yer acan ilgili fonksiyonu cagirir
                  default degerleri ilgili node'a atar.
		@param -> empty,
		@return -> node *
	*/

    node   * new_node;
    new_node = allocate();
    new_node -> next = NULL;
    return new_node;
}

node* allocate(){
	/*
		@brief -> Bellekte size(node) kadar yer acar
		@param -> empty,
		@return -> node *
	*/

    return (node*)malloc(sizeof(node)); 
}

