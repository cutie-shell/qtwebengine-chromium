// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000021.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000021[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x85,0x98,0x8b,0x97,0x8e,0x55,
    0x14,0xc6,0xdf,0xf9,0x66,0xe6,0x1b,0xc6,0x6d,0x64,0x42,0xa2,0x35,0x83,0xa4,0x46,
    0x43,0x35,0xee,0x46,0xa1,0x5c,0xca,0x25,0xc6,0x44,0x52,0x9a,0x52,0x4c,0x32,0xc5,
    0x28,0x2a,0xb7,0x48,0x46,0x92,0x50,0x51,0x8a,0x12,0x91,0x89,0x54,0x6e,0xa1,0x28,
    0xb7,0x2e,0xa8,0x5c,0xca,0xad,0xfe,0x8b,0x56,0x97,0xb5,0xba,0x9c,0xfd,0xce,0x6f,
    0xcf,0x7a,0xd6,0xb7,0xac,0x9a,0xb5,0xce,0x7a,0xbf,0xfd,0xec,0x7d,0x9e,0xf3,0xec,
    0xbd,0xcf,0x39,0xef,0xf7,0x4d,0x7a,0xa2,0x4d,0x56,0x14,0xa5,0x45,0xd9,0x51,0x9d,
    0xe8,0x97,0xa8,0xe6,0xaf,0x71,0x94,0x08,0x48,0x14,0xd5,0x8b,0x92,0xf1,0x73,0xc0,
    0xe0,0x92,0xc1,0x85,0x95,0xd3,0xc6,0x17,0x16,0x75,0xee,0x64,0xfe,0x86,0x51,0x7a,
    0x1c,0x67,0xbe,0x46,0x51,0x56,0x94,0x11,0x9e,0x36,0x26,0x97,0x95,0x57,0x18,0xde,
    0x2e,0x8c,0x8b,0x61,0xe4,0x84,0x38,0xc3,0xb3,0x8c,0x23,0x7c,0x6a,0x17,0x73,0xda,
    0x9c,0x28,0x1a,0x18,0x65,0x46,0x1d,0x58,0xaf,0x0d,0x4f,0xc7,0xd2,0xc0,0xea,0x08,
    0x96,0x00,0xcb,0x11,0x2c,0x1d,0x2c,0x57,0xb0,0x0c,0xb0,0xe6,0x82,0x65,0x82,0xb5,
    0x14,0x2c,0x09,0x96,0x27,0x58,0x16,0x58,0x5b,0xc1,0xea,0x80,0xb5,0x17,0xac,0x2e,
    0x58,0x07,0xc1,0xb2,0xc1,0x3a,0x09,0x56,0x0f,0xac,0x48,0xb0,0xfa,0x60,0xdd,0x04,
    0x6b,0x00,0xd6,0x2b,0xae,0x53,0x7a,0x6d,0xbe,0x56,0xb3,0x31,0xe1,0xd9,0x9a,0xfa,
    0xb8,0x9d,0x2f,0xb6,0xd5,0xf9,0x2a,0xec,0x26,0x61,0x56,0x22,0xf6,0xa7,0xc7,0xb5,
    0xb1,0xcf,0x4d,0xc3,0xa7,0x24,0x79,0xe6,0x85,0xf8,0x2c,0xf2,0x4c,0xc6,0x71,0x19,
    0x71,0x7e,0x49,0xb0,0x82,0x60,0x27,0xd1,0xd3,0xb2,0x70,0x48,0xcf,0xdc,0xc0,0xd0,
    0x50,0xf0,0x26,0x61,0x8c,0xd8,0x3d,0xb4,0x8f,0xdb,0x56,0xe3,0xd2,0xd2,0x33,0xbd,
    0xdd,0x6e,0x11,0x46,0x71,0xf6,0xc2,0x9b,0xdd,0xb6,0x7a,0x6f,0x1d,0x50,0x56,0x7c,
    0x79,0xb0,0xf3,0xd0,0x60,0xbd,0x6d,0x16,0xec,0x7c,0xec,0x04,0xba,0x5a,0xa3,0x21,
    0x1f,0x7f,0x5b,0x74,0x65,0xe0,0xbf,0x9a,0xb9,0x86,0xf7,0xc4,0x6e,0x27,0x7c,0xd7,
    0x10,0x6f,0x7c,0xb6,0x5e,0x01,0xfc,0x51,0x5c,0x9f,0x9c,0xb8,0xa6,0xf9,0x0c,0xd7,
    0x52,0xf0,0x3f,0x23,0xaf,0xf6,0x99,0x11,0x5d,0x4f,0xdf,0x3b,0xb0,0xbe,0xd9,0x85,
    0x60,0x05,0xe4,0xd7,0x11,0x3d,0x16,0xdf,0x09,0x5f,0xbe,0xf8,0xbb,0x48,0x3e,0x5d,
    0x6b,0xe7,0xd6,0xf8,0xed,0xd9,0x03,0xbd,0xe6,0xef,0x4d,0x3d,0xf2,0x64,0x7e,0x3f,
    0xf6,0xb2,0xc7,0x0f,0x62,0x3d,0xf7,0x0f,0xa5,0x77,0x36,0xff,0x2e,0xe6,0x5b,0xbd,
    0xae,0x08,0x2b,0x8d,0x96,0xfa,0xe8,0x5f,0x9a,0xac,0x79,0x37,0x9f,0x47,0x93,0xa3,
    0xd9,0x63,0xc0,0x7c,0x8d,0xb1,0x29,0x76,0x19,0xe7,0xd0,0xe6,0x3f,0x40,0x4e,0x79,
    0xf4,0xe4,0x21,0x3e,0xa7,0x4b,0x7c,0x39,0x1a,0xdc,0x9e,0xcc,0xd9,0xf1,0x9c,0x66,
    0xa7,0xf8,0xe7,0xa3,0xdb,0xfd,0x8b,0xe0,0x33,0xfe,0x17,0xf1,0x29,0xff,0x8a,0x94,
    0xbd,0xbc,0x5a,0xf4,0x9a,0xbd,0x29,0xb6,0xe6,0xf4,0xb3,0xf9,0xd5,0xe8,0xf3,0x9e,
    0x7c,0xc0,0xdc,0x6a,0xe1,0xdb,0xc6,0x1d,0xe0,0xf6,0xde,0x94,0x9e,0x1f,0xe1,0x4c,
    0xdb,0xfc,0x0b,0x68,0xa9,0xa6,0x7e,0x17,0xb8,0x07,0xd3,0xe3,0xde,0x67,0xc6,0x79,
    0x65,0xa0,0xc7,0xb0,0xdf,0x03,0x92,0x49,0x6c,0x6b,0xee,0x80,0x2c,0xb1,0x8b,0xc4,
    0xb6,0x7e,0x8e,0x12,0xdb,0x9e,0x95,0x29,0xf6,0x8c,0x14,0x7b,0x96,0xd8,0x96,0xdb,
    0x16,0xb1,0x6d,0x7f,0x1d,0xc6,0x2e,0xe6,0xbc,0xb5,0xe7,0x4c,0x0d,0x0b,0xa8,0x9d,
    0xa7,0x6b,0xc1,0xda,0xcb,0x5e,0xa9,0xe0,0xec,0x5e,0x87,0xbf,0x4f,0xc8,0xc0,0xf6,
    0xfa,0x0d,0x9c,0x87,0x8e,0xf0,0x59,0xcc,0x8d,0xe0,0xf3,0x42,0x8c,0xd9,0x37,0x31,
    0xcf,0xf0,0xde,0xa1,0x02,0x6d,0xc0,0x3c,0xbe,0x33,0x35,0x30,0x5f,0x11,0xb6,0xf1,
    0x77,0xe5,0xbe,0x2c,0xe4,0x0c,0x15,0xb3,0x17,0xba,0x83,0x57,0x87,0x98,0x86,0x71,
    0x5e,0x35,0x98,0x9d,0xa3,0xdf,0x02,0x47,0x31,0xba,0xff,0x0c,0xf1,0x3d,0xb9,0x5f,
    0x8b,0xa9,0x7b,0x2f,0xb8,0xad,0x0e,0x37,0x53,0xeb,0x1e,0x70,0x5b,0x5f,0x6f,0x01,
    0x9f,0x8d,0xdd,0x07,0xcc,0xe7,0xf4,0x95,0x39,0xa6,0xb7,0x2f,0x31,0x7f,0x04,0x6e,
    0x5f,0xa3,0x58,0xf4,0xdf,0x8a,0xfe,0x7e,0xa2,0xff,0x36,0x70,0xd7,0xdf,0x1f,0xcc,
    0xf5,0x0f,0x14,0xfd,0xfd,0xe3,0xfb,0x3e,0x8a,0x31,0xe3,0x1e,0x20,0x5a,0x6e,0x47,
    0xcb,0x20,0xd1,0x7f,0x07,0xb8,0xeb,0x1f,0x0c,0xe6,0x73,0x86,0xc8,0x1c,0xd3,0x3f,
    0x84,0x18,0xd3,0xef,0x6b,0x0c,0x14,0xfd,0xc3,0xd0,0x3f,0x54,0xf4,0xdf,0x09,0xee,
    0xfa,0x87,0x83,0xb9,0xfe,0x12,0xd1,0x6f,0xbe,0x11,0x61,0x94,0xc0,0x3d,0x42,0xfa,
    0x3e,0x12,0x2d,0xb6,0xef,0xcc,0x2e,0x05,0x1b,0x29,0xf7,0x93,0xef,0x89,0x52,0x34,
    0x3a,0x4f,0x09,0x3c,0x76,0x67,0xdd,0xc3,0x7d,0xe5,0x7b,0xf2,0x5e,0x34,0x8f,0x95,
    0xb5,0xee,0x03,0x77,0x7b,0x1c,0x6b,0xcf,0x65,0x8f,0xde,0x4f,0xcc,0x38,0x78,0xec,
    0x4e,0x7b,0x10,0x9e,0x32,0xa9,0xef,0x78,0xf0,0xe1,0x21,0xc6,0xec,0x87,0x99,0x1b,
    0x09,0x36,0x01,0x2c,0x2d,0xae,0x4b,0x32,0xbe,0x0f,0x27,0x12,0x3b,0x01,0x0e,0x5f,
    0xe3,0x11,0xd6,0x28,0x97,0x35,0x26,0x81,0x8f,0x0b,0x75,0xb1,0xf3,0xf9,0x28,0x39,
    0x4e,0xe4,0x8e,0x9c,0x44,0x5d,0x46,0xe1,0xf3,0x5e,0x55,0xc0,0x35,0x59,0x7a,0xf5,
    0x18,0xb8,0xf7,0xea,0x71,0x30,0xef,0xd5,0x54,0xe9,0x95,0xf9,0xa6,0x84,0x31,0x95,
    0x1a,0x4f,0x81,0xdb,0xee,0x8a,0x69,0xdc,0x43,0x7e,0x56,0xec,0x4e,0x7d,0x02,0xdc,
    0xb4,0x54,0x62,0x77,0x0f,0xf1,0xe6,0x7b,0x92,0xfb,0xbd,0x52,0x38,0xa6,0x0b,0x87,
    0xcd,0x99,0x4e,0x9c,0xfb,0x9f,0xc2,0x3f,0x48,0xd6,0x78,0x1a,0xdc,0xe2,0x67,0x60,
    0xfb,0x1a,0xcf,0xb0,0xc6,0x0c,0xe1,0x98,0x29,0x1c,0x36,0x67,0x26,0x71,0xee,0x9f,
    0x83,0x7f,0xb6,0xac,0x31,0x17,0xdc,0xe2,0x67,0x61,0xfb,0x1a,0xcf,0xb2,0xc6,0x2c,
    0xe1,0x98,0x27,0x1c,0x36,0x67,0x1e,0x71,0xb6,0x3f,0xbd,0x76,0x53,0xa5,0x2f,0xcf,
    0xd1,0x97,0xf9,0xd2,0x97,0x05,0xe0,0xde,0x97,0xe7,0xc1,0xbc,0x2f,0x55,0xd2,0x17,
    0xf3,0x2d,0x0c,0x63,0x39,0xdc,0x0b,0x45,0xcb,0x0b,0x68,0x59,0x24,0xf9,0x2c,0x06,
    0xf7,0xfb,0x7d,0x09,0x31,0xc3,0xc2,0x1b,0xcd,0xde,0x9d,0x2f,0x81,0x2d,0x91,0xfb,
    0x3d,0x11,0xe3,0x99,0xb1,0x7f,0x29,0x31,0x8b,0x85,0xe3,0xe5,0x5a,0x8e,0xba,0xb1,
    0xbd,0x0c,0x6c,0x29,0xef,0xb6,0x4c,0x79,0x27,0xfb,0xde,0x5c,0x46,0x4d,0xaa,0xd0,
    0xbd,0x5c,0x6a,0xf2,0x0a,0x35,0x59,0x21,0x35,0x79,0x15,0xdc,0x6b,0xf2,0x1a,0x98,
    0xd7,0x64,0x95,0xd4,0xc4,0x7c,0x2b,0xc3,0x58,0x05,0xf7,0x4a,0xa9,0xc9,0xeb,0x97,
    0xa8,0xc9,0x1b,0xe0,0x7b,0xe0,0x7e,0x13,0x6c,0x35,0x1a,0x9d,0xc7,0x9e,0xbf,0x06,
    0x16,0x8b,0x79,0x0b,0x0d,0xcb,0x89,0x5f,0x89,0x8e,0xb5,0xa2,0xc3,0x62,0xd6,0x84,
    0xb1,0x96,0xf9,0x6b,0x44,0xc7,0xdb,0x97,0xd0,0xf1,0x0e,0xb8,0xd7,0x75,0x5d,0x4a,
    0x6f,0xde,0x05,0x5b,0x97,0xd2,0x1b,0xbb,0x47,0xcc,0xbf,0x1e,0x0e,0x1f,0x55,0xf4,
    0x6c,0x03,0x73,0xd7,0x0b,0xf7,0x7b,0x29,0x3d,0xdb,0x08,0xb6,0xe1,0x3f,0x7a,0xb6,
    0x91,0x7a,0x78,0x3e,0x6b,0x53,0x7a,0x58,0x25,0xfc,0xef,0xc3,0x6f,0xfb,0xc6,0xec,
    0xcd,0x60,0x9b,0x84,0x6f,0xb3,0xc4,0x6f,0x25,0xbe,0x82,0xef,0x60,0x1f,0x82,0x59,
    0xec,0x16,0x6c,0xdf,0x1f,0x1f,0xb1,0x3f,0xb6,0xc9,0xfe,0xf8,0x18,0xdc,0xf7,0xc7,
    0x27,0x60,0xbe,0x3f,0x76,0x48,0x5f,0xcc,0xb7,0x3d,0xee,0x77,0x8d,0xee,0xed,0xf0,
    0xd8,0xba,0x3b,0xf9,0x4e,0xe4,0xef,0x9d,0x5d,0x60,0x3b,0xe5,0x3b,0x9a,0xc7,0xee,
    0xae,0x8d,0xad,0x1b,0xdb,0x9f,0x82,0xed,0x92,0x1a,0x26,0xa4,0x86,0x5b,0x88,0xb1,
    0x9a,0xed,0x60,0xed,0x3d,0x92,0xd7,0x3e,0xf2,0xda,0x2b,0x79,0x7d,0x06,0xee,0x79,
    0x7d,0x0e,0xe6,0x79,0x1d,0x90,0xbc,0xcc,0xb7,0x3f,0x8c,0x43,0x70,0xef,0x97,0x77,
    0xfb,0x17,0x68,0x5d,0x24,0xef,0x92,0x2f,0xc1,0x3d,0xe6,0x20,0x31,0x7e,0x07,0x1f,
    0x24,0xc6,0xf4,0x1e,0x80,0xf3,0x90,0xbc,0x9f,0x8e,0xa2,0xf7,0x88,0x70,0x7e,0x05,
    0x6e,0xf3,0x0f,0x63,0xbb,0xef,0x6b,0xbe,0x5f,0x1e,0xe5,0x5d,0xf8,0x0d,0x58,0xb9,
    0xe4,0xf7,0x2d,0xf8,0x58,0xf2,0x3b,0x2e,0xf9,0x99,0xef,0x58,0x18,0xc7,0xd1,0x72,
    0x4c,0xb4,0x9f,0x40,0xbb,0xdf,0xed,0x27,0xe0,0x30,0xed,0x1e,0x7f,0x5c,0xb4,0x7c,
    0x97,0xa2,0xe5,0x7b,0xb0,0x2e,0xa2,0xe5,0x07,0x70,0xd7,0x72,0x4a,0xb4,0x98,0xef,
    0x64,0x18,0xa7,0xe0,0x3e,0x29,0x5a,0x4e,0xa3,0xc5,0xdf,0x01,0xa7,0x45,0x8b,0xc7,
    0x9f,0x12,0x2d,0x67,0x52,0xb4,0xfc,0x08,0xb6,0x4d,0xb4,0xfc,0x04,0xee,0x5a,0xce,
    0x89,0x16,0xf3,0x9d,0x0d,0xe3,0x1c,0xdc,0x67,0x45,0xcb,0x79,0xe9,0xbb,0x69,0x39,
    0xcf,0xf7,0x71,0xd3,0xe2,0xf1,0xe7,0x52,0x7a,0x7c,0x20,0x65,0x8f,0xee,0x90,0x3d,
    0xff,0x33,0x7c,0xc6,0x75,0x11,0xfb,0xaf,0x70,0x13,0x75,0x0b,0xa3,0x0b,0xef,0xc5,
    0x6c,0xb4,0xd9,0x6f,0xa4,0xae,0x21,0x2e,0x8b,0xdf,0x47,0xc6,0x55,0x4f,0xee,0xbb,
    0xfa,0xe0,0xfb,0xc8,0xb1,0x11,0x58,0x03,0x72,0x6c,0x2c,0x39,0x36,0xe2,0xff,0x3c,
    0x4d,0xe1,0xc9,0x11,0x9e,0xcb,0xe0,0x59,0xc0,0xfa,0xb9,0x60,0xf6,0xbf,0x89,0xbf,
    0x43,0x6c,0x2e,0x73,0x9a,0xca,0x9c,0x66,0xcc,0xa9,0x1f,0xd4,0x25,0xe3,0xdf,0xc3,
    0x35,0xf7,0x69,0x0b,0x7c,0xcd,0x85,0xef,0x4a,0xfc,0x2d,0xe2,0xf7,0x74,0x0d,0xd6,
    0x0a,0xbc,0x25,0x6b,0xb4,0x62,0x0d,0xd3,0xfc,0x0f,0xf5,0xf8,0x17,0x08,0x2e,0x89,
    0x19,0x48,0x13,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform texture3D src;
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
//           vec4 srcValue = texelFetch(src, ivec3(params . srcOffset + srcSubImageCoords, params . srcLayer), params . srcMip);
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
