#pragma once

// 템플릿 때문에 여따가 구현

template <typename type>
struct Node {
	type data;
	Node * next = nullptr;
};

template <class type>	
class List {
private:
	Node<type> head;
	Node<type> tail;
	Node<type> * p_now;
	Node<type> * p_temp;
	Node<type> * p_before;

	int size;

public:
	int First() {
		if (size == 0)
			return 0;

		p_now = head.next;
		return 1;
	}

	int Next() {
		if (p_now->next == &tail || p_now == &tail)
			return 0;

		p_before = p_now;
		p_now = p_now->next;
		return 1;
	}

	void Add(type _data) {
		p_temp = new Node<type>;
		p_temp->data = _data;
		p_temp->next = p_now->next;
		p_now->next = p_temp;
		p_before = p_now;
		p_now = p_temp;
		size++;
	}

	void Remove() {
		p_temp = p_now;
		p_before->next = p_now->next;
		p_now = p_before;
		delete p_temp;
		size--;
	}

	void PutData(type _data) {
		p_now->data = _data;
	}

	type GetData() {
		return p_now->data;
	}

	int GetSize() {
		return size;
	}
	
	int IsEmpty() {
		if (size == 0) return 1;
		else return 0;
	}

	List() {
		Initialize();
	}

	~List() {
		First();
		while (!IsEmpty())
			Remove();
	}
	
private:
	void Initialize() {
		head.next = &tail;
		p_now = &head;
		size = 0;
	}
};