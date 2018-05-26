//POP_2015_12_22_projekt_1_Pryczkowska_Marta_AIR_3_160858 Dev-C++ 5.11
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
	struct gracz																//struktura opisuj¹ca gracza
	{
		int x;
		int y;
		int kierunek;
		int energia;
		int punkty;
	};
	
	
	struct pole 
	{
	int x;
	int y;
	};
	
const int maxi=15;													//maxymalny rozmiar tablicy labiryntu		
const int w=8;
const int k=10;														
const int wy=10;													//wspó³rzêdne wejœcia 
const int wx=5;

const int labirynt[maxi][maxi]={									//opis labiryntu 1-korytarz, 0-œciana		
{0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,1,1,0,1,0},
{0,0,1,0,1,0,0,1,0,1,0},
{0,0,1,1,1,0,0,1,1,1,0},
{0,1,1,0,0,0,0,0,0,1,5},
{0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0}};

//******************************************************************************************************************************************************************	

void pisztrase(int trasa[maxi][maxi])							// wypisanie schematu odwiedzonych pól 
{
	for(int i=0; i<w; i++)
	{
		for(int j=0; j<k; j++)
	{
	if (trasa[i][j]==0)   cout<<static_cast<char>(219);								
	else if(trasa[i][j]==2&&labirynt[i][j]==1)  cout<<"_";													// pole zobaczone - korytarz
	else if(trasa[i][j]==2&&labirynt[i][j]==0)
	cout<<"#";													// pole zobaczone - œciana
	else if(trasa[i][j]==1)
	cout<<"*";													// miejsce gracza 
	}
		cout<<endl;
	}
		
}

//******************************************************************************************************************************************************************	

void gentrasa( int trasa [maxi][maxi])								//tablica, na podstawie której wyœwietla schemat odwiedzonych pól
{
	for(int i=0; i<w; i++)
	for(int j=0; j<k; j++)
	trasa[i][j]=0;
}

//******************************************************************************************************************************************************************	

void zmienkierunek(int &kierunek, int wybrana)						// w zale¿noœci od poprzedniego kierunku i wyboru gracza - nowy kierunek
{
	switch(wybrana)
	{
		case 2:{
		switch(kierunek){
			case 1:{
			kierunek=2;}
			break;
			case 2:{
			kierunek=3;}
			break;
			case 3:{
			kierunek=4;}
			break;
			case 4:{
			kierunek=1;}
			break;
		}
	}
		break;
		
	case 3:{
		switch(kierunek){
			case 1:{
			kierunek=4;}
			break;
			case 2:{
			kierunek=1;}
			break;
			case 3:{
			kierunek=2;}
			break;
			case 4:{
			kierunek=3;}
			break;
		}
		break;
	}
}
}

//******************************************************************************************************************************************************************	


piszkierunek(int kierunek)														//wypisanie strza³ek symbolizuj¹cych kierunek 
{
	switch(kierunek)
	{
		case 1:{
		cout<<" < "<<endl;}
		break;
		case 2:{
		cout<<" ^ "<<endl;}
		break;
		case 3:{
		cout<<" > "<<endl;}
		break;
		case 4:{
		cout<< static_cast<char>(31)<<endl;}
		break;
	}
	
}

//******************************************************************************************************************************************************************	

void piszkomunikat( pole pole1)															// wypisuje co znajduje siê przed graczem
{
	if (labirynt[pole1.x][pole1.y]==0)
	cout<< " Przed Toba sciana, co robisz N/P/L/T "<<endl;
	else if (labirynt[pole1.x][pole1.y]==5)
	cout << "Przed Toba wyjscie co robisz N/P/L/T "<<endl;
	else 
	cout<< " Przed Toba korytarz co robisz N/P/L/T "<<endl;
}

//******************************************************************************************************************************************************************	


void losuj_kierunek(gracz &gracz1)												// dla teleportacji - losowy kierunek i wspó³rzêdne
{
	srand( time( NULL ) );
	gracz1.kierunek = rand() % 4 + 1;
	do
	{
	gracz1.x=( rand() % w ) ;
	gracz1.y=( rand() % k ) ;
	}
	while(labirynt[gracz1.x][gracz1.y]==0);										
}
//******************************************************************************************************************************************************************	
void odczytajpole(gracz gracz1, int wybrana, pole &pole1)						// odczytuje wspó³rzêdne pola, które jest przed graczem
{

	switch(gracz1.kierunek){
	case 1:{
	switch(wybrana)
	{
		case 1:{
		 pole1.y=gracz1.y-1;}
		 break;
		case 2:{
		 pole1.x=gracz1.x-1;}
		 break;
		case 3:{
		 pole1.x=gracz1.x+1;}
		 break;
	}
	break;
	case 2:
	{
		switch(wybrana)
		{
			case 1:{
			 pole1.x=gracz1.x-1;}
			 break;
			case 2:{
			 pole1.y=gracz1.y+1;}
			 break;
			case 3:{
			 pole1.y=gracz1.y-1;}
			 break;
		 }
	}
	break;
	case 3:
	{
		switch(wybrana)
		{
		case 1:{
		 pole1.y=gracz1.y+1;}
		 break;
		case 2:{
		 pole1.x=gracz1.x+1;}
		 break;
		case 3:{
		 pole1.x=gracz1.x-1;}
		 break;
			}
	}
		break;
	case 4:{
	switch(wybrana){
		case 1:{
		 pole1.x=gracz1.x+1;}
		 break;
		case 2:{
		 pole1.y=gracz1.y-1;}
		 break;
		case 3:{
		 pole1.y=gracz1.y+1;}
		 
		 break;}
		}
		break;
}
}
}


//******************************************************************************************************************************************************************	

void zmienwspolrzedne(gracz &gracz1)							// dla ruchu naprzód - zmienia wspó³rzêdne w zale¿noœci od kierunku
{
		switch (gracz1.kierunek)
	{
		case 1: {
			gracz1.y=gracz1.y-1;
			break;
		}
		case 2:
			{
			gracz1.x=gracz1.x-1;
			break;
		}
		case 3:
		{
			gracz1.y=gracz1.y+1;
			break;
		}
		case 4:
		{
			gracz1.x=gracz1.x+1;
			break;
		}
	}
}


//******************************************************************************************************************************************************************	

void ruch (int wybor, int  trasa[maxi][maxi], gracz &gracz1, pole &pole1, int punkty[maxi][maxi])
{

	int wybrana;
  switch(wybor)
  {
    case 'N': {
    		if(gracz1.energia<15)														// sprawdzenie energii
			cout<<" za malo energii na ten ruch "<<endl;
			else{
    		if((labirynt[pole1.x][pole1.y]==1)||(pole1.x==wx&&pole1.y==wy))			//sprawdzenie czy œciana lub wejœcie
    		{
    		wybrana=1;
    		pole1.x=gracz1.x;
			pole1.y=gracz1.y;
			trasa[gracz1.x][gracz1.y]=2;												
    		zmienwspolrzedne(gracz1);
    		punkty[gracz1.x][gracz1.y]=1;												// pole odwiedzone- zwiêkszenie punktów
    		odczytajpole(gracz1,wybrana, pole1);
    		gracz1.energia-=15;
    		
    		}
		
    	
    		else{
			
    		cout << " Nie przejdziesz tedy :)  "<<endl;
    	
    		}
    		}
  			}
		       
     		break;
	case 'P': {
			if(gracz1.energia<10)
			cout<<" za malo energii na ten ruch "<<endl;
			else{
			wybrana=2;
			 pole1.x=gracz1.x;
			pole1.y=gracz1.y;
			odczytajpole(gracz1,wybrana, pole1);
			zmienkierunek(gracz1.kierunek, wybrana);
			gracz1.energia-=10;
  			}
         	}
     		break;
  	case 'L': {
  			if(gracz1.energia<10)
			cout<<" za malo energii na ten ruch "<<endl;
			else{
  			wybrana=3;
  			pole1.x=gracz1.x;
			pole1.y=gracz1.y;
  			odczytajpole(gracz1,wybrana, pole1);
  			zmienkierunek(gracz1.kierunek, wybrana);
  			gracz1.energia-=10;
			}
			}
     		break;
	case 'T': {
			if(gracz1.energia<30)
			cout<<" za malo energii na ten ruch "<<endl;
			else{
			wybrana=1;
			 trasa[gracz1.x][gracz1.y]=2;
			losuj_kierunek(gracz1);
			pole1.x=gracz1.x;
			pole1.y=gracz1.y;
			punkty[gracz1.x][gracz1.y]=1;
			 odczytajpole(gracz1,wybrana, pole1);
            gracz1.energia-=30;
        	}
         	}
     		break;
    default :{
    	cout<<" Zle dane "<<endl;
    }
    	
		break;
	
	}
	
}

//******************************************************************************************************************************************************************	

	void zmientab(int trasa[maxi][maxi], pole pole1, gracz gracz1)							
	{
		trasa[pole1.x][pole1.y]=2;														//pole "przed graczem " zmiana na 2 , aby wyœwietliæ 
		trasa[gracz1.x][gracz1.y]=1;													//pole " gracza " zmiana na 1 , aby wyœwietliæ 
	}
	

//******************************************************************************************************************************************************************	

	int liczpunkty(int punkty[maxi][maxi])								//liczy punkty, w zale¿noœci od iloœci odwiedzonych  pól
	{
		int licz=0;
		for(int i=0; i<w; i++){
		for(int j=0; j<k; j++){
		if (punkty[i][j]==1)
		licz++;
		}
		}
	
	return licz;
	}
//******************************************************************************************************************************************************************	
	
int main()
{

int trasa[maxi][maxi];
int punkty [maxi][maxi];	
 gentrasa(trasa);									// generuje tablicê 0 dla punków i odwiedzonych pól
 gentrasa(punkty);

	gracz gracz1;
	gracz1.x=wx;									//ustawienie gracza na wejœciu
	gracz1.y=wy;
	gracz1.kierunek=1;
	gracz1.energia=500;
	gracz1.punkty=0;
	pole pole1;
	pole1.x=gracz1.x;
	pole1.y=gracz1.y;
	char wybor;
	
	
	cout<<" Rozpoczynasz gre, twoim zadaniem jest odwiedzic jak najwiecej pol i wyjsc z labiryntu."<<endl <<" Przed Toba wejscie do labiryntu. Masz "<< gracz1.energia<< "  punktow energii. Nacisnij N aby wejsc do labiryntu"<<endl;
	pisztrase(trasa);
	cin>>wybor;
	wybor=toupper(wybor);
	while(wybor!='N')
	{
		cout<<"  Nacisnij N aby wejsc do labiryntu " <<endl;
		cin>>wybor;
		wybor=toupper(wybor);
	}
	system("cls"); 
	ruch(wybor, trasa, gracz1, pole1,punkty);
	piszkierunek(gracz1.kierunek);
	cout<<" Masz  "<<gracz1.energia <<" punktow energii "<<endl;
    piszkomunikat(pole1);
    zmientab(trasa,pole1, gracz1);
    pisztrase(trasa);


	
	do
	{
		int k=0;
		do
		{
			cin>>wybor;
			k=cin.good();
			cin.clear();
			cin.sync();		
		} while(!k);
	 wybor=toupper(wybor);
     system("cls"); 
	ruch(wybor, trasa, gracz1, pole1,punkty);
	piszkierunek(gracz1.kierunek);
	cout<<" Masz  "<<gracz1.energia <<" punktow energii "<<endl;
    piszkomunikat(pole1);
    zmientab(trasa,pole1, gracz1);
    pisztrase(trasa);
  		
  		
   	}
	while(((gracz1.x!=wx)||(gracz1.y!=wy))&&(gracz1.energia>=10));						//dopóki wyjœcie z labiryntu lub wyczerpanie energii
	if((gracz1.x==wx)&&(gracz1.y==wy))
	{
		 system("cls"); 
		gracz1.punkty=liczpunkty(punkty);
		cout<< " Gratulacje, wyszedles z labiryntu  zdobyles    "<<  gracz1.punkty  << "  punkty/ow "<<endl;
	}
	else
	{
		cout << "wyczerpana energia - przegrales "<<endl;
	}
	
	system ("pause");
	return 0;
	
}
