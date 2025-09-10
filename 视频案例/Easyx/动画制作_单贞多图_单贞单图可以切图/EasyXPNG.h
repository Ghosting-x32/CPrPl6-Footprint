#ifndef EASYX_PNG_H
#define EASYX_PNG_H

#include <graphics.h>
#include <windows.h>
#include<iostream>

#pragma comment(lib, "MSIMG32.LIB")

/**
 * @brief EasyX PNG͸����ͼ������չ
 * @namespace EasyXPNG
 */
namespace EasyXPNG {

    /**
     * @brief ʹ��AlphaBlendʵ��PNG͸����ͼ��֧��Alphaͨ����
     * @param dstImg Ŀ��IMAGE����ָ�룬nullptr��ʾĬ�ϴ���
     * @param x ��ͼλ�õ�X����
     * @param y ��ͼλ�õ�Y����
     * @param srcImg ԴIMAGE����ָ��
     * @return �����ɹ�����true�����򷵻�false
     */
    inline bool TransparentImage(IMAGE* dstImg, int x, int y, IMAGE* srcImg)
    {
        // ��������Ч��
        if (srcImg == nullptr || srcImg->getwidth() == 0 || srcImg->getheight() == 0) {
            return false;
        }

        HDC dstDC = (dstImg == nullptr) ? GetImageHDC() : GetImageHDC(dstImg);
        HDC srcDC = GetImageHDC(srcImg);

        int width = srcImg->getwidth();
        int height = srcImg->getheight();

        // ���û�Ϻ�������
        BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

        // ʹ��AlphaBlend����ʵ��͸����ͼ
        BOOL result = AlphaBlend(
            dstDC, x, y, width, height,
            srcDC, 0, 0, width, height,
            bf
        );
        //std::cout << "1111\n";

        return result != FALSE;
    }

    /**
     * @brief ���ذ汾��ʹ��Ĭ�ϴ�����ΪĿ��
     * @param x ��ͼλ�õ�X����
     * @param y ��ͼλ�õ�Y����
     * @param srcImg ԴIMAGE����ָ��
     * @return �����ɹ�����true�����򷵻�false
     */
    inline bool TransparentImage(int x, int y, IMAGE* srcImg)
    {
       // std::cout << "2222\n";
        return TransparentImage(nullptr, x, y, srcImg);
    }

    /**
     * @brief ʹ��TransparentBltʵ��ָ����ɫ͸������ͼ
     * @param dstImg Ŀ��IMAGE����ָ�룬nullptr��ʾĬ�ϴ���
     * @param x ��ͼλ�õ�X����
     * @param y ��ͼλ�õ�Y����
     * @param srcImg ԴIMAGE����ָ��
     * @param transparentColor ָ��͸����ɫ��COLORREFֵ
     * @return �����ɹ�����true�����򷵻�false
     */
    inline bool TransparentImage(IMAGE* dstImg, int x, int y, IMAGE* srcImg, COLORREF transparentColor)
    {
        // ��������Ч��
        if (srcImg == nullptr || srcImg->getwidth() == 0 || srcImg->getheight() == 0) {
            return false;
        }

        HDC dstDC = (dstImg == nullptr) ? GetImageHDC() : GetImageHDC(dstImg);
        HDC srcDC = GetImageHDC(srcImg);

        int width = srcImg->getwidth();
        int height = srcImg->getheight();

        // ʹ��TransparentBlt����ʵ��ָ����ɫ͸��
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