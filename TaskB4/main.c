#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{int id;char group[4];} Donor;
typedef struct{Donor *data;int size,capacity;} DonorList;
int add_donor(DonorList *l,int id,const char *g){if(l->size==l->capacity){int cap=l->capacity==0?2:l->capacity*2;Donor *p=realloc(l->data,(size_t)cap*sizeof *p);if(!p)return 0;l->data=p;l->capacity=cap;}l->data[l->size].id=id;strncpy(l->data[l->size].group,g,3);l->data[l->size].group[3]='\\0';l->size++;return 1;}
int main(void){DonorList l={NULL,0,0};const char *g[]={"O+","A+","B-","AB+","O-"};for(int i=0;i<5;i++){if(!add_donor(&l,7001+i,g[i])){free(l.data);return 1;}printf("added %d (%s): size = %d, capacity = %d\\n",l.data[i].id,l.data[i].group,l.size,l.capacity);}free(l.data);return 0;}
