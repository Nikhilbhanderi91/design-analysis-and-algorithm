#include <iostream>
#include <vector>
#include <map>

using namespace std;

int coins_numbers(vector<int> &coins)
{
    // map<int, int> coins_map;
    int amount;
    cout << "Enter Target Amount : ";
    cin >> amount;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int curr_amnt = 1; curr_amnt <= amount; curr_amnt++)
    {
        for (int coin : coins)
        {
            if (curr_amnt >= coin)
            {
                if (dp[curr_amnt - coin] != INT_MAX)
                {
                    dp[curr_amnt] = min(dp[curr_amnt], 1 + dp[curr_amnt - coin]);
                }
            }
        }
    }
    if (dp[amount] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return dp[amount];
    }

    // int count = 0;
    // for (int i = coins.size() - 1; i >= 0; i--)
    // {
    //     while (number >= coins[i])
    //     {
    //         number -= coins[i];
    //         coins_map[coins[i]]++;
    //         count++;
    //     }
    // }
    // cout << endl
    //      << " Required  Coins : \nCoin  :  Number \n";
    // for (pair<int, int> p : coins_map)
    // {
    //     cout << p.first << "  :  " << p.second << endl;
    // }
    // return count;
}

void getvector(vector<int> &coins)
{
    cout << endl;
    for (int i = 0; i < coins.size(); i++)
    {
        cin >> coins[i];
    }
}

int main()
{
    int n;
    cout << "\nEnter Number of Unique coins : ";
    cin >> n;
    vector<int> coins(n);
    getvector(coins);
    cout << coins_numbers(coins);
}
