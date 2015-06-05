#include "FileHandler.h"
#include <iostream>

int main(int argc, char** argv)
{
        FileHandler* fileHandler = new FileHandler("data.txt",1000);
		//first write records
        //printf("Execution Time: %f \n", fileHandler -> writeRecords());
		
		//then read records
		//printf("Execution Time: %f \n", fileHandler -> readRecords());
       		
		//create index for each field name
		
		/**
		fileHandler -> createIndex(firstName);
		fileHandler -> createIndex(middleName);
		fileHandler -> createIndex(lastName);
		fileHandler -> createIndex(address);
		fileHandler -> createIndex(telephoneNumber);
		fileHandler -> createIndex(NICnumber);
		fileHandler -> createIndex(primarySchool);
		fileHandler -> createIndex(secondarySchool);
		fileHandler -> createIndex(teritarySchool);
		fileHandler -> createIndex(workPlace);
		fileHandler -> createIndex(dateOfBirth);
		*/

		
		//search by field name and value
	    fileHandler -> search(primarySchool,"jhk");
		return 0;
}