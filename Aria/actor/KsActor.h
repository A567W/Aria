/*************************************************************************************************/
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 A567W
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @file	KsActor.h
 * @brief	アクターオブジェクト
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSACTOR_H__
#define __KSACTOR_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                            */
/*==============================================================================================*/
#include "KsActorCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN


/************************************************************************************************/
/**
 * @class	KsActor
 * @brief	アクターオブジェクトクラス
 * @author	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsActor
{
    protected:
        KsModel*                    m_pModel;           /**< モデルデータ			*/
        KsSkeleton*                 m_pSkeleton;        /**< スケルトンデータ		*/
        KsAnimationController*      m_pCurrentAnim;     /**< 現在のアニメデータ	*/
        KsHumanIK*                  m_pHumanIK;         /**< IK制御データ			*/
        //KsPhysicsController*        m_pPhysics;   /**< 物理演算データ		*/

    public:
        /**
         * コンストラクタ
         */
        KsActor();

        /**
         * コンストラクタ
         * @param   pModel		モデル
         */
        KsActor( KsModel* pModel );

        /**
         * デストラクタ
         */
        virtual ~KsActor();

        /**
         * 更新処理
         * @param   gameTime    更新時間
         */
        virtual void update( KsReal gameTime );

        /**
         * 描画処理
         * @param   pRenderContext  描画コンテキスト
         */
        virtual void draw( KsRenderContext* pRenderContext );

		/**
         * アニメーションをセットする
         * @param   pCurrentAnim    アニメーション
         */
        void setAnimation( KsAnimationController* pCurrentAnim );

		/**
         * アニメーションをセットする
         * @return  現在のアニメーション
         */
        KsAnimationController* getAnimation() { return m_pCurrentAnim; }

        /**
         * モデルデータを取得する
         * @return  モデルデータ
         */
        KsModel*    getModel() { return m_pModel; }

        /**
         * IKをセットする
         * @param	pHumanIK    IK
         */
        void setHumanIK( KsHumanIK* pHumanIK );

        /**
         * 物理演算データをセットする
         * @param	pPhysics    物理演算データ
         */
        //void setPhysics( KsPhysicsController* pPhysics );
};

ksNS_KS_END

#endif /* __KSACTOR_H__ */
