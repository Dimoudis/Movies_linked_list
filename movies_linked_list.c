#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ena struct movie (titlo(string), xronia(int), timi(double))
stin main na ftiaksw 3 tainies(linked list)
me synartiseis:
na vrw mo timwn
na vrw mo timwn mono gia autes meta to 2000
na metrisw poses gyristikan prin to 1980
na zitisw ap ton user mia xronia kai na ektipwnw tous titlous tainiwn pou gyristikan tote, an den yparxei katallilo minima
na zitisw ap ton user ena gramma (%c) kai na metrisw apo poses tainies ksekinaei o titlos tous apo auto to gramma
*/

struct Movie{
	char titlos[15];
	int xronia;
	double timi;
	struct Movie *next;	
};

void mo_timwn(struct Movie *head);
void mo_timwn_meta_2000(struct Movie *head);
void poses_prin_1980(struct Movie *head);
void searching(struct Movie *head);
void poses_ksekinane_apo(struct Movie *head);

int main(){
	
	//treis tainies me linked list
	struct Movie head;
	strcpy(head.titlos,"Town");
	head.xronia=2002;
	head.timi=45.90;
	head.next=NULL; 
	
	struct Movie movie2;
	strcpy(movie2.titlos,"Bank");
	movie2.xronia=1970;
	movie2.timi=20;
	movie2.next=NULL;
	
	struct Movie movie3;
	strcpy(movie3.titlos,"House");
	movie3.xronia=2019;
	movie3.timi=26.50;
	movie3.next=NULL;
	
	head.next=&movie2;
	movie2.next=&movie3;
	
	struct Movie *current;
	current=&head;
	
	mo_timwn(&head);
	mo_timwn_meta_2000(&head);
	poses_prin_1980(&head);
	searching(&head);
	poses_ksekinane_apo(&head);

	return 0;
}

//mo timwn twn tainiwn
void mo_timwn(struct Movie *head){
	
	struct Movie *current;
	current=head;
	double mo;
	int count,sum=0;
	while(current!=NULL){
		sum=sum+current->timi;
		current=current->next;
		count++;
	}
	mo=(double)sum/count;
	printf("Mo timwn: %.2f euro\n",mo);
}

//mo timwn mono gia autes meta to 2000
void mo_timwn_meta_2000(struct Movie *head){
	int sum=0;
	int count=0;
	double mo;
	struct Movie *current;
	current=head;
	while(current!=NULL){
		if (2000<current->xronia){
			sum=sum+current->timi; 
			count++;
		}
		current=current->next;
	}
	if (count==0){
		mo=0;
	} 
	else{
		mo=(double)sum/count;
	} 
	printf("Mo timwn gia tis tainies meta to 2000 einai %.2f euro\n",mo);
}

//Poses tainies gyristikan prin to 1980
void poses_prin_1980(struct Movie *head){
	int count=0;
	struct Movie *current;
	current=head;
	while(current!=NULL){
		if (current->xronia<1980){
			count++;
		}
		current=current->next;	
	}
	
	if (count==0){
		printf("Den yparxei tainia pou gyristike prin to 1980!\n");
	} 
	else{
		printf("Oi tainies pou gyristikan prin to 1980 einai: %i\n",count);
	}
}
//zitaw mia xronia kai na ektipwnw tous titlous tainiwn pou gyristikan tote, an den yparxei katallilo minima
void searching(struct Movie *head){
	struct Movie *current;
	current=head;
	int xronia;
	int pos=-1;
	char temp;
	printf("Dwse mia xronia: ");
	scanf("%i",&xronia);
	scanf("%c",&temp); //gia na paralaboume to enter
	while(current!=NULL){
		if (current->xronia==xronia){
			pos=0;
			printf("\nTo %i gyristike h tainia me titlo '%s'\n",current->xronia,current->titlos);
		}
		current=current->next;
	}
	if (pos==-1){
		printf("Den yparxei tainia pou na gyristike tote\n");
	}
	
}

//zitaw ena gramma kai na metrisw apo poses tainies ksekinaei o titlos tous apo auto to gramma
void poses_ksekinane_apo(struct Movie *head){
	struct Movie *current;
	current=head;
	char gramma;
	int pos=-1;
	printf("Dwse ena gramma: ");
	scanf("%c",&gramma);
	while(current!=NULL){
		if (gramma==current->titlos[0]){
			pos=0;
			printf("\nOi tainia pou ksekinane me %c einai h '%s'\n",gramma,current->titlos);
		}
		current=current->next;
	}
	if (pos==-1){
		printf("Den yparxei tainia pou na ksekinaei apo '%c'",gramma);
	}
	
}

