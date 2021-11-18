/*

 This program randomly generates possible menus for a level 7 bar in Food Fantasy.
 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//symbolic constants
const int MAX_DRINKS = 11;

const int BASE_AMOUNT = 6;
const int FLAVORED_AMOUNT = 3;
const int OTHER_AMOUNT = 10;

const int BASE_CAP = 10;
const int FLAVORED_CAP = 4;
const int OTHER_CAP = 4;

const int FORMULA_AMOUNT = 21;
const int HIDDEN_AMOUNT = 14;


class drinks
{
	//data members
	int money,
		fame;

	int base[BASE_AMOUNT+1];
	int flavored[FLAVORED_AMOUNT+1];
	int other[OTHER_AMOUNT+1];
	
	
	//methods
public:
	drinks();
	int getMoney();
	int getFame();
	void displayIngredients();
	int selection(int, int&);
	int basicDrinks(int);
	int selectionManual(int);
	
private:
	bool list(int);
	
	bool screwdriver();
	bool rattlesnake();
	bool blackrussia();
	bool coffeemartini();
	bool sourpineapplejuice();
	bool tequilasour();
	bool vodkasour();
	bool mojito();
	bool sweetlemon();
	bool sweetorange();
	bool blueblazer();
	bool french75();
	bool bernice();
	bool honeysoda();
	bool mayan();
	bool brandyalexander();
	bool dirtybanana();
	bool lynchburglemonade();
	bool matador();
	bool hankypanky();
	bool margarita();
	
	bool longislandicedtea();
	bool cubalibre();
	bool fogcutter();
	bool palmbeach();
	bool betweenthesheets();
	bool zombie();
	bool ginbasilsmash();
	bool cantaritos();
	bool thorns();
	bool fishhousepunch();
	bool daiquiri();
	bool singaporesling();
	bool brandycrusta();
	bool bloodandsand();
};

//**************************************************************

int main()
{

	//variables
	int drinkAmount = 0,
		menuAmount,
		menu,
		bestProfit = 0,
		bestProfitMenu,
		bestFame = 0,
		bestFameMenu,
		failures = 0;
	//random seed
	srand(time(0));
	
	
	cout<<"*** LEVEL 7 BAR MENUS ***"
		<<endl
		<<endl<<"How many menus would you like to generate?"<<endl;
	cin>>menuAmount;
	cout<<endl<<endl;
	
				//menu generation
	for (menu = 1; menu <= menuAmount; menu++)
	//for (menu = 1; bestProfit < 400; menu++)
	{
		cout<<"*** Menu #"<<menu<<" ***"<<endl;
		drinks Drink = drinks();
			
		//fill menu with drinks
		while (drinkAmount < MAX_DRINKS)
		{
			drinkAmount = Drink.selection(drinkAmount, failures);
			//drinkAmount = Drink.selectionManual(drinkAmount);
			
			if (failures > 250)
			{
				drinkAmount = Drink.basicDrinks(drinkAmount);
			}
		}
	
	
		//summary
		cout<<endl<<"Menu #"<<menu<<" summary:"
			<<endl<<"  Money: "<<Drink.getMoney()
			<<endl<<"  Fame: "<<Drink.getFame();
		Drink.displayIngredients();
		
		
		//best menus
		if (Drink.getMoney() >= bestProfit)
			{
			bestProfit = Drink.getMoney();
			bestProfitMenu = menu;
			}
		if (Drink.getFame() >= bestFame)
			{
			bestFame = Drink.getFame();
			bestFameMenu = menu;
			}
		
		
		//reset
		drinkAmount = 0;
		failures = 0;
		cout<<endl<<endl<<endl<<endl;
		
	} 
	
	//end of program
	cout<<endl<<"The most profitable menu is menu "<<bestProfitMenu<<", which generates "<<bestProfit<<" money.";
	cout<<endl<<"The menu which generates the most fame is menu "<<bestFameMenu<<", which generates "<<bestFame<<" fame."<<endl<<endl<<endl;
	
	return 0;
}

//**************************************************************

drinks::drinks()
{
	money = 0;
	fame = 0;
	
	for (int i = 1; i <= BASE_AMOUNT; i++)
		{
			base[i] = 0;
		}
	for (int i = 1; i <= FLAVORED_AMOUNT; i++)
		{
			flavored[i] = 0;
		}
	for (int i = 1; i <= OTHER_AMOUNT; i++)
		{
			other[i] = 0;
		}
}


int drinks::getMoney()
{
	return money;
}


int drinks::getFame()
{
	return fame;
}


void drinks::displayIngredients()
{
	cout<<endl<<endl<<"Ingredients used:"<<endl;
	
	cout<<"  vodka, whiskey, rum, brandy, tequila, gin"<<endl;
	for (int i = 1; i <= BASE_AMOUNT; i++)
		{
			cout<<setw(4+(2*i)-((i/3)*3)-((i/4)*3))<<base[i];
		}
	
	cout<<endl<<endl<<"  coffee liqueur, orange curacao, vermouth"<<endl;
	for(int i = 1; i <= FLAVORED_AMOUNT; i++)
		{
			cout<<setw(9*i-((i/3)*16))<<flavored[i];
		}
	
	cout<<endl<<endl<<"  pineapple juice, cola, soda water, orange juice, lemon juice, cane syrup, mint leaf, sugar, honey, cream"<<endl;
	for(int i = 1; i <= OTHER_AMOUNT; i++)
		{
			cout<<setw(11+(i/6)-((i/9)*5))<<other[i];
		}
}


int drinks::selection(int amount, int& failures)
{
	int drink;
	bool makeable;
	
	drink = (rand() % (FORMULA_AMOUNT+HIDDEN_AMOUNT)) + 1;
	makeable = list(drink);
	
	if (makeable)
	{
		cout<<endl;
		failures = 0;
		return amount + 1;
	}
	else
	{
		failures++;
		return amount;
	}
}


int drinks::selectionManual(int amount)
{
	int drinks[] = {13, 16, 33, 28, 31, 32, 35, 19, 18, 18, 18};
	int drink;
	bool makeable;
	
	for(int i = 0; i < MAX_DRINKS; i++)
	{
		drink = drinks[i];
		makeable = list(drink);
		if (!makeable)
		{
			cout<<"Error in manual selection process."<<endl;
			exit(-1);
		}
		cout<<endl;
	}
	
	return MAX_DRINKS;
}


bool drinks::list(int drinkNum)
{
	switch (drinkNum)
	{
		case 1:		return screwdriver();
		case 2:		return rattlesnake();
		case 3:		return blackrussia();
		case 4:		return coffeemartini();
		case 5:		return sourpineapplejuice();
		case 6:		return tequilasour();
		case 7:		return mojito();
		case 8:		return sweetlemon();
		case 9:		return sweetorange();
		case 10:	return blueblazer();
		case 11:	return french75();
		case 12:	return bernice();
		case 13:	return honeysoda();
		case 14:	return mayan();
		case 15:	return brandyalexander();
		case 16:	return dirtybanana();
		case 17:	return vodkasour();
		case 18:	return longislandicedtea();
		case 19:	return cubalibre();
		case 20:	return fogcutter();
		case 21:	return palmbeach();
		case 22:	return betweenthesheets();
		case 23:	return zombie();
		case 24:	return ginbasilsmash();
		case 25:	return cantaritos();
		case 26:	return thorns();
		case 27:	return fishhousepunch();
		case 28:	return daiquiri();
		case 29:	return lynchburglemonade();
		case 30:	return matador();
		case 31:	return singaporesling();
		case 32:	return brandycrusta();
		case 33:	return hankypanky();
		case 34:	return margarita();
		case 35:	return bloodandsand();
							
		default: 	cout<<"Error in selection process."<<endl;
	}
}


int drinks::basicDrinks(int drinkAmount) //fill up rest of menu with lvl 1 drinks
{
	int drinksToMake;
	drinksToMake = MAX_DRINKS - drinkAmount;
	
	cout<<"** lvl 1 drinks x"<<drinksToMake<<endl;
	
	money += (15*drinksToMake);
	fame += (10*drinksToMake);
	
	return MAX_DRINKS;
}

//************************************************************** most of this program is just the data for all the drinks

bool drinks::screwdriver()
{
	if (base[1]+2 > BASE_CAP || other[5]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make screwdriver";
		return 0;
	}
	else
	{
		cout<<"* screwdriver";
		base[1] += 2;
		other[5] += 3;
		money += 25;
		fame += 10;
		return 1;
	}
}

bool drinks::rattlesnake()
{
	if (base[2]+1 > BASE_CAP || flavored[1]+3 > FLAVORED_CAP)
	{
		//cout<<"Cannot make rattlesnake";
		return 0;
	}
	else
	{
		cout<<"* rattlesnake";
		base[2] += 1;
		flavored[1] += 3;
		money += 20;
		fame += 10;
		return 1;
	}
}

bool drinks::blackrussia()
{
	if (base[1]+1 > BASE_CAP || flavored[1]+4 > FLAVORED_CAP)
	{
		//cout<<"Cannot make black russia";
		return 0;
	}
	else
	{
		cout<<"* black russia";
		base[1] += 1;
		flavored[1] += 4;
		money += 25;
		fame += 10;
		return 1;
	}
}

bool drinks::coffeemartini()
{
	if (base[1]+1 > BASE_CAP || flavored[1]+3 > FLAVORED_CAP)
	{
		//cout<<"Cannot make coffee martini";
		return 0;
	}
	else
	{
		cout<<"* coffee martini";
		base[1] += 1;
		flavored[1] += 3;
		money += 20;
		fame += 10;
		return 1;
	}
}

bool drinks::sourpineapplejuice()
{
	if (other[4]+1 > OTHER_CAP || other[1]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make sour pineapple juice";
		return 0;
	}
	else
	{
		cout<<"* sour pineapple juice";
		other[4] += 1;
		other[1] += 3;
		money += 20;
		fame += 10;
		return 1;
	}
}

bool drinks::tequilasour()
{
	if (base[5]+1 > BASE_CAP || other[5]+3 > OTHER_CAP || other[6]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make tequila sour";
		return 0;
	}
	else
	{
		cout<<"* tequila sour";
		base[5] += 1;
		other[5] += 3;
		other[6] += 3;
		money += 35;
		fame += 10;
		return 1;
	}
}

bool drinks::vodkasour()
{
	if (base[1]+1 > BASE_CAP || other[5]+3 > OTHER_CAP || other[6]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make vodka sour";
		return 0;
	}
	else
	{
		cout<<"* vodka sour";
		base[1] += 1;
		other[5] += 3;
		other[6] += 3;
		money += 35;
		fame += 10;
		return 1;
	}
}

bool drinks::mojito()
{
	if (other[5]+1 > OTHER_CAP || base[3]+2 > BASE_CAP || other[3]+2 > OTHER_CAP)
	{
		//cout<<"Cannot make mojito";
		return 0;
	}
	else
	{
		cout<<"* mojito";
		other[5] += 1;
		base[3] += 2;
		other[3] += 2;
		money += 25;
		fame += 10;
		return 1;
	}
}

bool drinks::sweetlemon()
{
	if (other[5]+1 > OTHER_CAP || other[8]+2 > OTHER_CAP || other[9]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make sweet lemon";
		return 0;
	}
	else
	{
		cout<<"* sweet lemon";
		other[5] += 1;
		other[8] += 2;
		other[9] += 3;
		money += 30;
		fame += 10;
		return 1;
	}
}

bool drinks::sweetorange()
{
	if (other[4]+2 > OTHER_CAP || other[2]+2 > OTHER_CAP || other[8]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make sweet orange";
		return 0;
	}
	else
	{
		cout<<"* sweet orange";
		other[4] += 2;
		other[2] += 2;
		other[8] += 3;
		money += 35;
		fame += 10;
		return 1;
	}
}

bool drinks::blueblazer()
{
	if (base[2]+1 > BASE_CAP || other[8]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make blue blazer";
		return 0;
	}
	else
	{
		cout<<"* blue blazer";
		base[2] += 1;
		other[8] += 3;
		money += 20;
		fame += 10;
		return 1;
	}
}

bool drinks::french75()
{
	if (base[1]+1 > BASE_CAP || other[5]+2 > OTHER_CAP || other[6]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make french 75";
		return 0;
	}
	else
	{
		cout<<"* french 75";
		base[1] += 1;
		other[5] += 2;
		other[6] += 3;
		money += 30;
		fame += 10;
		return 1;
	}
}

bool drinks::bernice()
{
	if (base[1]+1 > BASE_CAP || other[5]+3 > OTHER_CAP || other[6]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make bernice";
		return 0;
	}
	else
	{
		cout<<"* bernice";
		base[1] += 1;
		other[5] += 3;
		other[6] += 3;
		money += 35;
		fame += 10;
		return 1;
	}
}

bool drinks::honeysoda()
{
	if (other[10]+1 > OTHER_CAP || other[9]+3 > OTHER_CAP || other[3]+3 > OTHER_CAP)
	{
		//cout<<"Cannot make honey soda";
		return 0;
	}
	else
	{
		cout<<"* honey soda";
		other[10] += 1;
		other[9] += 3;
		other[3] += 3;
		money += 35;
		fame += 10;
		return 1;
	}
}

bool drinks::mayan()
{
	if (base[5]+1 > BASE_CAP || flavored[1]+2 > FLAVORED_CAP || other[1]+2 > OTHER_CAP)
	{
		//cout<<"Cannot make mayan";
		return 0;
	}
	else
	{
		cout<<"* mayan";
		base[5] += 1;
		flavored[1] += 2;
		other[1] += 2;
		money += 25;
		fame += 10;
		return 1;
	}
}

bool drinks::brandyalexander()
{
	if (base[4]+1 > BASE_CAP || flavored[1]+2 > FLAVORED_CAP || other[10]+2 > OTHER_CAP)
	{
		//cout<<"Cannot make brandy alexander";
		return 0;
	}
	else
	{
		cout<<"* brandy alexander";
		base[4] += 1;
		flavored[1] += 2;
		other[10] += 2;
		money += 25;
		fame += 10;
		return 1;
	}
}

bool drinks::dirtybanana()
{
	if (other[10]+1 > OTHER_CAP || base[3]+2 > BASE_CAP || flavored[1]+3 > FLAVORED_CAP)
	{
		//cout<<"Cannot make dirty banana";
		return 0;
	}
	else
	{
		cout<<"* dirty banana";
		other[10] += 1;
		base[3] += 2;
		flavored[1] += 3;
		money += 30;
		fame += 10;
		return 1;
	}
}

bool drinks::lynchburglemonade()
{
	if (base[2]+1 > BASE_CAP || flavored[2]+1 > FLAVORED_CAP || other[5]+3 > OTHER_CAP || other[3]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* lynchburg lemonade";
		base[2] += 1;
		flavored[2] += 1;
		other[5] += 3;
		other[3] += 3;
		money += 55;
		fame += 12;
		return 1;
	}
}

bool drinks::matador()
{
	if (base[5]+1 > BASE_CAP || flavored[2]+3 > FLAVORED_CAP || other[5]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* matador";
		base[5] += 1;
		flavored[2] += 3;
		other[5] += 3;
		money += 55;
		fame += 12;
		return 1;
	}
}

bool drinks::hankypanky()
{
	if (base[6]+1 > BASE_CAP || flavored[3]+2 > FLAVORED_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* hanky panky";
		base[6] += 1;
		flavored[3] += 2;
		money += 28;
		fame += 12;
		return 1;
	}
}

bool drinks::margarita()
{
	if (base[5]+1 > BASE_CAP || flavored[2]+2 > FLAVORED_CAP || other[5]+2 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* margarita";
		base[5] += 1;
		flavored[2] += 2;
		other[5] += 2;
		money += 39;
		fame += 12;
		return 1;
	}
}

bool drinks::longislandicedtea()
{
	if (base[3]+1 > BASE_CAP || base[5]+1 > BASE_CAP || base[6]+1 > BASE_CAP || base[1]+2 > BASE_CAP)
	{
		//cout<<"Cannot make long Island Iced Tea";
		return 0;
	}
	else
	{
		cout<<"* long island iced tea";
		base[3] += 1;
		base[5] += 1;
		base[6] += 1;
		base[1] += 2;
		money += 25;
		fame += 10;
		return 1;
	}
}

bool drinks::cubalibre()
{
	if (base[3]+2 > BASE_CAP || other[2]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* cuba libre";
		base[3] += 2;
		other[2] += 3;
		money += 31;
		fame += 14;
		return 1;
	}
}

bool drinks::fogcutter()
{
	if (base[3]+1 > BASE_CAP || base[6]+1 > BASE_CAP || base[4]+1 > BASE_CAP || other[5]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* fog cutter";
		base[3] += 1;
		base[6] += 1;
		base[4] += 1;
		other[5] += 3;
		money += 37;
		fame += 14;
		return 1;
	}
}

bool drinks::palmbeach()
{
	if (base[3]+1 > BASE_CAP || base[6]+2 > BASE_CAP || other[1]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* palm beach";
		base[3] += 1;
		base[6] += 2;
		other[1] += 3;
		money += 37;
		fame += 14;
		return 1;
	}
}

bool drinks::betweenthesheets()
{
	if (base[3]+1 > BASE_CAP || base[4]+2 > BASE_CAP || other[5]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* between the sheets";
		base[3] += 1;
		base[4] += 2;
		other[5] += 3;
		money += 37;
		fame += 14;
		return 1;
	}
}

bool drinks::zombie()
{
	if (other[1]+1 > OTHER_CAP || other[5]+2 > OTHER_CAP || base[3]+3 > BASE_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* zombie";
		other[1] += 1;
		other[5] += 2;
		base[3] += 3;
		money += 37;
		fame += 14;
		return 1;
	}
}

bool drinks::ginbasilsmash()
{
	if (base[6]+1 > BASE_CAP || other[5]+2 > OTHER_CAP || other[6]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* gin basil smash";
		base[6] += 1;
		other[5] += 2;
		other[6] += 3;
		money += 37;
		fame += 14;
		return 1;
	}
}

bool drinks::cantaritos()
{
	if (base[5]+1 > BASE_CAP || other[5]+3 > OTHER_CAP || other[3]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* cantaritos";
		base[5] += 1;
		other[5] += 3;
		other[3] += 3;
		money += 39;
		fame += 12;
		return 1;
	}
}

bool drinks::thorns()
{
	if (base[6]+1 > BASE_CAP || other[5]+3 > OTHER_CAP || other[6]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* thorns";
		base[6] += 1;
		other[5] += 3;
		other[6] += 3;
		money += 39;
		fame += 12;
		return 1;
	}
}

bool drinks::fishhousepunch()
{
	if (base[4]+1 > BASE_CAP || base[3]+2 > BASE_CAP || other[5]+2 > OTHER_CAP || other[6]+2 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* fish house punch";
		base[4] += 1;
		base[3] += 2;
		other[5] += 2;
		other[6] += 2;
		money += 35;
		fame += 10;
		return 1;
	}
}

bool drinks::daiquiri()
{
	if (base[3]+2 > BASE_CAP || base[4]+2 > BASE_CAP || other[5]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* daiquiri";
		base[3] += 2;
		base[4] += 2;
		other[5] += 3;
		money += 47;
		fame += 16;
		return 1;
	}
}

bool drinks::singaporesling()
{
	if (base[6]+1 > BASE_CAP || base[4]+2 > BASE_CAP || flavored[2]+3 > FLAVORED_CAP || other[1]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* singapore sling";
		base[6] += 1;
		base[4] += 2;
		flavored[2] += 3;
		other[1] += 3;
		money += 66;
		fame += 12;
		return 1;
	}
}

bool drinks::brandycrusta()
{
	if (base[4]+1 > BASE_CAP || flavored[2]+1 > FLAVORED_CAP || other[5]+1 > OTHER_CAP || other[6]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* brandy crusta";
		base[4] += 1;
		flavored[2] += 1;
		other[5] += 1;
		other[6] += 3;
		money += 39;
		fame += 12;
		return 1;
	}
}

bool drinks::bloodandsand()
{
	if (base[2]+2 > BASE_CAP || base[4]+2 > BASE_CAP || flavored[3]+2 > FLAVORED_CAP || other[4]+3 > OTHER_CAP)
	{
		return 0;
	}
	else
	{
		cout<<"* blood and sand";
		base[2] += 2;
		base[4] += 2;
		flavored[3] += 2;
		other[4] += 3;
		money += 55;
		fame += 12;
		return 1;
	}
}
