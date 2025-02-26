#include "Rac.h";

using namespace std;

void main(){
	Rac t1, t2, s1, s2, s3, s4;
	t1.get(1, 2);
	t2.get(1, 3);
	s1 = Rac().plus(t1, t2);
	s2 = Rac().minus(t1, t2);
	s3 = Rac().umn(t1, t2);
	s4 = Rac().del(t1, t2);

	Rac l[4] = {s1, s2, s3, s4};
	for (int i = 0; i < 4; i++)
	{
		Rac().printRac(l[i]);
	}

};