/**
**    Hatchit Engine
**    Copyright(c) 2015 Third-Degree
**
**    GNU Lesser General Public License
**    This file may be used under the terms of the GNU Lesser
**    General Public License version 3 as published by the Free
**    Software Foundation and appearing in the file LICENSE.LGPLv3 included
**    in the packaging of this file. Please review the following information
**    to ensure the GNU Lesser General Public License requirements
**    will be met: https://www.gnu.org/licenses/lgpl.html
**
**/

#include <ht_glshader.h>
#include <ht_debug.h>

namespace Hatchit {

    namespace Graphics {

        namespace OpenGL {

            GLShader::GLShader()
            {

            }

            GLShader::~GLShader()
            {
                delete[] m_blob;
            }

            void GLShader::printShaderLog()
            {
                GLint logLength = 0;
                GLsizei charsWritten = 0;
                glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &logLength);

                if (logLength > 0)
                {
                    std::vector<GLchar> log(logLength);

                    glGetShaderInfoLog(m_shader, logLength, &charsWritten, &log[0]);

                    Core::DebugPrintF(&log[0]);

                    glDeleteShader(m_shader);
                }
            }

            void GLShader::compileGL(GLenum shaderType)
            {
                m_shader = glCreateShader(shaderType);

                GLchar* string = (GLchar*)0;
                size_t sourceSize = strlen(string);

                glShaderSource(m_shader, 1, (const GLchar**)&string, (GLint*)&sourceSize);

                glCompileShader(m_shader);

#ifdef _DEBUG
                printShaderLog();
#endif
            }

        }	
    }
}
