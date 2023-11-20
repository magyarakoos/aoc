#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Monke
{
    int id;
    ll inspect;
    vector<ll> items;
    function<ll(ll)> operation;
    int div_by;
    pair<int, int> target;

    Monke(vector<string> data)
    {
        id = stoi(data[0].substr(7, 1));
        inspect = 0;
        stringstream ss(data[1].substr(17));
        string s;
        while (getline(ss, s, ','))
        {
            items.push_back(stoi(s));
        }
        
        if (data[2].substr(19) == "old * old")
        {
            operation = [](ll old) {
                return old * old;
            };
        }
        else
        {
            int n = stoi(data[2].substr(25));
            if (data[2][23] == '*')
            {
                operation = [n](ll old) {
                    return old * n;
                };
            }
            else
            {
                operation = [n](ll old) {
                    return old + n;
                };
            }
        }


        div_by = stoi(data[3].substr(21));

        target.first = stoi(data[4].substr(29));
        target.second = stoi(data[5].substr(30));
    }

    static Monke& search(vector<Monke>& monkeys, int id)
    {
        for (auto& m : monkeys)
        {
            if (m.id == id)
            {
                return m;
            }
        }
        throw exception();
    }
};

int main()
{
    vector<Monke> monkeys;

    ifstream f("input.txt");
    string line;
    vector<string> lines;

    while (getline(f, line))
    {
        if (line.empty())
        {
            Monke m(lines);
            monkeys.push_back(m);
            lines.clear();
        }
        else
        {
            lines.push_back(line);
        }
    }

    int mod = 1;
    for (auto& m : monkeys)
    {     
        mod *= m.div_by;
    }

    for (int i = 0; i < 10000; i++)
    {
        for (auto& m : monkeys)
        {
            for (int j = m.items.size() - 1; j >= 0; j--)
            {
                m.inspect++;
                ll temp = m.items[j];
                m.items.erase(m.items.begin() + j);

                temp = m.operation(temp);
                temp %= mod;

                if (temp % m.div_by == 0)
                {
                    Monke::search(monkeys, m.target.first).items.push_back(temp);
                }
                else
                {
                    Monke::search(monkeys, m.target.second).items.push_back(temp);
                }
            }
        }
    }

    ll _1 = 0;
    ll _2 = 0;
    for (auto& m : monkeys) 
    {
        if (m.inspect > _1) 
        {
            _2 = _1;
            _1 = m.inspect;
        } else if (m.inspect > _2) 
        {
            _2 = m.inspect;
        }
    }
    cout << _1 * _2 << endl;

    return 0;
}


