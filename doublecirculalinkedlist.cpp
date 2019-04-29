#include "stdio.h"
typedef struct Tnode
{
 int value;
 Tnode *next;
 Tnode *back;
};

Tnode *baru, *bantu,*head,*tail, *bantudelete;

void tambah(int value)
{
     baru = new Tnode;
     baru->next = baru;
     baru->back = baru;
     baru->value = value;
}
void tambahbelakang(int value)
{
     tambah(value);
     if(head == NULL)
        head = tail = baru;
     else
     {
        tail->next = baru;
        baru->back = tail;
        tail = baru;
     }
     tail->next = head;
     head->back = tail;
}
void deletebelakang()
{
     if(head == NULL)
        head = tail = NULL;
     else
     {
        bantudelete = tail;
        tail = tail->back;
        tail->next = head;
        head->back = tail;
        delete bantudelete;
     }
}

void cetak()
{
     if(head != NULL)
     {bantu = head;
     do
     {
      printf("%d",bantu->value);
      bantu = bantu->next;
     }while(bantu!=head);
     }else
     printf("tidak ada data");
 }
void menu()
{
     int pil;
     int isi;
     do
     {
         printf("Menu :\n1.Masuk dari belakang\n2.Delete dari belakang\n3.Cetak\n4.Exit\nMasukkan pilihan anda");
         scanf("%d",&pil);
         switch(pil)
         {
                    case 1 :
                         printf("Masukkan nilai : "); scanf("%d",&isi);
                         tambahbelakang(isi);
                         break;
                    case 2 :
                         deletebelakang();
                         break;
                    case 3 : cetak();
                         break;
                    case 4 : printf("Terima kasih");
                         break;

                    default:
                            printf("Tidak ada pilihan tersebut, masukkan angka dari 1 sampai 3");
         }
     }while(pil!=4);
 }

int main(){
    	menu();
 	return 0;
}
