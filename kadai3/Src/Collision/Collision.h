#pragma once
#include <DxLib.h>
#include <cmath>

/// <summary>
/// �l�p�`�Ɠ_�̓����蔻��
/// </summary>
/// <param name="RectX">�l�p�`�̍��WX</param>
/// <param name="RectY">�l�p�`�̍��WY</param>
/// <param name="RectW">�l�p�`�̉���</param>
/// <param name="RectH">�l�p�`�̏c��</param>
/// <param name="mousePosX">�}�E�X�̍��WX</param>
/// <param name="mousePosY">�}�E�X�̍��WY</param>
/// <returns>true = �������Ă���</returns>
static bool CollCheckPointRect(int RectX, int RectY, int RectW, int RectH, int mousePosX, int mousePosY)
{
    return (RectX - (RectW / 2) < mousePosX &&
        RectX - (RectW / 2) + RectW > mousePosX &&
        RectY - (RectH / 2) < mousePosY &&
        RectY - (RectH / 2) + RectH > mousePosY);
}

/// <summary>
/// 3D�l�p�`���m�̓����蔻��
/// </summary>
/// <param name="boxAPos">�l�p�`A�̍��W</param>
/// <param name="boxASize">�l�p�`A�̃T�C�Y</param>
/// <param name="boxBPos">�l�p�`B�̍��W</param>
/// <param name="boxBSize">�l�p�`A�̃T�C�Y</param>
/// <returns>true = �������Ă���</returns>
static bool CollCheckCube(VECTOR boxAPos, VECTOR boxASize, VECTOR boxBPos, VECTOR boxBSize)
{
    return (boxAPos.x < boxBPos.x + boxBSize.x &&
        boxAPos.x + boxASize.x > boxBPos.x &&
        boxAPos.y < boxBPos.y + boxBSize.y &&
        boxAPos.y + boxASize.y > boxBPos.y &&
        boxAPos.z < boxBPos.z + boxBSize.z &&
        boxAPos.z + boxASize.z > boxBPos.z
        );
}

/// <summary>
/// 3D�l�p�`���m�̓����蔻��
/// </summary>
/// <param name="boxAPos">�l�p�`A�̍��W</param>
/// <param name="boxASize">�l�p�`A�̃T�C�Y</param>
/// <param name="boxBPos">�l�p�`B�̍��W</param>
/// <param name="boxBSize">�l�p�`A�̃T�C�Y</param>
/// <returns>true = �������Ă���</returns>
static bool CollCheckCubeCenter(VECTOR boxAPos, VECTOR boxASize, VECTOR boxBPos, VECTOR boxBSize)
{
    return (abs(boxAPos.x - boxBPos.x) < (boxASize.x / 2 + boxBSize.x / 2) &&
        abs(boxAPos.y - boxBPos.y) < (boxASize.y / 2 + boxBSize.y / 2) &&
        abs(boxAPos.z - boxBPos.z) < (boxASize.z / 2 + boxBSize.z / 2));
}

/// <summary>
/// 3D�����m�̓����蔻��
/// </summary>
/// <param name="sphereAPos">����A�̍��W</param>
/// <param name="sphereARadius">����B�̔��a</param>
/// <param name="sphereBPos">����B�̍��W</param>
/// <param name="sphereBRadius">����B�̔��a</param>
/// <returns>true = �������Ă���</returns>
static bool CollCheckSphere(VECTOR sphereAPos, float sphereARadius, VECTOR sphereBPos, float sphereBRadius)
{
    // �Q�̍��W�Ԃ̋������s�^�S���X�̒藝�ŎZ�o
    VECTOR distance;
    distance.x = sphereAPos.x - sphereBPos.x;
    distance.y = sphereAPos.y - sphereBPos.y;
    distance.z = sphereAPos.z - sphereBPos.z;
    float dis = distance.x * distance.x + distance.y * distance.y + distance.z * distance.z;

    // ���݂��̔��a�����v����
    float radius = sphereARadius + sphereBRadius;

    // ���v�������a�̂Q������A�Q�̍��W�Ԃ̋�������������΋��̂͏Փ˂��Ă���
    return (radius * radius > dis);
}

/// <summary>
/// 2D�l�p�`���m�̓����蔻��
/// </summary>
/// <param name="boxAPos">�l�p�`A�̍��W</param>
/// <param name="boxASize">�l�p�`A�̃T�C�Y</param>
/// <param name="boxBPos">�l�p�`B�̍��W</param>
/// <param name="boxBSize">�l�p�`A�̃T�C�Y</param>
/// <returns>true = �������Ă���</returns>
static bool CollCheckBox(VECTOR boxAPos, VECTOR boxASize, VECTOR boxBPos, VECTOR boxBSize)
{
    return (boxAPos.x < boxBPos.x + boxBSize.x &&
        boxAPos.x + boxASize.x > boxBPos.x &&
        boxAPos.y < boxBPos.y + boxBSize.y &&
        boxAPos.y + boxASize.y > boxBPos.y
        );
}

/// <summary>
/// 2D�l�p�`���m�̓����蔻��
/// </summary>
/// <param name="boxAPos">�l�p�`A�̍��W</param>
/// <param name="boxASize">�l�p�`A�̃T�C�Y</param>
/// <param name="boxBPos">�l�p�`B�̍��W</param>
/// <param name="boxBSize">�l�p�`A�̃T�C�Y</param>
/// <returns>true = �������Ă���</returns>
static bool CollCheckBoxCenter(VECTOR boxAPos, VECTOR boxASize, VECTOR boxBPos, VECTOR boxBSize)
{
    return (abs(boxAPos.x - boxBPos.x) < (boxASize.x / 2 + boxBSize.x / 2) &&
        abs(boxAPos.y - boxBPos.y) < (boxASize.y / 2 + boxBSize.y / 2));
}

/// <summary>
/// 2D�����m�̓����蔻��
/// </summary>
/// <param name="sphereAPos">����A�̍��W</param>
/// <param name="sphereARadius">����B�̔��a</param>
/// <param name="sphereBPos">����B�̍��W</param>
/// <param name="sphereBRadius">����B�̔��a</param>
/// <returns>true = �������Ă���</returns>
static bool CollCheckCircle(VECTOR sphereAPos, float sphereARadius, VECTOR sphereBPos, float sphereBRadius)
{
    // �Q�̍��W�Ԃ̋������s�^�S���X�̒藝�ŎZ�o
    VECTOR distance;
    distance.x = sphereAPos.x - sphereBPos.x;
    distance.y = sphereAPos.y - sphereBPos.y;
    float dis = distance.x * distance.x + distance.y * distance.y;

    // ���݂��̔��a�����v����
    float radius = sphereARadius + sphereBRadius;

    // ���v�������a�̂Q������A�Q�̍��W�Ԃ̋�������������΋��̂͏Փ˂��Ă���
    return (radius * radius > dis);
}
