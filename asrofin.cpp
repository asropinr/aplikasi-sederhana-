#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
int data;	
cout<<"Masukkan jumlah data yang ingin di inputkan : ";cin>>data;
	struct motor{
		int kode;
		char nama[30];
		int cc;
		int b;
		int hrg;
	};
 struct motor mt[data];

for(int i=0; i<data; i++){
	cout<<"Data motor"<<i+1<<endl;
	cout<<"masukkan kode motor : ";cin>>mt[i].kode;
	cout<<"masukkan nama motor : ";cin>>mt[i].nama;
	cout<<"masukkan cc motor : ";cin>>mt[i].cc;
	cout<<"masukkan banyak motor di gudang : ";cin>>mt[i].b;
	cout<<"masukkan harga motor : ";cin>>mt[i].hrg;
	cout<<"================================="<<endl;
}

system("cls");
cout<<"====Dealer motor penuh berkah===="<<endl;
cout<<"================================="<<endl;
for(int i=0; i<data; i++){
	cout<<mt[i].kode<<" "<<mt[i].nama<<endl;
}
char cari[30];
cout<<"masukkan motor yang anda cari : ";cin>>cari;


for(int i=0; i<data; i++){
if(strcmpi(mt[i].nama,cari)==0){
	cout<<"\nmotor "<<" ' "<<cari<<" ' "<<" memiliki spesifikasi seperti berikut : "<<endl;
	cout<<"\nisi silinder : "<<mt[i].cc<<"cc";
	cout<<"\nbanyak motor di gudang : "<<mt[i].b;
	cout<<"\nharga motor/unit : "<<mt[i].hrg;
}else{
	0;
}
}


getch();
}
