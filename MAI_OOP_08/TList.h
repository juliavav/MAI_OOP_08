#ifndef TLIST_H
#define	TLIST_H

#include "Square.h"
#include "Rectangle.h"
#include "Trapeze.h"
#include "TListItem.h"
#include <memory>
#include "TIterator.h"
#include <future>
#include <mutex>

template <class T>
class TList {
public:
	TList();
	

	int length();

	void addFirst(std::shared_ptr<T> &figure);
	void insert(int index, std::shared_ptr<T> &figure);
	void addLast(std::shared_ptr<T> &figure);
	bool empty();
	void delElement(int &index);
	void eraseList();
	TIterator<TListItem<T>, T> begin();
	TIterator<TListItem<T>, T> end();
	std::shared_ptr<TListItem<T>> PSort(std::shared_ptr<TListItem<T>>& first);
	std::shared_ptr<TListItem<T>> Partition(std::shared_ptr<TListItem<T>>& first);
	void Sort();
	void ParSort();
	std::shared_ptr<TListItem<T>> PParSort(std::shared_ptr<TListItem<T>>& first);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TList<A>& list);
	virtual ~TList();
private:
	std::mutex mutex;
	std::shared_ptr<TListItem<T>> first;
};

#endif	/* TLIST_H */