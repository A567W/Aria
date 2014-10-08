/************************************************************************************************/
/** 
 * @file		KsDrawCmd.h
 * @brief		DirectX用深度ステンシルステート
 * @author		A567W
 * @date		----/--/--
 * @since		----/--/--
 * @version		1.0
 */
/************************************************************************************************/
#ifndef __KSDRAWCMD_H__
#define __KSDRAWCMD_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsRenderCmd.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsDrawCmd
 * @brief		深度ステンシルステート
 * @author		A567W
 */
/************************************************************************************************/
class ksENGINE_API KsDrawCmd : public KsRenderCmd
{
    public:
        KsUInt32            m_primitiveType;        /**< プリミティブタイプ  */
        KsUInt32            m_startVertexLocation;  /**< 開始頂点           */
        KsUInt32            m_vertexCount;          /**< 頂点数            */

    public:
        /**
         * KsDrawCmdの描画コマンドを実行する。
         */
        void                execute();
};


ksNS_KS_END

#endif		/* __KSDRAWCMD_H__ */

