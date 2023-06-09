// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000001.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000001[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x85,0x98,0x8b,0x97,0x8d,0x65,
    0x14,0xc6,0xbf,0x99,0x33,0x73,0x0e,0xe3,0x36,0x32,0x21,0xd1,0x9a,0x31,0x92,0x1a,
    0x0d,0xd5,0xb8,0x3b,0x84,0x72,0x29,0xb7,0x8c,0x89,0xa4,0x98,0x92,0x72,0x8d,0xdc,
    0x2a,0x72,0x99,0xdc,0x32,0x12,0xa5,0x28,0x11,0x91,0x92,0x0c,0x45,0x85,0x5c,0xba,
    0xa1,0x42,0xe5,0x56,0x7f,0x49,0xab,0xcb,0x5a,0x5d,0xde,0xfd,0xcd,0x6f,0xcf,0x7a,
    0x3a,0xcb,0xaa,0x59,0xeb,0x5d,0xdf,0xd9,0xcf,0xde,0xfb,0x79,0x9f,0xbd,0xdf,0xcb,
    0x77,0xce,0x24,0xb2,0x8b,0x53,0x51,0x94,0x15,0xe5,0x45,0xf5,0xa2,0x9f,0xa3,0xda,
    0xbf,0xa6,0x51,0x76,0x40,0xa2,0xa8,0x41,0x94,0x8c,0x9f,0x83,0x86,0x96,0x0f,0x2d,
    0x9d,0x33,0x77,0x52,0x69,0x59,0x97,0xce,0xe6,0x6f,0x1c,0x25,0xe2,0x38,0xf3,0x35,
    0x89,0x52,0x51,0x4e,0x78,0xda,0x98,0x51,0x39,0x65,0xa6,0xe1,0xed,0xc3,0xb8,0x12,
    0x46,0x7e,0x88,0x33,0x3c,0x65,0x1c,0xe1,0x53,0xfb,0x98,0xd3,0x72,0xa2,0x68,0x70,
    0x94,0x1b,0x75,0x64,0xbe,0x62,0x9e,0x8e,0x65,0x81,0xd5,0x13,0x2c,0x1b,0x2c,0x5f,
    0xb0,0x04,0x58,0x81,0x60,0x39,0x60,0x2d,0x05,0xcb,0x05,0x6b,0x2d,0x58,0x12,0xac,
    0x50,0xb0,0x14,0x58,0x3b,0xc1,0xea,0x81,0x75,0x10,0xac,0x3e,0x58,0x47,0xc1,0xf2,
    0xc0,0x3a,0x0b,0xd6,0x00,0xac,0x4c,0xb0,0x86,0x60,0xdd,0x05,0x6b,0x04,0xd6,0x3b,
    0xee,0x53,0xa2,0xae,0x5e,0xeb,0xd9,0xb8,0xf0,0x6c,0x4b,0x7f,0xdc,0x2e,0x12,0xdb,
    0xfa,0x7c,0x03,0x76,0xb3,0x90,0x95,0x1d,0xfb,0x13,0x71,0x6f,0xec,0x73,0xf3,0xf0,
    0x29,0x49,0x9d,0x85,0x21,0x3e,0x45,0x9d,0xc9,0x38,0x2e,0x27,0xae,0x2f,0x09,0x56,
    0x12,0xec,0x24,0x7a,0x5a,0x97,0x0e,0xeb,0x55,0x10,0x18,0x1a,0x0b,0xde,0x2c,0x8c,
    0x51,0x87,0x87,0xf7,0x73,0xdb,0x7a,0x5c,0x51,0x71,0xa5,0x8f,0xdb,0xad,0xc2,0x48,
    0xe7,0xad,0xea,0xeb,0xb6,0xf5,0xbb,0x66,0x50,0x65,0xfa,0xda,0x60,0x17,0xa2,0xc1,
    0xd6,0xb6,0x45,0xb0,0x8b,0xb0,0xb3,0xd1,0xd5,0x16,0x0d,0x45,0xf8,0xdb,0xa1,0x2b,
    0x07,0xff,0x8d,0xe4,0x1a,0xde,0x0b,0xbb,0xbd,0xf0,0xdd,0x44,0xbc,0xf1,0xd9,0x7c,
    0x25,0xf0,0x47,0x71,0x7f,0xf2,0xe3,0x9e,0x16,0x31,0x5c,0x4b,0xc9,0xff,0x8c,0xc2,
    0xba,0x67,0x4e,0x74,0x2b,0xeb,0xde,0x91,0xf9,0xcd,0x2e,0x05,0x2b,0xa1,0xbe,0x4e,
    0xe8,0xb1,0xf8,0xce,0xf8,0x8a,0xc4,0xdf,0x55,0xea,0xe9,0x56,0x97,0x5b,0xeb,0xb7,
    0x67,0x4f,0xf4,0x9a,0xbf,0x0f,0xfd,0x28,0x94,0xfc,0x01,0xec,0x65,0x8f,0x1f,0xc2,
    0x7c,0xee,0x1f,0xce,0xda,0x59,0xfe,0xfd,0xe4,0x5b,0xbf,0xae,0x0b,0x33,0x8d,0xa5,
    0x3f,0x59,0xd1,0xbf,0xff,0xb2,0x64,0xce,0x07,0xf8,0x3c,0x96,0x1a,0xcd,0x1e,0x07,
    0xe6,0x73,0x8c,0xcf,0xb0,0x2b,0x65,0x0d,0x1f,0xa1,0x26,0xd5,0x3c,0x99,0xb3,0xe1,
    0x9a,0x17,0x10,0xef,0xfe,0x45,0xe8,0x72,0x7f,0x15,0xe7,0xda,0xd6,0x74,0x05,0xbe,
    0x84,0xc4,0xaf,0xcd,0xd8,0xab,0x1b,0x45,0x8f,0xd9,0x3b,0x62,0x6b,0xc9,0x00,0xcb,
    0xdf,0x85,0x16,0xef,0xf9,0x3b,0xe4,0xee,0x12,0xbe,0x3d,0x9c,0x71,0xb7,0x0f,0x65,
    0xac,0xe9,0x49,0xce,0xac,0xe5,0x5f,0x46,0xcb,0x2e,0xfa,0x73,0x99,0x7b,0x2e,0x11,
    0xaf,0x6d,0x6e,0x5c,0x57,0x0e,0x7a,0x0c,0xfb,0x2d,0x20,0xb9,0xc4,0xb6,0xe5,0x8c,
    0xa7,0xc4,0x2e,0x13,0xdb,0xd6,0x6b,0x8c,0xd8,0xf6,0x9c,0x9e,0x61,0xcf,0xce,0xb0,
    0xe7,0x8b,0x6d,0xb5,0xed,0x16,0xdb,0xf6,0xcf,0x09,0xec,0x34,0xe7,0xa9,0x03,0x67,
    0x66,0x44,0x40,0xed,0xbc,0xdc,0x0c,0xd6,0x41,0xf6,0xc2,0x4c,0xce,0xe6,0x2d,0xf8,
    0xfb,0x85,0x0a,0x6c,0x2f,0xdf,0xc6,0x7e,0xef,0x04,0x9f,0xc5,0xdc,0x0e,0x5e,0x15,
    0x62,0xcc,0xbe,0x83,0x3c,0xc3,0xfb,0x84,0x0e,0x14,0x83,0x79,0x7c,0x17,0x7a,0x60,
    0xbe,0x32,0x6c,0xe3,0xef,0xc6,0x7d,0x58,0xca,0x19,0x49,0xb3,0x17,0x7a,0x80,0xef,
    0x0d,0x31,0x8d,0xe3,0xba,0x6a,0x31,0x3b,0x27,0xbf,0x06,0x8e,0x34,0xba,0xff,0x08,
    0xf1,0xbd,0xb8,0x3f,0xd3,0xf4,0xbd,0x37,0xdc,0xd6,0x87,0xbe,0xf4,0xba,0x27,0xdc,
    0xb6,0xae,0x77,0x82,0x2f,0xc6,0xee,0x07,0xe6,0x39,0xfd,0x25,0xc7,0xf4,0xf6,0x27,
    0xe6,0xf7,0xc0,0xed,0x73,0xa4,0x45,0xff,0x5d,0xe8,0x1f,0x20,0xfa,0xef,0x06,0x77,
    0xfd,0x03,0xc1,0x5c,0xff,0x60,0xd1,0x3f,0x30,0xbe,0xcf,0xa3,0x18,0x33,0xee,0x41,
    0xa2,0xe5,0x1e,0xb4,0x0c,0x11,0xfd,0xf7,0x82,0xbb,0xfe,0xa1,0x60,0x9e,0x33,0x4c,
    0x72,0x4c,0xff,0x30,0x62,0x4c,0xbf,0xcf,0x31,0x58,0xf4,0x8f,0x40,0xff,0x70,0xd1,
    0x3f,0x12,0xdc,0xf5,0xdf,0x07,0xe6,0xfa,0xcb,0x45,0xbf,0xf9,0x46,0x85,0x51,0x0e,
    0xf7,0x28,0x59,0xf7,0xd1,0x68,0xb1,0x7d,0x67,0x76,0x05,0xd8,0x68,0xb9,0x7f,0x7c,
    0x4f,0x54,0xa0,0xd1,0x79,0xca,0xe1,0xb1,0x3b,0xe9,0x41,0xee,0x23,0xdf,0x93,0x0f,
    0xa1,0x79,0xbc,0xcc,0xf5,0x30,0xb8,0xdb,0x13,0x98,0x7b,0x29,0x7b,0x74,0x22,0x31,
    0x13,0xe0,0xb1,0x3b,0xeb,0x51,0x78,0x2a,0xa5,0xbf,0x93,0xc0,0x27,0x04,0xcd,0x76,
    0x76,0x1e,0x63,0xfe,0x89,0xdc,0x5f,0x93,0xd0,0x3c,0x06,0x9f,0xf7,0xf1,0x71,0xb8,
    0x26,0x4b,0x1f,0x9f,0x00,0xf7,0x3e,0x4e,0x01,0xf3,0x3e,0x4e,0x93,0x3e,0x9a,0x6f,
    0x6a,0x18,0xd3,0xa8,0x7f,0x2a,0xdc,0x76,0x8e,0x67,0x70,0x47,0xf8,0x3e,0x4e,0xc6,
    0xe7,0xb5,0x16,0x37,0x2d,0xd3,0xb1,0x7b,0x84,0x78,0xf3,0x3d,0xc9,0xdd,0x3b,0x5d,
    0x38,0x66,0x09,0x87,0xe5,0xcc,0x22,0xce,0xfd,0x4f,0xe1,0x1f,0x22,0x73,0xcc,0x01,
    0xb7,0xf8,0xd9,0xd8,0x3e,0xc7,0x5c,0xe6,0x98,0x2d,0x1c,0xf3,0x84,0xc3,0x72,0xe6,
    0x11,0xe7,0xfe,0xa7,0xf1,0x2f,0x90,0x39,0x9e,0x01,0xb7,0xf8,0xf9,0xd8,0x3e,0xc7,
    0xb3,0xcc,0x31,0x5f,0x38,0x16,0x0a,0x87,0xe5,0x2c,0x24,0xce,0xf6,0x8e,0xf7,0x6e,
    0x9a,0xac,0xcb,0x73,0xac,0xcb,0x22,0x59,0x97,0xc5,0xe0,0xbe,0x2e,0x4b,0xc0,0x7c,
    0x5d,0x96,0xc9,0xba,0x2c,0x89,0xf7,0x50,0x14,0x55,0xc3,0xbd,0x54,0xb4,0x3c,0x8f,
    0x96,0x2a,0xa9,0x67,0x39,0xb8,0xdf,0xbd,0x2b,0x89,0x19,0x11,0xde,0x36,0xf6,0x5e,
    0x5b,0x05,0xb6,0x52,0xee,0x5e,0xdb,0x57,0xeb,0x02,0xa7,0xf9,0x57,0x13,0xb3,0x5c,
    0x38,0x5e,0xa8,0xe3,0xa8,0x1f,0xdb,0x6b,0xc0,0x56,0xf3,0xde,0xc9,0x95,0xf7,0xa5,
    0xef,0xcd,0x35,0xf4,0x64,0x19,0xba,0xab,0xa5,0x27,0x2f,0xd2,0x93,0xb5,0xd2,0x93,
    0x75,0xe0,0xde,0x93,0x97,0xc0,0xbc,0x27,0x1b,0xa4,0x27,0xe6,0x5b,0x1f,0xc6,0x06,
    0xb8,0xd7,0x4b,0x4f,0x5e,0xbe,0x4a,0x4f,0x5e,0x01,0x3f,0x0a,0xf7,0xab,0x60,0x1b,
    0xd1,0xe8,0x3c,0xf6,0xfc,0x25,0xb0,0x58,0xcc,0x6b,0x68,0xa8,0x26,0x7e,0x3d,0x3a,
    0x36,0x8b,0x0e,0x8b,0xd9,0x14,0xc6,0x66,0xf2,0x37,0x89,0x8e,0xd7,0xaf,0xa2,0xe3,
    0x0d,0x70,0xef,0xeb,0x96,0x8c,0xb5,0x79,0x13,0x6c,0x4b,0xc6,0xda,0x8c,0x0c,0xd9,
    0xe6,0xdf,0x0a,0x87,0x8f,0xd5,0xac,0xd9,0x36,0x72,0xb7,0x0a,0xf7,0x5b,0x19,0x6b,
    0xb6,0x1d,0x6c,0xdb,0x7f,0xac,0xd9,0x76,0xfa,0xe1,0xf5,0x6c,0xce,0x58,0xc3,0x65,
    0xc2,0xff,0x36,0xfc,0xb6,0x6f,0xcc,0xde,0x09,0xb6,0x43,0xf8,0x76,0x4a,0xfc,0xbb,
    0xc4,0xcf,0xe4,0xfb,0xd1,0x7b,0x60,0x16,0xbb,0x1b,0xdb,0xf7,0xc7,0xfb,0xec,0x8f,
    0x3d,0xb2,0x3f,0xf6,0x82,0xfb,0xfe,0xf8,0x00,0xcc,0xf7,0x47,0x8d,0xac,0x8b,0xf9,
    0xf6,0x85,0x71,0x10,0xdd,0xfb,0xe0,0xb1,0x79,0xf7,0xf3,0x7d,0xc5,0xdf,0x09,0x07,
    0xc0,0xf6,0xcb,0xf7,0x27,0x8f,0xfd,0xb0,0x2e,0xb6,0x7e,0x6c,0x7f,0x04,0x76,0x40,
    0x7a,0x98,0x2d,0x3d,0xdc,0x4d,0x8c,0xf5,0xac,0x86,0xb9,0x0f,0x4a,0x5d,0x1f,0x53,
    0xd7,0x21,0xa9,0xeb,0x13,0x70,0xaf,0xeb,0x53,0x30,0xaf,0xeb,0x88,0xd4,0x65,0xbe,
    0xc3,0x61,0x1c,0x87,0xfb,0xb0,0xbc,0x77,0x8f,0xa2,0xb5,0x4a,0xde,0x25,0x9f,0x81,
    0x7b,0xcc,0x31,0x62,0xfc,0x0e,0x3e,0x46,0x8c,0xe9,0x3d,0x02,0xe7,0x71,0x79,0x3f,
    0x7d,0x8e,0xde,0x93,0xc2,0xf9,0x05,0xb8,0xe5,0x9f,0xc0,0x76,0xdf,0x97,0x7c,0xf7,
    0x3b,0x13,0xf2,0xcd,0xfe,0x0a,0xac,0x52,0xea,0xfb,0x1a,0x7c,0x3c,0xf5,0x9d,0x96,
    0xfa,0xcc,0x77,0x2a,0x8c,0xd3,0x68,0x39,0x25,0xda,0xcf,0xa0,0xdd,0xef,0xf6,0x33,
    0x70,0x98,0x76,0x8f,0x3f,0x2d,0x5a,0xbe,0xc9,0xd0,0xf2,0x2d,0x58,0x57,0xd1,0xf2,
    0x1d,0xb8,0x6b,0x39,0x27,0x5a,0xcc,0x77,0x36,0x8c,0x73,0x70,0x9f,0x15,0x2d,0xe7,
    0xd1,0xe2,0xef,0x80,0xf3,0xa2,0xc5,0xe3,0xcf,0x89,0x96,0xef,0x33,0xb4,0xfc,0x00,
    0xb6,0x47,0xb4,0xfc,0x08,0xee,0x5a,0x2e,0x8a,0x16,0xf3,0x5d,0x08,0xe3,0x22,0xdc,
    0x17,0x44,0xcb,0x25,0x59,0x77,0xd3,0x72,0x89,0xef,0xca,0xa6,0xc5,0xe3,0x2f,0x66,
    0xac,0xf1,0x91,0x8c,0x3d,0x5a,0x23,0x7b,0xfe,0x27,0xf8,0x8c,0xeb,0x0a,0xf6,0x9f,
    0xe1,0x26,0xea,0x1e,0x46,0x57,0xde,0x8b,0x79,0x68,0xb3,0xdf,0x2f,0xdd,0x42,0x5c,
    0x8a,0xdf,0x2e,0xc6,0xd5,0x40,0xee,0xbb,0x86,0xe0,0xc7,0xa8,0xb1,0x09,0x58,0x23,
    0x6a,0x6c,0x2a,0x35,0x36,0xe1,0x7f,0x2c,0xcd,0xe1,0xc9,0x17,0x9e,0x6b,0xe0,0x59,
    0xc1,0xfc,0x05,0x60,0xf6,0x7f,0x81,0xbf,0x42,0x6c,0x01,0x39,0xcd,0x25,0xa7,0x05,
    0x39,0x0d,0x83,0xba,0x64,0xfc,0x5b,0xb4,0xf6,0x3e,0x6d,0x85,0xaf,0xa5,0xf0,0x5d,
    0x8f,0xbf,0x55,0xfc,0xee,0xac,0xc5,0xda,0x80,0xb7,0x66,0x8e,0x36,0xcc,0x61,0x9a,
    0xff,0xa6,0x1f,0xff,0x00,0x0d,0xfd,0x1d,0x2a,0xc4,0x12,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform texture2D src;
// layout(location = 0)out ivec4 dst;
//
// layout(push_constant)uniform PushConstants {
//
//     ivec2 srcOffset;
//     ivec2 dstOffset;
//     int srcMip;
//     int srcLayer;
//
//     bool flipX;
//     bool flipY;
//
//     bool premultiplyAlpha;
//     bool unmultiplyAlpha;
//
//     bool dstHasLuminance;
//     bool dstIsAlpha;
//
//     bool srcIsSRGB;
//     bool dstIsSRGB;
//
//     int dstDefaultChannelsMask;
//     bool rotateXY;
// } params;
//
// float linearToSRGB(float linear)
// {
//
//     if(linear <= 0.0031308)
//     {
//         return linear * 12.92;
//     }
//     else
//     {
//         return pow(linear,(1.0f / 2.4f))* 1.055f - 0.055f;
//     }
// }
//
// void main()
// {
//     ivec2 dstSubImageCoords = ivec2(gl_FragCoord . xy)- params . dstOffset;
//
//     ivec2 srcSubImageCoords = dstSubImageCoords;
//
//     if(params . flipX)
//     {
//         srcSubImageCoords . x = - srcSubImageCoords . x;
//     }
//     if(params . flipY)
//     {
//         srcSubImageCoords . y = - srcSubImageCoords . y;
//     }
//     if(params . rotateXY)
//     {
//         srcSubImageCoords . xy = srcSubImageCoords . yx;
//     }
//
//           vec4 srcValue = texelFetch(src, params . srcOffset + srcSubImageCoords, params . srcMip);
//
//     if(params . srcIsSRGB)
//     {
//
//         srcValue . r = linearToSRGB(srcValue . r);
//         srcValue . g = linearToSRGB(srcValue . g);
//         srcValue . b = linearToSRGB(srcValue . b);
//     }
//
//     if(params . premultiplyAlpha)
//     {
//         srcValue . rgb *= srcValue . a;
//     }
//     else if(params . unmultiplyAlpha && srcValue . a > 0)
//     {
//         srcValue . rgb /= srcValue . a;
//     }
//
//     srcValue *= 255.0;
//
//            ivec4 dstValue = ivec4(srcValue);
//
//     if(params . dstHasLuminance)
//     {
//         dstValue . rg = dstValue . ra;
//     }
//     else if(params . dstIsAlpha)
//     {
//         dstValue . r = dstValue . a;
//     }
//     else
//     {
//         int defaultChannelsMask = params . dstDefaultChannelsMask;
//         if((defaultChannelsMask & 2)!= 0)
//         {
//             dstValue . g = 0;
//         }
//         if((defaultChannelsMask & 4)!= 0)
//         {
//             dstValue . b = 0;
//         }
//         if((defaultChannelsMask & 8)!= 0)
//         {
//             dstValue . a = 1;
//         }
//     }
//
//     dst = dstValue;
// }
