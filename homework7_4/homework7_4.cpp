// homework7_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<fstream>

struct employee1
{
	char name[30];
	char surname[60];
	int age;
	int experience;
};

#pragma pack(push,1)
struct employee2
{
	char name[30];
	char surname[60];
	int age;
	int experience;
};
#pragma pack(pop)

int main()
{
	int size1 = sizeof(employee1);
	int size2 = sizeof(employee2);

	employee1* worker1 = new employee1;
	employee2* worker2 = new employee2;

	*worker1 = { "Anna", "Bolein", 40, 22 };
	*worker2 = { "Anna", "Bolein", 40, 22 };


	std::cout << "\r\nStructure without pragma pack: \r\n";
	std::cout << worker1->name << " - size=" << sizeof(worker1->name) << std::endl;
	std::cout << worker1->surname << " - size=" << sizeof(worker1->surname) << std::endl;
	std::cout << worker1->age << " - size=" << sizeof(worker1->age) << std::endl;
	std::cout << worker1->experience << " - size=" << sizeof(worker1->experience) << std::endl;

	std::cout << "Size of structure1: " << size1 << std::endl;
	
	std::cout << "\r\nStructure with pragma pack: \r\n";
	std::cout << worker2->name << " - size=" << sizeof(worker2->name) << std::endl;
	std::cout << worker2->surname << " - size=" << sizeof(worker2->surname) << std::endl;
	std::cout << worker2->age << " - size=" << sizeof(worker2->age) << std::endl;
	std::cout << worker2->experience << " - size=" << sizeof(worker2->experience) << std::endl;

	std::cout << "Size of structure2: " << size2 << std::endl;

	
	std::ofstream fout;
	fout.open("structures.txt");

	if (fout.is_open())
	{
		fout << "Structure without pragma pack: \r\n";

		fout << worker1->name << " - size=" << sizeof(worker1->name) << std::endl;
		fout << worker1->surname << " - size=" << sizeof(worker1->surname) << std::endl;
		fout << worker1->age << " - size=" << sizeof(worker1->age) << std::endl;
		fout << worker1->experience << " - size=" << sizeof(worker1->experience) << std::endl;
		
		fout << "Size of structure1: " << size1 << std::endl;

		fout << "\r\nStructure with pragma pack: \r\n";
		fout << worker2->name << " - size=" << sizeof(worker2->name) << std::endl;
		fout << worker2->surname << " - size=" << sizeof(worker2->surname) << std::endl;
		fout << worker2->age << " - size=" << sizeof(worker2->age) << std::endl;
		fout << worker2->experience << " - size=" << sizeof(worker2->experience) << std::endl;

		fout << "Size of structure2: " << size2 << std::endl;
	}
	fout.close();
	
	delete[] worker1;
	delete[] worker2;

	return 0;

}