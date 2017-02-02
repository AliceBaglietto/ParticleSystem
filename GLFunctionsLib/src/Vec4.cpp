/** @file Vec4.cpp
 * @brief This is a library for the Vec4 OpenGL function
 * @author Jon Macey
 * @version 1.0
 */

#include "Vec4.h"
#include "Mat4.h"
#include <cmath>
#include <cassert>

/**
 * @brief Vec4::colourGL
 * @author Jon Macey
 */
void Vec4::colourGL() const
{
  glColor4fv(m_openGL);
}

/**
 * @brief Vec4::cross
 * @author Jon Macey
 * @param _rhs
 * @return
 */
Vec4 Vec4::cross(const Vec4 &_rhs) const
{
   return Vec4(m_y * _rhs.m_z - m_z * _rhs.m_y,
               m_z * _rhs.m_x - m_x * _rhs.m_z,
               m_x * _rhs.m_y - m_y * _rhs.m_x,
               m_w);
}

/**
 * @brief Vec4::dot
 * @author Jon Macey
 * @param _rhs
 * @return
 */
float Vec4::dot(const Vec4 &_rhs) const
{
   return m_x *_rhs.m_x + m_y*_rhs.m_y + m_z*_rhs.m_z;
}

/**
 * @brief Vec4::length
 * @author Jon Macey
 * @return
 */
float Vec4::length() const
{
  return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

/**
 * @brief Vec4::lengthSquared
 * @author Jon Macey
 * @return
 */
float Vec4::lengthSquared() const
{
  return m_x*m_x + m_y*m_y + m_z*m_z;
}

/**
 * @brief Vec4::normalGL
 * @author Jon Macey
 */
void Vec4::normalGL() const
{
  glNormal3f(m_x, m_y, m_z);
}

/**
 * @brief Vec4::normalize
 * @author Jon Macey
 */
void Vec4::normalize()
{
  float l = length();
  assert(l != 0.0f);
  m_x /= l;
  m_y /= l;
  m_z /= l;
}

/**
 * @brief Vec4::operator *
 * @author Jon Macey
 * @param _r
 * @return
 */
Vec4 Vec4::operator * (const Mat4 &_r) const
{
  #warning "implement this"
}

/**
 * @brief Vec4::operator *
 * @author Jon Macey
 * @param _rhs
 * @return
 */
Vec4 Vec4::operator * (GLfloat _rhs) const
{
  return Vec4( m_x * _rhs, m_y * _rhs, m_z * _rhs, m_w);
}

/**
 * @brief Vec4::operator *=
 * @author Jon Macey
 * @param _rhs
 */
void Vec4::operator *= (GLfloat _rhs)
{
  m_x *= _rhs;
  m_y *= _rhs;
  m_z *= _rhs;
}

/**
 * @brief Vec4::operator +
 * @author Jon Macey
 * @param _rhs
 * @return
 */
Vec4 Vec4::operator + (const Vec4 &_rhs) const
{
  return Vec4(m_x + _rhs.m_x, m_y + _rhs.m_y, m_z + _rhs.m_z, m_w);
}

/**
 * @brief Vec4::operator +=
 * @author Jon Macey
 * @param _rhs
 */
void Vec4::operator += (const Vec4 &_rhs)
{
  #warning "implement this"
}

/**
 * @brief Vec4::operator -
 * @author Jon Macey
 * @param _rhs
 * @return
 */
Vec4 Vec4::operator - (const Vec4 &_rhs) const
{
  return Vec4(m_x - _rhs.m_x, m_y - _rhs.m_y, m_z - _rhs.m_z, m_w );
}

//Vec4 Vec4::operator -= (const Vec4 &_rhs)
//{

//}

/**
 * @brief Vec4::operator ==
 * @author Jon Macey
 * @param _rhs
 * @return
 */
bool Vec4::operator == (const Vec4 &_rhs) const
{

}

// float x = v1[0]
// v1[0] = 0.2f
GLfloat & Vec4::operator [] (int _i)
{
  assert(_i >= 0 && _i <= 3);
  return m_openGL[_i];
}

/**
 * @brief Vec4::set
 * @author Jon Macey
 * @param _x
 * @param _y
 * @param _z
 * @param _w
 */
void Vec4::set(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w)
{
  m_x = _x;
  m_y = _y;
  m_z = _z;
  m_w = _w;
}

/**
 * @brief Vec4::vertexGL
 * @author Jon Macey
 */
void Vec4::vertexGL() const
{
  glVertex3f(m_x, m_y, m_z);
}
