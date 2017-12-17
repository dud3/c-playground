#include "Vector2D.h"
#include <stdio.h>
#include <map>
#include <string>

int main(void)
{
	Vector2D v1(1, 1);
	Vector2D v2(2, 2);
	v1 += v2;	
	
	Vector2D v3 = v1 + v2;

	printf("%f\n", v1.length());
	printf("%f\n", v3.length());

	v1 += v2;
	printf("%f\n", v1.length());
	
	v1 += v2;
	printf("%f\n", v1.length());

    std::map<int,bool> m_activeKeys;
    
	// m_activeKeys.push_back(std::make_pair(new int(1), new bool(true)));
	
	m_activeKeys[1] = true;
	m_activeKeys[2] = false;
	
	printf("%d \n", (m_activeKeys[0]));
	printf("%d \n", (m_activeKeys[1]));
	printf("%d \n", (m_activeKeys[2]));
	
	enum button {
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};
	
	printf("%d\n", LEFT);
	printf("%d\n", MIDDLE);
	printf("%d\n", RIGHT);
	
	Vector2D* vec;
	vec->setX(600);

	return 0;
}
