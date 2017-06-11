#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include "Waktu.h"
using namespace std;

class CatatanHarian{
	private:
		int id;
		int prioritas;
		string detail;
		string status;
		string tanggal;
		Waktu w;
		
		void replaceString(string& str, const string& from, const string& to) {
		    if(from.empty())
		        return;
		    size_t start_pos = 0;
		    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		        str.replace(start_pos, from.length(), to);
		        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
		    }
		}
		
		void kosongkan()
		{
			id = 0;
			prioritas = 0;
			detail ="";
			status ="";
		}
		
	public:
		void setId(int idBaru)
		{
			id = idBaru;
		}
		
		int getId()
		{
			return id;
		}
		
		void setPrioritas(int prioritasBaru)
		{
			prioritas = prioritasBaru;
		}
		
		int getPrioritas()
		{
			return prioritas;
		}
		
		void setDetail(string detailBaru)
		{
			replaceString(detailBaru," ", "#");
			detail = detailBaru;
		}
		
		string getDetail()
		{
			string detailOut = detail;
			replaceString(detailOut,"#"," ");
			return detailOut;
		}
		
		void setStatus(string statusBaru)
		{
			replaceString(statusBaru," ", "#");
			status = statusBaru;
		}
		
		string getStatus()
		{
			return status;
		}
		
		string getTanggal()
		{
			return tanggal;
		}
		
		void tambahAktifitas()
		{
			ofstream tulis;
			tulis.open("data.txt", ios::app);
			tulis<<id<<"  "<<prioritas<<"  "<<detail<<"   "<<status<<endl;
			
			tulis.close();
			kosongkan();
		}
		
		void tampilAktifitas(string statusCek = "all")
		{
			ifstream baca ("data.txt");
			int n = 1;
			if(statusCek == "all")
			{
				while(baca >> id >> prioritas >> detail >> status)
				{
					replaceString(detail, "#", " ");
					cout<<"Ke : "<<n<<endl;
					cout<<"ID         = "<<id<<endl;
					cout<<"Prioritas  = "<<prioritas<<endl;
					cout<<"Detail     = "<< detail<<endl;
					cout<<"Status     = "<<status<<endl;
					n++;
				}
			}
			else if(statusCek == "selesai")
			{
				while(baca >> id >> prioritas >> detail >> status)
				{
					if(status == statusCek)
					{	
						replaceString(detail, "#", " ");
						cout<<"-------------------------"<<endl;
						cout<<"Ke : "<<n<<endl;
						cout<<"ID         = "<<id<<endl;
						cout<<"Prioritas  = "<<prioritas<<endl;
						cout<<"Detail     = "<< detail<<endl;
						cout<<"Status     = "<<status<<endl;
						cout<<"-------------------------"<<endl;
						n++;
						
					}
				}
			}
			else if(statusCek == "belum")
			{
				while(baca >> id >> prioritas >> detail >> status)
				{
					if(status == statusCek)
					{
						replaceString(detail, "#", " ");
						cout<<"-------------------------"<<endl;
						cout<<"Ke : "<<n<<endl;
						cout<<"ID         = "<<id<<endl;
						cout<<"Prioritas  = "<<prioritas<<endl;
						cout<<"Detail     = "<< detail<<endl;
						cout<<"Status     = "<<status<<endl;
						cout<<"-------------------------"<<endl;
						n++;
					}
				}
			}
			baca.close();
			kosongkan();
		}
		
		void tampilkanSesuaiPrioritas(int prioritasCek = 4)
		{
			ifstream baca ("data.txt");
			int n = 1;
			while(baca >> id >> prioritas >> detail >> status)
			{
				if(prioritas == prioritasCek)
				{
					replaceString(detail, "#", " ");
					cout<<"Ke : "<<n<<endl;
					cout<<"ID           = "<<id<<endl;
					cout<<"Prioritas    = "<<prioritas<<endl;
					cout<<"Detail       = "<< detail<<endl;
					cout<<"Status       = "<<status<<endl<<endl;
					n++;
				}
			}
			baca.close();
			kosongkan();
		}
		
		void editAktifitas()
		{
			int idTemp;
			int prioritasTemp;
			string detailTemp;
			string statusTemp;
			ifstream baca ("data.txt");
			ofstream tulis;
			tulis.open("output.txt", ios::app);
			while(baca >> idTemp >> prioritasTemp >> detailTemp >> statusTemp)
			{
				if(id == idTemp)
					tulis<<id<<"  "<<prioritas<<"  "<<detail<<"   "<<status<<endl;
			}
			tulis.close();
			baca.close();
			remove("data.txt");
			rename("output.txt","data.txt");
			kosongkan();
		}
		
		void menuCatatan()
		{
			cout<<"=========================="<<endl;
			cout<<"--------"<<w.getAll()<<"-------"<<endl;
			cout<<"1. tambah"<<endl;
			cout<<"2. edit"<<endl;
			cout<<"3. tampil sesuai prioritas"<<endl;
			cout<<"4. tampil sesuai status"<<endl;
			cout<<"=========================="<<endl;
			cout<<"Pilih menu =";
		}
		
		~CatatanHarian()
		{
			id = 0;
			prioritas = 0;
			status="";
			detail ="";
			tanggal ="";
		}
		
		CatatanHarian()
		{
			id = 0;
			prioritas = 0;
			detail ="";
			status ="";
			tanggal = w.getAll();
		}
};

int main()
{
	system("color f0");
	CatatanHarian c;
	char lagi;
	do
	{
		system("cls");
		char pil;
		c.menuCatatan();
		cin>>pil;
		system("cls");
		if(pil == '1' || pil == '2')
		{
			int idTemp, priorTemp;
			string detailTemp,statusTemp;
			cout<<"---------------------------------"<<endl;
			cout<<"ID                  =     "; cin>>idTemp;
			cout<<"Priotitas <1/2/3/4> =     "; cin>>priorTemp;
			cout<<"Detail              =     ";	cin.ignore();
			getline(cin, detailTemp);
			cout<<"Status <selesai / belum> = ";cin>>statusTemp;
			cout<<"---------------------------------"<<endl;
			c.setId(idTemp);
			c.setPrioritas(priorTemp);
			c.setDetail(detailTemp);
			c.setStatus(statusTemp);
			
			if(pil == '1')
			{
				c.tambahAktifitas();	
			}
			else
			{
				c.editAktifitas();
			}
		}
		else if(pil == '3')
		{
			cout<<"--------------------------"<<endl;
			int priorTemp;
			cout<<"Tampil prioritas <1/2/3/4>: "; cin>>priorTemp;
			cout<<"_________________________"<<endl;
			c.tampilkanSesuaiPrioritas(priorTemp);
			cout<<"--------------------------"<<endl;
		}
		else if(pil == '4')
		{
			string statusTemp;
			cout<<"--------------------------"<<endl;
			cout<<"Tampil status <all/selesai/belum> : ";
			cin>>statusTemp;
			c.tampilAktifitas(statusTemp);
			cout<<"--------------------------"<<endl;
		}
		else
			cout<<"menu tidak ada";
		
		cout<<endl<<"lanjut ? Y/N : "; cin>>lagi;
	}
	while(lagi=='Y' || lagi =='y');
}
