cbuffer cbPerObject : register(b0)
{
	// constant buff
	float4x4 gWorldViewProj;
};

// first example
//void VS(float3 iPosL:POSITION float4 iColor : COLOR, out float4 oPosH : SV_POSITION, out float4 oColor : COLOR)
//{
//	// Transform to homogeneous clip space
//	oPosH = mul(float4(iPosL, 1.f), gWorldViewProj);
//
//	// Just pass vertex color into the pixel shader
//	oColor = iColor;
//}

//float4 PS(float4 posH:SV_POSITION, float4 color : COLOR) :SV_Target
//{
//	return color;
//}



// second example
struct VertexIn
{
	float3 PosL:POSITION;
	float4 Color:COLOR;
};


struct VertexOut
{
	float4 PosH:SV_POSITION;
	float4 Color:COLOR;
};

VertexOut VS(VertexIn vin)
{
	VertexOut vout;

	// Transform to homogeneous clip space
	vout.PosH = mul(float4 (vin.PosL, 1.f), gWorldViewProj);

	// Just pass vertex color into the pixel shader
	vout.Color = vin.Color;

	return vout;
}

float4 PS(VertexOut pin) :SV_Target
{
	return pin.Color;
}