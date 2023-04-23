# Func.h

	#pragma once
	#include "Data.h"
	
	void DataEntry(Data* (&d), int& n);
	void DataRead(Data* (&d), int& n, string FileName);
	void Print(Data* d, int n);
	void DataChange(Data* d, int n);
	void Copy(Data* d_n, Data* d_o, int n);
	void DataAdd(Data* (&d), int& n);
	void DataDel(Data* (&d), int& n);
	void DataSort(Data* d, int n);
	void DataSave(Data* d, int n, string FileName);
