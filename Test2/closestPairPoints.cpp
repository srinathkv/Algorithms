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

float stripClosest(Point *strip,int  size,float  d)
{
	float min = d;
	qsort(strip, size, sizeof(Point), compareY);

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
		{
			if (distance(strip[i], strip[j]) < min)
			{
				min = distance(strip[i], strip[j]);
			}
		}
	}				
	return min;
}

float closestRec(Point* a, int size)
{
	if (size <= 3)
	{
		return bruteForce(a, size);
	}

	int mid = size / 2;
	Point midP = a[mid];

	float dL = closestRec(a, mid);
	float dR = closestRec(a + mid, size - mid);

	float d = dL < dR ? dL : dR;

	Point *strip = new Point[size];

	int j = 0;
	for (int i = 0; i < size; ++i)
	{
		if (abs(a[i].x - midP.x) < d)
		{
			strip[j].x = a[i].x;
			strip[j].y = a[i].y;
			j++;
		}
	}

	float dS =  stripClosest(strip, j,d);
	return d < dS ? d : dS;

}

float closestPair(Point* a, int size)
{
	qsort(a, size, sizeof(Point), compareX);
	return closestRec(a, size);
}

int main()
{
	Point a[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };

	

	cout << " Min : " << closestPair(a, sizeof(a) / sizeof(a[0]));
	return 0;
}