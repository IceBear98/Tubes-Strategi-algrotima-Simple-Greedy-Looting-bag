//Fractional Knapsack Problem.
#include <iostream>
#include <vector>
#include <algorithm> // sort().
#include <iterator>

using namespace std;

bool comparator(const pair<int, float> &a,
               const pair<int, float> &b)
{
    return (a.second > b.second);
}

int main()
{
	int n;             //jumlah barang
	float c, wtx, ptx;               //kapasitas knapsack yg dicapai
	vector<float> wt, pt;
	vector<pair<int, float> >vec;

	cout<<"nilai kapasitas yg di capai : ";
	cin>>c;
	cout<<"masukkan jumlah barang : ";
	cin>>n;

	for(int i = 0; i < n; i++)
	{
		cout<<"masukkan bobot dan nilai tiap barang : "<<i+1<<endl;
		cin>>wtx>>ptx;

		wt.push_back(wtx);
		pt.push_back(ptx);
		vec.push_back(make_pair(i, (pt.at(i)/wt.at(i)) ) );
	}

	sort(vec.begin(), vec.end(), comparator);

	int i = 0;
	float profit = 0, weight = 0;
	vector<float> fraction_x;

	while(weight < c)
	{
		if(weight + wt.at(vec[i].first) <= c)
		{
			fraction_x.push_back(1);
			weight = weight + wt.at(vec[i].first);
		}
		else
		{
			float lastfill = (c - weight)/(wt.at(vec[i].first));
			fraction_x.push_back(lastfill);
			weight = c;
		}
		profit = profit + pt.at(vec[i].first)*fraction_x.at(i);
		i++;
	}

	cout<<"maximum profit yg dicapai "<<profit<<endl;

	return 0;
}










