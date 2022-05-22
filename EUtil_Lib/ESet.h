#pragma once

#include "ESet_Node.h"

namespace Eavan
{
	template<class C>
	class ESet : public EBase
	{
	public:
		explicit ESet();
		virtual ~ESet();

		void Insert(C* _data);
		void Remove(C* _data);

		virtual void InitData(EPtr<EInfomation> _info) {};
		
	template<class C>
		class EIterator
		{
		public:
			explicit EIterator(ESet<C>& _Set)
			{
				m_curr = _Set.m_datas;
			}

			EBOOL operator++()
			{
				m_curr = (*m_curr)->m_next;
			}

			EBOOL operator--()
			{
				m_curr = (*m_curr)->m_prev;
			}

			EPtr<C> operator*()
			{
				return m_curr;
			}

		private:
			EPtr<ESet_Node<C>> m_curr;
		};

		class EConstIterator
		{
		public:
			explicit EConstIterator(ESet<C>& _Set)
			{
				m_curr = _Set.m_datas;
			}

			EBOOL operator++()
			{
				m_curr = (*m_curr)->m_next;
			}

			EBOOL operator--()
			{
				m_curr = (*m_curr)->m_prev;
			}

			const EPtr<C> operator*()
			{
				return m_curr;
			}

		private:
			EPtr<ESet_Node<C>> m_curr;
		};

	private:
		EBptree m_tree;
		EPtr<ESet_Node<C>> m_datas;
	};

	template<class C>
	inline ESet<C>::ESet()
	{

	}

	template<class C>
	inline ESet<C>::~ESet()
	{
		m_datas = nullptr;
	}

	template<class C>
	inline void ESet<C>::Insert(C* _data)
	{

	}

	template<class C>
	inline void ESet<C>::Remove(C* _data)
	{

	}
}

