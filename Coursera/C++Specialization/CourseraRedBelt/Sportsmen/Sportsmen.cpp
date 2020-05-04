// Sportsmen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int counter = 0;
	cin >> counter;
	forward_list<int> team;

	for (int i = 0; i < counter; ++i)
	{
		int player_number;
		cin >> player_number;
		int player_after;
		cin >> player_after;

		auto it = find(team.begin(), team.end(), player_after);
		if (it != team.end())
		{
			team.insert_after(it, player_number);
		}
		else 
		{
			team.push_front(player_number);
		}
		
	}

	team.reverse();

	for (const auto& it : team) {
		cout << it << "\n";
	}*/


		int n;
		cin >> n;

		list<int> result;
		vector<list<int>::iterator> sportsmenIter{ 100000, result.end() };

		int sportsmenNum, stayBefore;
		for (; n > 0; --n)
		{
			cin >> sportsmenNum >> stayBefore;
			sportsmenIter[sportsmenNum] = result.insert(sportsmenIter[stayBefore], sportsmenNum);
		}
		for (auto& sportsmen : result)
		{
			cout << sportsmen << " ";
		}
		cout << endl;
		return 0;

}

