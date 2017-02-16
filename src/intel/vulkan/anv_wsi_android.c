/*
 * Copyright © 2017 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */


#include <libsync.h>
#include <util/hash_table.h>
#include "vk_format_info.h"
#include "anv_private.h"

/* libhardware/include/hardware/gralloc.h */
enum {
   GRALLOC_USAGE_HW_TEXTURE = 0x00000100,
   GRALLOC_USAGE_HW_RENDER = 0x00000200,
   GRALLOC_USAGE_HW_FB = 0x00001000,
};

VkResult
anv_GetSwapchainGrallocUsageANDROID(VkDevice device,
                                    VkFormat format,
                                    VkImageUsageFlags imageUsage,
                                    int* grallocUsage)
{
  /* TODO - set grallocUsage from imageUsage flags (is src, dst?) */
  *grallocUsage =
      GRALLOC_USAGE_HW_FB | GRALLOC_USAGE_HW_RENDER | GRALLOC_USAGE_HW_TEXTURE;
  return VK_SUCCESS;
}

VkResult
anv_AcquireImageANDROID(VkDevice device,
                        VkImage image,
                        int nativeFenceFd,
                        VkSemaphore semaphore,
                        VkFence fence)
{
   sync_wait(nativeFenceFd, -1);
   close(nativeFenceFd);
   return VK_SUCCESS;
}

VkResult
anv_QueueSignalReleaseImageANDROID(VkQueue queue,
                                   VkImage image,
                                   int* pNativeFenceFd)
{
   *pNativeFenceFd = -1;
   return VK_SUCCESS;
}

