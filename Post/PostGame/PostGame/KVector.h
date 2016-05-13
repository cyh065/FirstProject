#pragma once
class KVector
{
public:
	int ix, iy;
	int iw, ih;
public:
	KVector();
	KVector(int x, int y, int w, int h) {
		ix = x;
		iy = y;
		iw = w;
		ih = h;
	};
	virtual ~KVector();
};

