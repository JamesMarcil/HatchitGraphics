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

#pragma once

#include <ht_platform.h>
#include <ht_pipeline.h>

namespace Hatchit
{
    namespace Graphics
    {
        namespace OpenGL
        {

            class GLPipeline : public IPipeline
            {
            public:
                GLPipeline();


                ~GLPipeline();


                void VSetRasterState(const RasterizerState& rasterState);
                void VSetMultisampleState(const MultisampleState& multiState);
                void VLoadShader(ShaderSlot shaderSlot, IShader* shader);
                
                bool VSetInt(std::string name, int data);
                bool VSetFloat(std::string name, float data);
                bool VSetFloat3(std::string name, Math::Vector3 data);
                bool VSetFloat4(std::string name, Math::Vector4 data);
                bool VSetMatrix4(std::string name, Math::Matrix4 data);

                bool VPrepare();

                bool VUpdate();
            private:
                RasterizerState     m_rasterState;
                MultisampleState    m_multiState;        
            };

        }
    }
}

