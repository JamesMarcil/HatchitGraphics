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
* \defgroup HatchitGraphics
*/

/**
* \class IRenderer
* \ingroup HatchitGraphics
*
* \brief An interface to a renderer that will need to be implemented with a graphics language
*
* A manager class that handles rendering objects into render passes and is
* responsible for throwing the final frame onto the screen by utilizing a
* graphics language
*/

#pragma once

#include <ht_platform.h>
#include <ht_color.h>
#include <ht_types.h>
#include <ht_string.h>
#include <ht_renderpass.h>

namespace Hatchit {

    namespace Graphics {

        enum class ClearArgs
        {
            Color,
            Depth,
            Stencil,
            ColorDepth,
            ColorStencil,
            ColorDepthStencil
        };

        enum RendererType
        {
            OPENGL,
            DIRECTX11,
            DIRECTX12,
            VULKAN
        };

        struct RendererParams
        {
            RendererType renderer;
            void*        window;
            uint32_t     viewportWidth;
            uint32_t     viewportHeight;
            void*        display;
            Color        clearColor;
            std::string  applicationName;
        };

        class HT_API IRenderer
        {
        public:
            virtual ~IRenderer() { };
            
            /** Initialize the renderer
            * \param params The paramaters to intialize this renderer with
            */
            virtual bool VInitialize(const RendererParams& params) = 0;
            ///Shutdown the renderer
            virtual void VDeInitialize() = 0;
            /** Resizes the the screen
            * \param width The new width of the screen
            * \param height The new height of the screen
            */
            virtual void VResizeBuffers(uint32_t width, uint32_t height) = 0;

            /** Sets the color that the screen will clear with
            * \param color The Color to clear the screen with
            */
            virtual void VSetClearColor(const Color& color) = 0;
            /** Clears the screen with the given clear color
            * \param args Arguments to describe which buffer you want to clear
            */
            virtual void VClearBuffer(ClearArgs args) = 0;
            
            ///Render all render passes
            virtual void VRender(float dt) = 0;

            ///Present a frame to the screen via a backbuffer
            virtual void VPresent() = 0;

            void AddRenderPass(IRenderPass* renderPass);
            void RemoveRenderPass(uint32_t index);

            uint32_t GetWidth();
            uint32_t GetHeight();

        protected:
            std::vector<IRenderPass*> m_renderPasses;

            uint32_t m_width;
            uint32_t m_height;
        };

    }
}
