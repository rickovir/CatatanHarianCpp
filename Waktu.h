#include <ctime>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include<windows.h>
#include <sstream>
#include <string>
using namespace std;
class Waktu{
	private :
//	const char* MONTHS[] =
//	{
//		"January", "February", "March", "April", "May", "June",
//		"July", "August", "September", "October", "November", "December"
//	};
//	
//	const char* day[] =
//	{			
//		"minggu",
//		"senin",
//		"selasa",
//		"rabu",
//		"kamis",
//		"jumat",
//		"sabtu"
//	};
	time_t rawtime;
	tm* timeinfo;
		string hariMinggu(int hari)
		{
			switch(hari)
			{
				case 0:
					return "Minggu";
				break;
				case 1:
					return "Senin";
				break;
				case 2:
					return "Selasa";
				break;
				case 3:
					return "Rabu";
				break;
				case 4:
					return "Kamis";
				break;
				case 5:
					return "Jumat";
				break;
				case 6:
					return "Sabtu";
				break;
			}
		}
		string bulan(int bln)
		{
			switch(bln)
			{
				case 0:
					return "Januari";
				break;
				case 1:
					return "Februari";
				break;
				case 2:
					return "Maret";
				break;
				case 3:
					return "April";
				break;
				case 4:
					return "Mei";
				break;
				case 5:
					return "Juni";
				break;
				case 6:
					return "Juli";
				break;
				case 7:
					return "Agustus";
				break;
				case 8:
					return "September";
				break;
				case 9:
					return "Oktober";
				break;
				case 10:
					return "November";
				break;
				case 11:
					return "Desember";
				break;
			}
		}
	public:
		string getHari()
		{
			return toString(timeinfo->tm_mday);
		}
		string getHariMinggu()
		{
			return hariMinggu(timeinfo->tm_wday);
		}
		string getBulan()
		{
			return bulan(timeinfo->tm_mon);
		}
		string getTahun()
		{
			return toString(timeinfo->tm_year + 1900);
		}
		string getAll()
		{
			string res ="";
			res +=getHari();
			res += "-";
			res +=getBulan();
			res +="-";
			res +=getTahun();
			return res;
		}
		string toString(int number)
		{
			ostringstream os;
			os<<number;
			return os.str();
		}
		Waktu()
		{		
			time(&rawtime);
			timeinfo = localtime( &rawtime );
			
		}
};
