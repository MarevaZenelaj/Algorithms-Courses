#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

int heap_size = 0;

class Employees{
public:
	int id;
	int total;
	int positive;
	int negative;
	int performance_score;
}; 

void heap_increase_key(Employees heap_array[], int i, Employees key, char parameter);

int parent(int i){
	return floor(i / 2);
}

void max_heapify(Employees heap_array[], int i, char parameter){
	int largest;
	Employees temp;
	int left = 2 * i;
	int right = 2 * i + 1;
	switch (parameter)
	{
	case 'p':
		if (left <= heap_size && heap_array[left].performance_score > heap_array[i].performance_score)
			largest = left;
		else
			largest = i;
		if (right <= heap_size && heap_array[right].performance_score > heap_array[largest].performance_score)
			largest = right;
		if (largest != i){
			temp = heap_array[i];
			heap_array[i] = heap_array[largest];
			heap_array[largest] = temp;
			max_heapify(heap_array, largest, parameter);
		}
		break;
	case 'c':
		if (left <= heap_size && heap_array[left].total > heap_array[i].total)
			largest = left;
		else
			largest = i;
		if (right <= heap_size && heap_array[right].total > heap_array[largest].total)
			largest = right;
		if (largest != i){
			temp = heap_array[i];	
			heap_array[i] = heap_array[largest];
			heap_array[largest] = temp;
			max_heapify(heap_array, largest, parameter);
		}
		break;
	default:
		break;
	}
	
	
}

void build_max_heapify(Employees heap_array[], char parameter){
	int start = (int)floor(heap_size/2);
	for (int i = start; i > 0; i--){
			max_heapify(heap_array, i, parameter);
		}
}

void heapsort(Employees heap_array[], char parameter){
	build_max_heapify(heap_array, parameter);
	int start = (int)floor(heap_size / 2);
	Employees temp;
	for (int i = start; i > 1; i--){
		temp = heap_array[1];
		heap_array[1] = heap_array[i];
		heap_array[i] = temp;
		// add heapsize--;
		max_heapify(heap_array, 1, parameter);
	}
}

Employees heap_maximum(Employees heap_array[]){
		return heap_array[0];
}

void heap_insert_employee(Employees heap_array[], Employees key, char parameter){
			heap_size++;
			heap_array[heap_size].total = -99999;
			heap_increase_key(heap_array, heap_size, key, parameter);
}

void heap_increase_key(Employees heap_array[], int i, Employees key, char parameter){
	Employees temp;
	if (parameter = 'i' && key.id < heap_array[i].id)
		return;
	if (parameter = 'p' && key.performance_score < heap_array[i].performance_score)
		return;
	if (parameter = 'c' && key.total < heap_array[i].total)
		return;
	 
	heap_array[i] = key;
	switch (parameter)
	{
	case 'p':
		while (i > 1 && heap_array[parent(i)].performance_score < heap_array[i].performance_score){
			temp = heap_array[1];
			heap_array[1] = heap_array[i];
			heap_array[i] = temp;
			i = parent(i);
		}
		break;
	case 'c':
		while (i > 1 && heap_array[parent(i)].total < heap_array[i].total){
			temp = heap_array[1];
			heap_array[1] = heap_array[i];
			heap_array[i] = temp;
			i = parent(i);
		}
		break;
	case 'i':
		while (i > 1 && heap_array[parent(i)].id < heap_array[i].id){
			temp = heap_array[1];
			heap_array[1] = heap_array[i];
			heap_array[i] = temp;
			i = parent(i);
		}
		break;
	default:
		break;
	}
}

int heap_extract_max(Employees heap_array[], char parameter){
	if (heap_size < 1)
		cout << "heap underflow";

	int max = heap_array[0].id;
	heap_array[0] = heap_array[heap_size];
	heap_size--;
	max_heapify(heap_array, 1, parameter);
	return max;
}

int search_id(Employees heap_array[], int id){
	int result = -1;
	for (int i = 0; i < heap_size; i++){
		if (heap_array[i].id == id)
			result = i;
	}
	return result;
}

int main(){
	Employees added_employee;
	Employees *heap_performance;
	Employees *heap_calls;
	heap_performance = new Employees;
	heap_calls = new Employees;
	fstream file;
	string str;
	int counter = 0;
	file.open("day1.csv");
	if (file){
		while (file.peek() != EOF){
			getline(file, str, ','); 
			added_employee.id = atoi(str.c_str());
			getline(file, str, ',');
			added_employee.total = atoi(str.c_str());
			getline(file, str, ',');
			added_employee.positive = atoi(str.c_str());
			getline(file, str, '\n');
			added_employee.negative = atoi(str.c_str());
			added_employee.performance_score = 2 * added_employee.total + added_employee.positive - added_employee.negative;
			heap_performance[heap_size] = added_employee;
			heap_calls[heap_size] = added_employee;
			build_max_heapify(heap_performance, 'p');
			build_max_heapify(heap_calls, 'c');	
			heap_size++;
		}

		
		heapsort(heap_performance, 'p');
		heapsort(heap_calls, 'c');
		cout << "AFTER DAY-" << 1 << endl;
		cout << "BEST PERFORMANCE\t" << ":" << heap_performance[heap_size].id << ',' << heap_performance[heap_size - 1].id << ',' << heap_performance[heap_size - 2].id << endl;
		cout << "WORST PERFORMANCE\t" << ":" << heap_performance[0].id << ',' << heap_performance[1].id << ',' << heap_performance[2].id << endl;
		cout << "MAXIMUM CALLS\t" << ":" << heap_calls[heap_size].id << ',' << heap_calls[heap_size - 1].id << ',' << heap_calls[heap_size - 2].id << endl;
		cout << "MINIMUM CALLS\t" << ":" << heap_calls[0].id << ',' << heap_calls[1].id << ',' << heap_calls[2].id << endl;
	}
	file.close();

	string input_file = "day";
	string extention = ".csv";
	fstream n_file;
	Employees new_emp;
	string middle, filee;
	int id, position1, position2, m;
	std::string out_string;
	std::stringstream ss;
	
	for (int k = 1; k < 11; k++){
		m = k + 1;
		ss << m;
		middle = ss.str();
		filee = input_file + middle + extention;
		n_file.open(filee.c_str());
		if (n_file){
			while (!file.eof()){
				getline(file, str, ',');
				id = atoi(str.c_str());
				position1 = search_id(heap_performance, id);
				position2 = search_id(heap_calls, id);
				if (position1>0){
					getline(file, str, ',');
					heap_performance[position1].total = heap_performance[position1].total + atoi(str.c_str());
					getline(file, str, ',');
					heap_performance[position1].positive = heap_performance[position1].positive + atoi(str.c_str());
					getline(file, str, '\n');
					heap_performance[position1].negative = heap_performance[position1].negative + atoi(str.c_str());
					heap_performance[position1].performance_score = 2 * heap_performance[position1].total + heap_performance[position1].positive - heap_performance[position1].negative;
					max_heapify(heap_performance, position1, 'p');
			}
				else{
					new_emp.id = id;
					getline(file, str, ',');
					new_emp.total = atoi(str.c_str());
					getline(file, str, ',');
					new_emp.positive = atoi(str.c_str());
					getline(file, str, '\n');
					new_emp.negative = atoi(str.c_str());
					new_emp.performance_score = 2 * new_emp.total + new_emp.positive - new_emp.negative;
					heap_insert_employee(heap_performance,new_emp, 'p');
					heap_insert_employee(heap_calls,new_emp, 'c');
					heap_size++;
				}
			if (position2>0){
					heap_calls[position2].total = heap_performance[position1].total;
					heap_calls[position2].positive = heap_performance[position1].positive;
					heap_calls[position2].negative = heap_performance[position1].negative;
					heap_calls[position2].performance_score = heap_performance[position1].performance_score;
					max_heapify(heap_calls, position2, 'c');
					}
			}
		}

		heapsort(heap_calls, 'c');
		heapsort(heap_performance, 'p');
		cout << "AFTER DAY-" << k+1 << endl;
		cout << "BEST PERFORMANCE\t" << ":" << heap_performance[heap_size].id << ',' << heap_performance[heap_size - 1].id << ',' << heap_performance[heap_size - 2].id << endl;
		cout << "WORST PERFORMANCE\t" << ":" << heap_performance[0].id << ',' << heap_performance[1].id << ',' << heap_performance[2].id << endl;

		cout << "MAXIMUM CALLS\t" << ":" << heap_calls[heap_size].id << ',' << heap_calls[heap_size - 1].id << ',' << heap_calls[heap_size - 2].id << endl;
		cout << "MINIMUM CALLS\t" << ":" << heap_calls[0].id << ',' << heap_calls[1].id << ',' << heap_calls[2].id << endl;
	}
	return 0;
}