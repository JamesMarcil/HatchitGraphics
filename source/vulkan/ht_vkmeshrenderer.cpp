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

#include <ht_vkmeshrenderer.h>

namespace Hatchit {

    namespace Graphics {

        namespace Vulkan {

            VKMeshRenderer::VKMeshRenderer()
            {
            }

            VKMeshRenderer::~VKMeshRenderer()
            {

            }

            void VKMeshRenderer::VSetRenderPass(IRenderPass* renderPass)
            {
                m_markedRenderPass = (VKRenderPass*)renderPass;
            }

            void VKMeshRenderer::VBuffer()
            {

            }

            void VKMeshRenderer::VRender()
            {

            }

            void VKMeshRenderer::VFree()
            {

            }
        }
    }
}