#ifndef TLISTITEM_H
#define	TLISTITEM_H

#include "Square.h"
#include "Rectangle.h"
#include "Trapeze.h"
#include <memory>
#include "TAllocationBlock.h"

template <class T>
class TListItem {
public:
	TListItem(const std::shared_ptr<T> &figure);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TListItem<A>& obj);

	std::shared_ptr<TListItem<T>> SetNext(std::shared_ptr<TListItem<T>> next);
	std::shared_ptr<TListItem<T>> GetNext();
	std::shared_ptr<T> GetFigure();
	//Figure GetFigure() const;
	void *operator new(size_t size);
	void operator delete(void *ptr);

	virtual ~TListItem();
private:
	std::shared_ptr<T> figure;
	std::shared_ptr<TListItem<T>> next;
	static TAllocationBlock listitem_allocator;
};

#endif	/* TLISTITEM_H */