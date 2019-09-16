#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
#include <vector>
 
using namespace std;


int const rozmiar = 16;
int widocznosc= 0;

class Wynik{

public:
	vector<int> tab_wyniki;	
	
	Wynik(){
	vector<int> tab_wyniki;	
	}
	
	void Dodaj(int i){
	
	tab_wyniki.push_back( i );
}
	
	int Zlicz(){
	int zlicz;
	for(int i=0;i<tab_wyniki.size();i++)
		zlicz=zlicz+tab_wyniki[0];
		
	return zlicz;
	}
};




class status  
{
public:
  	char stan;
  	int typ;
  	
// 	int statek= 0;
// 	int trafiony=1;
// 	int zatopiony=2; 
// 	int woda= 3;
//  int pudlo= 4;
  	
  	
  	
  
  	status(){
  	stan='~';
  	typ=3;
 	 }

	void wyswietl(int i){
    if(i)  
		cout << stan << "  ";
	else  
		if(stan== char(254)) 
		cout << "~  " ;
		else
		cout << stan << "  ";
}
};

class Plansza
{
public:
	int rozmiar;
	status ***tab;
	Plansza(int rozmiar=16){
		this->rozmiar = rozmiar;
		tab=new status**[rozmiar];   
  		for(int i=0; i<rozmiar; i++)  
  		{		
  			tab[i]=new status*[rozmiar];					
    		for(int j=0; j<rozmiar; j++)
	 	{
		tab[i][j]=new status();  
	  	}
  }
};
void Wyswietl1(int rozmiar=16)
{
	
	//system("cls"); 
	widocznosc=true;
	
	for(int i=1; i<=rozmiar; i++)  
    {
	cout << setw(2) << i << " ";  
    for(int j=1; j<=rozmiar; j++)
		 tab[i-1][j-1]->wyswietl(1); 
	
	
	switch(i)
	{
		case 1:
			cout << " ~  Pole puste nieostrzelane";
			break;
		case 2:
			cout << " o  Maszt ostrzelany";
			break;
		case 3:
			cout << " /  Maszt zatopiony";
			break;
		case 4:
			cout << " X  Pud³o";
			break;

    }
	cout << endl;
  }
  cout << "   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16\n\n";
}

void Wyswietl2(int rozmiar=16)
{
	widocznosc=false;
	 
	for(int i=1; i<=rozmiar; i++)  
    {
	cout << setw(2) << i << " ";  
    for(int j=1; j<=rozmiar; j++)
		 tab[i-1][j-1]->wyswietl(0); 
		 
	switch(i)
	{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
		
			break;
		case 4:
			
			break;

    }
	cout << endl;	 
  }
  cout << "   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16\n\n";
}
};
class Statki
{
public:
	virtual bool StatusStatku() 
	{
	return true;
	};
	virtual void Stworz(int x, int y,  Plansza &plansza, bool polozenie) {};
};

class Lotniskowiec : public Statki
{
public:
	int x, y;   
	bool polozenie;    
    status* lotniskowiec[5];   
	
	void Stworz(int x, int y, Plansza &plansza, bool polozenie){
		this->x = x;
		this->y = y;
		this->polozenie = polozenie;
		
		for(int i=0; i<5; i++)
		{
			if(polozenie)
			lotniskowiec[i]=plansza.tab[y+i][x];	
			else
			lotniskowiec[i]=plansza.tab[y][x+i];
			
			if(polozenie)
				plansza.tab[y+i][x] ->stan=char(254); 
			else
				plansza.tab[y][x+i] ->stan=char(254); 
			
			if(polozenie)
				plansza.tab[y+i][x] -> typ=0;
			else
				plansza.tab[y][x+i] -> typ=0;
		}
	};
	
	bool StatusStatku(){
		int zycie=5;
		for(int i=0; i<5; i++)
	{
		if(lotniskowiec[i]->typ==1 || lotniskowiec[i]->typ==2)   
			zycie--;   
	}
	if(zycie>0) 
	return true; 
	else 
	return false;
	}
};

class Pancernik : public Statki
{
public:
	int x, y;   
	bool polozenie;    
    status* pancernik[4];   
	
	void Stworz(int x, int y, Plansza &plansza, bool polozenie){
		this->x = x;
		this->y = y;
		this->polozenie = polozenie;
		
		for(int i=0; i<4; i++)
		{
			if(polozenie)
			pancernik[i]=plansza.tab[y+i][x];	
			else
			pancernik[i]=plansza.tab[y][x+i];
			
			if(polozenie)
				plansza.tab[y+i][x] ->stan=char(254); 
			else
				plansza.tab[y][x+i] ->stan=char(254); 
			
			if(polozenie)
				plansza.tab[y+i][x] -> typ=0;
			else
				plansza.tab[y][x+i] -> typ=0;
		}
	};
	
	bool StatusStatku(){
		int zycie=4;
		for(int i=0; i<4; i++)
	{
		if(pancernik[i]->typ==1 || pancernik[i]->typ==2)   
			zycie--;  
	}
	if(zycie>0) 
	return true; 
	else 
	return false;
	}
};

class Niszczyciel : public Statki
{
	public:
	int x, y;   
	bool polozenie;    
    status* niszczyciel[3];   
	
void Stworz(int x, int y, Plansza &plansza, bool polozenie){
		this->x = x;
		this->y = y;
		this->polozenie = polozenie;
		
		for(int i=0; i<3; i++)
		{
			if(polozenie)
			niszczyciel[i]=plansza.tab[y+i][x];	
			else
			niszczyciel[i]=plansza.tab[y][x+i];
			
			if(polozenie)
				plansza.tab[y+i][x] ->stan=char(254); 
			else
				plansza.tab[y][x+i] ->stan=char(254); 
			
			if(polozenie)
				plansza.tab[y+i][x] -> typ=0;
			else
				plansza.tab[y][x+i] -> typ=0;
		}
	};
	
	bool StatusStatku(){
		int zycie=3;
		for(int i=0; i<3; i++)
	{
		if(niszczyciel[i]->typ==1 || niszczyciel[i]->typ==2)   
			zycie--;   
	}
	if(zycie>0) 
	return true; 
	else 
	return false;
	}
};

class Torpedowiec : public Statki
{
public:
	int x, y;   
	bool polozenie;   
    status* torpedowiec[2];   
	
	void Stworz(int x, int y, Plansza &plansza, bool polozenie){
		this->x = x;
		this->y = y;
		this->polozenie = polozenie;
		
		for(int i=0; i<2; i++)
		{
			if(polozenie)
			torpedowiec[i]=plansza.tab[y+i][x];	
			else
			torpedowiec[i]=plansza.tab[y][x+i];
			
			if(polozenie)
				plansza.tab[y+i][x] ->stan=char(254); 
			else
				plansza.tab[y][x+i] ->stan=char(254); 
			
			if(polozenie)
				plansza.tab[y+i][x] -> typ=0;
			else
				plansza.tab[y][x+i] -> typ=0;
		}
}
	
	
	bool StatusStatku(){
		int zycie=2;
		for(int i=0; i<2; i++)
	{
		if(torpedowiec[i]->typ==1 || torpedowiec[i]->typ==2)   
			zycie--;   
	}
	if(zycie>0) 
	return true; 
	else 
	return false;
	}
};
	Lotniskowiec lotniskowiec1;
	Pancernik pancernik1;
	Niszczyciel niszczyciel1;
	Torpedowiec torpedowiec1;
	Lotniskowiec lotniskowiec2;
	Pancernik pancernik2;
	Niszczyciel niszczyciel2;
	Torpedowiec torpedowiec2;
	
	
int IleStatkow(int ilosc)  
{
	int ile=0; 
	Statki *tab[4]={&lotniskowiec1, &pancernik1, &niszczyciel1, &torpedowiec1};     
	for(int i=0; i<4; ++i)                              
		if((*(tab[i])).StatusStatku()) ile++;              
	if(ilosc) cout << "Statki komputera: " << ile << endl;
	
	if(ile==0)
	cout << "Wygrales! Zatopiles wszystkie statki komputera " << ile << endl;
	return ile;
}
int IleStatkow2(int ilosc)  
{
	int ile=0; 
	Statki *tab[4]={&lotniskowiec2, &pancernik2, &niszczyciel2, &torpedowiec2};     
	for(int i=0; i<4; ++i)                              
		if((*(tab[i])).StatusStatku()) ile++;              
	if(ilosc) cout << "Twoje statki: " << ile << endl;
	
	if(ile==0)
	cout << "Przegrales! Komputer zatopil wszystkie twoje statki " << ile << endl;
	return ile;
}


void Atak(Plansza &plansza, Lotniskowiec &lotniskowiec, Pancernik &pancernik, Niszczyciel &niszczyciel, Torpedowiec &torpedowiec )
{
	bool CzyZatopiony=false;
	int x,y;
	

	do    
	{
		cout << "Podaj x: ";
		cin >> x;
		cout << "Podaj y: ";
		cin >> y;
		if(x>16 || y>16 || x<0 || y<0) 
		{
        	cout << "Zle wspolrzedne\n";
		}
	} while(x>16 || y>16 || x<0 || y<0); 
	
	char temp=plansza.tab[y-1][x-1]->stan;
	switch (temp)
	{
	case '~': 
		plansza.tab[y-1][x-1]->stan='X';  
		plansza.tab[y-1][x-1]->typ=4;
		
		break;
	case char(254):
	case 'o':
		plansza.tab[y-1][x-1]->stan='o';
		plansza.tab[y-1][x-1]->typ=1;
		
		break;
	}
	Statki *tab;
	tab=&lotniskowiec;
	if(lotniskowiec.StatusStatku()==false) 
	{
		for(int i=1; i<=5; i++)
		{
			if(lotniskowiec.polozenie)
			plansza.tab[lotniskowiec.y+5-i][lotniskowiec.x]->stan='\\';
			else
			plansza.tab[lotniskowiec.y][lotniskowiec.x+5-i]->stan='\\';
			
			
			
			if(lotniskowiec.polozenie) 
			plansza.tab[lotniskowiec.y+5-i][lotniskowiec.x]->typ=2;
			else
			plansza.tab[lotniskowiec.y][lotniskowiec.x+5-i]->typ=2;
		}
	}
	if(pancernik.StatusStatku()==false) 
	{
		for(int i=1; i<=4; i++)
		{
			if(pancernik.polozenie)
			plansza.tab[pancernik.y+4-i][pancernik.x]->stan='\\';
			else
			plansza.tab[pancernik.y][pancernik.x+4-i]->stan='\\';
			
			
			
			if(pancernik.polozenie) 
			plansza.tab[pancernik.y+4-i][pancernik.x]->typ=2;
			else
			plansza.tab[pancernik.y][pancernik.x+4-i]->typ=2;
		}
	}
	
	if(niszczyciel.StatusStatku()==false)  
	{
			for(int i=1; i<=3; i++)
		{
			if(niszczyciel.polozenie)
			plansza.tab[niszczyciel.y+3-i][niszczyciel.x]->stan='\\';
			else
			plansza.tab[niszczyciel.y][niszczyciel.x+3-i]->stan='\\';
			
			
			
			if(niszczyciel.polozenie) 
			plansza.tab[niszczyciel.y+3-i][niszczyciel.x]->typ=2;
			else
			plansza.tab[niszczyciel.y][niszczyciel.x+3-i]->typ=2;
		}
	}
	
	if(torpedowiec.StatusStatku()==false)  
	{
		for(int i=1; i<=2; i++)
		{
			if(torpedowiec.polozenie)
			plansza.tab[torpedowiec.y+2-i][torpedowiec.x]->stan='\\';
			else
			plansza.tab[torpedowiec.y][torpedowiec.x+2-i]->stan='\\';
			
			
			
			if(torpedowiec.polozenie) 
			plansza.tab[torpedowiec.y+2-i][torpedowiec.x]->typ=2;
			else
			plansza.tab[torpedowiec.y][torpedowiec.x+2-i]->typ=2;
		}
	}
	

}

void Atak2(Plansza &plansza, Lotniskowiec &lotniskowiec, Pancernik &pancernik, Niszczyciel &niszczyciel, Torpedowiec &torpedowiec )
{
	bool CzyZatopiony=false;
	int x,y=0;
	
	x=rand()%15+1;	
	y=rand()%15+1;
	
	char temp=plansza.tab[y-1][x-1]->stan;
	switch (temp)
	{
	case '~': 
		plansza.tab[y-1][x-1]->stan='X'; 
		plansza.tab[y-1][x-1]->typ=4;
		
		break;
	case char(254):
	case 'o':
		plansza.tab[y-1][x-1]->stan='o';
		plansza.tab[y-1][x-1]->typ=1;
		break;
	}
	Statki *tab;
	tab=&lotniskowiec;
	if(lotniskowiec.StatusStatku()==false)  
	{
		for(int i=1; i<=5; i++)
		{
			if(lotniskowiec.polozenie)
			plansza.tab[lotniskowiec.y+5-i][lotniskowiec.x]->stan='\\';
			else
			plansza.tab[lotniskowiec.y][lotniskowiec.x+5-i]->stan='\\';
			
			
			
			if(lotniskowiec.polozenie) 
			plansza.tab[lotniskowiec.y+5-i][lotniskowiec.x]->typ=2;
			else
			plansza.tab[lotniskowiec.y][lotniskowiec.x+5-i]->typ=2;
		}
	}
	if(pancernik.StatusStatku()==false)  
	{
		for(int i=1; i<=4; i++)
		{
			if(pancernik.polozenie)
			plansza.tab[pancernik.y+4-i][pancernik.x]->stan='\\';
			else
			plansza.tab[pancernik.y][pancernik.x+4-i]->stan='\\';
			
			
			
			if(pancernik.polozenie) 
			plansza.tab[pancernik.y+4-i][pancernik.x]->typ=2;
			else
			plansza.tab[pancernik.y][pancernik.x+4-i]->typ=2;
		}
	}
	
	if(niszczyciel.StatusStatku()==false)  
	{
			for(int i=1; i<=3; i++)
		{
			if(niszczyciel.polozenie)
			plansza.tab[niszczyciel.y+3-i][niszczyciel.x]->stan='\\';
			else
			plansza.tab[niszczyciel.y][niszczyciel.x+3-i]->stan='\\';
			
			
			
			if(niszczyciel.polozenie) 
			plansza.tab[niszczyciel.y+3-i][niszczyciel.x]->typ=2;
			else
			plansza.tab[niszczyciel.y][niszczyciel.x+3-i]->typ=2;
		}
	}
	
	if(torpedowiec.StatusStatku()==false)  
	{
		for(int i=1; i<=2; i++)
		{
			if(torpedowiec.polozenie)
			plansza.tab[torpedowiec.y+2-i][torpedowiec.x]->stan='\\';
			else
			plansza.tab[torpedowiec.y][torpedowiec.x+2-i]->stan='\\';
			
			
			
			if(torpedowiec.polozenie) 
			plansza.tab[torpedowiec.y+2-i][torpedowiec.x]->typ=2;
			else
			plansza.tab[torpedowiec.y][torpedowiec.x+2-i]->typ=2;
		}
	}
	

}

int main()
{
	srand(time(NULL));
	bool polozenie=rand()%2;
	Plansza planszagracza;
	Plansza planszakomputera;
	
	int x,y;
	Statki *tab=&lotniskowiec1;
	if(polozenie)
	x=rand()%15+1;
	else
	x=rand()%12+1;
	
	if(polozenie)
	y=rand()%12+1;
	else
	y=rand()%15+1;
	
	
	(*tab).Stworz(x,y,planszakomputera,polozenie);  
	polozenie=rand()%2; 
	x=0, y=0;
	do                                                          
	{    
		if(polozenie)
		x=rand()%15+1;
		else
		x=rand()%12+1;                                                      
		if(polozenie)
		y=rand()%12+1;
		else
		y=rand()%15+1;         
	}	while((abs(x - lotniskowiec1.x)<4) || (abs(y - lotniskowiec1.y)<4));  
	tab=&pancernik1;
	(*tab).Stworz(x,y,planszakomputera,polozenie);
	polozenie=rand()%2;
	do                                                          
	{                                                          
		if(polozenie)
		x=rand()%15+1;
		else
		x=rand()%12+1;             
		if(polozenie)
		y=rand()%12+1;
		else
		y=rand()%15+1;          
	}	while((abs(x - lotniskowiec1.x)<3 || abs(x - pancernik1.x)<3) || (abs(y - lotniskowiec1.y)<3 || abs(y - pancernik1.y)<3));
	tab=&niszczyciel1;
	(*tab).Stworz(x,y,planszakomputera,polozenie);
	polozenie=rand()%2;
	do                                                          
	{                                                        
		if(polozenie)
		x=rand()%15+1;
		else
		x=rand()%12+1;            
		if(polozenie)
		y=rand()%12+1;
		else
		y=rand()%15+1;         
	}	while((abs(x - lotniskowiec1.x)<2 && (abs(y - lotniskowiec1.y)<2) || (abs(x - pancernik1.x)<2 && abs(y - pancernik1.y)<2) || (abs(x - niszczyciel1.x)<2) && abs(y - niszczyciel1.y)<2));
	tab=&torpedowiec1;
	(*tab).Stworz(x,y,planszakomputera,polozenie);
	polozenie=rand()%2;
	
	int xs,ys,ws;
//	{'lotniskowca', 'pancernika', 'niszczyciela','torpedowca'};

	planszagracza.Wyswietl1();
	planszakomputera.Wyswietl2();
	
	cout << "Podaj wspolrzedne lotniskowca (dlugosc 5)"<< endl;
	do    
	{
		cout << "Podaj x: ";
		cin >> xs;
		cout << "Podaj y: ";
		cin >> ys;
		if(xs>16 || ys>16 || xs<0 || ys<0) 
		{
        	cout << "Zle wspolrzedne\n";
		}
	} while(xs>16 || ys>16 || xs<0 || ys<0); 

	cout << "Podaj ulozenie poziome - 0 , pionowe - 1 :";
	cin >> ws;
	lotniskowiec2.Stworz(xs-1,ys-1,planszagracza,ws);
	system("cls");
	planszagracza.Wyswietl1();
	planszakomputera.Wyswietl2();
	cout << "Podaj wspolrzedne pancernika (dlugosc 4)"<< endl;
		do    
	{
		cout << "Podaj x: ";
		cin >> xs;
		cout << "Podaj y: ";
		cin >> ys;
		if(xs>16 || ys>16 || xs<0 || ys<0) 
		{
        	cout << "Zle wspolrzedne\n";
		}
	} while(xs>16 || ys>16 || xs<0 || ys<0); 
	cout << "Podaj ulozenie poziome - 0 , pionowe - 1 :";
	cin >> ws;
	pancernik2.Stworz(xs-1,ys-1,planszagracza,ws);
	system("cls");	
	planszagracza.Wyswietl1();
	planszakomputera.Wyswietl2();
	cout << "Podaj wspolrzedne niszczyciela (dlugosc 3)"<< endl;
		do    
	{
		cout << "Podaj x: ";
		cin >> xs;
		cout << "Podaj y: ";
		cin >> ys;
		if(xs>16 || ys>16 || xs<0 || ys<0) 
		{
        	cout << "Zle wspolrzedne\n";
		}
	} while(xs>16 || ys>16 || xs<0 || ys<0); 
	cout << "Podaj ulozenie poziome - 0 , pionowe - 1 :";
	cin >> ws;
	niszczyciel2.Stworz(xs-1,ys-1,planszagracza,ws);
	system("cls");
	planszagracza.Wyswietl1();
	planszakomputera.Wyswietl2();
	cout << "Podaj wspolrzedne torpedowca (dlugosc 2)"<< endl;
		do    
	{
		cout << "Podaj x: ";
		cin >> xs;
		cout << "Podaj y: ";
		cin >> ys;
		if(xs>16 || ys>16 || xs<0 || ys<0) 
		{
        	cout << "Zle wspolrzedne\n";
		}
	} while(xs>16 || ys>16 || xs<0 || ys<0); 
	cout << "Podaj ulozenie poziome - 0 , pionowe - 1 :";
	cin >> ws;
	torpedowiec2.Stworz(xs-1,ys-1,planszagracza,ws);
	system("cls");

	
	Wynik wyniki;
//	Wynik pudlo;
//	Wynik trafienia;
	
	int strzal;
	
	while(IleStatkow(0)) 
	{
		IleStatkow(1);
		IleStatkow2(1);
		cout<<"Ilosc twoich ruchow: "<< wyniki.Zlicz()<<endl; 
//		cout<<"Trafienia: "<< trafienia.Zlicz()<< "   Pudla: "<<pudlo.Zlicz()<<endl; 
		planszagracza.Wyswietl1();
		planszakomputera.Wyswietl2();
		//Atak(planszakomputera,lotniskowiec1,pancernik1,niszczyciel1,torpedowiec1);
		Atak(planszakomputera,lotniskowiec1,pancernik1,niszczyciel1,torpedowiec1);
//		if(strzal==1)
//		trafienia.Dodaj(1);
//		else
//		pudlo.Dodaj(1);
		Atak2(planszagracza,lotniskowiec2,pancernik2,niszczyciel2,torpedowiec2);
		wyniki.Dodaj(1)	;
		system("cls");
	}
	
	
	
	
return( 0 );
}

