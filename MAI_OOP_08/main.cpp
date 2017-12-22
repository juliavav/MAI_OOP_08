#include <cstdlib>
#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapeze.h"
#include "TListItem.h"
#include "TList.h"
#include "TTree.h"
#include "Rectangle.h"





int main(int argc, char** argv) {
	TList<Figure> list;
	int menuNum = 7;
	int size;
	int figure;
	std::shared_ptr<Figure> sptr, sptrTemp;
	sptr = std::make_shared<Square>();
	std::cout << "Hello! That's my MENU:" << std::endl;
	while (menuNum != 0) {
		if ((menuNum >= 0) || (menuNum <= 7))
		{
			switch (menuNum)
			{
			case 0:
				std::cout << "Bye!" << std::endl;
				break;
			case 1:
				std::cout << "Please, enter a figure (1 - trapeze; 2- rectangle, 3 - square) " << std::endl;
				std::cin >> figure;
				if (figure == 1) {
					sptr = std::make_shared<Trapeze>(std::cin);
					list.addFirst(sptr);
					std::cout << "Figure is added." << std::endl;
				} 
				else if(figure == 2){
					sptr = std::make_shared<Rectangle>(std::cin);
					list.addFirst(sptr);
					std::cout << "Figure is added." << std::endl;
				}
				else if (figure == 3) {
					sptr = std::make_shared<Square>(std::cin);
					list.addFirst(sptr);
					std::cout << "Figure is added." << std::endl;
				}
				else {
					std::cout << "I can't make such figure." << std::endl;
				}
				std::cout << "______________________________________" << std::endl;
				break;
			case 2:
				std::cout << "Please, enter a figure (1 - trapeze; 2- rectangle, 3 - square). " << std::endl;
				std::cin >> figure;
				if (figure == 1) {
					sptr = std::make_shared<Trapeze>(std::cin);
					list.addLast(sptr);
					std::cout << "Figure is added." << std::endl;
				}
				else if (figure == 2) {
					sptr = std::make_shared<Rectangle>(std::cin);
					list.addLast(sptr);
					std::cout << "Figure is added." << std::endl;
				}
				else if (figure == 3) {
					sptr = std::make_shared<Square>(std::cin);
					list.addLast(sptr);
					std::cout << "Figure is added." << std::endl;
				}
				else {
					std::cout << "I can't make such figure." << std::endl;
				}
				std::cout << "______________________________________" << std::endl;
				break;
			case 3:
				//sptr = std::make_shared<Trapeze>(std::cin);
				//list.addFirst(sptr);
				//std::cout << "______________________________________" << std::endl;
				//break;
				std::cout << "Please, enter an index of figure you want to delete " << std::endl;
				std::cin >> size;
				if (size < 0) {
					std::cout << "I don't know such index." << std::endl;
					break;
				}
				list.delElement(size);
				std::cout << "______________________________________" << std::endl;
				break;
			case 4:
				std::cout << list << std::endl;
				std::cout << "______________________________________" << std::endl;
				break;
			case 5:
				std::cout << "Please, enter a figure you want to add (1 - trapeze; 2- rectangle, 3 - square)." << std::endl;
				std::cin >> figure;
				if (figure == 1) {
					sptr = std::make_shared<Trapeze>(std::cin);
				}
				else if (figure == 2) {
					sptr = std::make_shared<Rectangle>(std::cin);
				}
				else if (figure == 3) {
					sptr = std::make_shared<Square>(std::cin);
				}
				else {
					std::cout << "I can't find such figure." << std::endl;
				}
				std::cout << "Please, enter an index." << std::endl;
				std::cin >> size;
				list.insert(size,sptr);
				std::cout << "______________________________________" << std::endl;
				break;

			case 6:
				list.eraseList();
				std::cout << "List is absolutely clean." << std::endl;
				std::cout << "______________________________________" << std::endl;
				break;
			case 7:
				std::cout << "1. Add new item in begin of list." << std::endl;
				std::cout << "2. Add new item in end of list." << std::endl;
				std::cout << "3. Delete item from list" << std::endl;
				std::cout << "4. Print list." << std::endl;
				std::cout << "5. Insert in list" << std::endl;
				std::cout << "6. Erase list." << std::endl;
				std::cout << "7. Print MENU." << std::endl;
				std::cout << "8. Print list with iterator." << std::endl;
				std::cout << "9. Sort list." << std::endl;
				std::cout << "0. Exit out program." << std::endl;
				std::cout << "______________________________________" << std::endl;
				break;
			case 8:
				for (auto i : list) {
					i->Print();
				}
				break;
			case 9:
				std::cout << "1 to regular sort, 2 to parallel" << std::endl;
				std::cin >> menuNum;
				int temp=1;
				if (menuNum == 1) {
					list.addFirst(sptr);
					list.Sort();
					list.delElement(temp);
				}
				else if (menuNum == 2) {
					list.addFirst(sptr);
					list.ParSort();
					list.delElement(temp);
				}
				else {
					std::cout << "Unknown command" << std::endl;
					break;
				}
				std::cout << list << std::endl;
				break;
			}
			
			//default:
			//std::cout<<"I hardly understand you!"<<std::endl;
		}
		else {
			std::cout << "I hardly understand you!" << std::endl;
		}
		std::cout << "Input from 1 to 9 or 0 for actions." << std::endl;
		std::cin >> menuNum;

	}


	//std::cout << list<<std::endl;
	system("pause");
	return 0;
}
//list.addFirst(Figure(3));
//list.addFirst(Figure(5));
//list.addLast(Figure(4)); //works
//list.insert(Figure(5),Figure(4));//works
//list.delElement(Figure(3));//works
//list.getElement(2); //works
//list.empty();