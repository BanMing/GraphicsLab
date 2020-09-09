#pragma once
#include<Windows.h> // for XMVerifyCPUSupport
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;


//ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v);
void vectorTest();
void vectorMethodTest();
void vectorNumbericalTest();