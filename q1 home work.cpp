
#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int number;
	struct node *next;
	
	
};

typedef struct node node;

int main(){
	
	
	int deger,TekSayisi=0,CiftSayisi=0; 
	node *thead,*p,*chead,*q;
	
	while(1){
		
		printf("Bir deger giriniz:");
		scanf("%d",&deger);
		
		if(deger == -1) break;
		
		if(deger%2!=0){ 
			if(TekSayisi==0){
			
				thead=(node*)malloc(sizeof(node));
				p=thead;
	
			}else{
			
				p->next=(node*)malloc(sizeof(node));
				p=p->next;			
			}
		
			p->number=deger;
			TekSayisi++;
			p->next=NULL;
						
		}else{
			
			if(CiftSayisi==0){
			
				chead=(node*)malloc(sizeof(node));
				q=chead;
	
			}else{
			
				q->next=(node*)malloc(sizeof(node));
				q=q->next;			
			}
		
			q->number=deger;
			CiftSayisi++;
			q->next=NULL;
					
		}
	
	}
	
	p->next=chead; 
	
	p=thead;
	
	while(p!=NULL){ 
		
		printf("%d  ",p->number);
		
		p=p->next;
		
	}
	
return 0;	
}
