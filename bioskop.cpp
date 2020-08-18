#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
/* 
Asrofin Widyantomo Rahardjo 16.12.9020
Dheana Titaura Hanindita 16.12.8984
Tio Amir Putera Budiman 16.12.8987
Hanna Aulia Pertiwi Korompot 16.12.9024
*/

struct T{
	int harga;
	char film[30];
	int tiket;
	int total;
	T *next;
	T *prev;
};

T *head=NULL, *tail=NULL, *current=NULL, *temp=NULL, *b1, *b2;

int empty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

void input(int biaya,int tkt,char judul[30]){
	T *baru;
	baru = new T;
	baru->harga=biaya;
	baru->tiket=tkt;
	baru->total=tkt*biaya;
	strcpy(baru->film,judul);
	baru->next=NULL;
	baru->prev=NULL;
	
	if(empty()==1){
		head=baru;
		tail=baru;
	
	}else{
		tail->next=baru;
		baru->prev=tail;
		tail=baru;
	}
	cout<<"\n Data telah ditambahkan"<<endl;
}


void hapus(){
	T *hapus;
	int biaya;
	char judul[30];
	
	if(empty()==1){
		cout<<"Data Kosong"<<endl;
	}
	else if(head->next==NULL) {
		hapus=head;
		biaya=hapus->harga;
		strcpy(hapus->film,judul);
		
		head=NULL;
		tail=NULL;
		delete hapus;
		cout<<endl<<"Data telah Terhapus"<<endl;
	}
	else{
		hapus=head;
		biaya=hapus->harga;
		strcpy(hapus->film,judul);
		head=hapus->next;
		head->prev=NULL;
		delete hapus;
		cout<<endl<<"Data telah Terhapus"<<endl;
	}
}
	

void tampil(){
	T *z;
	if(empty()==1)
		cout<<"Data Kosong";
	else{
		cout<<"Harga tiket film : "<<endl<<endl;
		z=head;
		while(z!=NULL){
			cout<<" Judul Film  : "<<z->film<<endl;
			cout<<" Harga Film : "<<z->tiket<<endl;
			cout<<" Harga tiket : "<<z->harga<<endl;
			cout<<" Total bayar : "<<z->total<<endl<<endl;
			z=z->next;
		}
	}
}

void searching(char judul[30])
{
    T *search = NULL;
	T *temp = head;
	T *current= head;
	
	while(current!=NULL && (strcmpi(current->film,judul) != 0)){
	temp = current;
	current = current->next;
	}
	
	if (current != NULL)
    {
        search = current;
        cout<<endl<<" Judul Film = "<<search->film<<endl;
        cout<<" Harga tiket film = "<<search->harga<<endl;
    }
    else
    {
        cout<<endl<<" Data tidak ditemukan"<<endl;
    }

	
}

void sorting(){
	int temp;
	
	cout<<"Urutan harga tiket film : "<<endl<<endl;
	for(b1=head;b1!=NULL;b1=b1->next){
		for(b2=b1->next;b2!=NULL;b2=b2->next){
			if(b1->harga > b2->harga){
			temp = b1->harga;
			b1->harga = b2->harga;
			b2->harga= temp;
			}
	}
}

for(b1=head;b1!=NULL;b1=b1->next){
	cout<< b1->film<<" ";
	cout<< b1->harga<<endl;
	}
}



main(){
	int pil;
	
	do{
		int biaya;
		int tkt;
		char judul[30];
		
		cout<<"\n==========================================\n";
		cout<<"==========   Program Bioskop    =========="<<endl;
		cout<<"==========================================\n";
		cout<<"[1.]  Masukkan Film dan Harga tiketnya"<<endl;
		cout<<"[2.]  Hapus Film" <<endl;
		cout<<"[3.]  Tampilkan"<<endl;
		cout<<"[4.]  Mencari Judul Film"<<endl;
		cout<<"[5.]  Mengurutkan Harga Film "<<endl;
		cout<<"[6.]  Exit Program"<<endl;
		cout<<"==========================================\n";
		cout<<"Masukkan Pilihan = "; cin>>pil;
		cout<<"==========================================";
		cout<<endl;
		
		switch(pil){
					 
			case 1 : cout<<"Masukkan Judul Film  = ";cin>>judul;
					 cout<<"Masukkan Harga tiket film = ";cin>>biaya;
					 cout<<"Masukkan Jumlah Tiket = ";cin>>tkt;
					 empty();
					 input(biaya,tkt,judul);
					 break;
					 
			case 2 : hapus();
					 break;
					 
			case 3 : empty();
					 tampil();
					 break;
					 
			case 4 : cout<<"Masukkan judul film yang akan dicari = ";cin>>judul;
					 searching(judul);
					 break;
			
			case 5 : sorting();
					 break;
					 
			case 6 : return 0; break;
					 
		}
	}while(pil!=8);
}
