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

////////////////////////////////////////////////////////////////////////////////
// Includes

#define _USE_MATH_DEFINES
#include <math.h>

#include "jkmath.h"


////////////////////////////////////////////////////////////////////////////////
// Prototypes


int jkmath_test( void );


////////////////////////////////////////////////////////////////////////////////

int jkmath_test( void )
{
  int testOk = 1;

  // JKVector3
  {
    JKVector3 v1 = { 1, 2, 3 };
    JKVector3 v2 = { 4, 5, 6 };
    JKVector3 v3;
    int     b;
    GLfloat farr[3];   

    // jkvector3_add
    jkvector3_add( &v1, &v2, &v3 );
    testOk = (v3.x == 5 && v3.y == 7 && v3.z == 9) && testOk;

    // jkvector3_sub
    jkvector3_sub( &v1, &v2, &v3 ); 
    testOk = (v3.x == -3 && v3.y == -3 && v3.z == -3) && testOk;

    // jkvector3_muls
    jkvector3_muls( &v1, 2, &v3 );
    testOk = (v3.x == 2 && v3.y == 4 && v3.z == 6) && testOk;

    // jkvector_divs
    set(v1, 3, 6, 9);
    v3 = v1 / 3;
    testOk = (v3.x_ == 1 && v3.y_ == 2 && v3.z_ == 3) && testOk;

    // operator* (friend operator);
    Set(v1, 1, 2, 3); 
    v3 = 2 * v1;
    testOk = (v3.x_ == 2 && v3.y_ == 4 && v3.z_ == 6) && testOk;
    
    // operator==
    Set(v1, 1, 2, 3);
    Set(v2, 1, 2, 3);
    Set(v3, 1, 1, 3);
    testOk = (v1 == v2) && !(v1 == v3) && testOk;

    // operator!=
    Set(v1, 1, 2, 3);
    Set(v2, 1, 2, 3);
    Set(v3, 1, 1, 3);
    testOk == !(v1 != v2) && (v1 != v3) && testOk;

    // JKVector3& Set(JKVector3& v, float x, float y, float z);
    // Tested above.
    
    // JKVector3& Set(JKVector3& v, const float* pV);
    farr[0] = 5; farr[1] = 6; farr[2] = 7;
    Set(v1, farr);
    testOk = (v1.x_ == 5 && v1.y_ == 6 && v1.z_ == 7) && testOk;

    // Normalize
    Set(v1, 100, 100, 100);
    Normalize(v1);
    testOk = (abs(Length(v1) - 1) < 0.00005) && ((v1.x_ == v1.y_) && (v1.x_ == v1.z_)) && testOk;
    Set(v1, 0, 50, 0);
    Normalize(v1);
    testOk = (abs(Length(v1) - 1) < 0.00001) && (abs(v1.y_ - 1) < 0.00001) && (v1.x_ == 0) && (v1.z_ == 0) && testOk;

    //JKVector3& Add(JKVector3& res, const JKVector3& v1, const JKVector3& v2);
    Set(v1, 1, 2, 3);
    Set(v2, 5, 6, 7);
    Add(v3, v1, v2);
    testOk = (v3.x_ == 6 && v3.y_ == 8 && v3.z_ == 10) && testOk;

    //JKVector3& Sub(JKVector3& res, const JKVector3& v1, const JKVector3& v2);
    Set(v1, 5, 6, 7);
    Set(v2, 1, 2, 3);
    Sub(v3, v1, v2);
    testOk = (v3.x_ == 4 && v3.y_ == 4 && v3.z_ == 4) && testOk;

    //JKVector3& Mul(JKVector3& res, float x, const JKVector3& v);
    Set(v1, 1, 2, 3);
    Mul(v3, 5, v1);
    testOk = (v3.x_ == 5 && v3.y_ == 10 && v3.z_ == 15) && testOk;

    //float Length(const JKVector3& v);
    Set(v1, 3, 4, 0);
    Set(v2, 0, 3, 4);
    Set(v3, 0, 0, 0);
    testOk = (Length(v1) == 5) && (Length(v2) == 5) && (Length(v3) == 0) && testOk;

    //float SqrLength(const JKVector3& v);
    Set(v1, 1, 1, 1);
    Set(v2, 1, 2, 3);
    Set(v3, 0, 0, 0);
    testOk = (SqrLength(v1) == 3) && (SqrLength(v2) == 14) && (SqrLength(v3) == 0) && testOk;

    // Dot()
    Set(v1, 1, 0, 0);
    Set(v2, 0, 1, 2);
    Set(v3, 1, 2, 3);
    testOk = (Dot(v1, v2) == 0) && (Dot(v1,v3) == 1) && (Dot(v2, v3) == 8) & testOk;

    //JKVector3& Cross(JKVector3& res, const JKVector3& v1, const JKVector3& v2);
    Set(v1, 1, 2, 3);
    Set(v2, 2, -2, 3);
    Cross(v3, v1, v2);
    testOk = (v3.x_ == 12 && v3.y_ == 3 && v3.z_ == -6) && testOk;
  }
  
  // Matrix4
  {
    float farr[16];
    farr[0] = 1;  farr[1] = 2;  farr[2] = 3;   farr[3] = 4;
    farr[4] = -1; farr[5] = 2;  farr[6] = 3;   farr[7] = 4;
    farr[8] = 4;  farr[9] = 3;  farr[10] = 2;  farr[11] = 1;
    farr[12] = 4; farr[13] = 3; farr[14] = -2; farr[15] = 1;
    
    // Matrix4(const float* m);
    Matrix4 m1(farr);
    testOk = m1.e11_ == 1  && m1.e12_ == 2 && m1.e13_ == 3  && m1.e14_ == 4 &&
             m1.e21_ == -1 && m1.e22_ == 2 && m1.e23_ == 3  && m1.e24_ == 4 &&
             m1.e31_ == 4  && m1.e32_ == 3 && m1.e33_ == 2  && m1.e34_ == 1 &&
             m1.e41_ == 4  && m1.e42_ == 3 && m1.e43_ == -2 && m1.e44_ == 1 && testOk;

    // Matrix4(const Matrix4& m);
    Matrix4 m2(m1);
    testOk = (m1 == m2) && testOk;

    // Matrix4(float e11, float e12, float e13, float e14, ...
    Matrix4 m3(farr[0],  farr[1],  farr[2],  farr[3],
               farr[4],  farr[5],  farr[6],  farr[7],
               farr[8],  farr[9],  farr[10], farr[11],
               farr[12], farr[13], farr[14], farr[15]);
    testOk = (m1 == m3) && testOk;

    // operator float*();
    {
      float* fp = m1;
      Matrix4 m(fp);
      testOk = (m1 == m) && testOk;
    }

    // operator const float*() const;
    {
      const float* fp = m1;
      Matrix4 m(fp);
      testOk = (m1 == m) && testOk;
    }

    // Modify m2 for upcoming tests
    m2.e11_ = 2;
    m2.e14_ = 5;
    m2.e24_ = 5;
    m2.e34_ = -1;
    m2.e42_ = 4;
    m2.e43_ = 2;
    m2.e44_ = -1;

    // Matrix4& operator*=(const Matrix4& rhs);
    {
      Matrix4 m(m1);
      m *= m2;  // m = m * m1
      testOk = m.e11_ == 28 && m.e12_ == 31 && m.e13_ == 23 && m.e14_ == 8  &&
               m.e21_ == 24 && m.e22_ == 27 && m.e23_ == 17 && m.e24_ == -2 &&
               m.e31_ == 17 && m.e32_ == 24 && m.e33_ == 27 && m.e34_ == 32 &&
               m.e41_ == 1  && m.e42_ == 12 && m.e43_ == 19 && m.e44_ == 36 && testOk;
    }

    // Matrix4& operator+=(const Matrix4& rhs);
    {
      Matrix4 m(m2);
      m += m1;  // m = m + m1
      testOk = m.e11_ == 3 &&  m.e12_ == 4 && m.e13_ == 6 && m.e14_ == 9 &&
               m.e21_ == -2 && m.e22_ == 4 && m.e23_ == 6 && m.e24_ == 9 &&
               m.e31_ == 8  && m.e32_ == 6 && m.e33_ == 4 && m.e34_ == 0 &&
               m.e41_ == 8  && m.e42_ == 7 && m.e43_ == 0 && m.e44_ == 0 && testOk;
    }

    // Matrix4& operator-=(const Matrix4& rhs);
    {
      Matrix4 m(m2);
      m -= m1;  // m = m - m1
      testOk = m.e11_ == 1 && m.e12_ == 0 && m.e13_ == 0 && m.e14_ == 1  &&
               m.e21_ == 0 && m.e22_ == 0 && m.e23_ == 0 && m.e24_ == 1  &&
               m.e31_ == 0 && m.e32_ == 0 && m.e33_ == 0 && m.e34_ == -2 &&
               m.e41_ == 0 && m.e42_ == 1 && m.e43_ == 4 && m.e44_ == -2 && testOk;
    }
  
    //TODO

    // Matrix4& operator*=(float rhs);
    {
      Matrix4 m(m1);
      m *= 2;
      testOk = m.e11_ == m1.e11_ * 2 && m.e12_ == m1.e12_ * 2 && m.e13_ == m1.e13_ * 2 && m.e14_ == m1.e14_ * 2 &&
               m.e21_ == m1.e21_ * 2 && m.e22_ == m1.e22_ * 2 && m.e23_ == m1.e23_ * 2 && m.e24_ == m1.e24_ * 2 &&
               m.e31_ == m1.e31_ * 2 && m.e32_ == m1.e32_ * 2 && m.e33_ == m1.e33_ * 2 && m.e34_ == m1.e34_ * 2 &&
               m.e41_ == m1.e41_ * 2 && m.e42_ == m1.e42_ * 2 && m.e43_ == m1.e43_ * 2 && m.e44_ == m1.e44_ * 2 && testOk;
    }

    // Matrix4& operator/=(float rhs);
    {
      Matrix4 m(m1);
      m /= 2;
      testOk = m.e11_ == m1.e11_ / 2 && m.e12_ == m1.e12_ / 2 && m.e13_ == m1.e13_ / 2 && m.e14_ == m1.e14_ / 2 &&
               m.e21_ == m1.e21_ / 2 && m.e22_ == m1.e22_ / 2 && m.e23_ == m1.e23_ / 2 && m.e24_ == m1.e24_ / 2 &&
               m.e31_ == m1.e31_ / 2 && m.e32_ == m1.e32_ / 2 && m.e33_ == m1.e33_ / 2 && m.e34_ == m1.e34_ / 2 &&
               m.e41_ == m1.e41_ / 2 && m.e42_ == m1.e42_ / 2 && m.e43_ == m1.e43_ / 2 && m.e44_ == m1.e44_ / 2 && testOk;
    }

    // Matrix4 operator+() const;
    {
      Matrix4 m(+m1);
      testOk = (m == m1) && testOk;
    }

    // Matrix4 operator-() const; 
    {
      Matrix4 m(-m1);
      testOk = m.e11_ == -m1.e11_ && m.e12_ == -m1.e12_ && m.e13_ == -m1.e13_ && m.e14_ == -m1.e14_ &&
               m.e21_ == -m1.e21_ && m.e22_ == -m1.e22_ && m.e23_ == -m1.e23_ && m.e24_ == -m1.e24_ &&
               m.e31_ == -m1.e31_ && m.e32_ == -m1.e32_ && m.e33_ == -m1.e33_ && m.e34_ == -m1.e34_ &&
               m.e41_ == -m1.e41_ && m.e42_ == -m1.e42_ && m.e43_ == -m1.e43_ && m.e44_ == -m1.e44_ && testOk;
    }

    // Matrix4 operator*(const Matrix4& rhs) const;
    {
      Matrix4 m(m1 * m2);
      testOk = m.e11_ == 28 && m.e12_ == 31 && m.e13_ == 23 && m.e14_ ==  8 &&
               m.e21_ == 24 && m.e22_ == 27 && m.e23_ == 17 && m.e24_ == -2 &&
               m.e31_ == 17 && m.e32_ == 24 && m.e33_ == 27 && m.e34_ == 32 &&
               m.e41_ == 1  && m.e42_ == 12 && m.e43_ == 19 && m.e44_ == 36 && testOk;
    }

    // Matrix4 operator+(const Matrix4& rhs) const;
    {
      Matrix4 m(m1 + m2);
      testOk = m.e11_ == 3  && m.e12_ == 4 && m.e13_ == 6 && m.e14_ == 9 &&
               m.e21_ == -2 && m.e22_ == 4 && m.e23_ == 6 && m.e24_ == 9 &&
               m.e31_ == 8  && m.e32_ == 6 && m.e33_ == 4 && m.e34_ == 0 &&
               m.e41_ == 8  && m.e42_ == 7 && m.e43_ == 0 && m.e44_ == 0 && testOk;
    }

    // Matrix4 operator-(const Matrix4& rhs) const;
    {
      Matrix4 m(m1 - m2);
      testOk = m.e11_ == -1 && m.e12_ == 0  && m.e13_ == 0  && m.e14_ == -1 &&
               m.e21_ == 0  && m.e22_ == 0  && m.e23_ == 0  && m.e24_ == -1 &&
               m.e31_ == 0  && m.e32_ == 0  && m.e33_ == 0  && m.e34_ == 2  &&
               m.e41_ == 0  && m.e42_ == -1 && m.e43_ == -4 && m.e44_ == 2  && testOk;
    }

    // Matrix4 operator*(float rhs) const;
    {
      Matrix4 m(m1 * 2);
      testOk = m.e11_ == 2  && m.e12_ == 4 && m.e13_ == 6  && m.e14_ == 8 &&
               m.e21_ == -2 && m.e22_ == 4 && m.e23_ == 6  && m.e24_ == 8 &&
               m.e31_ == 8  && m.e32_ == 6 && m.e33_ == 4  && m.e34_ == 2  &&
               m.e41_ == 8  && m.e42_ == 6 && m.e43_ == -4 && m.e44_ == 2  && testOk;
    }

    // Matrix4 operator/(float rhs) const;
    {
      Matrix4 m(m1 / 2);
      testOk = m.e11_ == 0.5f  && m.e12_ == 1.0f && m.e13_ == 1.5f  && m.e14_ == 2.0f &&
               m.e21_ == -0.5f && m.e22_ == 1.0f && m.e23_ == 1.5f  && m.e24_ == 2.0f &&
               m.e31_ == 2.0f  && m.e32_ == 1.5f && m.e33_ == 1.0f  && m.e34_ == 0.5f &&
               m.e41_ == 2.0f  && m.e42_ == 1.5f && m.e43_ == -1.0f && m.e44_ == 0.5f && testOk;
    }

    // friend inline Matrix4 operator*(float lhs, const Matrix4& rhs);
    {
      Matrix4 m(2 * m1);
      //TODO
      testOk = m.e11_ == 2  && m.e12_ == 4 && m.e13_ == 6  && m.e14_ == 8 &&
               m.e21_ == -2 && m.e22_ == 4 && m.e23_ == 6  && m.e24_ == 8 &&
               m.e31_ == 8  && m.e32_ == 6 && m.e33_ == 4  && m.e34_ == 2  &&
               m.e41_ == 8  && m.e42_ == 6 && m.e43_ == -4 && m.e44_ == 2  && testOk;
    }

    // bool operator==(const Matrix4& rhs) const;
    {
      Matrix4 m(m1);
      testOk = (m == m1) && testOk;
      m.e23_ += 1;
      testOk = !(m == m1) && testOk;
    }

    // bool operator!=(const Matrix4& rhs) const;
    {
      Matrix4 m(m1);
      testOk = !(m != m1) && testOk;
      m.e23_ += 1;
      testOk = (m != m1) && testOk;
    }

    //Matrix4& Set(Matrix4& m, const float* pM);
    {
      float   farr[16];
      Matrix4 m;
      int     i;
      for (i = 0; i < 16; ++i) farr[i] = (float)i;
      Set(m, farr);
      testOk = m.e11_ == 0  && m.e12_ == 1 &&  m.e13_ == 2  && m.e14_ == 3  &&
               m.e21_ == 4  && m.e22_ == 5 &&  m.e23_ == 6  && m.e24_ == 7  &&
               m.e31_ == 8  && m.e32_ == 9 &&  m.e33_ == 10 && m.e34_ == 11 &&
               m.e41_ == 12 && m.e42_ == 13 && m.e43_ == 14 && m.e44_ == 15 && testOk;
    }

    //Matrix4& Add(Matrix4& res, const Matrix4& m1, const Matrix4& m2);
    {
      Matrix4 m;
      Add(m, m1, m2);
      testOk = (m.e11_ == m1.e11_ + m2.e11_) &&
               (m.e12_ == m1.e12_ + m2.e12_) &&
               (m.e13_ == m1.e13_ + m2.e13_) &&
               (m.e14_ == m1.e14_ + m2.e14_) &&
               (m.e21_ == m1.e21_ + m2.e21_) &&
               (m.e22_ == m1.e22_ + m2.e22_) &&
               (m.e23_ == m1.e23_ + m2.e23_) &&
               (m.e24_ == m1.e24_ + m2.e24_) &&
               (m.e31_ == m1.e31_ + m2.e31_) &&
               (m.e32_ == m1.e32_ + m2.e32_) &&
               (m.e33_ == m1.e33_ + m2.e33_) &&
               (m.e34_ == m1.e34_ + m2.e34_) &&
               (m.e41_ == m1.e41_ + m2.e41_) &&
               (m.e42_ == m1.e42_ + m2.e42_) &&
               (m.e43_ == m1.e43_ + m2.e43_) &&
               (m.e44_ == m1.e44_ + m2.e44_) && testOk;
    }

    //Matrix4& Sub(Matrix4& res, const Matrix4& m1, const Matrix4& m2);
    {
      Matrix4 m;
      Sub(m, m1, m2);
      testOk = (m.e11_ == m1.e11_ - m2.e11_) &&
               (m.e12_ == m1.e12_ - m2.e12_) &&
               (m.e13_ == m1.e13_ - m2.e13_) &&
               (m.e14_ == m1.e14_ - m2.e14_) &&
               (m.e21_ == m1.e21_ - m2.e21_) &&
               (m.e22_ == m1.e22_ - m2.e22_) &&
               (m.e23_ == m1.e23_ - m2.e23_) &&
               (m.e24_ == m1.e24_ - m2.e24_) &&
               (m.e31_ == m1.e31_ - m2.e31_) &&
               (m.e32_ == m1.e32_ - m2.e32_) &&
               (m.e33_ == m1.e33_ - m2.e33_) &&
               (m.e34_ == m1.e34_ - m2.e34_) &&
               (m.e41_ == m1.e41_ - m2.e41_) &&
               (m.e42_ == m1.e42_ - m2.e42_) &&
               (m.e43_ == m1.e43_ - m2.e43_) &&
               (m.e44_ == m1.e44_ - m2.e44_) && testOk;
    }

    //Matrix4& Mul(Matrix4& res, const Matrix4& m1, const Matrix4& m2);
    {
      Matrix4 m;
      Mul(m, m1, m2);
      testOk = m.e11_ == 28 && m.e12_ == 31 && m.e13_ == 23 && m.e14_ == 8  &&
               m.e21_ == 24 && m.e22_ == 27 && m.e23_ == 17 && m.e24_ == -2 &&
               m.e31_ == 17 && m.e32_ == 24 && m.e33_ == 27 && m.e34_ == 32 &&
               m.e41_ == 1  && m.e42_ == 12 && m.e43_ == 19 && m.e44_ == 36 && testOk;
    }

    //JKVector3& Transform(JKVector3& res, const Matrix4& m, const JKVector3& v);
    {
      JKVector3 v(1, 2, 3);
      JKVector3 u;
      Transform(u, m1, v);
      testOk = (Length(u - JKVector3(3.6f, 3.2f, 3.4f)) < 0.00005) && testOk;
    }

    //Matrix4& SetIdentity(Matrix4& m);
    {
      Matrix4 m;
      SetIdentity(m);
      testOk = m.e11_ == 1 && m.e12_ == 0 && m.e13_ == 0 && m.e14_ == 0 &&
               m.e21_ == 0 && m.e22_ == 1 && m.e23_ == 0 && m.e24_ == 0 &&
               m.e31_ == 0 && m.e32_ == 0 && m.e33_ == 1 && m.e34_ == 0 &&
               m.e41_ == 0 && m.e42_ == 0 && m.e43_ == 0 && m.e44_ == 1 && testOk;
    }

    //Matrix4& SetTranslation(Matrix4& m, const JKVector3& v);
    //Matrix4& SetTranslation(Matrix4& m, float x, float y, float z);
    {
      Matrix4 m;
      JKVector3 v(1, 2, 3);
      JKVector3 u1;
      JKVector3 u2;
      SetTranslation(m, JKVector3(1, 2, 3));
      Transform(u1, m, v);
      SetTranslation(m, 1, 2, 3);
      Transform(u2, m, v);
      testOk = (u1 == JKVector3(2, 4, 6)) && (u2 == JKVector3(2, 4, 6)) && testOk;
    }
    
    //Matrix4& SetRotationX(Matrix4& m, float angle);
    {
      Matrix4 m;
      JKVector3 v(2, 1, 1);
      JKVector3 u;
      SetRotationX(m, (float)M_PI_2);
      Transform(u, m, v);
      testOk = (Length(u - JKVector3(2, -1, 1)) < 0.00005) && testOk;
    }

    //Matrix4& SetRotationY(Matrix4& m, float angle);
    {
      Matrix4 m;
      JKVector3 v(1, 2, 1);
      JKVector3 u;
      SetRotationY(m, (float)M_PI_2);
      Transform(u, m, v);
      testOk = (Length(u - JKVector3(1, 2, -1)) < 0.00005) && testOk;
    }

    //Matrix4& SetRotationZ(Matrix4& m, float angle);
    {
      Matrix4 m;
      JKVector3 v(1, 1, 2);
      JKVector3 u;
      SetRotationZ(m, (float)M_PI_2);
      Transform(u, m, v);
      testOk = (Length(u - JKVector3(-1, 1, 2)) < 0.00005) && testOk;
    }
  }

  return testOk;
}
