# ListMenu.h

	#pragma once
	#include <iostream>
	#include <conio.h>
	
	using namespace std;
	
	struct DataMenu {
    	string ItemMenu{};
    	DataMenu* next{};
	};
	
	class Menu {
	private:
    	DataMenu* head;
    	string SelectedItem;
	public:
    	Menu() {
	        head = NULL;
	        SelectedItem = "";
    	}
    	bool isDigit(char ch) {
	        if (ch >= 48 and ch <= 57)
	            return true;
	        else
	            return false;
    	}
    	bool isStringDigit(string _str) {
	        for (int i = 0; i < _str.length(); i++)
	            if (not isDigit(_str[i]))
	                return false;
	        if (_str.length() == 0)
	            return false;
	        return true;
    	}
    	void addItem(string ItemMenu) {
	        DataMenu* newDataMenu = new DataMenu();
	        newDataMenu->ItemMenu = ItemMenu;
	        newDataMenu->next = NULL;
	        if (head == NULL) {
	            head = newDataMenu;
	        }
	        else {
	            DataMenu* current = head;
	            while (current->next != NULL) {
	                current = current->next;
	            }
	            current->next = newDataMenu;
	        }
    	}
    	void printItems() {
	        int NumberMenu = 0;
	        DataMenu* current = head;
	        while (current != NULL) {
	            cout << "(" << NumberMenu << ") " << current->ItemMenu << endl;
	            NumberMenu++;
        	    current = current->next;
        	}
        	cout << "Введите значение: ";
    	}
    	void clearItem(string _SelectedItem = "") {
	        system("cls");
	        SelectedItem = _SelectedItem;
    	}
    	int entryItem(int min, int max) {
	        char ch = 0;
	        printItems();
	        cout << SelectedItem;
	        while (ch != 13) {
	            ch = _getch();
	            if (ch == 8) {
	                if (SelectedItem.length() > 0) {
	                    SelectedItem.pop_back();
	                    system("cls");
	                    printItems();
	                    cout << SelectedItem;
	                }
	                continue;
	            }
	            if (isDigit(ch)) {
	                cout << ch;
	                SelectedItem = SelectedItem + ch;
	            }
	        }
	        int num = max + 1;
	        if (isStringDigit(SelectedItem))
	            num = atoi(SelectedItem.c_str());
	        if (not (num >= min and num <= max)) {
	            cout << endl << "Ошибка: Номер меню, который вы ввели: " << num << " Выходит из диапазона (" << min << "; " << max << ") " << endl;
	            system("pause");
	            clearItem();
	            entryItem(min, max);
	        }
	        return num;
    	}
	};
