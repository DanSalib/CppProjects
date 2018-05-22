#include <stdio.h>
#include <stdlib.h>


int* make_array() {
	int* array = malloc(sizeof(int) * 2);
	array[0] = 24;
	array[1] = 25;
	return array;
}

void fill_array(int* array) {
	array[0] = 24;
	array[1] = 25;
}

void other_func() {
	int other[2];
	other[0] = 0xa7a;
	other[1] = 0xa7a;
}


typedef struct MyClass {
	int num;
	double num2;
} MyClass;

MyClass* MyClass_create() {
	MyClass* c = malloc(sizeof(MyClass));
	c->num = 3;
	c->num2 = 3.2;
	return c;
}

MyClass_delete(MyClass* c) {
	free(c);
}

int main(void) {

	
	MyClass* c = MyClass_create();

	int err = 3;
	if (err != 0) {
		MyClass_delete(c);
		return err;
	}

    printf("Hello world!\n");
}
