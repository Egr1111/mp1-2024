#include "Rac.h";

void main(){
	Rac<int> t1, t2, s1, s2, s3, s4;
	t1.get(1, 2);
	t2.get(1, 3);
	s2.get(1, 4);
	t1.plus(t2);
	s1 = t1;
	t1.minus(s2);
	s2 = t1;
	t1.umn(t2);
	s3 = t1;
	t1.del(t2);
	s4 = t1;

	Rac<int> l[4] = {s1, s2, s3, s4};
	for (int i = 0; i < 4; i++)
	{
		Rac<int>().printRac(l[i]);
	}

};