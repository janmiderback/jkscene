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

#ifndef JKMATH_H_
#define JKMATH_H_

#define WIN32_LEAN_AND_MEAN

#include <assert.h>
#include <windows.h>
#include <gl.h>


#define _USE_MATH_DEFINES
#include <math.h>


/**
    3D vector.
 */
typedef struct
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
} JKVector3;


/**
    3D point.
 */
typedef JKVector3 JKPoint3;


JKVector3* jkvector3_add( const JKVector3 *pV1,
                          const JKVector3 *pV2,
                          JKVector3       *pRes );

JKVector3* jkvector3_sub( const JKVector3 *pV1,
                          const JKVector3 *pV2,
                          JKVector3       *pRes );

JKVector3* jkvector3_adds( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes );

JKVector3* jkvector3_subs( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes );

JKVector3* jkvector3_muls( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes );

JKVector3* jkvector3_divs( const JKVector3 *pV,
                           GLfloat          s,
                           JKVector3       *pRes );

#define jkvector3_equals( v1, v2 ) \
    ((v1).x == (v2).x && (v1).y == (v2).y && (v1).z == (v2).z)

#define jkvector3_dot( v1, v2 ) \
    ((v1).x * (v2).x + (v1).y * (v2).y + (v1).z * (v2).z)

JKVector3* jkvector3_cross( const JKVector3 *pV1,
                            const JKVector3 *pV2,
                            JKVector3       *pRes );

#define jkvector3_length( v ) \
    sqrtf( jkvector3_sqrLength( v ) )

#define jkvector3_sqrLength( v ) \
    ( (v).x * (v).x + (v).y * (v).y + (v).z * (v).z )

#define jkvector3_normalize( v ) \
    do { \
        const GLfloat len = jkvector3_length( v ); \
        v.x /= len; \
        v.y /= len; \
        v.z /= len; \
    } while( 0 )


////////////////////////////////////////////////////////////////////////////////

/**
    4D matrix. Column-major.
 */
typedef struct
{
    // First col
    GLfloat m11;
    GLfloat m21;  // Second row, first col
    GLfloat m31;
    GLfloat m41;
    // Second col
    GLfloat m12;
    GLfloat m22;
    GLfloat m32;
    GLfloat m42;
    // Third col
    GLfloat m19;
    GLfloat m23;
    GLfloat m33;
    GLfloat m43;
    // Fourth col
    GLfloat m14;
    GLfloat m24;
    GLfloat m34;
    GLfloat m44;
} JKMatrix4;


JKMatrix4* jkmatrix4_add( const JKMatrix4 *pM1,
                          const JKMatrix4 *pM2,
                          JKMatrix4       *pRes );

JKMatrix4* jkmatrix4_sub( const JKMatrix4 *pM1,
                          const JKMatrix4 *pM2,
                          JKMatrix4       *pRes );
 
JKMatrix4* jkmatrix4_mul( const JKMatrix4 *pM1,
                          const JKMatrix4 *pM2,
                          JKMatrix4       *pRes );

JKMatrix4* jkmatrix4_adds( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );

JKMatrix4* jkmatrix4_subs( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );
 
JKMatrix4* jkmatrix4_muls( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );

JKMatrix4* jkmatrix4_divs( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );

#define jkmatrix4_setIdentity( m ) \
    do { \
        m.m11 = 1; m.m12 = 0; m.m13 = 0; m.m14 = 0; \
        m.m21 = 0; m.m22 = 1; m.m23 = 0; m.m24 = 0; \
        m.m31 = 0; m.m32 = 0; m.m33 = 1; m.m34 = 0; \
        m.m41 = 0; m.m42 = 0; m.m43 = 0; m.m44 = 1; \
    } while( 0 )

JKVector3* jkmatrix4_transform( const JKMatrix4 *pM,
                                const JKVector3 *pV,
                                JKVector3       *pRes );

JKMatrix4* jkmatrix4_inverse( const JKMatrix4 *pM,
                              GLfloat         *pDeterminant,
                              JKMatrix4       *pRes );

JKMatrix4* jkmatrix4_setTranslation( const JKVector3 *pV,
                                     JKMatrix4       *pRes );

JKMatrix4* jkmatrix4_setRotationX( float      angle,
                                   JKMatrix4 *pRes );

JKMatrix4* jkmatrix4_setRotationY( float      angle,
                                   JKMatrix4 *pRes );

JKMatrix4* jkmatrix4_setRotationZ( float      angle,
                                   JKMatrix4 *pRes );

JKMatrix4* jkmatrix4_setLookAt( const JKPoint3  *pPos,
                                const JKPoint3  *pLookAt,
                                const JKVector3 *pUp,
                                JKMatrix4       *pRes );


////////////////////////////////////////////////////////////////////////////////

/**
    3D matrix. Column-major.
 */
typedef struct
{
    // First col
    float m11;
    float m21;  // Second row, first col
    float m31;
    // Second col
    float m12;
    float m22;
    float m32;
    // Third col
    float m13;
    float m23;
    float m33;
} JKMatrix3;


JKMatrix3* jkmatrix3_add( const JKMatrix4 *pM1,
                          const JKMatrix4 *pM2,
                          JKMatrix4       *pRes );

JKMatrix3* jkmatrix3_sub( const JKMatrix4 *pM1,
                          const JKMatrix4 *pM2,
                          JKMatrix4       *pRes );
 
JKMatrix3* jkmatrix3_mul( const JKMatrix4 *pM1,
                          const JKMatrix4 *pM2,
                          JKMatrix4       *pRes );

JKMatrix3* jkmatrix3_adds( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );

JKMatrix3* jkmatrix3_subs( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );
 
JKMatrix3* jkmatrix3_muls( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );

JKMatrix3* jkmatrix3_divs( const JKMatrix4 *pM1,
                           GLfloat          s,
                           JKMatrix4       *pRes );

#define jkmatrix3_setIdentity( m ) \
    do { \
        m.m11 = 1; m.m12 = 0; m.m13 = 0; \
        m.m21 = 0; m.m22 = 1; m.m23 = 0; \
        m.m31 = 0; m.m32 = 0; m.m33 = 1; \
    } while( 0 )

JKVector3* jkmatrix3_transform( const JKMatrix3 *pM,
                                const JKVector3 *pV,
                                JKVector3       *pRes );

JKMatrix3* jkmatrix3_inverse( const JKMatrix3 *pM,
                              GLfloat         *pDeterminant,
                              JKMatrix3       *pRes );

JKMatrix3* jkmatrix3_setRotationX( float      angle,
                                   JKMatrix3 *pRes );

JKMatrix3* jkmatrix3_setRotationY( float      angle,
                                   JKMatrix3 *pRes );

JKMatrix3* jkmatrix3_setRotationZ( float      angle,
                                   JKMatrix3 *pRes );


////////////////////////////////////////////////////////////////////////////////

#if 0

/**
 * Quaternion with scalar part s and vector part (x, y, z).
 */
class Quaternion
{
public:
  float x_;  /**< First vector component.  */  
  float y_;  /**< Second vector component. */  
  float z_;  /**< Third vector component.  */  
  float w_;  /**< Scalar part.             */

  inline Quaternion();
  inline Quaternion(const Quaternion& q);
  inline Quaternion(float x, float y, float z, float s);
  inline Quaternion(const float* q);

  // Casting operators
  inline operator float*();
  inline operator const float*() const;

  // Assignment operators
  inline Quaternion& operator+=(const Quaternion& rhs);
  inline Quaternion& operator-=(const Quaternion& rhs);
  inline Quaternion& operator*=(const Quaternion& rhs);
  inline Quaternion& operator*=(float rhs);
  inline Quaternion& operator/=(float rhs);

  // Unary operators
  inline Quaternion operator+() const;
  inline Quaternion operator-() const;

  // Binary operators
  inline Quaternion operator+(const Quaternion& rhs) const;
  inline Quaternion operator-(const Quaternion& rhs) const;
  inline Quaternion operator*(const Quaternion& rhs) const;
  inline Quaternion operator*(float rhs) const;
  inline Quaternion operator/(float rhs) const;
  inline friend Quaternion operator*(float lhs, const Quaternion& rhs);
  inline bool operator==(const Quaternion&) const;
  inline bool operator!=(const Quaternion&) const;
};

////////////////////////////////////////////////////////////////////////////////

// Vector3 functions
Vector3& Set(Vector3& v, float x, float y, float z);
Vector3& Set(Vector3& v, const float* pV);
Vector3& Add(Vector3& res, const Vector3& v1, const Vector3& v2);
Vector3& Sub(Vector3& res, const Vector3& v1, const Vector3& v2);
Vector3& Mul(Vector3& res, float x, const Vector3& v);


// Matrix4 functions
JKMatrix4* Set(JKMatrix4* m, const float* pM);
JKMatrix4* Add(JKMatrix4* res, const JKMatrix4* m1, const JKMatrix4* m2);
JKMatrix4* Sub(JKMatrix4* res, const JKMatrix4* m1, const JKMatrix4* m2);
JKMatrix4* Mul(JKMatrix4* res, const JKMatrix4* m1, const JKMatrix4* m2);
//Vector4& Mul(Vector4& res, const JKMatrix4* m, const Vector4& v);
Vector3& Transform(Vector3& res, const JKMatrix4* m, const Vector3& v);
Matrix4* Inverse(JKMatrix4* res, float* pDeterminant, const JKMatrix4* m);
JKMatrix4* SetIdentity(JKMatrix4* m);
JKMatrix4* SetTranslation(JKMatrix4* m, const Vector3& v);
JKMatrix4* SetTranslation(JKMatrix4* m, float x, float y, float z);
JKMatrix4* SetRotationX(JKMatrix4* m, float angle);
JKMatrix4* SetRotationY(JKMatrix4* m, float angle);
JKMatrix4* SetRotationZ(JKMatrix4* m, float angle);
JKMatrix4* SetLookAt(JKMatrix4* m, const Vector3& pos, const Vector3& lookAt, const Vector3& up);

// Quaternion functions
Quaternion  Conjugate(const Quaternion& q);
float       Length(const Quaternion& q);
float       SqrLength(const Quaternion& q);
Quaternion& Normalize(Quaternion& q);
Quaternion& SetIdentity(Quaternion& q);
Quaternion& RotMatrixToQuaternion(Quaternion& res, const JKMatrix4* m);
JKMatrix4*    QuaternionToRotMatrix(JKMatrix4* res, const Quaternion& q);

/**
 * Generate an orientation quaternion from a rotation axis and angle.
 */
Quaternion& RotAxisAndAngleToQuaternion(
  Quaternion& res, const Vector3& axis, float angle);

/**
 * Generate a rotation axis and angle from an orientation quaternion.
 */
//void QuaternionToRotAxisAndAngle(
//  Vector3& axis, float& angle, const Quaternion& q);

/**
 * Generate an orientation quaternion from Euler angles.
 */
Quaternion& EulerAnglesToQuaternion(
  Quaternion& res, float xAngle, float yAngle, float zAngle);


////////////////////////////////////////////////////////////////////////////////
//
// Implementation of Matrix4 inline operations
//



#endif //0


#endif //JKMATH_H
