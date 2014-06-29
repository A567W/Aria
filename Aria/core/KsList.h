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
 * @file	KsList.h
 * @brief	テンプレートリスト操作クラス
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSLIST_H__
#define __KSLIST_H__

/*==============================================================================================*/
/*                                 << インクルード >>                                           */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << 定義 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << 宣言 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsList
 * @brief		テンプレートリスト操作クラス
 * @author		A567W
 * @date		2008/02/06
 * @since		2008/02/06
 * @version		1.0.0
 */
/************************************************************************************************/
template< typename T> class KsList
{
	private:
		/**
		 * @struct		KsListNode
		 * @brief		リストノード
		 * @author		A567W
		 * @date		2004/03/30
		 */
		struct KsListNode
		{
			/**
			 * コンストラクタ
			 */
			KsListNode() : next(0), prev(0) {}

			KsListNode*		next;		/**< 次のノード	*/
			KsListNode*		prev;		/**< 前のノード	*/
			T				element;	/**< 要素		*/
		};

	public:

		/**
		 * @class		Iterator
		 * @brief		イテレータ
		 * @author		A567W
		 * @date		2004/03/30
		 */
		class Iterator
		{
			public:
				Iterator() : current(0) {}

				Iterator( KsListNode* begin ) : current(begin) {}

				Iterator&		operator ++() { current = current->next; return *this; }
				Iterator&		operator --() { current = current->prev; return *this; }
				Iterator		operator ++(KsInt32) { Iterator tmp = *this; current = current->next; return tmp; }
				Iterator		operator --(KsInt32) { Iterator tmp = *this; current = current->prev; return tmp; }

				Iterator		operator + ( KsInt32 num ) const 
				{ 
					Iterator tmp = *this; 

					if( num >= 0 ){
						while( num-- && tmp.current != 0 ){
							++tmp;
						}
					}
					else{
						while( num++ && tmp.current != 0 ){
							--tmp;
						}
					}

					return tmp; 
				} 

				Iterator&		operator+=( KsInt32 num )
				{ 
					if( num >= 0 ){
						while( num-- && this->current != 0 ) ++(*this);
					}
					else{
						while( num++ && this->current != 0 ) --(*this); 
					}

					return *this; 
				} 

				Iterator		operator-( KsInt32 num ) const  { return (*this)+(-num);          } 
				Iterator		operator-=( KsInt32 num ) const { (*this)+=(-num);  return *this; }

				bool			operator ==(const Iterator& other) const { return current == other.current; };
				bool			operator !=(const Iterator& other) const { return current != other.current; };

				T&				operator *() { return current->element; };

			private:

				friend class	KsList<T>;

				KsListNode*		current;
		};

	public:
		/**
		 * コンストラクタ
		 */
								KsList() : m_root( 0 ), m_last( 0 ), m_size( 0 ) {}

		/**
		 * デストラクタ
		 */
								~KsList() { clear(); }

		/**
		 * 要素数を取得する
		 * @return				リストの要素数
		 */
		KsInt32					size() const { return m_size; }

		/**
		 * リストの要素をすべて削除してクリアする
		 */
		void					clear()
		{
			KsListNode* node = m_root;

			while( node )
			{
				KsListNode* next = node->next;
				delete node;
				node = next;
			}

			m_root = 0;
			m_last = 0;
			m_size = 0;
		}

		/**
		 * リストが空かどうかをチェックする
		 * @retval	ksTRUE		配列は空
		 * @retval	ksFALSE		空じゃない
		 */
		KsBool					empty()			const	{ return ( m_root == 0 );	}

		/**
		 * 要素を最後に追加する
		 * @param	element		リストに追加する要素
		 */
		void					push_back( const T& element )
		{
			KsListNode* node = new KsListNode;
			node->element = element;

			++m_size;

			if( m_root == 0 )
			{
				m_root = node;
			}

			node->prev = m_last;

			if (m_last != 0)
				m_last->next = node;

			m_last = node;
		}

		/**
		 * 要素を先頭に追加する
		 * @param	element		リストに追加する要素
		 */
		void					push_front(const T& element)
		{
			KsListNode* node = new KsListNode;
			node->element = element;

			++m_size;

			if( m_root == 0 )
			{
				m_last = node;
				m_root = node;
			}
			else
			{
				node->next = m_root;
				m_root->prev = node;
				m_root = node;
			}
		}

		/**
		 * リストの先頭イテレータのを取得する
		 * @return	リストの先頭イテレータ
		 */
		Iterator				begin() const { return Iterator(m_root); }

		/**
		 * リストの終端イテレータのを取得する
		 * @return	リストの終端イテレータ
		 */
		Iterator				end() const { return Iterator(0); }

		Iterator				getLast() const { return Iterator(m_last); }

		Iterator				find( Iterator& start, Iterator& end, const T& element )
		{
			for( Iterator it = start; it != end(); ++i ){
				if( it.current->element == element ){
					return it;
				}
			}

			return end();
		}

		void					insert_after(Iterator& it, const T& element)
		{
			KsListNode* node = new KsListNode;
			node->element = element;

			node->next = it.current->next;

			if (it.current->next)
				it.current->next->prev = node;

			node->prev = it.current;
			it.current->next = node;
			++m_size;

			if (it.current == m_last) 
				m_last = node;
		}

		void					insert_before(Iterator& it, const T& element)
		{
			KsListNode* node = new KsListNode;
			node->element = element;

			node->prev = it.current->prev;

			if (it.current->prev)
				it.current->prev->next = node;

			node->next = it.current;
			it.current->prev = node;
			++m_size;

			if (it.current == m_root) 
				m_root = node;
		}

		Iterator				erase(Iterator& it)
		{
			Iterator returnIterator(it);
			++returnIterator;

			if (it.current == m_root)
				m_root = it.current->next;

			if (it.current == m_last)
				m_last = it.current->prev;

			if (it.current->next)
				it.current->next->prev = it.current->prev;

			if (it.current->prev)
				it.current->prev->next = it.current->next;

			delete it.current;
			it.current = 0;
			--m_size;

			return returnIterator;
		}

	private:
		KsListNode*				m_root;		/**< ルートノード	*/
		KsListNode*				m_last;		/**< ラストノード	*/
		KsInt32					m_size;		/**< リストサイズ	*/
};

ksNS_KS_END

#endif /* __KSLIST_H__ */

