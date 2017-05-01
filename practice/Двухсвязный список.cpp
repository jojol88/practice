#include <iostream>
using namespace std;

template <class T>
struct List{
	T name[30];
	List *next;
	List *prev;
};

List *head; // голова списка

void CreateList(){ // створення списка
	head = NULL;
}

template <typename T>
void push_back(T newname[30]){ // добавити з хвоста
	List *n = new List;
	strcpy_s(n->name, newname);
	if (head == NULL){
		head = n;
		head->next = NULL;
	}
	else{
		n->next = head;
		while (n->next != NULL)
			n = n->next;
		List * nova = new List;
		strcpy_s(nova->name, newname);
		n->next = nova;
		nova->prev = n;
		nova->next = NULL;
	}
}

template <typename T>
bool insert(T after[30]){ // добавити після якогось елемента
	T newname[30];
	List *n = head;
	while (n != NULL){
		if (strcmp(n->name, after) == 0){
			cout << after << " Знайдено!" << endl;
			cout << "Введіть ім'я, що потрібно додати: " << endl;
			cin >> newname;
			List * list = new List;
			list->next = n->next;
			n->next = list;
			list->prev = n;
			strcpy_s(list->name, newname);
			return true;
		}
		n = n->next;
	}
	cout << "Не знайдено нікого!" << endl;
	return false;
}

template <typename T>
void delete_at(T smbdy[30]){ // видалення елемента
	if (head == NULL){
		perror("Список порожній!");
	}
	else{
		List * n = head;
		while (strcmp(head->name, smbdy) == 0){
			head = head->next;
		}
		List * pr;
		n = head;
		if (n != NULL){
			while (n->next != NULL){
				if (strcmp(n->next->name, smbdy) == 0){
					pr = n->next->next;
					delete n->next;
					n->next = pr;
					pr->prev = n;
				}
				if ((n->next != NULL) && (strcmp(n->next->name, smbdy) != 0))
					n = n->next;
			}
		}
	}
}