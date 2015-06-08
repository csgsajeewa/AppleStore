#include "FileHandler.h"

//write records to file
double FileHandler::writeRecords()
{
       
		PersonnalDetails* p = new PersonnalDetails[m_numberOfRecords];
		double executionTime = 0;
		//load data
		for(int i=0; i<m_numberOfRecords; ++i)
		{
			strcpy((p+i)->firstName, generateRandomString(3).c_str());
			strcpy((p+i)->middleName, generateRandomString(3).c_str());
			strcpy((p+i)->lastName, generateRandomString(3).c_str());
			strcpy((p+i)->address, generateRandomString(3).c_str());
			strcpy((p+i)->telephoneNumber, generateRandomNumber(3).c_str());
			strcpy((p+i)->emailAddress, (generateRandomString(3)+"@" + generateRandomString(4) + ".com").c_str());
			strcpy((p+i)->primarySchool, generateRandomString(3).c_str());
			strcpy((p+i)->secondarySchool, generateRandomString(3).c_str());
			strcpy((p+i)->teritarySchool, generateRandomString(3).c_str());
			strcpy((p+i)->workPlace, generateRandomString(3).c_str());
			strcpy((p+i)->NICnumber, (generateRandomNumber(9) + "v").c_str());
			strcpy((p+i)->dateOfBirth, (generateRandomNumber(2) + "/" + generateRandomNumber(2) + "/" + generateRandomNumber(4)).c_str());
		}
				
		ofstream outFile("C:\\Users\\chamaths\\Desktop\\data.bin", ios::out | ios::binary);
		if(outFile.is_open())
		{
			clock_t start = clock();
			for(int i=0; i<m_numberOfRecords; ++i)
			{
				outFile.write((char*)(p+i), sizeof(PersonnalDetails));
			}
			clock_t end = clock();
			executionTime = double(double(end - start)*1000/double(CLOCKS_PER_SEC));
			outFile.close();
		}
		else
			cout<<"File Error"<<endl;

		return executionTime;
}

//read records from file
double FileHandler::readRecords()
{
        double executionTime = 0;
		PersonnalDetails* p =new PersonnalDetails[m_numberOfRecords];
		ifstream inFile("C:\\Users\\chamaths\\Desktop\\data.bin", ios::in | ios::binary);
		if(inFile.is_open())
		{
			clock_t start = clock();
			for(int i = 0; i<m_numberOfRecords; ++i)
			{
				inFile.read((char*)(p+i), sizeof(PersonnalDetails));
			}
			clock_t end = clock();
			executionTime = double(double(end - start)*1000/double(CLOCKS_PER_SEC));
			inFile.close();
		}
		else
			cout<<"File Error"<<endl;
		
		for(int i=0; i<m_numberOfRecords; ++i)
		{
			cout<< "------------------------------------"<< i << endl;
			cout<< (p+i)->firstName << endl;
			cout<< (p+i)->middleName<< endl;
			cout<< (p+i)->lastName << endl;
			cout<< (p+i)->address << endl;
			cout<< (p+i)->telephoneNumber << endl;
			cout<< (p+i)->emailAddress<< endl;
			cout<< (p+i)->primarySchool<< endl;
			cout<< (p+i)->secondarySchool<< endl;
			cout<< (p+i)->teritarySchool<< endl;
			cout<< (p+i)->workPlace<< endl;
			cout<< (p+i)->NICnumber<< endl;
			cout<< (p+i)->dateOfBirth<< endl;
		}
		       
        return executionTime;
}

//create the index
void FileHandler::createIndex(FieldName fieldName)
{
	PersonnalDetails* p =new PersonnalDetails[m_numberOfRecords];
	ifstream inFile("C:\\Users\\chamaths\\Desktop\\data.bin", ios::in | ios::binary);
	if(inFile.is_open())
	{
		for(int i = 0; i<m_numberOfRecords; ++i)
		{
			inFile.read((char*)(p+i), sizeof(PersonnalDetails));
		}	
		inFile.close();
	}
	else
		cout<<"File Error"<<endl;

	std::multimap<string,int>*index = new std::multimap<string,int>();
	for(int i=0; i<m_numberOfRecords; ++i)
	{
		//select appropriate field name
		switch(fieldName)
		{
		case firstName:
			index->insert(std::pair<string,int>((p+i)->firstName,i));
			break;
		case middleName:
			index->insert(std::pair<string,int>((p+i)->middleName,i));
			break;
		case lastName:
			index->insert(std::pair<string,int>((p+i)->lastName,i));
			break;
		case address:
			index->insert(std::pair<string,int>((p+i)->address,i));
			break;
		case telephoneNumber:
			index->insert(std::pair<string,int>((p+i)->telephoneNumber,i));
			break;
		case emailAddress:
			index->insert(std::pair<string,int>((p+i)->emailAddress,i));
			break;
		case NICnumber:
			index->insert(std::pair<string,int>((p+i)->NICnumber,i));
			break;
		case primarySchool:
			index->insert(std::pair<string,int>((p+i)->primarySchool,i));
			break;
		case secondarySchool:
			index->insert(std::pair<string,int>((p+i)->secondarySchool,i));
			break;
		case teritarySchool:
			index->insert(std::pair<string,int>((p+i)->teritarySchool,i));
			break;
		case workPlace:
			index->insert(std::pair<string,int>((p+i)->workPlace,i));
			break;
		case dateOfBirth:
			index->insert(std::pair<string,int>((p+i)->dateOfBirth,i));
			break;
		}
		
	}
		
	multimap<string, int>::iterator m_it = index->begin();
	multimap<string, int>::iterator m_itEnd = index->end();
	multimap<string, int>::iterator s_it;

	FILE* file = fopen(getIndexFileName(fieldName), "w");
	if(file)
	{
		for(;m_it != m_itEnd; m_it = s_it)
		{
			pair<multimap<string,int>::iterator, multimap<string,int>::iterator> iteratorPair = index->equal_range((*m_it).first);
			//write key value
			fputs((*m_it).first.c_str(), file);
			//write each value related to the key
			for (s_it = iteratorPair.first; s_it != iteratorPair.second;++s_it)
			{
				int number = (*s_it).second;
				char *intStr = new char(); 
				itoa(number,intStr,10);
				fputs(" ", file);
				fputs(intStr, file);
			}
			fputs("\n", file);
		}
		fclose(file);
	}
	else
		cout << "Can not create Index" << endl;
			       
}


			 {
				 if(matched)
				 {
					 int num= atoi(token.c_str());
					 //get specific record from data file
					 p = getSpecificRecord(num);	
					 cout<< "------------------------------------"<< endl;
						cout<< "First Name: " << p->firstName << endl;
						cout<< "Middle Name: " << p->middleName<< endl;
						cout<< "Last Name: " << p->lastName << endl;
						cout<< "Address: " << p->address << endl;
						cout<< "TP: " << p->telephoneNumber << endl;
						cout<< "E-mail: " << p->emailAddress<< endl;
						cout<< "Primary School: " << p->primarySchool<< endl;
						cout<< "Secondary School: " <<p->secondarySchool<< endl;
						cout<< "Teritery School: " << p->teritarySchool<< endl;
						cout<< "Work Place: " << p->workPlace<< endl;
						cout<< "NIC: " << p->NICnumber<< endl;
						cout<< "DOB: " << p->dateOfBirth<< endl;
				 }
				 if(token.compare(value) == 0)
				 {
					 matched = true;
				 }
			 }	 
			 if(matched)
			 {
				 cout<<endl;
				 break;
			 }
		 }
		 file.close();
	}
	else
		cout<< "Can not perform search operation" << endl;
}

string FileHandler::generateRandomString(int length)
{
	char *s = new char[length+1]; 
	static const char alphanum[] =
        "aehjkl";
    for (int i = 0; i < length; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[length] = 0;
	string randomString(s);
	return randomString;
}

string FileHandler::generateRandomNumber(int length)
{
	char *s = new char[length+1]; 
	static const char alphanum[] =
        "0123456789";
    for (int i = 0; i < length; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[length] = 0;
	string randomString(s);
	return randomString;
}

string FileHandler::generateRandomEmailAddress(int length)
{
	string eMailAddress = generateRandomString(length)+"@"+generateRandomString(4)+".com";
	return eMailAddress;
}

char* FileHandler::getIndexFileName (FieldName fieldName)
{	
	char* fileName;
	switch(fieldName)
	{
		case firstName:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\firstNameIndex.txt";
			break;
		case middleName:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\middleNameIndex.txt";
			break;
		case lastName:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\lastNameIndex.txt";
			break;
		case address:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\addressIndex.txt";
			break;
		case telephoneNumber:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\telephoneNumberIndex.txt";
			break;
		case emailAddress:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\emailAddressIndex.txt";
			break;
		case NICnumber:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\NICnumberIndex.txt";
			break;
		case primarySchool:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\primarySchoolIndex.txt";
			break;
		case secondarySchool:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\secondarySchoolIndex.txt";
			break;
		case teritarySchool:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\teritarySchoolIndex.txt";
			break;
		case workPlace:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\workPlaceIndex.txt";
			break;
		case dateOfBirth:
			fileName = "C:\\Users\\chamaths\\Desktop\\Index\\dateOfBirthIndex.txt";
			break;
	}
	return fileName;
}