#include <iostream>

class Point
{
protected:
	int x;
	int y;
public:
	Point() 
	{
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		printf("Point(%i, %i)\n", x, y);
		this->x = x;
		this->y = y;
	}
	Point(Point &p)
	{
		printf("Point(Point &p)\n");
		x = p.x;
		y = p.y;
	}
	virtual ~Point()
	{
		printf("~Point(%d, %d)\n", x, y);
	}
	void move(int dx, int dy)
	{
		printf("move(%d, %d)\n", dx, dy);
		x += dx;
		y += dy;
	}
	void reset();
};

void Point::reset() 
{
	printf("reset(%i, %i)\n", x,y);
	x = 0;
	y = 0;
}

class Point3D: public Point
{
protected:
	int z;
public:
	Point3D(): Point()
	{
		printf("Point3D()\n");
		z = 0;
	}
	Point3D(int x, int y, int z): Point(x, y)
	{
		printf("Point3D(%i, %i, %i)\n", x, y, z);
		this->z = z;
	}
	Point3D(Point3D &p):Point(p.x,p.y)
	{
		printf("Point3D(Point3D &p)\n");
		z = p.z;
	}
	~Point3D()
	{
		printf("~Point3D(%d, %d, %d)\n", x, y, z);
	}
	void move3D(int dx, int dy, int dz)
	{
		printf("move3D(%d, %d, %d)\n", dx, dy, dz);
		move(dx, dy);
		z += dz;
	}
	void reset3D() 
	{
		printf("reset3D(%d, %d, %d)\n", x, y, z);
		reset();
		z = 0; 
	}
};

class Segment
{
protected:
	Point *p1;
	Point *p2;
public:
	Segment()
	{
		printf("Segment()\n");
		p1 = new Point;
		p2 = new Point;
	}
	Segment(int x1, int y1, int x2, int y2)
	{
		printf("Segment(%i, %i, %i, %i)\n", x1, y1, x2, y2);
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);
	}
	Segment(Segment &s)
	{
		printf("Segment(Segment &s)\n");
		p1 = new Point(*(s.p1));
		p2 = new Point(*(s.p2));
	}
	~Segment()
	{
		printf("~Segment()\n");
		delete p1;
		delete p2;
	}
	void reset() 
	{
		printf("reset()\n");
		p1->reset();
		p2->reset();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	{
		printf("янгдюмхе ярюрхвеяйху назейрнб:\n");
		Point p0;
		Point p1(5, 6);
		Point p2(p1);
		p2.move(2, 1);
		Point p3(22, 22);
		p3.reset();
	}
	{
		printf("\nянгдюмхе дхмюлхвеяйху назейрнб:\n");
		Point *p0 = new Point();
		Point *p1 = new Point(7, 8);
		Point *p2 = new Point(*p1);
		p2->move(2, 1);
		Point *p3 = new Point3D(7, 7, 7);
		delete p0;
		delete p1;
		delete p2;
		delete p3;
	}
	{
		printf("\nянгдюмхе рнвей б опнярпюмяре:\n");
		Point3D p0;
		Point3D p1(1, 2, 3);
		Point3D p2(p1);
		p1.reset3D();
		p0.move3D(2, 1, 0);
	}
	{
		printf("\nянгдюмхе нрпегйю мю окняйнярх:\n");
		Segment s0;
		Segment s1(0, 0, 1, 1);
		Segment s2(s1);
		s1.reset();
	}

	printf("йнмеж.\n");
}
