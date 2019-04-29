#include <iostream>
#include<string>

using namespace std;

struct mahasiswa{
//membuat tipe data struct yang berfungsi menyimpan data yang berbeda.
int no_peserta;
int nim;
char kelas;

mahasiswa*next; //nams_sturct*next.
};

void printlist(mahasiswa*n) //membuat fungsi printlist
{
while (n!=NULL) //syarat n tidak samadengan null
{
cout<<"no peserta:"<<n->no_peserta<<""<<endl;
cout<<"nim:"<<n->nim<<""<<endl;
cout<<"kelas:"<<n->kelas<<""<<endl;
cout<<""<<endl;

//n-,data adalah sebuah variabel yang akan di panggil
n=n->next;
}
}

int main()
{
mahasiswa*head=NULL;
mahasiswa*second=NULL;
mahasiswa*third=NULL;

head= new mahasiswa();
second= new mahasiswa();
third= new mahasiswa();

head->no_peserta = 3;
head->nim = 18140016;
head->kelas = 'b';
head->next = second;

second->no_peserta = 4;
second->nim = 1829140011;
second->kelas = 'b';
second->next = third;

third->no_peserta = 5;
third->nim = 1829140018;
third->kelas = 'b';
third->next = NULL;

printlist(head);

cin.get();
return 0;
}
