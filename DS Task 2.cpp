// DS Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//    Данная лабораторная работа состоит в выполнении варианта задания из пункта 1 и пункта 2.
// 1. Написать операции работы с заданной структурой данных,
// включив их в один модуль(файл). К основным операциям (см.таблицу 1) 
// добавить операцию, показывающую содержимое структуры после выполнения какого - либо действия с ней.
// Эту операцию реализовать на основе базовых операций
// б) основные операции над динамическим стеком;
// 2. Написать программу, демонстрирующую выполнение операций
// над заданной структурой данных. Эту программу надо поместить в свой модуль
// (файл). Модуль с основными операциями включать в программу, используя
// директиву include.
//
// Авторы: Бурлаков В., Неретин С. Бригада № 9.

#include <iostream>
#include <string>

#include "DynamicStack.h"

enum MenuCommand : char
{
   MenuCommand_PushBack = '1', 
   MenuCommand_PopBack = '2',
   MenuCommand_Print = '3',
   MenuCommand_Empty = '4',
   MenuCommand_Exit = '5',
   MenuCommand_Help = '?'
};

inline void printHelpSection(std::ostream &output)
{
   output << "\t THE HELP MENU SECTION" << std::endl
      << "Please, press the following key on the keyboard" << std::endl
      << "Stack commands menu: " << std::endl
      << "<1> - add element to stack" << std::endl
      << "<2> - delete element from stack" << std::endl
      << "<3> - print stack" << std::endl
      << "<4> - check if a stack is empty" << std::endl
      << "<5> - exit" << std::endl
      << "<?> - call the help menu" << std::endl;
}

inline void printIncorrectCommandInfo(std::ostream &output, std::string menuCommand)
{
   output << "ERROR: incorrect command <" << menuCommand << "> " << std::endl
      << "Please, press <?> to call the help menu" << std::endl;
}

inline void printCommandDone(std::ostream &output)
{
   output << "Done!" << std::endl;
}

inline void printEnterMenuCommand(std::ostream &output)
{
   output << "Enter the menu command: " << std::endl;
}

inline void printEnterData(std::ostream &output)
{
   output << "Enter the data: " << std::endl;
}

void exitMenu(std::ostream &output, bool &done)
{
   output << "EXTITING . . ." << std::endl;
   done = true;
}

int main()
{
   printHelpSection(std::cout);

   DynamicStack<int> stack;

   std::string menuCommand;
   bool done = false;

   do
   {
      bool correctCommand = true;
      do
      {
         printEnterMenuCommand(std::cout);
         std::cin >> menuCommand;

         if (menuCommand.size() != 1)
         {
            printIncorrectCommandInfo(std::cout, menuCommand);
            correctCommand = false;
            break;
         }
         
         int data = 0;

         switch (menuCommand[0])
         {
         case MenuCommand_PushBack:
            printEnterData(std::cout);
            std::cin >> data;
            stack.pushBack(data);
            printCommandDone(std::cout);
            break;
         case MenuCommand_PopBack:
            stack.popBack();
            printCommandDone(std::cout);
            break;
         case MenuCommand_Print:
            stack.print(std::cout);
            break;
         case MenuCommand_Empty:
            stack.printEmpty(std::cout);
            break;
         case MenuCommand_Exit:
            exitMenu(std::cout, done);
            break;
         case MenuCommand_Help:
            printHelpSection(std::cout);
            break;
         default:
            printIncorrectCommandInfo(std::cout, menuCommand);
            correctCommand = false;
            break;
         }
      } while (correctCommand && !done);
   } while (!done);
   
   return 0;
}
