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

/**
* \class GLMaterial
* \ingroup HatchitGraphics
*
* \brief A material to draw objects with; implemented in OpenGL
*
* This is an extension of IMaterial and extends its methods 
* with ones that will utilize OpenGL calls
*/

#pragma once

#include <ht_material.h>
#include <ht_glvertexshader.h>
#include <ht_glfragmentshader.h>
#include <ht_glgeoshader.h>
#include <ht_gltessshader.h>

namespace Hatchit {

	namespace Graphics {

        namespace OpenGL {

            class HT_API GLMaterial : public IMaterial
            {
            public:
                GLMaterial();
                virtual ~GLMaterial();

 
            private:
                GLuint shaderProgram;
                std::map <std::string, ShaderVariable*> variables;
                std::map <std::string, GLuint> variableLocations;

                void printProgramLog();
                void reflectShaderGL();
            };
        }
	}
}
