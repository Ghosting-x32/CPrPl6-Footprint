#ifndef EASYX_PNG_H
#define EASYX_PNG_H

#include <graphics.h>
#include <windows.h>
#include<iostream>

#pragma comment(lib, "MSIMG32.LIB")

/**
 * @brief EasyX PNG透明贴图功能扩展
 * @namespace EasyXPNG
 */
namespace EasyXPNG {

    /**
     * @brief 使用AlphaBlend实现PNG透明贴图（支持Alpha通道）
     * @param dstImg 目标IMAGE对象指针，nullptr表示默认窗口
     * @param x 贴图位置的X坐标
     * @param y 贴图位置的Y坐标
     * @param srcImg 源IMAGE对象指针
     * @return 操作成功返回true，否则返回false
     */
    inline bool TransparentImage(IMAGE* dstImg, int x, int y, IMAGE* srcImg)
    {
        // 检查参数有效性
        if (srcImg == nullptr || srcImg->getwidth() == 0 || srcImg->getheight() == 0) {
            return false;
        }

        HDC dstDC = (dstImg == nullptr) ? GetImageHDC() : GetImageHDC(dstImg);
        HDC srcDC = GetImageHDC(srcImg);

        int width = srcImg->getwidth();
        int height = srcImg->getheight();

        // 设置混合函数参数
        BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

        // 使用AlphaBlend函数实现透明贴图
        BOOL result = AlphaBlend(
            dstDC, x, y, width, height,
            srcDC, 0, 0, width, height,
            bf
        );
        //std::cout << "1111\n";

        return result != FALSE;
    }

    /**
     * @brief 重载版本：使用默认窗口作为目标
     * @param x 贴图位置的X坐标
     * @param y 贴图位置的Y坐标
     * @param srcImg 源IMAGE对象指针
     * @return 操作成功返回true，否则返回false
     */
    inline bool TransparentImage(int x, int y, IMAGE* srcImg)
    {
       // std::cout << "2222\n";
        return TransparentImage(nullptr, x, y, srcImg);
    }

    /**
     * @brief 使用TransparentBlt实现指定颜色透明的贴图
     * @param dstImg 目标IMAGE对象指针，nullptr表示默认窗口
     * @param x 贴图位置的X坐标
     * @param y 贴图位置的Y坐标
     * @param srcImg 源IMAGE对象指针
     * @param transparentColor 指定透明颜色的COLORREF值
     * @return 操作成功返回true，否则返回false
     */
    inline bool TransparentImage(IMAGE* dstImg, int x, int y, IMAGE* srcImg, COLORREF transparentColor)
    {
        // 检查参数有效性
        if (srcImg == nullptr || srcImg->getwidth() == 0 || srcImg->getheight() == 0) {
            return false;
        }

        HDC dstDC = (dstImg == nullptr) ? GetImageHDC() : GetImageHDC(dstImg);
        HDC srcDC = GetImageHDC(srcImg);

        int width = srcImg->getwidth();
        int height = srcImg->getheight();

        // 使用TransparentBlt函数实现指定颜色透明
        BOOL result = TransparentBlt(
            dstDC, x, y, width, height,
            srcDC, 0, 0, width, height,
            transparentColor
        );

        //std::cout << "3333\n";

        return result != FALSE;
    }

} // namespace EasyXPNG

#endif // EASYX_PNG_H