// 150150906
// Mareva Zenelaj
// Homework 3
// 16.12.2018

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <map>
using namespace std;

#define m 14000

void divide_number(int, int []);

class HashNode{
public:
	int key; // the line number i guess
	string value;	
	HashNode(int, string);
};

HashNode::HashNode(int key, string value){
	this->value = value;
	this->key = key;
}

class HashTable{
public:
	HashNode **hashTable;
	int size;
	int capacity;
	int collisions;
	int collisions_search;
	int a[3];
	void fill_a();
	HashTable();
	void put_set(int key, string value);
	int linear_probing(int);
	int double_hashing(int);
	int universal_hashing(int);
	void insert_set(int, string, char);
	void print_table();
	int search_linear(string, int);
	int search_double(string, int);
	int search_universal(string, int);
};

void HashTable::fill_a(){
	int r = 3;
	for(int i = 0; i < r; i++)
		a[i] = rand() % (capacity-1);
}

int HashTable::search_linear(string word, int line_number){
	int key; 
	int k;
	if(strcmp(hashTable[line_number]->value.c_str(), word.c_str()) == 0){
		key = line_number;
	}
	else{
		k = line_number + 1;
		while(k < capacity){
			if(!hashTable[k])
				continue;
			if(strcmp(hashTable[k]->value.c_str(), word.c_str())==0){
				key = k;
				break;
			}
			k++;
			collisions_search++;
			}
	}
	return key;

}

int HashTable::search_double(string word, int line_number){
	int key, hash_key; 
	int i = 0;
	int p = 7;
	int h1, h2;
	h1 = line_number % capacity;
	h2 = p - (line_number % p);
	hash_key = (h1+i*h2) % capacity;

	if(strcmp(hashTable[hash_key]->value.c_str(), word.c_str()) == 0){
		key = line_number;
	}
	else{
		while(hashTable[hash_key] && hash_key<capacity && strcmp(hashTable[hash_key]->value.c_str(), word.c_str())!=0){
			i++;
			hash_key = (h1+i*h2) % capacity;
			collisions_search++;
		}
		if(strcmp(hashTable[hash_key]->value.c_str(), word.c_str())==0)
			key = line_number;
	}
	return key;
}

int HashTable::search_universal(string word, int line_number){
	int key = -1; 
	int k, r = 3;
	int k_array[3] = {0};
	divide_number(line_number, k_array);
	int hash_key = 0; 

	for(int j = 0; j < r; j++){
		hash_key += k_array[j]*a[j];
	}
	hash_key = hash_key % capacity;

	if(strcmp(hashTable[hash_key]->value.c_str(), word.c_str()) == 0){
		key = line_number;
	}
	else{
		k = hash_key + 1;
		while(k<capacity){
			if(hashTable[k] == NULL)
				continue;
			if(strcmp(hashTable[k]->value.c_str(), word.c_str())==0){
				key = k;
				break;
			}
			k++;
			collisions_search++;
		}
	}
	cout << 3;
	return key;
}

void HashTable::print_table(){
	int i = 0;
	while(i < capacity){
		if(hashTable[i])
			cout << hashTable[i]->key << " " << hashTable[i]->value << endl;
			i++;
		}
}

int HashTable::linear_probing(int key){
	int i = 0;
	int hash_key;

	hash_key = (key+i) % capacity;
	while(hashTable[hash_key] != NULL){
		i++;
		collisions++;
		hash_key = (key+i) % capacity;
	}
	return hash_key;
}

int HashTable::double_hashing(int key){
	int i = 0;
	int p = 7;
	int hash_key;
	int h1, h2;
	h1 = key % capacity;
	h2 = p - (key % p);
	hash_key = (h1+i*h2) % capacity;
	while(hashTable[hash_key] != NULL){
		i++;
		collisions++;
		hash_key = (h1+i*h2) % capacity;
	}
	return hash_key;
}

int HashTable::universal_hashing(int key){
	int r = 3;
	int k_array[3] = {};
	divide_number(key, k_array);
	int hash_key = 0;
	fill_a();
	for(int j = 0; j < r; j++){
		hash_key += k_array[j]*a[j];
	}
	hash_key = hash_key % capacity;
	while(hashTable[hash_key] != NULL){
		hash_key++;
		collisions++;
	}
	return hash_key;
}

void divide_number(int number, int number_array[3]){
	int i;
	for(i = 0; i < 3; i++){
		number_array[i] = number % 100;
		number = (int)(number - number_array[i])/100;
	}
}

void HashTable::insert_set(int key, string word, char parameter){
	int hash_key;
	switch(parameter){
	case 'l':
		hash_key = linear_probing(key);
		break;
	case 'd':
		hash_key = double_hashing(key); // change 
		break;
	case 'u':
		hash_key = universal_hashing(key); // change
		break;
	}

	hashTable[hash_key] = new HashNode(key, word);
	size++;
}

HashTable::HashTable(){
		capacity = m;
		size = 0;
		collisions = 0;
		collisions_search = 0;
		hashTable = new HashNode*[capacity];
		for(int i=0; i < capacity; i++) 
            hashTable[i] = NULL;
}

int main(int argc, char* argv[]){
	fstream file_vocab, file_search;
	map<string, int> mymap;
	map<string,int>::iterator it;
	string str_, str_1;
	int counter = 0;
	HashTable *table = new HashTable;
	int i = 0, line_number;
	file_vocab.open(argv[1]);
	if(file_vocab){
		while(counter < m){
		getline(file_vocab, str_);
		mymap[str_] = counter;
		table->insert_set(counter, str_, 'd');
		counter++; // counter is the key
		}
	}
	cout << table->collisions;
	//table->print_table();
	getchar();
	file_vocab.close();
	file_search.open(argv[2]);
	if(file_search){
		while(!file_search.eof()){
		getline(file_search, str_1);
		it = mymap.find(str_1);
		if(it != mymap.end())
			line_number = it->second;

		cout << table->search_double(str_1, line_number) << endl;
		}
	}
	file_search.close();
	cout << endl << endl << endl << table->collisions_search;
	getchar();
	return 0;
}