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

#include <ht_glpipeline.h>

namespace Hatchit
{

    namespace Graphics
    {
        namespace OpenGL
        {
            GLPipeline::GLPipeline()
            {

            }

            GLPipeline::~GLPipeline()
            {

            }

            void GLPipeline::VSetRasterState(const RasterizerState& rasterState)
            {
                m_rasterState = rasterState;            
            }

            void GLPipeline::VSetMultisampleState(const MultisampleState& multiState)
            {
                m_multiState = multiState;   
            }

            void GLPipeline::VLoadShader(ShaderSlot shaderSlot, IShader* shader)
            {

            }

            bool GLPipeline::VSetInt(std::string name, int data)
            {
                return true;
            }

            bool GLPipeline::VSetFloat(std::string name, float data)
            {
                return true;
            }

            bool GLPipeline::VSetFloat3(std::string name, Math::Vector3 data)
            {
                return true;
            }

            bool GLPipeline::VSetFloat4(std::string name, Math::Vector4 data)
            {
                return true;
            }

            bool GLPipeline::VSetMatrix4(std::string name, Math::Matrix4 data)
            {
                return true;
            }

            bool GLPipeline::VPrepare()
            {
                switch(m_rasterState.cullMode)
                {
                case NONE:
                    glDisable(GL_CULL_FACE);
                    break;

                case FRONT:
                    glEnable(GL_CULL_FACE);
                    glCullFace(GL_FRONT);
                    break;
                case BACK:
                    glEnable(GL_CULL_FACE);
                    glCullFace(GL_BACK);
                    break;
                }

                return true;
            }

            bool GLPipeline::VUpdate()
            {
                return true;
            }
        }
    }
}
