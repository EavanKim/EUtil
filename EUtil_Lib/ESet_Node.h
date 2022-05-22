#pragma once

namespace Eavan
{
	template<class C = EBase>
	class ESet_Node : public EBase
	{
	public:
		explicit ESet_Node();
		explicit ESet_Node(C* _data);
		explicit ESet_Node(EPtr<ESet_Node<C>>& _data);
		ESet_Node(ESet_Node<C>& _data);
		ESet_Node(ESet_Node<C>&& _data);

		virtual ~ESet_Node();

		void Insert(EPtr<ESet_Node<C>>& _node);
		void Insert(C* _node);
		void Remove();

		virtual void InitData(EPtr<EInfomation> _info) {};

	private:
		EPtr<ESet_Node<C>> m_prev = nullptr;
		EPtr<ESet_Node<C>> m_next = nullptr;
		EPtr<C> m_data = nullpt;
	};

	template<class C>
	inline ESet_Node<C>::ESet_Node()
		: EBase()
	{
		m_data = nullptr;
	}

	template<class C>
	inline ESet_Node<C>::ESet_Node(C* _data)
		: EBase()
	{
		m_data = _data;
	}

	template<class C>
	inline ESet_Node<C>::ESet_Node(ESet_Node<C>& _data)
		: EBase()
	{
		m_data = _data.m_data;
		m_prev = _data.m_prev;
		m_next = _data.m_next;
	}

	template<class C>
	inline ESet_Node<C>::ESet_Node(ESet_Node<C>&& _data)
		: EBase()
	{
		m_data = _data.m_data;
		m_prev = _data.m_prev;
		m_next = _data.m_next;
	}

	template<class C>
	inline ESet_Node<C>::~ESet_Node()
	{
		Remove();
	}

	template<class C>
	inline void ESet_Node<C>::Insert(EPtr<ESet_Node<C>>& _node)
	{
		if (m_next.IsNull())
		{
			m_next = _node;
		}
		else
		{
			(*m_next)->m_prev = _node;
			m_next = _node;
		}
	}

	template<class C>
	inline void ESet_Node<C>::Insert(C* _node)
	{
		if (m_next.IsNull())
		{
			m_next = new ESet_Node<C>(_node);
		}
		else
		{
			ESet_Node<C>* newPtr = new ESet_Node<C>(_node);
			(*m_next)->m_prev = newPtr;
			m_next = newPtr;
		}
	}

	template<class C>
	inline void ESet_Node<C>::Remove()
	{
		if (!m_prev.IsNull())
		{
			(*m_prev)->m_next = m_next;
		}

		if (!m_next.IsNull())
		{
			(*m_next)->m_prev = m_prev;
		}
	}
}

