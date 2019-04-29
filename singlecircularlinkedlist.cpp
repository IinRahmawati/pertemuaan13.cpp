#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct node{
        int data;
        struct node *next;
};

typedef struct node node;

node *pList = NULL;

node *alokasiNodeBaru(){
  node *pNew = NULL;
  pNew = (node *) malloc(sizeof(node));
  return(pNew);
}


void tambahAwal(node *pNew){
     node *temp;
     if(pList == NULL){
              pNew->next = pNew;
              pList = pNew;
     }
     else{
              //cari node yang menunjuk ke pList
              temp = pList;
              while(temp->next != pList){
                    temp = temp->next;
              }

              temp->next = pNew;
              pNew->next = pList;
              pList = pNew;
     }
}



void cetak(){
     node *pWalker = pList;
     node *pNext = NULL;
     while(pNext != pList){
         printf("pWalker = %d, ", pWalker->data);
         pNext = pWalker->next;
         pWalker = pNext;
         printf("pWalker->next = %d \n", pWalker->data);
     }

}


void tambahTengah(node *pNew){
     node *pWalker;
     pWalker=pList;
     int nilai,sisip;
     printf("masukkan nilai yang ingin ditambahkan: "); scanf("%d",&nilai);
     pNew->data = nilai;
     cetak();
     printf("data disisipkan setelah nilai : "); scanf("%d",&sisip);
     while(pWalker!=NULL && pWalker->data!=sisip){
                         pWalker=pWalker->next; }

     if(pWalker->next==pList) printf("\ndata tidak ditemukan");
     else {pNew->next=pWalker->next;
           pWalker->next=pNew; }
     cetak();

}

void tambahAkhir(node *pNew){
     node *pPre;
     pPre=pList;
     int nilai;
     printf("masukkan nilai yang ingin ditambahkan: "); scanf("%d",&nilai);
     pNew->data = nilai;
     while(pPre->next!=pList){
                         pPre=pPre->next; }
     pNew->next=pList;
     pPre->next=pNew;

}

void hapusAwal(){
     node *pEnd, *pHapus;
     pEnd=pList;
     pHapus=pList;
     while(pEnd->next!=pList){
                              pEnd=pEnd->next;}
     pEnd->next=pHapus->next;
     pList=pList->next;
     free(pHapus);
}

void hapusTengah(){
     node *pCari,*pPre;int hapus;
     pPre=pList;
     pCari=pList;
     cetak();
     printf("masukkan bilangan yang ingin dihapus: "); scanf("%d",&hapus);
     while(pCari->data!=hapus){
                               pCari=pCari->next; }
     while(pPre->next!=pCari){
                              pPre=pPre->next;}
     pPre->next=pCari->next;
     free(pCari);

}

void hapusAkhir(){
     node *pEnd,*pPre;
     pEnd=pList;
     pPre=pList;
     while(pEnd->next!=pList){
                              pEnd=pEnd->next;}
     while(pPre->next!=pEnd){
                             pPre=pPre->next;}
     pPre->next=pList;
     free(pEnd);
}


int main(int argc, char *argv[])
{
  node *pNew; int pilih,bil;
  do{system("cls");
   printf("----------MENU-----------");
    printf("\n1.tambah awal");
    printf("\n2.tambah tengah");
    printf("\n3.tambah akhir");
    printf("\n4.hapus awal ");
    printf("\n5.hapus tengah");
    printf("\n6.hapus akhir");
    printf("\n7.cetak");
    printf("\n8.exit");
    printf("\npilihan : ");scanf("%d",&pilih);

    if(pilih==1){pNew=alokasiNodeBaru();
                 printf("masukkan bilangan: ");
                 scanf("%d",&bil);
                 pNew->data=bil;
                 tambahAwal(pNew);
                 }
    else if(pilih==2){pNew=alokasiNodeBaru();
                 tambahTengah(pNew);
                 }
    else if(pilih==3){pNew=alokasiNodeBaru();
                 tambahAkhir(pNew);
                 }
    else if(pilih==4){hapusAwal();}
    else if(pilih==5){hapusTengah();}
    else if(pilih==6){hapusAkhir();}
    else if(pilih==7){cetak();getch();}



}while(pilih!=8);


  /*
  cetak();
  pNew = alokasiNodeBaru();
  tambahTengah(pNew);
  */
  printf("\n");
  system("PAUSE");
  return 0;
}
