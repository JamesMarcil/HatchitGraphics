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
#include <ht_vulkan.h>
#include <ht_renderer.h>
#include <ht_string.h>
#include <vector>

//Totally remove this
#include <fstream>

namespace Hatchit {

    namespace Graphics {

        namespace Vulkan {

            class HT_API VKRenderer : public IRenderer
            {
            public:
                VKRenderer();

                ~VKRenderer();

                /** Initialize the renderer
                * \param params The paramaters to intialize this renderer with
                */
                bool VInitialize(const RendererParams& params);

                ///Shutdown the renderer
                void VDeInitialize();

                /** Resizes the the screen
                * \param width The new width of the screen
                * \param height The new height of the screen
                */
                void VResizeBuffers(uint32_t width, uint32_t height);

                /** Sets the color that the screen will clear with
                * \param color The Color to clear the screen with
                */
                void VSetClearColor(const Color& color);
                /** Clears the screen with the given clear color
                * \param args Arguments to describe which buffer you want to clear
                */
                void VClearBuffer(ClearArgs args);

                ///Present a frame to the screen via a backbuffer
                void VPresent();

            private:
                typedef struct _SwapchainBuffers {
                    VkImage image;
                    VkCommandBuffer command;
                    VkImageView view;
                }SwapchainBuffers;

                struct DepthBuffer {
                    VkFormat format;
                    VkImage image;
                    VkMemoryAllocateInfo memAllocInfo;
                    VkDeviceMemory memory;
                    VkImageView view;
                };

                struct UniformData {
                    VkBuffer buffer;
                    VkMemoryAllocateInfo memAllocInfo;
                    VkDeviceMemory memory;
                    VkDescriptorBufferInfo bufferInfo;
                };

                std::vector<const char*>    m_enabledLayerNames;
                std::vector<const char*>    m_enabledExtensionNames;

                uint32_t m_width;
                uint32_t m_height;

                //Vuklan data structs
                VkApplicationInfo                       m_appInfo;
                VkInstance                              m_instance;
                VkPhysicalDevice                        m_gpu;
                VkPhysicalDeviceProperties              m_gpuProps;
                std::vector<VkQueueFamilyProperties>    m_queueProps;
                VkSurfaceKHR                            m_surface;
                uint32_t                                m_graphicsQueueNodeIndex;
                VkDevice                                m_device; 
                VkQueue                                 m_queue;
                VkFormat                                m_format;
                VkColorSpaceKHR                         m_colorSpace;
                VkPhysicalDeviceMemoryProperties        m_memoryProps;
                
                VkCommandPool                           m_commandPool;
                VkSwapchainKHR                          m_swapchain;
                std::vector<SwapchainBuffers>           m_swapchainBuffers;
                DepthBuffer                             m_depthBuffer;

                //Things that should be loaded from other classes ie textures, meshes, etc.
                VkDescriptorSetLayout                   m_descriptorLayout;
                VkPipelineLayout                        m_pipelineLayout;
                VkPipelineCache                         m_pipelineCache;
                VkRenderPass                            m_renderPass;
                VkDescriptorPool                        m_descriptorPool;
                VkDescriptorSet                         m_descriptorSet;
                uint32_t                                m_currentBuffer;
                VkCommandBuffer                         m_commandBuffer;
                VkPipeline                              m_pipeline;
                std::vector<VkFramebuffer>              m_framebuffers;
                VkSemaphore                             m_presentSemaphore;

                VkClearValue                            m_clearColor;
                VkClearValue                            m_depthStencil;

                //Vulkan Callbacks
                PFN_vkCreateDebugReportCallbackEXT m_createDebugReportCallback;
                PFN_vkDestroyDebugReportCallbackEXT m_destroyDebugReportCallback;
                VkDebugReportCallbackEXT msg_callback;
                PFN_vkDebugReportMessageEXT m_debugReportMessage;

                static VKAPI_ATTR VkBool32 VKAPI_CALL debugFunction(VkFlags msgFlags, VkDebugReportObjectTypeEXT objType,
                    uint64_t srcObject, size_t location, int32_t msgCode,
                    const char *pLayerPrefix, const char *pMsg, void *pUserData);

                //Advanced vulkan feature function pointers
                PFN_vkGetPhysicalDeviceSurfaceSupportKHR
                    fpGetPhysicalDeviceSurfaceSupportKHR;
                PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR
                    fpGetPhysicalDeviceSurfaceCapabilitiesKHR;
                PFN_vkGetPhysicalDeviceSurfaceFormatsKHR
                    fpGetPhysicalDeviceSurfaceFormatsKHR;
                PFN_vkGetPhysicalDeviceSurfacePresentModesKHR
                    fpGetPhysicalDeviceSurfacePresentModesKHR;

                //Function pointers to device functions
                PFN_vkCreateSwapchainKHR
                    fpCreateSwapchainKHR;
                PFN_vkDestroySwapchainKHR
                    fpDestroySwapchainKHR;
                PFN_vkGetSwapchainImagesKHR
                    fpGetSwapchainImagesKHR;
                PFN_vkAcquireNextImageKHR
                    fpAcquireNextImageKHR;
                PFN_vkQueuePresentKHR
                    fpQueuePresentKHR;

                //Core init methods
                bool initVulkan(const RendererParams& params);
                bool initVulkanSwapchain(const RendererParams& params);
                bool prepareVulkan();

                //Helper init methods

                //Helper inits for initVulkan
                bool checkInstanceLayers();
                bool checkInstanceExtensions();
                bool enumeratePhysicalDevices();
                bool checkDeviceLayers();
                bool checkDeviceExtensions();
                bool setupDebugCallbacks();
                bool setupDeviceQueues();
                bool setupProcAddresses();

                //Helper inits for initVulkanSwapchain
                bool setupQueues();
                bool createDevice();
                bool getSupportedFormats();

                //Helpers for prepareVulkan
                bool prepareSwapchainBuffers();
                bool prepareSwapchainDepth();
                bool prepareDescriptorLayout();
                bool prepareRenderPass();
                bool preparePipeline();
                bool prepareDescriptorPool();
                bool prepareDescriptorSet();
                bool prepareFrambuffers();
                bool allocateCommandBuffers();

                //Reused helpers
                bool checkLayers(std::vector<const char*> layerNames, VkLayerProperties* layers, uint32_t layerCount);
                bool setImageLayout(VkImage image, VkImageAspectFlags aspectMask, 
                    VkImageLayout oldImageLayout, VkImageLayout newImageLayout);
                bool memoryTypeFromProperties(uint32_t typeBits, VkFlags requirementsMask, uint32_t* typeIndex);
                bool buildCommandBuffer(VkCommandBuffer commandBuffer);

                //Used for drawing
                void flushCommandBuffer();

                //TOTALLY need to be moved somewhere else
                char* readFile(const char* filename, size_t* pSize);
                VkShaderModule loadShaderSPIRV(const char* fileName);
            };

        }
    }
}