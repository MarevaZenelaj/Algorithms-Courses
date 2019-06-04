#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include <cstdlib>

using namespace std;

class Items{
	public:
		string timestamp;
		int instrument_token;
		float last_price;
		int volume;
		int sell_quantity;
		int last_quantity;
		float change;
		float average_price;
		float open;
		float high;
		float low;
		float close;
		float depth_buy_price_0;
		int depth_buy_orders_0;
		int depth_buy_quantity_0;
		float depth_sell_price_0;
		int depth_sell_orders_0;
		int depth_sell_quantity_0;
		float depth_buy_price_1;
		int depth_buy_orders_1;
		int depth_buy_quantity_1;
		float depth_sell_price_1;
		int depth_sell_orders_1;
		int depth_sell_quantity_1;
		float depth_buy_price_2;
		int depth_buy_orders_2;
		int depth_buy_quantity_2;
		float depth_sell_price_2;
		int depth_sell_orders_2;
		int depth_sell_quantity_2;
		float depth_buy_price_3;
		int depth_buy_orders_3;
		int depth_buy_quantity_3;
		float depth_sell_price_3;
		int depth_sell_orders_3;
		int depth_sell_quantity_3;
		float depth_buy_price_4;
		int depth_buy_orders_4;
		int depth_buy_quantity_4;
		float depth_sell_price_4;
		int depth_sell_orders_4;
		int depth_sell_quantity_4;
};


void merge_sort(Items arr[], int, int, char);
void merge_all(Items array_[], int low, int mid, int high, char);
void insertion_sort(Items array_[], int, char);
bool compare_class_objects(Items a, Items b, char parameter);

int main(int argc, char* argv[]){
	char algorithm, feature;
	int nr_inputs;
	if (strcmp(argv[1],"-algo")==0){
		if (strcmp(argv[2],"m")==0)
			algorithm = 'm';
		else if (strcmp(argv[2],"i")==0)
			algorithm = 'i';
	}
	if (strcmp(argv[3],"-feature")==0){
		if (strcmp(argv[4],"t")==0)
			feature = 't';
		else if (strcmp(argv[4],"p")==0)
			feature = 'p';
	}
	if (strcmp(argv[5],"-size")==0){
		nr_inputs = atoi(argv[6]);
	}
	//char feature_used = feature[0];
	Items *array_of_items = new Items[nr_inputs+1];
	fstream file;
	string a, get_string;
	file.open("sorted_1.csv");
	if (!file) cout << "File could not be opened!";
	if (file){
		getline(file, a, '\n');
		for (int i = 0; i < nr_inputs; i++){
			getline(file, array_of_items[i].timestamp, ',');
			getline(file, get_string, ',');
			array_of_items[i].instrument_token = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].last_price = strtof(get_string.c_str(),0);

			getline(file, get_string, ',');
			array_of_items[i].volume = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].sell_quantity = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].last_quantity = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].change = strtof(get_string.c_str(),0);

			getline(file, get_string, ',');
			array_of_items[i].average_price = strtof(get_string.c_str(), 0);

			getline(file, get_string, ',');
			array_of_items[i].open = strtof(get_string.c_str(),0);

			getline(file, get_string, ',');
			array_of_items[i].high = strtof(get_string.c_str(), 0);

			getline(file, get_string, ',');
			array_of_items[i].low = strtof(get_string.c_str(), 0);

			getline(file, get_string, ',');
			array_of_items[i].close = strtof(get_string.c_str(), 0);

			getline(file, get_string, ',');
			array_of_items[i].depth_buy_price_0 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_orders_0 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_quantity_0 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_price_0 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_orders_0 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_quantity_0 = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].depth_buy_price_1 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_orders_1 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_quantity_1 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_price_1 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_orders_1 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_quantity_1 = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].depth_buy_price_2 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_orders_2 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_quantity_2 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_price_2 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_orders_2 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_quantity_2 = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].depth_buy_price_3 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_orders_3 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_quantity_3 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_price_3 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_orders_3 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_quantity_3 = atoi(get_string.c_str());

			getline(file, get_string, ',');
			array_of_items[i].depth_buy_price_4 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_orders_4 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_buy_quantity_4 = atoi(get_string.c_str());
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_price_4 = strtof(get_string.c_str(), 0);
			getline(file, get_string, ',');
			array_of_items[i].depth_sell_orders_4 = atoi(get_string.c_str());
			getline(file, get_string, '\n');
			array_of_items[i].depth_sell_quantity_4 = atoi(get_string.c_str());		
		}
	}
	
	Items new_data;	
	new_data.timestamp = "6/22/2017  5:14:44 AM";
	new_data.instrument_token = 340481;
	new_data.last_price=1646;
	new_data.volume=728165;
	new_data.sell_quantity=143273;
	new_data.last_quantity=4;
	new_data.change=1.090127437;
	new_data.average_price=1644.9;
	new_data.open=1626.1;
	new_data.high=1651.15;
	new_data.low=1626.1;
	new_data.close=1628.25;
	new_data.depth_buy_price_0=1645.95;
	new_data.depth_buy_orders_0=16;
	new_data.depth_buy_quantity_0=395;
	new_data.depth_sell_price_0=1646;
	new_data.depth_sell_orders_0=12;
	new_data.depth_sell_quantity_0=269;
	new_data.depth_buy_price_1=1645.9;
	new_data.depth_buy_orders_1=4;
	new_data.depth_buy_quantity_1=64;
	new_data.depth_sell_price_1=1646.05;
	new_data.depth_sell_orders_1=3;
	new_data.depth_sell_quantity_1=19;
	new_data.depth_buy_price_2=1645.85;
	new_data.depth_buy_orders_2=1;
	new_data.depth_buy_quantity_2=43;
	new_data.depth_sell_price_2=1646.1;
	new_data.depth_sell_orders_2=1;
	new_data.depth_sell_quantity_2=9;
	new_data.depth_buy_price_3=1645.5;
	new_data.depth_buy_orders_3=1;
	new_data.depth_buy_quantity_3=500;
	new_data.depth_sell_price_3=1646.15;
	new_data.depth_sell_orders_3=1;
	new_data.depth_sell_quantity_3=2;
	new_data.depth_buy_price_4=1645.35;
	new_data.depth_buy_orders_4=1;
	new_data.depth_buy_quantity_4=57;
	new_data.depth_sell_price_4=1646.5;
	new_data.depth_sell_orders_4=2;
	new_data.depth_sell_quantity_4=2;

	array_of_items[nr_inputs] = new_data;


	clock_t before_time, after_time;
	if (algorithm == 'm'){
		before_time = clock();
		merge_sort(array_of_items, 0, nr_inputs - 1, feature);
		after_time = clock();
	}
	else if (algorithm=='i'){
		before_time = clock();
		insertion_sort(array_of_items, nr_inputs, feature);
		after_time = clock();
	}
	//clock_t time_elapsed = after_time - before_time;
	cout << ((double)after_time - (double)before_time)/CLOCKS_PER_SEC << endl;
	
	return 0;
}

void merge_sort(Items array_[], int low, int high, char parameter){
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		merge_sort(array_, low, mid, parameter);
		merge_sort(array_, mid + 1, high, parameter);
		merge_all(array_, low, mid, high, parameter);
	}
}

bool compare_class_objects(Items a, Items b, char parameter){
	bool result = false;
	switch (parameter)
	{
	case 't': 
		//cout << endl << a.timestamp << " " << b.timestamp << endl;
		if (a.timestamp.compare(b.timestamp)<=0)
			result = true;
	case 'p':
		if (a.last_price <= b.last_price)
			result = true;
	}
	return result;
}

void merge_all(Items array_[], int low, int mid, int high, char parameter){
	int sizea = mid - low + 1;
	int sizeb = high - mid;
	Items *L = new Items[sizea];
	Items *H = new Items[sizeb];
	for (int i = 0; i < sizea; i++)
		L[i] = array_[low + i];
	for (int j = 0; j < sizeb; j++)
		H[j] = array_[mid + j + 1];

	int i = 0, j = 0, cnt = low;
	while (i < sizea && j < sizeb)
	{
		if (compare_class_objects(L[i],H[j], parameter))
		{
			array_[cnt++] = L[i];
			i++;
		}
		else
		{
			array_[cnt++] = H[j];
			j++;
		}
	}
	while (i < sizea)
	{
		array_[cnt++] = L[i];
		i++;
	}
	while (j < sizeb)
	{
		array_[cnt++] = H[j];
		j++;
	}
}

void insertion_sort(Items array_[], int n, char parameter){
	Items key;
	int i;
	for (int j = 2; j < n; j++){
		key = array_[j];
		i = j - 1;
		while (i >= 0 && !compare_class_objects(array_[i], key, parameter)){
			array_[i + 1] = array_[i];
			i--;
		}
		array_[i + 1] = key;
	}
}