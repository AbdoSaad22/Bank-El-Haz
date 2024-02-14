#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<bitset>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<cstdlib> 
#include<ctime>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define test_case int t;cin>>t;while(t--)
typedef long long int ll;
typedef long double ld;
using namespace std;
void Abdo_Saad() { ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }
ll gcd(ll a, ll b) { return(b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void set_bit(int& n, int idx) { n |= 1 << idx; }
void reset_bit(int& n, int idx) { n &= ~(1 << idx); }
void flib_bit(int& n, int idx) { n ^= 1 << idx; }\

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________ Bank El Haz _____________________________________________________________________________________//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//___________________________________________________________________________________________________________________________________________
int balance1 = 1200, balance2 = 1200;                                                     // prepating data 
int pos1 = 0, pos2 = 0, c = 0;
int prison1 = 0, prison2 = 0;
string player1, player2, shape1 = "  ####  ", shape2 = "  <<>>  ", shape3 = " ###<>> ";
struct details
{
	string place, player;
	int idx;
	char property1, property2;
};

vector<details>All(28);

vector<string>places = { " Mecca  ","  Gaza  ","  Aden  ","       Haz        "
," Aswan  "," Court  ","  Giza  "," Sohag  "," Sinai  "," Assuit "," Train  "
," Riyade ","  Alex  ","  Haz   ","  Court "," Alquds "," Cairo  "
," Start  "," Qatar  "," Kuwait ","       Haz        "," Sanaa  "
	," Court  "," Luxor  "," Mynia  "," Amman  "," Sudan  "," Prison " };

vector<int>price = { 0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,1 };
vector<int>fare = { 0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,1 };
vector<int>move_ = { 17,15,13,11,0,1,2,3,4,5,6,7,8,9,10,12,14,16,27,26,25,24,23,22,21,20,19,18 };

//___________________________________________________________________________________________________________________________________________

void default_()
{
	for (int i = 0;i < 28;i++)
	{
		All[i].place = places[i];
		All[i].property1 = '.';
		All[i].property2 = '.';
		All[i].player = "        ";
		All[i].idx = i;
	}
}
void price_fare(int player_num, int place_num)
{
	if (player_num == 1)
	{
		if (All[move_[place_num]].property1 == '.')
		{
			string buy;
			cout << All[move_[place_num]].place << " is not belong to anyone .\n";
			cout << All[move_[place_num]].place << " price is " << price[place_num] << " and it's fare is " << fare[place_num] << endl;
			cout << "if you want to buy " << All[place_num].place << " enter yes otherwise enter no :";
			cin >> buy;
			if (buy == "yes")
			{
				if (balance1 >= price[place_num])
				{
					balance1 -= price[place_num];
					cout << "\nIt's your own place from now\n\n";
					All[move_[place_num]].property1 = '*';
					All[move_[place_num]].property2 = '*';
				}
				else
				{
					cout << "sorry you can't buy this place you don't have enough money\n\n";
				}
			}
		}
		else if (All[move_[place_num]].property1 == '$')
		{
			cout << "ooohhhhhhhhhh " << All[move_[place_num]].place << "belongs to your oppenent ..\n";
			cout << "you have to pay " << fare[place_num] << " for him :(\n\n";
			balance1 -= fare[place_num];
		}
	}
	else
	{
		if (All[move_[place_num]].property1 == '.')
		{
			string buy;
			cout << All[move_[place_num]].place << " is not belong to anyone.\n";
			cout << All[move_[place_num]].place << " price is " << price[place_num] << " and it's fare is " << fare[place_num] << endl;
			cout << "if you want to buy " << All[place_num].place << " enter yes otherwise enter no:";
			cin >> buy;
			if (buy == "yes")
			{
				if (balance2 >= price[place_num])
				{
					balance2 -= price[place_num];
					cout << "\nIt's your own place from now\n\n";
					All[move_[place_num]].property1 = '$';
					All[move_[place_num]].property2 = '$';
				}
				else
				{
					cout << "sorry you can't buy this place you don't have enough money\n\n";
				}
			}
		}
		else if (All[move_[place_num]].property1 == '*')
		{
			cout << "ooohhhhhhhhhh " << All[move_[place_num]].place << "belongs to your oppenent ..\n";
			cout << "you have to pay " << fare[place_num] << " for him :(\n\n";
			balance2 -= fare[place_num];
		}
	}
}
void Court(int& balance11, int& balance22, int& prison, int& pos)
{
	int ra = 0;
	vector<pair<string, pair<int, int>>>v(6);
	v[0] = { "You broken your someone's leg . go to the prison now\n",{0 ,0} };
	v[1] = { "You won a case against your old friend ,take 100 pounds from him\n",{100,0} };
	v[2] = { "You lost a case against your old friend , pay 100 pounds for him\n",{-100,0} };
	v[3] = { "You has escaped from the government go to the prison now\n",{0,0} };
	v[4] = { "You threw rabbish in the street pay 50 pounds",{-50,0} };
	v[5] = { "Someone has broken your car take 100 ",{100,0} };
	cout << "Court--> " << v[ra].first << endl;
	if (ra == 0 || ra == 3)
	{
		pos = 18;
		prison = 2;
	}
	else
	{
		balance11 += v[ra].second.first;
		balance22 += v[ra].second.second;
	}

}
void Haz(int& balance11, int& balance22)
{
	int ra = rand() % 6;
	vector<pair<string, pair<int, int>>>v(6);
	v[0] = { "It,s your birthday take 40 from your opponent\n",{40 ,-40} };
	v[1] = { "You served your country a lot,so you got 100 pounds\n",{100,0} };
	v[2] = { "you joke a lot pay 100 pounds for what you have caused\n",{-100,0} };
	v[3] = { "god has bleesed you with a boy take 75 pounds\n",{75,0} };
	v[4] = { "You have four children pay 25 pounds for each one to pay their school expenses\n",{100,0} };
	v[5] = { "You have a good heart , take 50 pounds\n",{50,0} };
	cout << "Hazk--> " << v[ra].first << endl;
	balance11 += v[ra].second.first;
	balance22 += v[ra].second.second;
}
bool prison_function(int& balance, int& num, string player)
{
	cout << "sorry you " << player << " can't play now as you are in the prison :(\n";
	cout << "if you want to leave the prison now and pay 50 pounds enter yes ";
	cout << ", otherwise enter no and you will leave after " << num << " turns\n";
	string s;
	cin >> s;
	if (s == "yes")
	{
		if (balance2 >= 50)
		{
			balance2 -= 50;
			num = 0;
			return true;
		}
		else
		{
			cout << "sorry you don't have enough money so you have to be in the prison\n";
			return false;
		}
	}
	num--;
	return false;
}
void print_up_down(vector<details>up_down)
{
	for (int i = 0;i < 11;i++)
	{
		if (up_down[i].place == "       Haz        ")
		{
			for (int j = 0;j < 20;j++)cout << up_down[i].property1;
		}
		else
		{
			for (int j = 0;j < 10;j++)cout << up_down[i].property1;
		}
	}
	cout << endl;

	/////////////////////////////////////////////////////////////////////

	for (int i = 0;i < 11;i++)
	{
		cout << up_down[i].property2 << up_down[i].place << up_down[i].property2;
	}
	cout << endl;


	/////////////////////////////////////////////////////////////////////

	for (int i = 0;i < 11;i++)
	{
		cout << up_down[i].property2;
		if (up_down[i].place == "       Haz        ")
		{
			for (int j = 0;j < 18;j++)cout << " ";
		}
		else
		{
			for (int j = 0;j < 8;j++)cout << " ";
		}
		cout << up_down[i].property2;

	}
	cout << endl;

	/////////////////////////////////////////////////////////////////////

	for (int i = 0;i < 11;i++)
	{
		cout << up_down[i].property2;
		if (up_down[i].place == "       Haz        ")
		{
			for (int j = 0;j < 5;j++)cout << " ";
			cout << up_down[i].player;
			for (int j = 0;j < 5;j++)cout << " ";
		}
		else cout << up_down[i].player;
		cout << up_down[i].property2;

	}
	cout << endl;

	/////////////////////////////////////////////////////////////////////

	for (int i = 0;i < 11;i++)
	{
		cout << up_down[i].property2;
		if (up_down[i].place == "       Haz        ")
		{
			for (int j = 0;j < 18;j++)cout << " ";
		}
		else
		{
			for (int j = 0;j < 8;j++)cout << " ";
		}
		cout << up_down[i].property2;

	}
	cout << endl;

	/////////////////////////////////////////////////////////////////////

	for (int i = 0;i < 11;i++)
	{
		if (up_down[i].place == "       Haz        ")
		{
			for (int j = 0;j < 20;j++)cout << up_down[i].property1;
		}
		else
		{
			for (int j = 0;j < 10;j++)cout << up_down[i].property1;
		}
	}
	cout << endl;
}
void print_sides(vector<details>sides)
{
	for (int i = 0;i < 6;i += 2)
	{
		for (int j = 0;j < 10;j++)cout << sides[i].property1;
		for (int j = 0;j < 100;j++)cout << " ";
		for (int j = 0;j < 10;j++)cout << sides[i + 1].property1;
		cout << endl;

		/////////////////////////////////////////////////////////////////////

		cout << sides[i].property2 << sides[i].place << sides[i].property2;
		for (int j = 0;j < 100;j++)cout << " ";
		cout << sides[i + 1].property2 << sides[i + 1].place << sides[i + 1].property2;
		cout << endl;

		/////////////////////////////////////////////////////////////////////

		cout << sides[i].property2;
		for (int j = 0;j < 8;j++)cout << " ";
		cout << sides[i].property2;
		for (int j = 0;j < 100;j++)cout << " ";
		cout << sides[i + 1].property2;
		for (int j = 0;j < 8;j++)cout << " ";
		cout << sides[i + 1].property2;

		/////////////////////////////////////////////////////////////////////

		cout << sides[i].property2 << sides[i].player << sides[i].property2;
		for (int j = 0;j < 100;j++)cout << " ";
		cout << sides[i + 1].property2 << sides[i + 1].player << sides[i + 1].property2;
		cout << endl;

		/////////////////////////////////////////////////////////////////////

		cout << sides[i].property2;
		for (int j = 0;j < 8;j++)cout << " ";
		cout << sides[i].property2;
		for (int j = 0;j < 100;j++)cout << " ";
		cout << sides[i + 1].property2;
		for (int j = 0;j < 8;j++)cout << " ";
		cout << sides[i + 1].property2;

		/////////////////////////////////////////////////////////////////////

		for (int j = 0;j < 10;j++)cout << sides[i].property1;
		for (int j = 0;j < 100;j++)cout << " ";
		for (int j = 0;j < 10;j++)cout << sides[i + 1].property1;
		cout << endl;
	}

}
void manage_print()
{
	vector<details>up(All.begin(), All.begin() + 11);
	vector<details>sides(All.begin() + 11, All.begin() + 17);
	vector<details>down(All.begin() + 17, All.end());

	print_up_down(up);
	print_sides(sides);
	print_up_down(down);
}
void update_pos(int& pos, int& prison_cnt, int& balance, string& player, int turn)
{
	if (prison_cnt)
	{
		if (!prison_function(balance, prison_cnt, player))
		{
			return;
		}
	}
	cout << "its " << player << "'s turn \nplease enter any char to throw the dice :";
	char k;
	cin >> k;
	c = 1;
	pos = (pos + c) % 28;
	system("cls");
	for (int i = 0;i < 28;i++)All[i].player = "        ";
	if (move_[pos] == 10)
	{
		cout << "you stood on the fast train, so your move has been doubled \n";
		pos = (pos + c) % 28;
	}
	if (pos1 == pos2)
	{
		cout << "You are in the same place\n";
		All[move_[pos]].player = shape3;
	}
	else
	{
		All[move_[pos1]].player = shape1;
		All[move_[pos2]].player = shape2;
	}
	cout << player1 << "'s balance = " << balance1 << " , " << player2 << "'s balance = " << balance2 << endl;
	manage_print();
	cout << "New Move = " << c << endl;

	if (move_[pos] == 17)
	{
		cout << "congratulation you got 250 pounds as you stand on the start of the game :)\n";
		balance += 250;
	}
	else if (move_[pos] == 27)
	{
		prison_cnt = 2;
	}
	else if (move_[pos] == 5 || move_[pos] == 14 || move_[pos] == 22)
	{
		if (turn % 2 == 1)Court(balance1, balance2, prison1, pos1);
		else Court(balance2, balance1, prison2, pos2);
	}
	else if (move_[pos] == 3 || move_[pos] == 13 || move_[pos] == 20)
	{
		if (turn % 2 == 1)Haz(balance1, balance2);
		else Haz(balance2, balance1);
	}
	else if (move_[pos] != 10) price_fare(turn % 2, pos);

}
void solve()
{

	srand(time(0));                 // time to update random value of the dice 
	default_();                     // intitial value of each place
	All[17].player = " ###<>> ";    // name of each player  
	manage_print();
	for (int i = 0;i < 28;i++)cout << All[i].place << " " << move_[i] << endl;
	cout << "enter firstplayer's name : ";
	cin >> player1;
	cout << "enter secondplayer's name : ";
	cin >> player2;
	int turn = 1;
	cout << endl;
	do
	{
		if (turn % 2 == 1)update_pos(pos1, prison1, balance1, player1, turn);
		else update_pos(pos2, prison2, balance2, player2, turn);
		turn++;
	} while (true);

}
int main()
{
	Abdo_Saad();
	solve();
}