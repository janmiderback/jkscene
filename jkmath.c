/*
Copyright (c) 2010 Jan Miderbaeck and Karim Benchemsi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


//TODO:
// Needsa lot:
// - Cross products
// - Dot product
// - Matrix operations
// - etc, etc, etc...


////////////////////////////////////////////////////////////////////////////////
// Includes

#include <assert.h>
#include "jkmath.h"


////////////////////////////////////////////////////////////////////////////////

JKVector3* jkvector3_add( const JKVector3 *pV1,
                          const JKVector3 *pV2,
                          JKVector3       *pRes )
{
    pRes->x = pV1->x + pV2->x;
    pRes->y = pV1->y + pV2->y;
    pRes->z = pV1->z + pV2->z;
    return pRes;
}

JKVector3* jkvector3_sub( const JKVector3 *pV1,
                          const JKVector3 *pV2,
                          JKVector3       *pRes )
{
    pRes->x = pV1->x - pV2->x;
    pRes->y = pV1->y - pV2->y;
    pRes->z = pV1->z - pV2->z;
    return pRes;
}

JKVector3* jkvector3_adds( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes )
{
    pRes->x = pV->x + s;
    pRes->y = pV->y + s;
    pRes->z = pV->z + s;
    return pRes;
}

JKVector3* jkvector3_subs( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes )
{
    pRes->x = pV->x - s;
    pRes->y = pV->y - s;
    pRes->z = pV->z - s;
    return pRes;
}

JKVector3* jkvector3_muls( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes )
{
    pRes->x = pV->x * s;
    pRes->y = pV->y * s;
    pRes->z = pV->z * s;
    return pRes;
}

JKVector3* jkvector3_divs( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes )
{
    pRes->x = pV->x / s;
    pRes->y = pV->y / s;
    pRes->z = pV->z / s;
    return pRes;
}

JKVector3* jkvector3_cross( const JKVector3 *pV1,
                            const JKVector3 *pV2,
                            JKVector3       *pRes )
{
    if( pV1 != pV2 )
    {
        JKVector3 tmp;
        tmp.x = pV1->y * pV2->z - pV1->z * pV2->y;
        tmp.y = pV1->z * pV2->x - pV1->x * pV2->z;
        tmp.z = pV1->x * pV2->y - pV1->y * pV2->x;
        *pRes = tmp;
    }
    else
    {
        pRes->x = 0;
        pRes->y = 0;
        pRes->z = 0;
    }

    return pRes;
}





#if 0

Vector3& Set(Vector3& v, float x, float y, float z)
{
  v.x_ = x;
  v.y_ = y;
  v.z_ = z;
  return v;
}

////////////////////////////////////////////////////////////////////////////////

Vector3& Set(Vector3& v, const float* pV)
{
  v.x_ = pV[0];
  v.y_ = pV[1];
  v.z_ = pV[2];
  return v;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& Set(Matrix4& m, const float* pM)
{
  m.e11_ = pM[0];  m.e12_ = pM[1];  m.e13_ = pM[2];  m.e14_ = pM[3];
  m.e21_ = pM[4];  m.e22_ = pM[5];  m.e23_ = pM[6];  m.e24_ = pM[7];
  m.e31_ = pM[8];  m.e32_ = pM[9];  m.e33_ = pM[10]; m.e34_ = pM[11];
  m.e41_ = pM[12]; m.e42_ = pM[13]; m.e43_ = pM[14]; m.e44_ = pM[15];
  return m;
}

////////////////////////////////////////////////////////////////////////////////

Vector3& Normalize(Vector3& v)
{
  v /= Length(v);
  return v;
}

////////////////////////////////////////////////////////////////////////////////

Vector3& Add(Vector3& res, const Vector3& v1, const Vector3& v2)
{
  res.x_ = v1.x_ + v2.x_;
  res.y_ = v1.y_ + v2.y_;
  res.z_ = v1.z_ + v2.z_;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& Add(Matrix4& res, const Matrix4& m1, const Matrix4& m2)
{
  res.e11_ = m1.e11_ + m2.e11_;
  res.e12_ = m1.e12_ + m2.e12_;
  res.e13_ = m1.e13_ + m2.e13_;
  res.e14_ = m1.e14_ + m2.e14_;
  res.e21_ = m1.e21_ + m2.e21_;
  res.e22_ = m1.e22_ + m2.e22_;
  res.e23_ = m1.e23_ + m2.e23_;
  res.e24_ = m1.e24_ + m2.e24_;
  res.e31_ = m1.e31_ + m2.e31_;
  res.e32_ = m1.e32_ + m2.e32_;
  res.e33_ = m1.e33_ + m2.e33_;
  res.e34_ = m1.e34_ + m2.e34_;
  res.e41_ = m1.e41_ + m2.e41_;
  res.e42_ = m1.e42_ + m2.e42_;
  res.e43_ = m1.e43_ + m2.e43_;
  res.e44_ = m1.e44_ + m2.e44_;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

Vector3& Sub(Vector3& res, const Vector3& v1, const Vector3& v2)
{
  res.x_ = v1.x_ - v2.x_;
  res.y_ = v1.y_ - v2.y_;
  res.z_ = v1.z_ - v2.z_;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& Sub(Matrix4& res, const Matrix4& m1, const Matrix4& m2)
{
  res.e11_ = m1.e11_ - m2.e11_;
  res.e12_ = m1.e12_ - m2.e12_;
  res.e13_ = m1.e13_ - m2.e13_;
  res.e14_ = m1.e14_ - m2.e14_;
  res.e21_ = m1.e21_ - m2.e21_;
  res.e22_ = m1.e22_ - m2.e22_;
  res.e23_ = m1.e23_ - m2.e23_;
  res.e24_ = m1.e24_ - m2.e24_;
  res.e31_ = m1.e31_ - m2.e31_;
  res.e32_ = m1.e32_ - m2.e32_;
  res.e33_ = m1.e33_ - m2.e33_;
  res.e34_ = m1.e34_ - m2.e34_;
  res.e41_ = m1.e41_ - m2.e41_;
  res.e42_ = m1.e42_ - m2.e42_;
  res.e43_ = m1.e43_ - m2.e43_;
  res.e44_ = m1.e44_ - m2.e44_;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

Vector3& Mul(Vector3& res, float x, const Vector3& v)
{
  res.x_ = x * v.x_;
  res.y_ = x * v.y_;
  res.z_ = x * v.z_;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

//Vector4& Mul(Vector4& res, const Matrix4& m, const Vector4& v)
//{
//
//}

////////////////////////////////////////////////////////////////////////////////

Matrix4& Mul(Matrix4& res, const Matrix4& m1, const Matrix4& m2)
{
  Matrix4 tmp;
  
  tmp.e11_ = m1.e11_ * m2.e11_ + m1.e12_ * m2.e21_ + m1.e13_ * m2.e31_ + m1.e14_ * m2.e41_;
  tmp.e12_ = m1.e11_ * m2.e12_ + m1.e12_ * m2.e22_ + m1.e13_ * m2.e32_ + m1.e14_ * m2.e42_;
  tmp.e13_ = m1.e11_ * m2.e13_ + m1.e12_ * m2.e23_ + m1.e13_ * m2.e33_ + m1.e14_ * m2.e43_;
  tmp.e14_ = m1.e11_ * m2.e14_ + m1.e12_ * m2.e24_ + m1.e13_ * m2.e34_ + m1.e14_ * m2.e44_;
  
  tmp.e21_ = m1.e21_ * m2.e11_ + m1.e22_ * m2.e21_ + m1.e23_ * m2.e31_ + m1.e24_ * m2.e41_;
  tmp.e22_ = m1.e21_ * m2.e12_ + m1.e22_ * m2.e22_ + m1.e23_ * m2.e32_ + m1.e24_ * m2.e42_;
  tmp.e23_ = m1.e21_ * m2.e13_ + m1.e22_ * m2.e23_ + m1.e23_ * m2.e33_ + m1.e24_ * m2.e43_;
  tmp.e24_ = m1.e21_ * m2.e14_ + m1.e22_ * m2.e24_ + m1.e23_ * m2.e34_ + m1.e24_ * m2.e44_;
  
  tmp.e31_ = m1.e31_ * m2.e11_ + m1.e32_ * m2.e21_ + m1.e33_ * m2.e31_ + m1.e34_ * m2.e41_;
  tmp.e32_ = m1.e31_ * m2.e12_ + m1.e32_ * m2.e22_ + m1.e33_ * m2.e32_ + m1.e34_ * m2.e42_;
  tmp.e33_ = m1.e31_ * m2.e13_ + m1.e32_ * m2.e23_ + m1.e33_ * m2.e33_ + m1.e34_ * m2.e43_;
  tmp.e34_ = m1.e31_ * m2.e14_ + m1.e32_ * m2.e24_ + m1.e33_ * m2.e34_ + m1.e34_ * m2.e44_;
  
  tmp.e41_ = m1.e41_ * m2.e11_ + m1.e42_ * m2.e21_ + m1.e43_ * m2.e31_ + m1.e44_ * m2.e41_;
  tmp.e42_ = m1.e41_ * m2.e12_ + m1.e42_ * m2.e22_ + m1.e43_ * m2.e32_ + m1.e44_ * m2.e42_;
  tmp.e43_ = m1.e41_ * m2.e13_ + m1.e42_ * m2.e23_ + m1.e43_ * m2.e33_ + m1.e44_ * m2.e43_;
  tmp.e44_ = m1.e41_ * m2.e14_ + m1.e42_ * m2.e24_ + m1.e43_ * m2.e34_ + m1.e44_ * m2.e44_;

  res = tmp;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

Vector3& Transform(Vector3& res, const Matrix4& m, const Vector3& v)
{
  Vector3 tmp;
  float   w;
  tmp.x_ = m.e11_ * v.x_ + m.e12_ * v.y_ + m.e13_ * v.z_ + m.e14_;
  tmp.y_ = m.e21_ * v.x_ + m.e22_ * v.y_ + m.e23_ * v.z_ + m.e24_;
  tmp.z_ = m.e31_ * v.x_ + m.e32_ * v.y_ + m.e33_ * v.z_ + m.e34_;
  w      = m.e41_ * v.x_ + m.e42_ * v.y_ + m.e43_ * v.z_ + m.e44_;
  // Transform back to w = 1
  tmp.x_ /= w;
  tmp.y_ /= w;
  tmp.z_ /= w;
  res = tmp;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

float Length(const Vector3& v)
{
  return sqrt(v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_);
}

////////////////////////////////////////////////////////////////////////////////

float SqrLength(const Vector3& v)
{
  return v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_;
}

////////////////////////////////////////////////////////////////////////////////

float Dot(const Vector3& v1, const Vector3& v2)
{
  return v1.x_ * v2.x_ + v1.y_ * v2.y_ + v1.z_ * v2.z_;
}

////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////

Matrix4& SetIdentity(Matrix4& m)
{
  m.e11_ = 1; m.e12_ = 0; m.e13_ = 0; m.e14_ = 0;
  m.e21_ = 0; m.e22_ = 1; m.e23_ = 0; m.e24_ = 0;
  m.e31_ = 0; m.e32_ = 0; m.e33_ = 1; m.e34_ = 0;
  m.e41_ = 0; m.e42_ = 0; m.e43_ = 0; m.e44_ = 1;
  return m;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4* Inverse(Matrix4& res, float* pDeterminant, const Matrix4& m)
{
  D3DXMATRIX* pDXres = (D3DXMATRIX*)&res;
  D3DXMATRIX* pDXm   = (D3DXMATRIX*)&m;

  if (D3DXMatrixInverse(pDXres, pDeterminant, pDXm) != NULL) {
    return &res;
  }
  else {
    return NULL;
  }
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& SetTranslation(Matrix4& m, const Vector3& v)
{
  return SetTranslation(m, v.x_, v.y_, v.z_);
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& SetTranslation(Matrix4& m, float x, float y, float z)
{
  m.e11_ = 1; m.e12_ = 0; m.e13_ = 0; m.e14_ = x;
  m.e21_ = 0; m.e22_ = 1; m.e23_ = 0; m.e24_ = y;
  m.e31_ = 0; m.e32_ = 0; m.e33_ = 1; m.e34_ = z;
  m.e41_ = 0; m.e42_ = 0; m.e43_ = 0; m.e44_ = 1;
  return m;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& SetRotationX(Matrix4& m, float angle)
{
  const float cosAngle = cosf(angle);
  const float sinAngle = sinf(angle);

  m.e11_ = 1; m.e12_ = 0;        m.e13_ = 0;         m.e14_ = 0;
  m.e21_ = 0; m.e22_ = cosAngle; m.e23_ = -sinAngle; m.e24_ = 0;
  m.e31_ = 0; m.e32_ = sinAngle; m.e33_ = cosAngle;  m.e34_ = 0;
  m.e41_ = 0; m.e42_ = 0;        m.e43_ = 0;         m.e44_ = 1;
  return m;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& SetRotationY(Matrix4& m, float angle)
{
  const float cosAngle = cosf(angle);
  const float sinAngle = sinf(angle);

  m.e11_ = cosAngle;  m.e12_ = 0; m.e13_ = sinAngle; m.e14_ = 0;
  m.e21_ = 0;         m.e22_ = 1; m.e23_ = 0;        m.e24_ = 0;
  m.e31_ = -sinAngle; m.e32_ = 0; m.e33_ = cosAngle; m.e34_ = 0;
  m.e41_ = 0;         m.e42_ = 0; m.e43_ = 0;        m.e44_ = 1;
  return m;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& SetRotationZ(Matrix4& m, float angle)
{
  const float cosAngle = cosf(angle); 
  const float sinAngle = sinf(angle);

  m.e11_ = cosAngle; m.e12_ = -sinAngle; m.e13_ = 0; m.e14_ = 0;
  m.e21_ = sinAngle; m.e22_ = cosAngle;  m.e23_ = 0; m.e24_ = 0;
  m.e31_ = 0;        m.e32_ = 0;         m.e33_ = 1; m.e34_ = 0;
  m.e41_ = 0;        m.e42_ = 0;         m.e43_ = 0; m.e44_ = 1;
  return m;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& SetLookAt(Matrix4& m, const Vector3& pos, const Vector3& lookAt, const Vector3& up)
{
  D3DXMATRIX*  pDXm      = (D3DXMATRIX*)&m;
  D3DXVECTOR3* pDXpos    = (D3DXVECTOR3*)&pos;
  D3DXVECTOR3* pDXlookAt = (D3DXVECTOR3*)&lookAt;
  D3DXVECTOR3* pDXup     = (D3DXVECTOR3*)&up;
  D3DXMatrixLookAtLH(pDXm, pDXpos, pDXlookAt, pDXup);
  return m;
}

////////////////////////////////////////////////////////////////////////////////

Quaternion& RotMatrixToQuaternion(Quaternion& res, const Matrix4& m)
{
  const float trace = m.e11_ + m.e22_ + m.e33_ + 1;
  float s;

  if (trace > 0.00000001f) {
    // Quick calculation. Test on 0.00000001 avoids division
    // by very small values.
    s = 0.5f / sqrt(trace);
    res.w_ = 0.25f / s;
    res.x_ = (m.e32_ - m.e23_) * s;
    res.y_ = (m.e13_ - m.e31_) * s;
    res.z_ = (m.e21_ - m.e12_) * s;
  }
  else if (m.e11_ > m.e22_ && m.e11_ > m.e33_ ) {
    // m.e11_ largest of the diagonal elements
    s = sqrt(1 + m.e11_ - m.e22_ - m.e33_ ) * 2;
    res.x_ = 0.25f * s;
    res.y_ = (m.e21_ + m.e12_ ) / s;
    res.z_ = (m.e13_ + m.e31_ ) / s;
    res.w_ = (m.e32_ - m.e23_ ) / s;
  }
  else if (m.e22_ > m.e33_) {
    // m.e22_ largest of the diagonal elements
    s = sqrt(1 + m.e22_ - m.e11_ - m.e33_ ) * 2;
    res.x_ = (m.e21_ + m.e12_ ) / s;
    res.y_ = 0.25f * s;
    res.z_ = (m.e32_ + m.e23_ ) / s;
    res.w_ = (m.e13_ - m.e31_ ) / s;
  }
  else {
    // m.e33_ largest of the diagonal elements
    s = sqrt(1 + m.e33_ - m.e11_ - m.e22_ ) * 2;
    res.x_ = (m.e13_ + m.e31_ ) / s;
    res.y_ = (m.e32_ + m.e23_ ) / s;
    res.z_ = 0.25f * s;
    res.w_ = (m.e21_ - m.e12_ ) / s;
  }

  return res;
}

////////////////////////////////////////////////////////////////////////////////

Vector3& RotateX(Vector3& v, float angle)
{
  static Matrix4 m;
  
  SetRotationX(m, angle);
  Transform(v, m, v);
  return v;
}

////////////////////////////////////////////////////////////////////////////////

Quaternion Conjugate(const Quaternion& q)
{
  return Quaternion(-q.x_, -q.y_, -q.z_, q.w_);
}

////////////////////////////////////////////////////////////////////////////////

float Length(const Quaternion& q)
{
  return sqrt((q.w_ * q.w_) + (q.x_ * q.x_) + (q.y_ * q.y_) + (q.z_ * q.z_));
}

////////////////////////////////////////////////////////////////////////////////

float SqrLength(const Quaternion& q)
{
  return (q.w_ * q.w_) + (q.x_ * q.x_) + (q.y_ * q.y_) + (q.z_ * q.z_) ;
}

////////////////////////////////////////////////////////////////////////////////

Quaternion& Normalize(Quaternion& q)
{
  q /= Length(q);
  return q;
}

////////////////////////////////////////////////////////////////////////////////

Quaternion& SetIdentity(Quaternion& q)
{
  q.x_ = 0;
  q.y_ = 0;
  q.z_ = 0;
  q.w_ = 1;
  return q;
}

////////////////////////////////////////////////////////////////////////////////

Matrix4& QuaternionToRotMatrix(Matrix4& res, const Quaternion& q)
{
  const float qx2 = q.x_ * q.x_;
  const float qy2 = q.y_ * q.y_;
  const float qz2 = q.z_ * q.z_;
  const float qw2 = q.w_ * q.w_;
  const float qxqy = q.x_ * q.y_;
  const float qxqz = q.x_ * q.z_;
  const float qxqw = q.x_ * q.w_;
  const float qyqz = q.y_ * q.z_;
  const float qyqw = q.y_ * q.w_;
  const float qzqw = q.z_ * q.w_;

  // Row 1
  res.e11_ = 1 - 2 * (qy2 + qz2);
  res.e12_ = 2 * (qxqy - qzqw); 
  res.e13_ = 2 * (qxqz + qyqw); 
  res.e14_ = 0;
  // Row 2
  res.e21_ = 2 * (qxqy + qzqw);
  res.e22_ = 1 - 2 * (qx2 + qz2);
  res.e23_ = 2 * (qyqz - qxqw);
  res.e24_ = 0;
  // Row 2
  res.e31_ = 2 * (qxqz - qyqw);
  res.e32_ = 2 * (qyqz + qxqw);
  res.e33_ = 1 - 2 * (qx2 + qy2);
  res.e34_ = 0;
  // Row 2
  res.e41_ = 0;
  res.e42_ = 0;
  res.e43_ = 0;
  res.e44_ = 1;

  return res;
}

////////////////////////////////////////////////////////////////////////////////

Quaternion& RotAxisAndAngleToQuaternion(
  Quaternion& res, const Vector3& axis, float angle)
{
  const float sin_a = sinf(angle / 2);
  const float cos_a = cosf(angle / 2);
  Vector3 nAxis(axis);
  
  Normalize(nAxis);
  res.x_ = nAxis.x_ * sin_a;
  res.y_ = nAxis.y_ * sin_a;
  res.z_ = nAxis.z_ * sin_a;
  res.w_ = cos_a;
  return res;
}

////////////////////////////////////////////////////////////////////////////////

Quaternion& EulerAnglesToQuaternion(
  Quaternion& res, float xAngle, float yAngle, float zAngle)
{
  const float sin_x = sinf(xAngle / 2);
  const float cos_x = cosf(xAngle / 2);
  const float sin_y = sinf(yAngle / 2);
  const float cos_y = cosf(yAngle / 2);
  const float sin_z = sinf(zAngle / 2);
  const float cos_z = cosf(zAngle / 2);
  const float cos_x_cos_y = cos_x * cos_y;
  const float sin_x_sin_y = sin_x * sin_y;
  res.x_ = (sin_z * cos_x_cos_y)   - (cos_z * sin_x_sin_y);
  res.y_ = (cos_z * sin_x * cos_y) + (sin_z * cos_x * sin_y);
  res.z_ = (cos_z * cos_x * sin_y) - (sin_z * sin_x * cos_y);
  res.w_ = (cos_z * cos_x_cos_y)   + (sin_z * sin_x_sin_y);
  return res;
}

////////////////////////////////////////////////////////////////////////////////

//Matrix4& QuaternionToRotMatrix(Matrix4& res, const Quaternion& q)
//{
//  const float s = 2 / SqrLength(q);
//  const float qx2 = q.x_ * q.x_;
//  const float qy2 = q.y_ * q.y_;
//  const float qz2 = q.z_ * q.z_;
//  const float qw2 = q.w_ * q.w_;
//  const float qxqy = q.x_ * q.y_;
//  const float qxqz = q.x_ * q.z_;
//  const float qxqw = q.x_ * q.w_;
//  const float qyqz = q.y_ * q.z_;
//  const float qyqw = q.y_ * q.w_;
//  const float qzqw = q.z_ * q.w_;
//
//  // Row 1
//  m.e11_ = 1 - s * (qy2 + qz2);
//  res.e12_ = s * (qxqy - qzqw); 
//  res.e13_ = s * (qxqz + qyqw); 
//  res.e14_ = 0;
//  // Row 2
//  res.e21_ = s * (qxqy + qzqw);
//  res.e22_ = 1 - s * (qx2 + qz2);
//  res.e23_ = s * (qyqz - qxqw);
//  res.e24_ = 0;
//  // Row 2
//  res.e31_ = s * (qxqz - qyqw);
//  res.e32_ = s * (qyqz + qxqw);
//  res.e33_ = 1 - s * (qx2 + qy2);
//  res.e34_ = 0;
//  // Row 2
//  res.e41_ = 0;
//  res.e42_ = 0;
//  res.e43_ = 0;
//  res.e44_ = 1;
//
//  return res;
//}


//void Matrix4::toString(char* s)
//{
//  s
//}

#endif