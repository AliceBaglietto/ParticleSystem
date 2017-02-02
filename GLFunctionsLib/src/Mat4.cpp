/** @file Mat4.cpp
 * @brief This is a library for the Mat4 OpenGL function
 * @author Jon Macey
 * @version 1.0
 */

#include "Mat4.h"
#include "Vec4.h"
#include <cstring>

/**
 * @brief Mat4::Mat4
 * @author Jon Macey
 * @param _s
 */
Mat4::Mat4(GLfloat _s)
{
  memset(&m_m, 0, sizeof(m_m));
  m_00 = _s;
  m_11 = _s;
  m_22 = _s;
  m_33 = _s;
}

/**
 * @brief Mat4::operator *=
 * @author Jon Macey
 * @param _rhs
 */
void Mat4::operator *= (const Mat4 &_rhs)
{

}

/**
 * @brief Mat4::operator *
 * @author Jon Macey
 * @param _rhs
 * @return
 */
Mat4 Mat4::operator * (const Mat4 &_rhs) const
{

}

/**
 * @brief Mat4::identity
 * @author Jon Macey
 */
void Mat4::identity()
{
  m_00 = 1.0f;
  m_11 = 1.0f;
  m_22 = 1.0f;
  m_33 = 1.0f;
}

/**
 * @brief Mat4::loadModelView
 * @author Jon Macey
 */
void Mat4::loadModelView() const
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity(); // set the above matrix as the default
  glMultMatrixf(m_openGL); // load our current matrix into the model matrix
}

/**
 * @brief Mat4::loadProjection
 * @author Jon Macey
 */
void Mat4::loadProjection() const
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMultMatrixf(m_openGL);
  glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief Mat4::transpose
 * @author Jon Macey
 * @return
 */
const Mat4 & Mat4::transpose()
{

}
