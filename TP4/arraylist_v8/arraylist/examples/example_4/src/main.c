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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"

int main(void) {
        startTesting(1); //al_newArrayList
        startTesting(2); //al_add
        startTesting(3); //al_delete
        startTesting(4); //al_len
        startTesting(5); //al_get
        startTesting(6); //al_contains
        startTesting(7); // al_set
        startTesting(8); //al_remove
        //startTesting(9);
        startTesting(10); //al_clone
        startTesting(11); //al_push     ERROR
        startTesting(12); //al_index of
        startTesting(13); // al is empty
        startTesting(14); //al pop      ERROR
        startTesting(15); //al subList  ERROR
        startTesting(16); // al conteinsAll
        //startTesting(17);

    return 0;
}





