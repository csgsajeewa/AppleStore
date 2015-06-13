#pragma once
#include "PersonnalDetails.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

enum FieldName
{
	firstName,
	middleName,
	lastName,
	address,
	telephoneNumber,
	emailAddress,
	NICnumber,

};

class FileHandler
{
public:
		void show();
        FileHandler(string fileName, int numberOfRecords):m_fileName(fileName), m_numberOfRecords(numberOfRecords){}
        double writeRecords(); //
        double readRecords(); //
		PersonnalDetails* getSpecificRecord(int offset); //
		void createIndex(FieldName fieldName);//
		void search(FieldName, string value);//
private:
		string generateRandomString(int length);
		string generateRandomNumber(int length);
		string generateRandomAlphaNumericString(int length);
		string generateRandomEmailAddress(int length);
		char* getIndexFileName(FieldName fieldName);
        string m_fileName;
		int m_numberOfRecords;
};