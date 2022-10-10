#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"
using namespace std;

int main()
{
	//OrderedArray<int> array(4);
	//UnorderedArray<int> array(455);
	OrderedArray<int> arr(7);
	arr.GetSize();
	arr.push(4);
	arr.push(23);
	arr.push(93);
	arr.push(45);
	arr.push(17);
	arr.push(15);
	arr.push(32);
	arr.push(96);
	arr.push(111);
	arr.search(45);
	arr.remove(7);

	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}