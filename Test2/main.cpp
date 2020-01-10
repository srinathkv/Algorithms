#include <iostream>
#include <vector>
using namespace std;

int maxCollection()
{
	int arr[] = { 10,2,5,6,20,45,7,4,3,6,8,6, 9};

	vector<int> countVec;
	int maxMoney = 30;
	int MaxCount = 0;
	for (int i = 0; i < 13; ++i)
	{
		int sum = 0;
		int count = 0;
		for (int j = i; j < 13; ++j)
		{
			if (sum + arr[j] <= maxMoney)
			{
				sum += arr[j];
				count++;
			}
			else
			{				
				break;
			}
		}
		if (count > MaxCount)
		{
			MaxCount = count;
		}
		//countVec.push_back(count);
	}

	cout << "MaxCount = " << MaxCount << endl;
	/*for (int i = 0; i < countVec.size(); ++i)
	{
		cout << countVec[i] << "\t";
	}*/
	return 0;
}

void merge(vector<int> left, vector<int> right, vector<int>& Arr)
{
	int i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			Arr[k] = left[i];
			i++;
			k++;
		}
		else
		{
			Arr[k] = right[j];
			j++;
			k++;
		}
	}
	while (i < left.size())
	{
		Arr[k] = left[i];
		i++;
		k++;
	}

	while (j < right.size())
	{
		Arr[k] = right[j];
		j++;
		k++;
	}
	return;
}

void mergeSort(vector<int>& Arr)
{
	if (Arr.size() < 2)
		return;

	int midPoint = Arr.size() / 2;

	vector<int> leftArr;
	vector<int> rightArr;

	for (int i = 0; i < midPoint; ++i)
	{
		leftArr.push_back(Arr[i]);
	}
	for (int i = midPoint; i < Arr.size(); ++i)
	{
		rightArr.push_back(Arr[i]);
	}
	mergeSort(leftArr);
	mergeSort(rightArr);
	//vector<int> sortedArr;
	merge(leftArr, rightArr, Arr);
}

int main()
{
	vector<int> arr = { 2,6,4,9,3,5,1,8 };

	mergeSort(arr);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << "\t";
	}
	return 0;
}