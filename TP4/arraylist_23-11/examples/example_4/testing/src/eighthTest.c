/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <utest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//INCLUDE LIBRARY TO TEST
#include "../../inc/ArrayList.h"
#include "../../inc/Employee.h"

//DEFINES OF THIS TEST
#define LENGTH 5


static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};


void eighthTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void eighthTestCase01(void)
{
    printf("----R1----\n");
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    for(i=LENGTH-1; i >=0 ; i--)
    {
        r = list->remove(list,i);
        utest_assertEqualsIntMsg(r,0,"Error in return value <remove> if ok the correct value to return is 0");
    }

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


void eighthTestCase02(void)
{  printf("----R2----\n");
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    for(i=LENGTH-1; i >=0 ; i--)
    {
        r = list->remove(list,0);
        utest_assertEqualsIntMsg(r,0,"Error in return value <remove(list,0)> if ok the correct value to return is 0");
    }
    utest_assertEqualsIntMsg(list->size,0,"Error in the size of the array, after remove all the elements the correct value is 0");

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


void eighthTestCase03(void)
{
      printf("----R3----\n");
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();


    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }


    r = list->set(list,9);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <remove> if the index is invalid the correct value to return is -1");

    free(list);

}

void eighthTestCase04(void)
{
      printf("----R4----\n");
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];



    list = al_newArrayList();


    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    r = list->remove(NULL,0);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <remove> if the pointer to array is NULL the correct value to return is -1");

    free(list);

}
