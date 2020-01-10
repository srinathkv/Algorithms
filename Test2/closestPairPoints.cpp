#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point
{
public:
	int x;
	int y;
};

int compareX(const void* a, const void* b)
{
	Point* p1 = (Point*)a, * p2 = (Point*)b;
	return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
	Point* p1 = (Point*)a, * p2 = (Point*)b;
	return (p1->y - p2->y);
}

float distance(Point p, Point q)
{
	return (float)sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

float bruteForce(Point* a, int size)
{
	float min = FLT_MAX;

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			float  d = distance(a[i], a[j]);
			if ( d < min)
			{
				min = d;
			}
		}
	}
	return min;
}

float closestPair(Point* a, int size)
{
	return bruteForce(a, size);
}

int main()
{
	Point a[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };

	qsort(a, 6,sizeof(Point), compareX);

	cout << " Min : " << bruteForce(a, sizeof(a) / sizeof(a[0]));
	return 0;
}