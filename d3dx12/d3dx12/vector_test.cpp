
#include "vector_test.h"

/*Overload the "<<" operators so that we can use cout to
output XMVECTOP objects.*/
ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);
	os << "(" << dest.x << "," << dest.y << "," << dest.z << ")";
	return os;
}


void vectorTest()
{
	cout.setf(ios_base::boolalpha);
	//Check support for SSE2 (Pentium4,AMD K8, and above).
	if (!XMVerifyCPUSupport())
	{
		cout << "directx math not supported" << endl;
		return;
	}

	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSplatOne();
	XMVECTOR u = XMVectorSet(1.f, 2.f, 3.f, 0.f);
	XMVECTOR v = XMVectorReplicate(-2.f);
	XMVECTOR w = XMVectorSplatZ(u);

	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;

}

void vectorMethodTest()
{
	cout.setf(ios_base::boolalpha);
	//Check support for SSE2 (Pentium4,AMD K8, and above).
	if (!XMVerifyCPUSupport())
	{
		cout << "directx math not supported" << endl;
		return;
	}

	XMVECTOR n = XMVectorSet(1.f, 0.f, 0.f, 0.f);
	XMVECTOR u = XMVectorSet(1.f, 2.f, 3.f, 0.f);
	XMVECTOR v = XMVectorSet(-1.f, 2.f, -3.f, 0.f);
	XMVECTOR w = XMVectorSet(.707f, .707f, 0.f, 0.f);


	// Vector addition: XMVECTOR operator +
	XMVECTOR  a = u + v;

	// Vector subtraction: XMVECTOR operator -
	XMVECTOR b = u - v;

	// Scaler mutiplication: XMVECTOR operator *
	XMVECTOR c = 10.f*u;

	// ||u||
	XMVECTOR L = XMVector3Length(u);

	// d = u / ||u||
	XMVECTOR d = XMVector3Normalize(u);

	// s = u dot v
	XMVECTOR s = XMVector3Dot(u, v);

	// e = u x e
	XMVECTOR e = XMVector3Cross(u, v);

	// Find proj_n(w) and perp_n(w)
	XMVECTOR projW;
	XMVECTOR perpW;
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	// Does projW + perpW == w?
	bool equal = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// The angle between projW and perpW should be 90 degrees
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;
	cout << "n = " << n << endl;
	cout << "a = u + v = " << a << endl;
	cout << "b = u - v = " << b << endl;
	cout << "c = 10 * u = " << c << endl;
	cout << "d = u / ||u || = " << d << endl;
	cout << "e = u x v = " << e << endl;
	cout << "L = || u || = " << L << endl;
	cout << "s = u.v = " << s << endl;
	cout << "projW = " << projW << endl;
	cout << "perpW = " << perpW << endl;
	cout << "projW + perpW == w = " << equal << endl;
	cout << "projW + perpW != w = " << notEqual << endl;
	cout << "angle = " << angleDegrees << endl;
}

void vectorNumbericalTest()
{
	cout.precision(8);

	// Check support for SSE2 (Pentium4, AMD K8, and above)
	if (!XMVerifyCPUSupport())
	{
		cout << "directx math not supported" << endl;
		return;
	}

	XMVECTOR u = XMVectorSet(1.f, 1.f, 1.f, 0.f);
	XMVECTOR n = XMVector3Normalize(u);

	float LU = XMVectorGetX(XMVector3Length(n));

	// Mathematicall, the length should be 1. Is it numerically?
	cout << LU << endl;
	if (LU==1.f)
	{
		cout << "Length 1" << endl;
	}
	else
	{
		cout << "Length not 1" << endl;
	}

	// Raising 1 to any power should still be 1. Is it?
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;
}